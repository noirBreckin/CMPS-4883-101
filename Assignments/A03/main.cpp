/**
* Name: Breckin Hume
* Course: 4883-Prog Tech
* Date: 9-6-24
*/
#include <iostream>
#include <fstream>
#define endl "\n"

using namespace std;


void openFiles(ifstream &infile, ofstream &outfile);

int main() {
    ifstream input;
    ofstream output;
    openFiles(input,output);
  
    long B = 0, A = 0;

    while(input >> A >> B)
      {
        if(A > B)
        {
          cout << A - B << endl;
          output << A - B << endl;
        }
        else
        {
          cout << B - A << endl;
          output << B - A << endl;
        }

      }
  input.close();
  output.close();
  return 0;
}

// Implementation for openFiles
void openFiles(ifstream &infile, ofstream &outfile) {
  char inFileName[40];
  char outFileName[40];

  cout << "Enter the input file name please: " << endl;
  cin >> inFileName;
  infile.open(inFileName); // Opens the input file

  cout << "Enter the output file name please: " << endl;
  cin >> outFileName;
  outfile.open(outFileName); // open output file
}
