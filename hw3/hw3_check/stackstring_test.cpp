#include <iostream>
#include "stackstring.h"
using namespace std;

int main(){
	StackString s1;
	cout <<boolalpha<<s1.empty()<<" "<<s1.size()<<endl;
	s1.push("yep");
	s1.push("time");
	s1.push("panda");
	s1.push("express");
	cout <<boolalpha<<s1.empty()<<" "<<s1.size()<<" "<<s1.top()<<endl;
	for(int i=1;i<=5;i++){
		s1.pop();
		cout <<s1.size()<<" "<<s1.top()<<endl;
	}
}