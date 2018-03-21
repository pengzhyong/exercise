/*
两个大的整数相乘，属于大数问题
定义字符串的乘法操作和加法操作，在此基础上模拟数的加法和乘法操作
2018-2-31 by kk
*/

#include <iostream>
#include <string>
#include <vector>

using namespace  std;
string multi(const string& a, int b);
string add(string& str_1, string& str_2);

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	int neg = 1;
	if (a < 0)
	{
		a = -a;
		neg = -neg;
	}
	if (b < 0)
	{
		b = -b;
		neg = -neg;
	}
	string astr = to_string(a);
	string bstr = to_string(b);
	int size_b = bstr.size();
	vector<string> mulVec;
	for (int i = 0; i < size_b; i++)
	{
		string mstr = multi(astr, bstr[size_b - 1 -i] - '0');

		for (int j = 0; j < i; j++)
		{
			mstr.push_back('0');
		}
		mulVec.push_back(mstr);
	}
	string sumStr;
	for (int i = 1; i < mulVec.size(); i++)
	{
		mulVec.at(i) = add(mulVec.at(i), mulVec.at((i - 1)));
	}
	string rslt = mulVec.back();
	if(neg == 1)
		cout << rslt << endl;
	if (neg == -1)
		cout << "-" << rslt << endl;
	system("pause");
	return 0;
}
//乘法操作，字符串与整数相乘
string multi(const string& a, int b)
{
	string invString;
	for (auto iter = a.rbegin(); iter != a.rend(); ++iter)
		invString.push_back(*iter);
	int over = 0;
	for (int i = 0; i < invString.size(); i++)
	{
		char ch = invString.at(i);
		int sum = (ch - '0') * b + over;
		invString.at(i) = sum % 10 + '0';
		if (sum >= 10)
			over = sum / 10;
		else
			over = 0;

	}
	if (over)
		invString.push_back(over + '0');
	string ret;
	for (auto iter = invString.rbegin(); iter != invString.rend(); ++iter)
		ret.push_back(*iter);
	return ret;
}

//字符串相加
string add(string& str_1, string& str_2)
{
	string str1, str2;
	for (auto iter = str_1.rbegin(); iter != str_1.rend(); ++iter)
		str1.push_back(*iter);
	for (auto iter = str_2.rbegin(); iter != str_2.rend(); ++iter)
		str2.push_back(*iter);
	string sum;
	int over = 0;
	if (str1.size() < str2.size())
	{
		int diff = str2.size() - str1.size();
		while (diff--)
			str1.push_back('0');
	}
	if (str1.size() > str2.size())
	{
		int diff = str1.size() - str2.size();
		while (diff--)
			str2.push_back('0');
	}
	int len = str1.size();
	for (int i = 0; i < len; i++)
	{
		int sumVal = (str1[i] - '0') + (str2[i] - '0') + over;
		char ch = sumVal % 10 + '0';
		sum.push_back(ch);
		if (sumVal >= 10)
			over = 1;
		else
			over = 0;
	}
	if (over)
		sum.push_back('1');

	string ret;
	for (auto iter = sum.rbegin(); iter != sum.rend(); ++iter)
		ret.push_back(*iter);
	return ret;
}