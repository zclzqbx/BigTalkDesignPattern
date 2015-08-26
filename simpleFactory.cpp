//simple factory model

#include<iostream>

using namespace std;

//用一个单独的类来做这个创造实例的过程，即工厂
class Operation{
public:
	Operation()
	{
		number1=0;
		number2=0;
		result=0;
	}

	Operation(int one,int two):number1(one),number2(two)
	{
		result=0;
	}

	void setOne(int one)
	{
		number1=one;
	}

	void setTwo(int two)
	{
		number2=two;
	}
	
	int getOne()
	{
		return number1;
	}

	int getTwo()
	{
		return number2;
	}

	virtual int getResult()
	{//虚接口，需要子类自己实现
		return result;
	}

protected:
	int number1;
	int number2;
	int result;
};

//四个具体操作的子类，主要用于实现虚函数接口
class AddOperation:public Operation{
public:
	virtual int getResult()
	{
		result=number1+number2;
		return result;
	}
};

class SubOperation:public Operation{
public:
	virtual int getResult()
	{
		result=number1-number2;
		return result;
	}
};

class MulOperation:public Operation{
public:
	virtual int getResult()
	{
		result=number1*number2;
		return result;
	}
};

class DivOperation:public Operation{
public:
	virtual int getResult()
	{
		result=number1/number2;
		return result;
	}
};

//工厂，一个接口类
class SimpleFactory{
public:
	static Operation* createOper(char operChar)
	{
		static Operation* oper;
		
		switch(operChar)
		{
			case '+':
				oper=new AddOperation();
				break;
			case '-':
				oper=new SubOperation();
				break;
			case '*':
				oper=new MulOperation();
				break;
			case '/':
				oper=new DivOperation();
				break;
			default:
				break;
		}
		return oper;	
	}
};

int main()
{
	char operChar;
	int number1,number2;
	cout<<"please input number1:";
	cin>>number1;
	cout<<endl;

	cout<<"please input number2:";
	cin>>number2;
	cout<<endl;

	cout<<"please input a operation:";
	cin>>operChar;
	cout<<endl;

	Operation* oper;//具体操作在创建时确定

	opedgr=SimpleFactory::createOper(operChar);//根据输入实例化对象
	//当需要新增其他操作时，只需要添加操作类及修改工厂，与客户端无关，客户端看不到改变
	oper->setOne(number1);
	oper->setTwo(number2);

	cout<<"The Result is:";
	cout<<oper->getResult()<<endl;

	return 0;
}

