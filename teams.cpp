#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
// edited from USC CS104 Spring 2019 skeleton given
using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

void generateTeam(string* names, string* t1, string* t2,
      int len, int currlen1, int currlen2, 
      int li, int t1i, int t2i);

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
       const string* team2,
       int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here

void generateTeam(string* names, string* t1, string* t2,
      int len, int currlen1, int currlen2, 
      int li, int t1i, int t2i)
{
  if(li>=2*len) return;
  if(currlen1==len || currlen2==len){
    if(currlen1==len && currlen2<len){
      for(int i=t2i;i<len;i++){
        t2[i] = names[li];
        li++;
      }
    }
    else if(currlen2==len && currlen1<len){
      for(int i=t1i;i<len;i++){
        t1[i] = names[li];
        li++;
      }
    }
    printSolution(t1,t2,len);
    return;
  }
  t1[t1i] = names[li];
  generateTeam(names,t1,t2,len,currlen1+1,currlen2,li+1,t1i+1,t2i);
  t2[t2i] = names[li];
  generateTeam(names,t1,t2,len,currlen1,currlen2+1,li+1,t1i,t2i+1);
}


int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  // Complete the rest of main
  ifstream ifle(argv[1]);
  if(ifle.fail()){
    cout << "Error\n";
    return 1;
  }
  string temp;
  int n;
  ifle >> n;
  if(ifle.fail()){
    cout << "Error\n";
    return 1;
  }
  if(n%2!=0){
    cout << "Should be an even number\n";
    return 1;
  }
  string* names = new string[n];
  for(int i=0;i<n;i++){
    ifle >> temp;
    if(ifle.fail()){
      cout << "Error\n";
      return 1;
    }
    names[i] = temp;
  }
  int len = n/2;
  string* t1 = new string[len];
  string* t2 = new string[len];
  generateTeam(names, t1, t2, len, 0, 0, 0, 0, 0);
  delete [] names;
  delete [] t1;
  delete [] t2;
  return 0;
}
