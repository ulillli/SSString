#include "STRING.h"
 
int main() {
	try {
		String a = "aaaa";
		String b = "bbb";
		String c = "cc";
		a = b;
		cout << "Operator=   a=b       a=";
		a.printString();
		cout << "Operator+=  a+=a       a=";
		a = "aa";
		a += a;
		a.printString();
		cout << "Operator+=  a+=b       a=";
		a += b;
		a.printString();
		cout << "Operator+=  a+=b+=c    a=";
		a = "aa";
		a += b += c;
		a.printString();
		cout << "Operator+=  (a+=b)+=c  a=";
		a = "aa";
		b = "bbb";
		(a += b) += c;
		a.printString();
		cout << "b=";
		b.printString();
		cout << "Operator+  (a+b)+c=";
		a = "aa";
		b = "bbb";
		((a + b) + c).printString();
		cout << "Operator+  a+(b+c)=";
		a = "aa";
		(a + (b + c)).printString();
		cout << "Find in a str=aab  ";
		a = "aaaaaaab";
		cout << "index=" << a.find("aab") << endl;
		cout << "Insert in a str=bbb on position 2   a=";
		a = "aaaaaaaa";
		a.insert(2,b);
		a.printString();
		cout << "Insert in a str=bbb on position 7   a=";
		a = "aaaaaaaa";
		a.insert(8, b);
		a.printString();
		cout << "Insert in a 2 characters from str=bbbb on position 3   a=";
		a = "aaaaaaaa";
		a.insert(3,2,b);
		a.printString();
		cout << "Erase 3 characters from a=aaavsds with position 2     a=";
		a = "aaavsds";
		a.erase(2, 3);
		a.printString();
		String a1 = "aaaa", a2 = "aaaaa";
		cout << "a1=";
		a1.printString();
		cout << "a2=";
		a2.printString();
		cout << "a1==a1  " << (a1==a1) << endl;
		cout << "a1==a2  " << (a1 == a2) << endl;
		cout << "a1!=a1  " << (a1 != a1) << endl;
		cout << "a1!=a2  " << (a1 != a2) << endl;
		cout << "a1<a2   " << (a1 < a2) << endl;
		cout << "a2<a1   " << (a2 < a1) << endl;
		cout << "a1>a2   " << (a1 > a2) << endl;
		cout << "a2>a1   " << (a2 > a1) << endl;
		cout << "a1<=a1   " << (a1 <=a1) << endl;
		cout << "a2<=a1   " << (a2 <=a1) << endl;
		cout << "a1<=a2   " << (a1 <= a2) << endl;
		cout << "a1>=a1   " << (a1 >= a1) << endl;
		cout << "a2>=a1   " << (a2 >= a1) << endl;
		cout << "a1>=a2   " << (a1 >= a2) << endl;
		cout << "Function clear \n";
		cout << "a=";
		a.printString();
		a.clear();
		cout << "a=";
		a.printString();
		cout << "Is the a empty?  " << a.empty();
	}
	catch (const char* str) {
		cout << str;
	}

	return 0;

}
