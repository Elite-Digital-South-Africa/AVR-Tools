#include "String.h"
#include <string.h>


String String::operator+=(char*  other)
{
	char* current = strContent;
	char *tmp=new char[1];
	strcpy(tmp, current);
	strcat(tmp, other);
	strContent = tmp;
	return strContent;
}

String String::operator+=(String  other)
{
	char* current = strContent;
	char *tmp = new char[1];
	strcpy(tmp, current);
	strcat(tmp, other.toCharArray());
	strContent = tmp;
	return strContent;
}

String String::operator+(char*  other)
{
	char* current = strContent;
	char *tmp = new char[1];
	strcpy(tmp, current);
	strcat(tmp, other);
	strContent = tmp;
	return strContent;
}

String String::operator+(String  other)
{
	char* current = strContent;
	char *tmp = new char[1];
	strcpy(tmp, current);
	strcat(tmp, other.toCharArray());
	strContent = tmp;
	return strContent;
}

String String::operator=(char*  other)
{
	strContent = other;
	return strContent;
}

String String::operator=(String other)
{
	return strContent;
}

String::String()
{
	strContent = new char[0];
}

String::String(char* other)
{
	strContent = other;
}

char* String::toCharArray()
{
	return strContent;
}

int String::length()
{
	return strlen(strContent);
}

String::~String()
{
	
}