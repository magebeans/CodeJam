#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

vector<string> split(const string& path); //Splits a path string into a vector of folder names
int count_folders(const string& path); //Counts the number of folders in a given path string, excluding root
string sub_path(const string& path, int k); //Returns the path of the first k+1 folders in the path, excluding root

int main()
{
	int i,t,n,m,j,count,k;
	fstream fin("A-large-practice.in",ios::in);
	fstream fout("out",ios::out);
	
	fin >> t;
	for(i = 0; i < t;i++)
	{
		set<string> fs;
		fin >> n >> m;
		for(j = 0; j < n; j++)
		{
			string path;
			fin >> path;
			fs.insert(path);
		}

		count = 0;
		for(j = 0; j < m; j++)
		{
			string path;
			fin >> path;
			for(k = 0; k < count_folders(path); k++)
			{
				if(fs.find(sub_path(path,k)) == fs.end())
				{
					count++;
					fs.insert(sub_path(path,k));
				}

			}
			
		}

		fout << "Case #" << i+1 << ": " <<count << endl;
	}
	
	/*string path; 
	fin >> path;

	{
		vector<string> folders = split(path);
		fout << "Count: " << count_folders(path) << endl;
		fout << "Folder names: " << endl;
		for(unsigned int i = 0; i < folders.size(); i++)
			fout << folders[i] << " ";
		fout << endl;
		fout << "Folder paths: " << endl;
		for(int i = 0; i < count_folders(path); i++)
			fout << sub_path(path,i) << endl;
	}
	
	fout << endl;*/
}

vector<string> split(const string& path) //Splits a path string into a vector of folder names
{
	vector<string> ret;
	string::const_iterator i,j;
	i = path.begin();
	
	while(i++ != path.end()) //Increment i to move past previous '/' so that it now points to first letter of folder name
	{
		j = find(i,path.end(),'/'); //j points to the next '/' or to the end of path string
		ret.push_back(string(i,j)); //Add the next folder name, the substring between i and j
		i = j; //Move i forward to j, so i now points to the '/'
	}
	
	return ret;
}

int count_folders(const string& path) //Counts the number of folders in a given path string, excluding root
{
	return count(path.begin(),path.end(),'/');
}

string sub_path(const string& path, int k) //Returns the path of the first k+1 folders in the path, excluding root
{
	vector<string> folders = split(path);
	string ret;
	int i;
	for(i=0;i<k+1;i++)
		ret+= "/" + folders[i];
	return ret;
}