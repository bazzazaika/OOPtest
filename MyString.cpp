#include "MyString.h"

const char* MyString::StrToCharPtr(const std::string& str)
{
	return &str[0];
}

char* gStringForPlus = nullptr;

void MyString::free_gStringForPlus(void) const
{
	if (gStringForPlus != nullptr)
	{
		delete gStringForPlus;
		gStringForPlus = nullptr;
	}
		
}

//*****************************
//         Constructors
//*****************************

MyString::MyString(void) : string_(nullptr), lengthVal_(0), capacityVal_(0) {}

MyString::MyString(const char* str) : MyString::MyString(str, strlen(str)) {}

MyString::MyString(const std::initializer_list<char>& list)
{
	lengthVal_ = list.size();
	capacityVal_ = lengthVal_ + 1;
	string_ = new char[capacityVal_];
	int i = 0;
	for (char c : list)
	{
		string_[i++] = c;
	}
	string_[i] = '\0';
}

MyString::MyString(const std::string& str) :MyString::MyString(StrToCharPtr(str)) {}

MyString::MyString(const char* str, int count)
{
	//lengthVal_ = count;
	if (count < 0)
	{
		count = 0;
	}
	capacityVal_ = count + 1;
	string_ = new char[capacityVal_];
	int i = 0;
	for (i;i < count && str[i];++i)
	{
		string_[i] = str[i];
	}
	lengthVal_ = i;
	string_[i] = '\0';
}

MyString::MyString(int count, const char c)
{
	if (count < 0)
		count = 0;
	capacityVal_ = count + 1;
	lengthVal_ = count;
	string_ = new char[capacityVal_];
	int i = 0;
	for (i = 0;i < lengthVal_;++i)
	{
		string_[i] = c;
	}
	string_[i] = '\0';
}

MyString::MyString(const MyString& other) : MyString(other.data()) {}



MyString::~MyString()
{
	if (string_ != nullptr)
		delete string_;
	lengthVal_ = 0;
	capacityVal_ = 0;
	string_ = nullptr;
}


//*****************************
//         Operators
//*****************************

const char* MyString::operator+(const MyString& other)
{
	return operator+(other.data());
}

const char* MyString::operator+(const char* str)
{
	free_gStringForPlus();
	gStringForPlus = new char[strlen(string_) + strlen(str) + 1];
	strcpy_s(gStringForPlus, strlen(string_) + strlen(str) + 1, string_);
	strcat_s(gStringForPlus, strlen(string_) + strlen(str) + 1, str);
	return gStringForPlus;
}

const char* MyString::operator+(const std::string& str)
{
	return operator+(StrToCharPtr(str));
}

void MyString::operator+=(const char* str)
{
	this->append(str);
}

void MyString::operator+=(const MyString& other)
{
	operator+=(other.data());
}

void MyString::operator+=(const std::string& str)
{
	operator+=(StrToCharPtr(str));
}

void MyString::operator=(const std::string& str)
{
	operator=(StrToCharPtr(str));
}

void MyString::operator=(const char* str)
{
	clear();
	append(str);
	free_gStringForPlus();

}

void MyString::operator=(const char c)
{
	clear();
	append(1, c);
}


char MyString::operator[](int i) const
{
	if (i > strlen(string_))
	{
		std::cout << "Index out of the range" << std::endl;
		return '\0';
	}
	return string_[i];
}

bool MyString::operator>(const MyString& other) const
{
	if (strcmp(other.string_, string_) < 0)
	{
		return true;
	}
	return false;
}
bool MyString::operator<(const MyString& other) const
{
	if (strcmp(other.string_, string_) > 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator>=(const MyString& other) const
{
	if (strcmp(other.string_, string_) <= 0)
	{
		return true;
	}
	return false;
}
bool MyString::operator<=(const MyString& other) const
{
	if (strcmp(other.string_, string_) >= 0)
	{
		return true;
	}
	return false;
}
bool MyString::operator!=(const MyString& other) const
{
	return !operator==(other);
}

bool MyString::operator==(const MyString& other) const
{
	if (strcmp(other.string_, string_) == 0)
	{
		return true;
	}
	return false;
}

char* MyString::c_str(void) const
{
	return &string_[0];
}

char* MyString::data(void) const
{
	return string_;
}

int MyString::length(void) const
{
	return lengthVal_;
}

int MyString::size(void) const
{
	return lengthVal_;
}

bool MyString::empty(void) const
{
	if (string_ == nullptr)
	{
		return true;
	}
	return false;
}

int MyString::capacity(void) const
{
	return capacityVal_;
}

void MyString::shrink_to_fit()
{
	
	MyString tmp(string_);
	if(string_!= nullptr) 
		delete[] string_;
	capacityVal_ = tmp.capacityVal_;
	string_ = new char[capacityVal_];
	strcpy_s(string_, capacityVal_, tmp.c_str());
}

void MyString::clear()
{
	int i = 0;
	for (i = 0;i < lengthVal_; ++i)
		string_[i] = '\0';
	lengthVal_ = 0;
}


//*****************************
//         Insert
//*****************************

void MyString::insert(int index, int count, const char c)
{
	if (index >= capacityVal_)
	{
		std::cout << "Index out of the range" << std::endl;
		return;
	}
	MyString tmp(string_);
	delete[] string_;
	capacityVal_ = capacityVal_ + count;
	string_ = new char[capacityVal_];
	int i = 0;
	for (i = 0;i < index && tmp[i];++i)
	{
		string_[i] = tmp[i];
	}
	int j = i;
	for (i = 0;i < count && tmp[i];++i)
	{
		string_[j + i] = c;
	}
	for (j;j + i < lengthVal_ + count && tmp[i];++j)
	{
		string_[j + i] = tmp[j];
	}
	string_[j + i] = 0;
	lengthVal_ = i + j;
}


void MyString::insert(int index, const char* str)
{
	MyString::insert(index, str, strlen(str));
}


void MyString::insert(int index, const char* str, int count)
{
	if (index >= capacityVal_ || count > strlen(str))
	{
		std::cout << "Index out of the range" << std::endl;
		return;
	}
	MyString tmp(string_);
	delete[] string_;
	capacityVal_ = capacityVal_ + count;
	string_ = new char[capacityVal_];
	int i = 0;
	//char* tmpStr = tmp.data();
	for (i = 0;i < index && tmp[i];++i)
	{
		string_[i] = tmp[i];
	}
	int j = i;
	for (i = 0;i < count && str[i] && string_[j + i];++i)
	{
		string_[j + i] = str[i];
	}
	for (j;j + i < lengthVal_ + count && tmp[j];++j)
	{
		string_[j + i] = tmp[j];
	}
	lengthVal_ = i + j;
	string_[lengthVal_] = 0;

}

void MyString::insert(int index, const std::string& str)
{
	const char* tmpStr = StrToCharPtr(str);
	MyString::insert(index, tmpStr, strlen(tmpStr));
}

void MyString::insert(int index, const std::string& str, int count)
{
	const char* tmpStr = StrToCharPtr(str);
	MyString::insert(index, tmpStr, count);
}

//*****************************
//         erase
//*****************************

void MyString::erase(int index, int count)
{
	if (lengthVal_ - index < count)
	{
		std::cout << "Index out of the range" << std::endl;
		return;
	}
	MyString tmp(string_);
	delete[] string_;

	string_ = new char[capacityVal_ - count];
	int i = 0;
	char* str = tmp.data();
	for (i; i < index;++i)
	{
		string_[i] = str[i];
	}
	int j = i;
	i += count;
	for (i; str[i];++i, ++j)
	{
		string_[j] = str[i];
	}
	string_[j] = 0;
	lengthVal_ = j;

}

//*****************************
//         append
//*****************************


void MyString::append(int count, const char c)
{
	char* tmpStr = new char[count + 1];
	int i = 0;
	for (i;i < count;++i)
	{
		tmpStr[i] = c;
	}
	tmpStr[i] = 0;
	append(tmpStr, 0, count);
	delete[] tmpStr;
}

void MyString::append(const char* str)
{
	append(str, 0, strlen(str));
}

void MyString::append(const std::string& str)
{
	const char* ptr = StrToCharPtr(str);
	append(ptr, 0, strlen(ptr));
}

void MyString::append(const std::string& str, int index, int count)
{
	const char* ptr = StrToCharPtr(str);
	append(ptr, index, count);
}

void MyString::append(const char* str, int index, int count)
{
	if (index >= strlen(str) || count > strlen(str))
	{
		std::cout << "Index out of the range" << std::endl;
		return;
	}

	char* newStr = new char[count];
	int i = 0;
	for (i;i < count;++i)
	{
		newStr[i] = str[i + index];
	}
	newStr[i] = 0;
	if (string_ == nullptr)
	{
		capacityVal_ = 1;
		string_ = new char[capacityVal_];
		string_[0] = 0;
	}
	MyString::insert(strlen(string_), newStr, count);
}

void MyString::replace(const int index, const int count, const char* str)
{
	erase(index, count);
	insert(index, str);
}

void MyString::replace(const int index, const int count, const std::string& str)
{
	replace(index, count, StrToCharPtr(str));
}

char* MyString::substr(int index)
{
	return substr(index, lengthVal_ - index);
}

char* MyString::substr(int index, int count)
{
	free_gStringForPlus();
	gStringForPlus = new char[count+1];
	int i = index;
	for (i;i < strlen(string_) && i - index < count;++i)
	{
		gStringForPlus[i - index] = string_[i];
	}
	gStringForPlus[i - index] = 0;
	return gStringForPlus;
}


std::ostream& operator<<(std::ostream& os, const MyString& other)
{
	char* str = other.data();
	if (str != nullptr)
	{
		os << str;
	}
	else
	{
		os << "";
	}
	return os;
}

std::istream& operator>>(std::istream& is, MyString& obj) {
	char buffer[4096];
	is >> buffer;
	obj.append(buffer);
	return is;
}

int MyString::find(const char* str)
{
	return find(str, 0);
}

int MyString::find(const char* str, int index)
{
	int count = 0;

	for (int i = index; i < lengthVal_; i++)
	{
		if (string_[i] == str[count])
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == strlen(str))
		{
			return i - count + 1;
		}
	}
	return -1;
}

int MyString::find(const std::string& str)
{
	return find(str, 0);
}

int MyString::find(const std::string& str, int index)
{
	const char* ptr = StrToCharPtr(str);
	return find(ptr, index);
}



int MyString::Print()
{
	if (string_ == nullptr)
	{
		return 0;
	}
	std::cout << string_ << std::endl;
	std::cout << "length = " << lengthVal_ << std::endl;
	std::cout << "capacityVal_ = " << capacityVal_ << std::endl;
	return 1;
}



