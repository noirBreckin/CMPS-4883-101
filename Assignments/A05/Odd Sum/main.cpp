#include <iostream>
#include <fstream>
using namespace std;

// void openFiles(ifstream &infile, ofstream &outfile);

int main() {

  // ifstream input;
  // ofstream output;
  // openFiles(input,output);

  
   int Cases;
   int a;
   int z;
   int sum = 0 ;
   int CaseCurrent = 0;
  
   cin >> Cases;
   while(Cases--)
   {
      sum=0;
      cin >> a;
      cin >> z;
      for(int i = a;i <= z;i++){

         if(i % 2 == 1){
            sum += i;
         }
      }
      cout << "Case " << ++CaseCurrent << ": "<< sum << endl;
   }
  // input.close();
  // output.close();
}  

// Implementation for openFiles
// void openFiles(ifstream &infile, ofstream &outfile) {
//   char inFileName[40];
//   char outFileName[40];

//   cout << "Enter the input file name please: " << endl;
//   cin >> inFileName;
//   infile.open(inFileName); // Opens the input file

//   cout << "Enter the output file name please: " << endl;
//   cin >> outFileName;
//   outfile.open(outFileName); // open output file
// }
