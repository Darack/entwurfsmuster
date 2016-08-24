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
	cout << "s1: " << s1;
	cout << "s1 counter: ";
	s1.printCounter();
	cout << endl;

	cout << "s2: " << s2;
	cout << "s2 counter: ";
	s2.printCounter();
	cout << endl;

	sequence<char> t1 = s1+s2;
	cout << "t1=s1+s2: " << t1;
	cout << "t1 counter: ";
	t1.printCounter();
	cout << endl;

	sequence<char> s3 = 'c';
	sequence<char> t2 = s3+'d';
	cout << "t2=s3+'f': " << t2;
	cout << "t2 counter: ";
	t2.printCounter();
	cout << endl;

	cout << "-------------------------" << endl;

	{
		sequence<char> t3 = t1+t1;
		cout << "t3=t1+t1: " << t3;
		cout << "t3 counter: ";
		t3.printCounter();
		cout << endl;

//		sequence<char> t4 = t1+t2;
//		cout << "t4=t1+t2: " << t4;
//		cout << "t4 counter: ";
//		t4.printCounter();
//		cout << endl;

	}

	cout << "t1=s1+s2: " << t1;
	cout << "t1 counter: ";
	t1.printCounter();
	cout << endl;

	cout << "t2=s3+'f': " << t2;
	cout << "t2 counter: ";
	t2.printCounter();
	cout << endl;

	cout << "s1 counter: ";
	s1.printCounter();
	cout << "s2 counter: ";
	s2.printCounter();

	cout << endl;
	sequence<char> t5 = t1 + t2;
	cout << "t5: " << endl;
	cout << t5 << endl;
	cout << endl;

	sequence<char>::Iterator it = t2.begin();
//	*it = 'a';

	cout << t2 << endl;
	cout << t5 << endl;

//	sequence<char> s0('f');
//	cout << s0 << endl;
//	for (sequence<char>::Iterator it = s0.begin(); it!=s0.end(); ++it) {
//		*it = 'X';
//	}
//	cout << s0 << endl;

}
