//代理模式，对真实对象的访问通过代理完成
#include<iostream>

using namespace std;

//代理和真实对象的公用接口
class Subject{
public:
	virtual void request()=0;
	virtual void behavior()=0;
};

//真实对象
class RealSubject:public Subject{
public:
	void request()
	{
		cout<<"真实的请求"<<endl;
	}

	void behavior()
	{
		cout<<"真实的行为"<<endl;
	}
};

//代理，代理通过访问真实对象完成和真实对象相同的操作
class Proxy:public Subject{
public:
	void request()
	{
		subject.request();
	}
	
	void behavior()
	{
		subject.behavior();
	}

private:
	RealSubject subject;
};

int main()
{
	//网页加载时图片的加载就是使用的代理，网页打开时，图片是一张一张出现的，先于图片出现的就是代理
	Proxy* proxy=new Proxy();
	proxy->request();
	proxy->behavior();
	return 0;
}
