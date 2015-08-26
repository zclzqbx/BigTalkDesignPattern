//decorate model
//用于给某些类动态添加功能，虽然添加了一些功能，但人还是人，只不过是装饰后的人
#include<iostream>
#include<string>

using namespace std;

class Person{//被装饰对象类
public:
	virtual void show()
	{
		cout<<"Person"<<endl;
	}

};

class Decorate:public Person{//所有装饰类的基类
public:
	void setPerson(Person* dePerson)
	{//设置该类所装饰的对象，该函数传递的是一Person类的指针，所以也可以由子类初始化
		person=dePerson;
	}

    void show()
	{//显示函数，这一函数是一个虚函数，可以由子类实现
		//而且，person是一个基类指针，具体指向由用户决定
		if(person!=NULL)
			person->show();
	}

protected:
	Person *person;
};

class Tshirts:public Decorate{
public:
	void addFunction1()
	{//特有操作
		cout<<"function1 added"<<endl;
	}

	void show()
	{
		addFunction1();//子类添加的功能
		Decorate::show();//被装饰对象原有的功能
	}
};

class Trouser:public Decorate{
public:
	void addFunction2()
	{//特有操作
		cout<<"function2 added"<<endl;
	}

	void show()
	{
		addFunction2();//子类添加的功能
		Decorate::show();//子被装饰对象原有的功能
	}
};

int main()
{
	Person* person=new Person();
	person->show();

	Tshirts* tshir=new Tshirts();
	tshir->setPerson(person);
	tshir->show();

	Trouser* trou=new Trouser();
	trou->setPerson(tshir);
	trou->show();
	return 0;
}
