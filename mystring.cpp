#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Mystring{
private:
    char *m_data;//字符串
    int m_length;//长度
public:
    Mystring(const char *str=NULL);//构造函数
    Mystring(const Mystring &str);//拷贝函数
    ~Mystring();

    Mystring operator +(const Mystring &str);//重载+
    String& operator =(const String &str);//重载=
    bool operator ==(const Mystring &str);//重载==
    bool operator !=(const Mystring &str);//重载!=
    bool operator >(const Mystring &str);//重载>
    bool operator <(const Mystring &str);//重载<
    char& operator [](int n);//重载[]

    friend istream& operator >>(istream &is, Mystring &str);//重载>>
    friend ostream& operator <<(ostream &os, Mystring &str);//重载<<
};

Mystring::Mystring(const char *str)//构造函数
{
    if(!str)
    {
        m_length = 0;
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        m_length = strlen(str);
        m_data = new char[m_length+1];
        strcpy(m_data, str);
    }
}

Mystring::Mystring(const Mystring &str)//拷贝函数
{
    m_length = strlen(str.m_data);
    m_data = new char[m_length+1];
    strcpy(m_data, str.m_data);
}

Mystring::~Mystring()//析构函数
{
    m_length = 0;
    delete[] m_data;
}

//重载+
Mystring Mystring::operator +(const Mystring &str) 
{
    Mystring p;
    p.m_length = m_length + str.m_length;
    p.m_data = new char[p.m_length+1];
    strcpy(p.m_data, m_data);
    strcat(p.m_data, str.m_data);
    return p;
}

//重载=
String& Mystring::operator =(const String &str)
{
    if(this == &str)
        return *this;
    delete[] m_data;
    m_length = str.m_length;
    m_data = new char[m_length+1];
    strcpy(m_data, str.m_data);
    return *this;
}

//重载==
bool Mystring::operator ==(const Mystring &str)
{
    if(m_length != str.m_length)
        return false;
    return strcmp(m_data, str.m_data)?false:true;
}

//重载!=
bool Mystring::operator !=(const Mystring &str)
{
    return strcmp(m_data, str.m_data)?true:false;
}

//重载>
bool Mystring::operator >(const Mystring &str)
{
    if(m_data > str.m_data)
        return true;
    else
        return false;
}

//重载<
bool Mystring::operator <(const Mystring &str)
{
    if(m_data < str.m_data)
        return true;
    else
        return false;
}

//重载[]
char& Mystring::operator [](int n)
{
    if(n >= m_length)
        return m_data[m_length-1];//长度太大时读最后一个字符
    else
        return m_data[n];
}

//重载>>
istream& operator >>(istream &is, Mystring &str)
{
    char tmp[100];
    is>>tmp;
    str.m_length = strlen(tmp);
    str.m_data = new char[str.m_length+1];
    strcpy(str.m_data, tmp);
    return is;
}

//重载<<
ostream& operator <<(ostream &os, Mystring &str)
{
    os<<str.m_data;
    return os;
}

int main(void)
{
    Mystring s;
	cout<<"请输入:";
    cin>>s;
    cout<<s<<endl;

    char a[]="hello", b[]="world";
    Mystring s1(a), s2(b); 
    Mystring s3 = s1+s2;
    cout<<s1<<"+"<<s2<<"="<<s3<<endl;

    cout<<(s1==s2)<<endl;
	cout<<(s1!=s2)<<endl;
	cout<<(s1<s3)<<endl;
	cout<<(s1>s3)<<endl;
}
