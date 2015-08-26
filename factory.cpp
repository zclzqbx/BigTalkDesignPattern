//simple factory model
//与简单工厂模式的区别：简单工厂模式在增加新操作时，需要更改工厂函数，违反了开放与封闭原则
//而工厂方法模式支持扩展，在修改时只需要添加新的操作类和工厂类即可，但客户端也需要作相应的修改
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

//抽象工厂函数
class Factory{
public:
	virtual Operation* createOper()=0;
};

//四个具体工厂
class AddFactory:public Factory{
	Operation* createOper()
	{
		AddOperation* addOper=new AddOperation();
		return addOper;
	}
};

class SubFactory:public Factory{
	Operation* createOper()
	{
		SubOperation* subOper=new SubOperation();
		return subOper;
	}
};

class MulFactory:public Factory{
	Operation* createOper()
	{
		MulOperation* mulOper=new MulOperation();
		return mulOper;
	}
};

class DivFactory:public Factory{
	Operation* createOper()
	{
		DivOperation* divOper=new DivOperation();
		return divOper;
	}
};

int main()
{
	int number1,number2;
	cout<<"please input number1:";
	cin>>number1;
	cout<<endl;

	cout<<"please input number2:";
	cin>>number2;
	cout<<endl;

	Factory* factory=new AddFactory();//创建新工厂，用于生产新的对象
	Operation* oper;//具体操作在创建时确定

	oper=factory->createOper();
	oper->setOne(number1);
	oper->setTwo(number2);

	cout<<"The Result is:";
	cout<<oper->getResult()<<endl;

	return 0;
}

