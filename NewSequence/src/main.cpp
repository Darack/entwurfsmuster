#include <iostream>
#include "sequence.h"

using namespace std;


class A {
public:
	A() {
		cout << "A+" << endl;
	}

	A(const A& crArg) {
		cout << "A_copycons" << endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const A& crArg) {
		os << "ich bin ein A" << endl;
		return os;
	}
};

int main() {
	sequence<char> s1('a');
	sequence<char> s2('b');
	cout << "s1: " << s1 << endl;
	cout << "s1 counter: ";
	s1.printCounter();
	cout << "-------------------------" << endl;

	cout << "s2: " << s2 << endl;
	cout << "s2 counter: ";
	s2.printCounter();
	cout << "-------------------------" << endl;

	sequence<char> t1 = s1+s2;
	cout << "t1=s1+s2: " << t1 << endl;
	cout << "t1 counter: ";
	t1.printCounter();
	cout << "-------------------------" << endl;

	sequence<char> s3 = 'c';
	sequence<char> t2 = s3+'d';
	cout << "t2=s3+'f': " << t2 << endl;
	cout << "t2 counter: ";
	t2.printCounter();

	cout << "-------------------------" << endl;
	{
		sequence<char> t3 = t1+t1;
		cout << "t3=t1+t1: " << t3 << endl;
		cout << "t3 counter: ";
		t3.printCounter();

//		sequence<char> t4 = t1+t2;
//		cout << "t4=t1+t2: " << t4 << endl;
//		cout << "t4 counter: ";
//		t4.printCounter();
//		cout << endl;

	}
	cout << "t3 deleted!" << endl;
	cout << "-------------------------" << endl;

	cout << "t1=s1+s2: " << t1 << endl;
	cout << "t1 counter: ";
	t1.printCounter();
	cout << "-------------------------" << endl;

	cout << "t2=s3+'f': " << t2 << endl;
	cout << "t2 counter: ";
	t2.printCounter();
	cout << "-------------------------" << endl;

	sequence<char> t5 = t1 + t2;
	cout << "t5: " << t5 << endl;
	t5.printCounter();
	cout << "-------------------------" << endl;

	sequence<char>::Iterator it = t2.begin();
	*it = 'X';
	cout << "write on t2!" << endl;
	cout << "-------------------------" << endl;

	cout << "new t2: " << t2 << endl;
	t2.printCounter();
	cout << "unchanged t5?: " << t5 << endl;
	t5.printCounter();
	cout << "-------------------------" << endl;

//	sequence<char> s0('f');
//	cout << s0 << endl;
//	for (sequence<char>::Iterator it = s0.begin(); it!=s0.end(); ++it) {
//		*it = 'X';
//	}
//	cout << s0 << endl;

}
