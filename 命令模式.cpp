//  命令模式 上

#if 0 
#include<iostream>
using namespace std;

class Doctor
{
public:
	void  treat_eye()
	{
		cout << "医生治疗 眼科病" << endl;
	}
	void treat_nose()
	{
		cout << "医生治疗 鼻科病" << endl;
	}
};

// 这种方法医生和病人 的耦合度太高；假如医生生病了，那病人就没有人给看病。
// 通过一个命令，通过命令执行来看病
class CommandTreatEye
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_eye();
	}

private:
	Doctor *m_doctor;
};

class CommandTreatNose
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_nose();
	}

private:
	Doctor *m_doctor;
};

void test()
{
	// 1、 医生直接看病
	// 这种方法医生和病人 的耦合度太高；假如医生生病了，那病人就没有人给看病。
	Doctor *doctor = new Doctor;
	doctor->treat_eye();

	delete doctor;
	doctor = NULL;


	// 2、通过命令来让 医生看病
	Doctor *doctor = new Doctor;
	CommandTreatEye *commandtreateye = new CommandTreatEye(doctor);   
	
	//ctrl+u 把所选中的的代码转换成小写；ctrl+Shift+u  把所选中的代码转换成大写
	commandtreateye->treat();
	delete doctor;
	delete commandtreateye;
}
int main(void)
{
	test();
	return 0;
}
#endif

// 命令模式下

// 上面的两种方法，一种是医生直接看病 ，一种是医生可以通过命令来看病
//  当医生越来越厉害，看病的人越来越多时。这时候就需要病号，通过排队来看病。
//  这个时候就要来引入一个发起者，再添加一个护士类，护士可以把来看病的人的兵力 收集起来 给医生，医生 一个一个给看病


#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void  treat_eye()
	{
		cout << "医生治疗 眼科病" << endl;
	}
	void treat_nose()
	{
		cout << "医生治疗 鼻科病" << endl;
	}
};


// 对命令进行一个抽象 ，面对抽象类编程

class Command
{
public:
	virtual void treat() = 0;

};


// 这种方法医生和病人 的耦合度太高；假如医生生病了，那病人就没有人给看病。
// 通过一个命令，通过命令执行来看病
class CommandTreatEye:public Command
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_eye();
	}

private:
	Doctor *m_doctor;
};

class CommandTreatNose:public Command
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_nose();
	}

private:
	Doctor *m_doctor;
};


// 护士类来收集命令
class BeautifulNurse
{
public:
	BeautifulNurse(Command *command)
	{
		m_command = command;
	}

	// 提交病例，下达命令
	void SubmitteCase()
	{
		m_command->treat();

	}

private:
	Command*   m_command;
};
void test()
{
	// 1、 医生直接看病
	// 这种方法医生和病人 的耦合度太高；假如医生生病了，那病人就没有人给看病。
	Doctor *doctor = new Doctor;
	doctor->treat_eye();

	delete doctor;
	doctor = NULL;


	// 2、通过命令来让 医生看病
	doctor = new Doctor;
	Command *command = new CommandTreatEye(doctor);

	//ctrl+u 把所选中的的代码转换成小写；ctrl+Shift+u  把所选中的代码转换成大写
	command->treat();
	delete doctor;
	delete command;
}

// 添加护士长，负责收集10个命令
// 护士长类
class AdvHeadNurse
{
public:
	AdvHeadNurse()
	{
		m_list.clear();   // 清空链表
	}
	void setCommand(Command *command)
	{
		m_list.push_back(command);
	}

	void SubmittedCase()    // 提交病例，下单 命令
	{	
		for (list<Command*>::iterator it=m_list.begin();it!=m_list.end();++it)
		{
			(*it)->treat();
		}
	
	}
private:
	list<Command*>m_list;
};
void test2()
{
	// 护士提交简历，给以上看病
	BeautifulNurse * beautiful = NULL;

	Doctor *doctor = NULL;
	Command *command = NULL;


	doctor = new Doctor;

	command = new CommandTreatNose(doctor);
	beautiful = new BeautifulNurse(command);

	beautiful->SubmitteCase();

	//ctrl+u 把所选中的的代码转换成小写；ctrl+Shift+u  把所选中的代码转换成大写
	command->treat();
	delete doctor;
	delete command;

}

// 通过护士长批量的下达命令

void test3()
{
	// 护士提交简历，给以上看病
	AdvHeadNurse * advHeadNurse = NULL;

	Doctor *doctor = NULL;
	Command *command1 = NULL;
	Command *command2 = NULL;

	doctor = new Doctor;

	command1 = new CommandTreatNose(doctor);
	command2 = new CommandTreatEye(doctor);


	advHeadNurse = new AdvHeadNurse();   // new一个护士长,可以提交好多病例
	advHeadNurse->setCommand(command1);
	advHeadNurse->setCommand(command2);
	advHeadNurse->SubmittedCase();

;
	delete doctor;
	delete command1;
	delete command2;
	delete advHeadNurse;

}
int main(void)
{
	test3();
	return 0;
}