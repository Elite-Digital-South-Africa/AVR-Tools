#pragma once
class String
{
public:
	String();
	String(char* other);
	~String();
	String operator+=(char* other);
	String operator+=(String other);
	String operator+(char* other);
	String operator+(String other);
	String operator=(char* other);
	String operator=(String other);
	char* toCharArray();
	int length();
private:
	char* strContent;
};

