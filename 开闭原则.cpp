#include<iostream>
using namespace std;

class BankWorker
{
public:

	void save()
	{
		cout << "���" << endl;
	}
	void moveMoney()
	{
		cout <<"ת�� " <<endl;
	}
	void withdrawMoney()
	{
		cout << "ȡ��" << endl;
	}
protected:

private:
};

class AdvBankWorke
{
public:
	virtual void dothing() = 0;
};

class SaveMoney:public AdvBankWorke
{
public:
	virtual void dothing()
	{
		cout << "���" << endl;
	}
};

class WithDrawMonry :public AdvBankWorke
{
public:

	virtual void dothing()
	{
		cout << "ȡ��" << endl;
	}
};

class MoveMoney :public AdvBankWorke
{
public:

	virtual void dothing()
	{
		cout << "ת��" << endl;
	}
};

class AdvMoveMoeny:public MoveMoney
{
public:
	virtual void dothing()
	{
		cout << "����ת��" << endl;
	}
private:

};

void HowDo(AdvBankWorke *bw)
{
	bw->dothing();
}

int main1(void)
{
	BankWorker *bw = new BankWorker;
	bw->save();
	bw->moveMoney();
	bw->withdrawMoney();
	delete bw;
	bw = NULL;
	return 0;
}

int main(void)
{
	AdvBankWorke *bw;
	bw= new SaveMoney;
	HowDo(bw);

//	bw->dothing();
	delete bw;

	bw = new WithDrawMonry;
	HowDo(bw);
	//	bw->dothing();
	delete bw;
	
	 bw = new MoveMoney;
	 HowDo(bw);
	 //	bw->dothing();
	delete bw;

	bw = new AdvMoveMoeny;
	HowDo(bw);
	delete bw;
	bw = NULL;
	return 0;
}

int getAGeAndName(int *age ,char **name)
{

	*age = 11;
	*name = "Lzj";
}

int main(void)
{
	int age=10;
	char *name="ArrAYLi";
	getAGeAndName(&age,&name);

	return;
}