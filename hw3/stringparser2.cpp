#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "stackstring.h"

using namespace std;

string process(string);
string processPlus(string);
string processMinus(string);
string processRemove(string);

string process(string s){
	// delete leading and trailing spaces
	size_t x = s.find_first_not_of(" ");
	size_t y = s.find_last_not_of(" ");
	s.erase(y+1);
	s.erase(0,x);
	// check if there is space in the word
	for(size_t i=0;i<s.size();i++)
		if(isspace(s[i])) return "MAL";
	return s;
}

string processPlus(string s){
	// recursively process a string with several '+'s
	size_t pos = s.find("+");
	// base case 1: no more '+'
	if(pos==string::npos) return processRemove(s);

	// base case 2: '+' at the beginning or the end
	if(pos==0 || pos==s.size()-1) return "MAL";

	// recursive case: separate string at '+'
	string result;
	result = processRemove(s.substr(0,pos)) + 
		processPlus(s.substr(pos+1));
	if(result.find("MAL")!=string::npos) return "MAL";
	else return result;
}

string processMinus(string s){
	// process a string with one '-'
	size_t pos = s.find("-");
	if(pos==0 || pos==s.size()-1) return "MAL";
	string s1 = processRemove(s.substr(0,pos));
	string s2 = processRemove(s.substr(pos+1));
	if(s1=="MAL"||s2=="MAL") return "MAL";
	size_t found = s1.find(s2);
	if(found==string::npos) return s1;
	else{
		return s1.substr(0,found)+
			s1.substr(found+s2.size());
	}
}

string processRemove(string s){
	// process a string with '>' '<' or not
	int count1 = 0;
	int count2 = 0;
	size_t i = 0;
	while(i<s.size()-1 && !islower(s[i])){
		if(s[i]=='>') count1++;
		else if(s[i]=='<') count2++;
		i++;
	}
	for(size_t j=i;j<s.size();j++){
		if(!islower(s[j])) return "MAL";
	}
	// i = count1+count2 >= s.size()-i
	if(2*i >= s.size()) return "MAL";
	return s.substr(i+count1,s.size()-i-count1-count2);
}

int main(int argc, char* argv[]){
	if(argc!=3){
		cout << "Missing command line arguments\n";
		return 0;
	}
	ifstream ifile(argv[1]);
	if(ifile.fail()){
		cout << "Error\n";
		return 0;
	}
	ofstream ofile(argv[2]);
	if(ofile.fail()){
		cout << "Error\n";
		return 0;
	}	
	string target;
	while(getline(ifile, target))
	{
		if(target.find_first_not_of(' ')==string::npos)
		{
			// eliminate blank lines
			ofile << endl;
			continue;
		}

		StackString s;
		string temp = "";
		bool mal = false; // malform
		bool started = false; // new word started

		for(size_t i = 0;i<target.size();i++)
		{
			char curr = target[i];
			if(curr == '(' || curr == '<' || curr == '>' || curr == '+'
				|| curr == '-' || curr == ')' || islower(curr) || isspace(curr))
			{
				if(curr == '('){
					if(started){
						mal = true;
						break;
					}
					s.push("(");
					started = false;
					temp = "";
				}
				else if(curr=='+' || curr=='-' || curr == '<' || curr == '>'){
					started = false;
					string t = process(temp);
					if(t=="MAL"){
						mal = true;
						break;
					}
					s.push(t);
					temp = "";
					string x;
					x = curr;
					s.push(x);
				}
				else if(isspace(curr)){
					if(started==false) continue;
					else{ //started==true
						temp+=" ";
					}
				}
				else if(islower(curr)){
					if(started==false){
						started = true;
						temp = curr;
					}
					else{ // started==true
						temp+=curr;
					}
				}
				else if(curr == ')'){
					started = false;
					string t = process(temp);
					if(t=="MAL"){
						mal = true;
						break;
					}					
					s.push(t); 
					temp = "";
					string currString = "";
					while(!s.empty() && s.top()!="("){
						currString = s.top() + currString;
						s.pop();
					}
					if(s.empty()){
						// missing '('
						mal = true;
						break;
					}
					if(currString.find("+")!=string::npos && 
						currString.find("-")!=string::npos){
						// contains both '+' and '-'
						mal = true;
						break;
					}
					if(currString.find("+")!=string::npos){
						// contain only '+'
						currString = processPlus(currString);
						if(currString=="MAL"){
							mal = true;
							break;
						}
					}
					else if(currString.find("-")!=string::npos){
						// contain only '-'
						currString = processMinus(currString);
						if(currString=="MAL"){
							mal = true;
							break;
						}
					}
					else{
						// contains neither '+' or '-'
						currString = processRemove(currString);
						if(currString=="MAL"){
							mal = true;
							break;
						}
					}
					// pop '('
					s.pop();
					// push new string
					s.push(currString);
				}
				if(i==target.size()-1 && temp != ""){
					// end of line wrap up temp
					string t = process(temp);
					if(t=="MAL"){
						mal = true;
						break;
					}					
					s.push(t);
				}
			}
			else{ 
				// invalid characters like A, ^
				mal = true;
				break;
			}
		}
		if(mal) ofile << "Malformed\n";
		else{
			string result = "";
			while(!s.empty()){
				if(s.top()=="("){
					mal = true;
					break;
				}
				else{
					result = s.top() + result;
					s.pop();	
				}
			}
			if(mal) ofile << "Malformed\n";
			else{	
				result = processRemove(result);
				if(result=="MAL") ofile << "Malformed\n";
				else ofile << result << endl;
			}
		}
	}
	ifile.close();
	ofile.close();
	return 0;
}