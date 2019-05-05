 

To compile and run.
g++ question2.cpp -o ques
./ques input.txt 2 2


While reading records from input.txt it is checked for presence of duplicate in data structure,if duplicate is found records are not added to the linear hashing data structure.


output file consists of duplicates.current hashvalue and current boxtosplit


eg:
elements in buffer 
0  8 16 
1  1 9 17 
2  2 10 18 
3  3 11 
4  4 12 
5  13 5 
6  14 6 
7  15 7 

Duplicates found 
1 2 3 4 5 6 7 8 9 10 

current_hash_Value 8 

box_to_split 4 