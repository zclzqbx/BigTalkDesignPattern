#include<iostream>

using namespace std;

//把所有公共操作都提取到基类实现，具体操作由子类完成
class AbstractClass{
public:
	virtual	~AbstractClass()
	{
		//基类要有虚析构函数	
	}

	void templateMethod()
	{
		PrimitiveOperation1();
		PrimitiveOperation2();
	}

	//两个纯虚的析构函数，子类必须重新定义
	virtual void PrimitiveOperation1()=0;
	virtual void PrimitiveOperation2()=0;
};

//子类Ａ
class ConcreteClassA:public AbstractClass{
	void PrimitiveOperation1()
	{
		cout<<"A method one"<<endl;
	}

	void PrimitiveOperation2()
	{
		cout<<"A method two"<<endl;
	}
};

//子类Ｂ
class ConcreteClassB:public AbstractClass{
	void PrimitiveOperation1()
	{
		cout<<"B method one"<<endl;
	}

	void PrimitiveOperation2()
	{
		cout<<"B method two"<<endl;
	}
};

int main()
{
	AbstractClass* obj;

	obj=new ConcreteClassA();
	obj->templateMethod();
	delete obj;

	obj=new ConcreteClassB();
	obj->templateMethod();
	delete obj;

	return 0;
}
