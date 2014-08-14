import Data.List

main = do 
	putStrLn . unwords . map show $ sort [0.23,0.72,0.82,0.99,0.17,0.98,0.70,0.44,0.51,0.45]
	putStrLn . unwords . map show $ sort [0.01,0.04,0.14,0.48,0.19,0.06,0.65,0.33,0.88,0.55]
