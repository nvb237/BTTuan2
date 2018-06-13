#include <iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;

void bai1(){
	ifstream fileIn;
	fileIn.open("input.txt", ios::in);
	if (fileIn.fail() == true){
		cout << "File khong ton tai";
	}
	int n = 0;
	string str;
	stack<char> a;
	fileIn >> str;
	for (int i = 0; i < str.length(); i++){ // duyet tat ca cac phan tu cua chuoi
		if (str[i] == '('){  // neu gap dau mo ngoac
			a.push(str[i]); //push vao stack
		}
		else { // neu gap dau dong ngoac
			if (!a.empty())	{ // neu stack khac rong thi lay phan tu trong stack ra  
				a.pop();
			}
			else {  // neu stack rong thi n= n +1
				n++; // dem so ngoac dong thua
			}
		}
	}
	ofstream fileOut;
	fileOut.open("output.txt", ios::out);
	int  k = n; //gan k = so ngoac dong thua
	while (!a.empty())
	{
		n++; 
		a.pop();
	}
	fileOut << n; // n la so ngoac dong va mo thua 
	for (int i = 1; i <= n; i++)
	{
		if (i <= k) fileOut << "\n(" << i - 1 << endl;
		else fileOut << ")" << str.length() + i - k - 1 << endl;

	}
	fileIn.close();
	
	fileOut.close();
}
int main(){
	bai1();
	
}

