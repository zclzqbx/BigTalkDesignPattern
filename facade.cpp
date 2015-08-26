#include<iostream>

using namespace std;

class SubSystemOne{
public:
	void methodOne()
	{
		cout<<"method One"<<endl;
	}
};

class SubSystemTwo{
public:
	void methodTwo()
	{
		cout<<"method Two"<<endl;
	}
};

class SubSystemThree{
public:
	void methodThree()
	{
		cout<<"method Three"<<endl;
	}
};

class Facade{
public:
	void methodA()
	{
		systemOne.methodOne();
		systemTwo.methodTwo();
		systemThree.methodThree();
		cout<<"Three Operation"<<endl;
	}

	void methodB()
	{
		systemOne.methodOne();
		cout<<"Just one operation"<<endl;
	}

private:
	SubSystemOne systemOne;
	SubSystemTwo systemTwo;
	SubSystemThree systemThree;
};

int main()
{
	Facade facade;
	facade.methodA();
	facade.methodB();

	return 0;
}
