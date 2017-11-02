//  ����ģʽ ��

#if 0 
#include<iostream>
using namespace std;

class Doctor
{
public:
	void  treat_eye()
	{
		cout << "ҽ������ �ۿƲ�" << endl;
	}
	void treat_nose()
	{
		cout << "ҽ������ �ǿƲ�" << endl;
	}
};

// ���ַ���ҽ���Ͳ��� ����϶�̫�ߣ�����ҽ�������ˣ��ǲ��˾�û���˸�������
// ͨ��һ�����ͨ������ִ��������
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
	// 1�� ҽ��ֱ�ӿ���
	// ���ַ���ҽ���Ͳ��� ����϶�̫�ߣ�����ҽ�������ˣ��ǲ��˾�û���˸�������
	Doctor *doctor = new Doctor;
	doctor->treat_eye();

	delete doctor;
	doctor = NULL;


	// 2��ͨ���������� ҽ������
	Doctor *doctor = new Doctor;
	CommandTreatEye *commandtreateye = new CommandTreatEye(doctor);   
	
	//ctrl+u ����ѡ�еĵĴ���ת����Сд��ctrl+Shift+u  ����ѡ�еĴ���ת���ɴ�д
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

// ����ģʽ��

// ��������ַ�����һ����ҽ��ֱ�ӿ��� ��һ����ҽ������ͨ������������
//  ��ҽ��Խ��Խ��������������Խ��Խ��ʱ����ʱ�����Ҫ���ţ�ͨ���Ŷ���������
//  ���ʱ���Ҫ������һ�������ߣ������һ����ʿ�࣬��ʿ���԰����������˵ı��� �ռ����� ��ҽ����ҽ�� һ��һ��������


#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void  treat_eye()
	{
		cout << "ҽ������ �ۿƲ�" << endl;
	}
	void treat_nose()
	{
		cout << "ҽ������ �ǿƲ�" << endl;
	}
};


// ���������һ������ ����Գ�������

class Command
{
public:
	virtual void treat() = 0;

};


// ���ַ���ҽ���Ͳ��� ����϶�̫�ߣ�����ҽ�������ˣ��ǲ��˾�û���˸�������
// ͨ��һ�����ͨ������ִ��������
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


// ��ʿ�����ռ�����
class BeautifulNurse
{
public:
	BeautifulNurse(Command *command)
	{
		m_command = command;
	}

	// �ύ�������´�����
	void SubmitteCase()
	{
		m_command->treat();

	}

private:
	Command*   m_command;
};
void test()
{
	// 1�� ҽ��ֱ�ӿ���
	// ���ַ���ҽ���Ͳ��� ����϶�̫�ߣ�����ҽ�������ˣ��ǲ��˾�û���˸�������
	Doctor *doctor = new Doctor;
	doctor->treat_eye();

	delete doctor;
	doctor = NULL;


	// 2��ͨ���������� ҽ������
	doctor = new Doctor;
	Command *command = new CommandTreatEye(doctor);

	//ctrl+u ����ѡ�еĵĴ���ת����Сд��ctrl+Shift+u  ����ѡ�еĴ���ת���ɴ�д
	command->treat();
	delete doctor;
	delete command;
}

// ��ӻ�ʿ���������ռ�10������
// ��ʿ����
class AdvHeadNurse
{
public:
	AdvHeadNurse()
	{
		m_list.clear();   // �������
	}
	void setCommand(Command *command)
	{
		m_list.push_back(command);
	}

	void SubmittedCase()    // �ύ�������µ� ����
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
	// ��ʿ�ύ�����������Ͽ���
	BeautifulNurse * beautiful = NULL;

	Doctor *doctor = NULL;
	Command *command = NULL;


	doctor = new Doctor;

	command = new CommandTreatNose(doctor);
	beautiful = new BeautifulNurse(command);

	beautiful->SubmitteCase();

	//ctrl+u ����ѡ�еĵĴ���ת����Сд��ctrl+Shift+u  ����ѡ�еĴ���ת���ɴ�д
	command->treat();
	delete doctor;
	delete command;

}

// ͨ����ʿ���������´�����

void test3()
{
	// ��ʿ�ύ�����������Ͽ���
	AdvHeadNurse * advHeadNurse = NULL;

	Doctor *doctor = NULL;
	Command *command1 = NULL;
	Command *command2 = NULL;

	doctor = new Doctor;

	command1 = new CommandTreatNose(doctor);
	command2 = new CommandTreatEye(doctor);


	advHeadNurse = new AdvHeadNurse();   // newһ����ʿ��,�����ύ�öಡ��
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