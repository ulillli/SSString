#pragma once
#include <iostream>
using namespace std;

class String {
private:
	char* data = nullptr;
public:
	String(int n = 0) {
		if (n == 0) {
			this->data = new char[n + 1];
			this->data[0] = '\0';
		}
		else {
			data = new char[n + 1];
			for (int i = 0; i < n; i++) data[i] = '_';
			data[n] = '\0';
		}
	}
	String(const String & str) {
		int n = str.Size();
		if (n == 0) {
			this->data = new char[n + 1];
			this->data[0] = str[0];
		}
		else {
			data = new char[n + 1];
			for (int i = 0; i < n; i++) this->data[i] = str[i];
			data[n] = '\0';
		}
	}
	String(const char * str) {
		int n = culculateSize(str);
		if (n == 0) {
			this->data = new char[n + 1];
			this->data[0] = '\0';
		}
		else {
			data = new char[n + 1];
			for (int i = 0; i < n + 1; i++) this->data[i] = str[i];
		}
	}

	String & operator=(const String & str) {
		delete[] data;
		int n = str.Size();
		data = new char[n + 1];
		for (int i = 0; i < n; i++) this->data[i] = str[i];
		data[n] = '\0';
		return *this;
	}
	String & operator+=(const String & str) {
		if (str.Size() != 0) {
			int n = this->Size();
			int newSize = n + str.Size();
			char * tmp = new char[newSize + 1];
			int i = 0, j = 0;
			while (this->data[i] != '\0') {
				tmp[i] = data[i];
				i++;
			}
			while (str[j] != '\0') {
				tmp[i++] = str[j++];
			}
			delete[] data;
			tmp[newSize] = '\0';
			data = tmp;
		}
		return *this;

	}
	String operator+(const String & str) const {
		String res = *this;
		res += str;
		return res;

	}

	void insert(int pos, const String & str) {
		int len1 = this->Size(), len2 = str.Size(), newSize = len1 + len2;
		char * tmp = new char[newSize + 1];
		int i = 0, j = 0,k=0;
		if (pos <=len1) {
			while (i != pos) {
				tmp[i++] = this->data[k++];
			}
			while (str[j] != '\0') {
				tmp[i++] = str[j++];
			}
			while (this->data[k] != '\0') {
				tmp[i++] = this->data[k++];
			}
			tmp[newSize] = '\0';
			delete[] data;
			data = tmp;
		}
		else throw "Error in function insert\n";
	}
	void insert(int pos, int len, const String & str) {
		int len1 = this->Size(), newSize = len1+len;
		char * tmp = new char[newSize + 1];
		int i = 0, j = 0, k = 0;
		if ((pos < len1)&&(len<=str.Size())) {
			while (i != pos) {
				tmp[i++] = this->data[k++];
			}
			while (j!=len) {
				tmp[i++] = str[j++];
			}
			while (this->data[k] != '\0') {
				tmp[i++] = this->data[k++];
			}
			tmp[newSize] = '\0';
			delete[] data;
			data = tmp;
		}
		else throw "Error in function insert\n";
	}
	void erase(int pos, int n = 1) {
		int size = this->Size();
		if ((pos < size-n) && ((size - n) >= 0)) {
			char * tmp = new char[size+n+1];
			int i = 0, j = 0;
			while (j != pos) {
				tmp[i++] = data[j++];
			}
			j = j + n;
			while (data[j] != '\0') {
				tmp[i++] = data[j++];
			}
			tmp[size - n] = '\0';
			delete[] data;
			data = tmp;
		}
		else throw "Error in function erase\n";
	}
	bool operator==(const String& str) const {
		int len1 = this->Size(), len2 = str.Size();
		bool flag = 1;
		if (len1 == len2) {
			int i = 0;
			while (i < len1) {
				if (this->data[i] != str[i]) {
					flag = 0;
					break;
				}
				i++;
			}
			return flag;
		}
		else return 0;
	}
	int find(const char * subStr) {
		int j = 0;
		for (char* pstr = this->data; *pstr != '\0'; pstr++, j++) {
			bool flag = false;
			int i = 0;
			for (const char* psubStr = subStr; *psubStr != '\0'; psubStr++, i++) {
				if (*(pstr + i) != *psubStr) {
					flag = true;
					break;
				}
			}
			if (flag == false) return j;
		}
		return -1;
	}
	bool operator!=(const String & str) const {
		if (*this == str)  return 0;
		else return 1;
	}
	bool operator<(const String & str) const {
		int len1 = this->Size(), len2 = str.Size();
		if (len1 < len2) return 1;
		if (len1 > len2) return 0;
		if (len1 == len2) {
			int i = 0;
			while ((i < len1) && (this->data[i] == str[i])) {
				i++;
			}
			if (this->data[i] < str[i]) return 1;
			else return 0;
		}
	}
	bool operator>(const String & str) const {
		if ((*this != str) && (not(*this < str))) return 1;
		else return 0;
	}
	bool operator>=(const String & str)const {
		if ((*this == str) || (*this > str)) return 1;
		else 0;
	}
	bool operator<=(const String & str) const {
		if ((*this == str) || (*this < str)) return 1;
		else 0;
	}
	void clear() {
		delete[] data;
		data = new char[1];
		data[0] = '\0';
	}
	bool empty() const {
		return (this->Size() == 0);
	}
	char& operator[](int index) const {
		return this->data[index];
	}
	void printString() {
		int n = this->Size();

		for (int i = 0; i < n; i++) cout << this->data[i];
		cout << endl;
	}
	int Size() const {
		return culculateSize(this->data);
	}
	static const int culculateSize(const char* str) {
		int i = 0;
		while (str[i++] != '\0');
		return i - 1;
	}
	~String() {
		delete[] data;
	}
};
