//strategy model
//策略模式是一种定义一系列算法的方法
#include<iostream>

using namespace std;

//一个抽象的策略类
class Strategy{
public:
	virtual void algorithmInterface()=0;
};

//三种不同策略
class StrategyA:public Strategy{
	void algorithmInterface()
	{
		cout<<"A strategy"<<endl;
	}
};

class StrategyB:public Strategy{
	void algorithmInterface()
	{
		cout<<"B strategy"<<endl;
	}
};

class StrategyC:public Strategy{
	void algorithmInterface()
	{
		cout<<"C strategy"<<endl;
	}
};

//维护一个具体策略，具体策略由用户指定
class StrategyContext{
public:
	StrategyContext(char X)
	{//根据用户需要创建策略类
		switch(X)
		{//这里其实就是一个简单工厂模式，实例化一个具体对象
			case 'A':
				stra=new StrategyA();
				break;
			case 'B':
				stra=new StrategyB();
				break;
			case 'C':
				stra=new StrategyC();
				break;
			default:
				break;
		}
	}
	
	void getResult()
	{//根据选择的策略得出结果
		stra->algorithmInterface();
	}

private:
	Strategy* stra;
	//基类指针，用于指向一个具体的子对象
	//这里曾出现过一个编译问题：如果子类是私有继承或保护继承自基类，则基类指针不能指向子类对象，具体原因不明
};

int main()
{
	//客户端只需要知道一个StrategyContext类就可以，而不需要知道其他策略类
	StrategyContext straContxt('B');
	straContxt.getResult();
	return 0;
}
