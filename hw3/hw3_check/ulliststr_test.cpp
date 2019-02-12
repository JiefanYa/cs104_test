#include <iostream>
#include "ulliststr.h"

using namespace std;

int main(){
	
	ULListStr test1, test2, test3;
	test1.push_back("hi");
	test1.push_back("there");
	test1.push_front("Oops");
	test2.push_front("Yo");
	test2.push_front("how's");
	test2.push_front("going");
	test2.push_front("dude");
	test3.push_back("My");
	test3.push_back("name");
	test3.push_back("is");
	test3.push_back("Pikachu");
	test3.push_front("there");
	test3.push_front("Hello");
	test3.push_back("It's");
	test3.push_back("nice");
	test3.push_back("to");
	test3.push_back("meet");
	test3.push_back("you");
	test3.push_back("Yeah");
	test3.push_back("My");
	test3.push_back("friend");
	
	ULListStr list1(test1);
	cout <<list1.size()<<" "<<list1[0]<<" "<<list1[1]<<" "<<list1[2]<<endl;
	list1 = test2;
	cout <<list1.size()<<" "<<list1[0]<<" "<<list1[1]<<" "<<list1[2]<<" "<<list1[3]<<endl;
	list1[2] = "fuck";
	cout << list1[2]<<endl;
	test3-=8;
	cout<<test3.size()<<" "<<test3[5]<<endl;
	test3 = test3 + test1;
	cout<<test3.size()<<" "<<test3[5]<<" "<<test3[8]<<endl;

	return 0;
}