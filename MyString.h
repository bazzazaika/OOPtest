#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class MyString
{
    
private:
    
    char* string_;
    int lengthVal_;
    int capacityVal_;

    const char* StrToCharPtr(const std::string& str);
    void free_gStringForPlus(void) const;

public:
    MyString(void);
    MyString(const char* str);
    MyString(const std::initializer_list<char>& list);
    MyString(const std::string& str);
    MyString(const char* str, int count);
    MyString(int count, const char c);
    MyString(const MyString& other);
    ~MyString();

    const char* operator+(const MyString& other);
    const char* operator+(const char* str);
    const char* operator+(const std::string& str);

    void operator+=(const char* str);
    void operator+=(const MyString& other);
    void operator+=(const std::string& str);

    void operator=(const std::string& str);
    void operator=(const char* str);
    void operator=(const char c);

    char operator[](int i) const;

    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator==(const MyString& other) const;

    char* c_str(void) const;
    char* data(void) const;
    int length(void) const;
    int size(void) const;
    bool empty(void) const;
    int capacity(void) const;
    void shrink_to_fit();
    void clear();

    void insert(int index, int count, const char c);
    void insert(int index, const char* str);
    void insert(int index, const char* str,int count);
    void insert(int index,const std::string& str);
    void insert(int index, const std::string& str, int count);
    
    void erase(int index, int count);

    void append(int count,const char c);
    void append(const char* str);
    void append(const std::string& str);
    void append(const std::string& str, int index, int count);
    void append(const char* str, int index, int count);
    
    void replace(const int index, const int count, const char* str);
    void replace(const int index, const int count, const std::string& str);

    char* substr(int index);
    char* substr(int index,int count);

    int find(const char* str);
    int find(const char* str, int index);
    int find(const std::string& str);
    int find(const std::string& str, int index);


    friend std::ostream& operator<<(std::ostream& os, const MyString& other);
    friend std::istream& operator>>(std::istream& is, MyString& obj);
    
    int Print();
};

#endif //_MYSTRING_H_