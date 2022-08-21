#include<iostream>
using namespace std;
// ���������� cpu���Կ����ڴ�
// ���麯�� - ��������
class cpu {
public:
	virtual void cal() = 0;
};
class videocard {
public:
	virtual void display() = 0;
};
class memo {
public:
	virtual void storage() = 0;
};

// �̳г����� -�� ��д�����麯��- ��
class lenovcpu :public cpu {
	 void cal() {
		cout << "lenvo �� CPU ���ڼ���" << endl;
	}
};
class lenvovc :public videocard {
	 void display() {
		cout << "lenvo ���Կ� ������ʾ" << endl;
	}
};
class lenvome :public memo {
	 void storage() {
		cout << "lenvo ���Կ� ������ʾ" << endl;
	}
};

class intelcpu :public cpu {
	 void cal() {
		cout << "intel �� CPU ���ڼ���" << endl;
	}
};
class intelvc :public videocard {
	 void display() {
		cout << "intel ���Կ� ������ʾ" << endl;
	}
};
class intelme :public memo {
	 void storage() {
		cout << "intel ���Կ� ������ʾ" << endl;
	}
};
class computer {
public:
	computer(cpu* c, videocard* vc, memo* m) {
		c1 = c;
		vc1 = vc;
		m1 = m;
	}
	void work() {
		c1->cal();
		vc1->display();
		m1->storage();

	}
	cpu* c1;
	videocard* vc1;
	memo* m1;
	~computer() {
		if (c1 != NULL) {
			delete c1;
			c1 = NULL;
		}
		if (vc1 != NULL) {
			delete vc1;
			vc1 = NULL;
		}
		if (m1 != NULL) {
			delete m1;
			m1 = NULL;
		}
	}
};
void test() {
	computer* com1 = new computer(new lenovcpu,new intelvc,new intelme );
	com1->work();
}
int main() {
	test();
}