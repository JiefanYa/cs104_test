#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
// edited from USC CS104 Spring 2019 skeleton given
using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

void generateTeam1(string* names, string* t, 
      int len, int currlen, int li, int ti);
void generateTeam2(string* names, string* t, int len);
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

void generateTeam2(string* names, string* t1, string* t2, int len)
{
  int n = 0;
  bool found = false;
  for(int i = 0;i<len*2;i++){
    for(int j=0;j<len;j++){
      if(names[i]==t1[j]){
        found = true;
        break;
      }
    }
    if(!found){
      t2[n] = names[i];
      n++;
      if(n==len) break;
    }
    found = false;
  }
}

void generateTeam1(string* names, string* t, 
			int len, int currlen, int li, int ti)
{
	if(li>=2*len) return;
  if(currlen==len){
    string* t2 = new string[len];
    generateTeam2(names,t,t2,len);
    printSolution(t,t2,len);
    printSolution(t2,t,len);
    return;
  }
	t[ti] = names[li];
	generateTeam1(names,t,len,currlen+1,li+1,ti+1);
  t[ti] = "";
  generateTeam1(names,t,len,currlen,li+1,ti);
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
  string* t = new string[len];
  generateTeam1(names, t, len, 0, 0, 0);
  delete [] names;
  delete [] t;
  return 0;
}