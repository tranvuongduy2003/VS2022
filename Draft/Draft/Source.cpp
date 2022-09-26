#include <iostream>
using namespace std;
class A {
public:
	A() {
		cout << "Constructing A ";
	}
	~A() {
		cout << "Destructing A ";
	}
};
class B : public A {
public:
	B() {
		cout << "Constructing B ";
	}
	~B() {
		cout << "Destructing B ";
	}
};
int main() {
	B b1;
	return 0;
}