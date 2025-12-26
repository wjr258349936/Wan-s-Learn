#include <iostream>
#include <string>
using namespace std;

int main() {
	//基础构造
	string str1("Hello");
	//复制构造，传入已有的string
	string str2(str1);
	//创建一个大小为n的string，每个元素赋值为传入的字符
	string str3(10,'a');
	
	//长度 length方法和size方法，结果是一样的，size方法是为了兼容STL的操作方法
	int strLen1 = str1.size();
	int strLen2 = str2.length();
	//复制 传统C语言方法要用到strcpy，C++中则方便许多，可以直接用 '=' 进行复制
	str2 = str1;
	//连接 string之间可以用 '+' 连接起来
	string str4 = str1 + str3;
	//拼接与附加 可以用 '+=' 来在已有的string后面加东西，也可以调用append方法完成
	//还有一个push_back方法可以加一个字符到字符串后面
	str3 += "bbbbbb";
	str3.append(str2);
	str3.append("ccccccc");
	str3.push_back('d');
	//比较 传统C语言用strcmp和strncmp，C++中简单用时可以直接用关系运算符进行比较(string作简单变量)
	//也可以用compare方法来进行一些更复杂的比较( 可以传入位置pos和需要比较的长度len )
	if (str1 < str2|| str2.compare(str1)) {
		cout << "str1 < str2" << endl;
	}
	//截取子串 substr方法，传入位置和长度
	string substring = str2.substr(1, 6);
	//访问字符串中的元素 可以像C语言一样用数组访问方法，也可调用at方法(索引还是从零开始)
	cout << str1.at(2) << str2[5] << endl;
	//查找 find方法，传入的是要查找的子字符串，可以加原函数的pos，子函数的pos、len。
	//也可以传入一个字符查找其第一次出现的位置，返回值都是第一次找到时的索引，如果没找到返回-1
	//rfind方法与find方法传入值相同，但是是从右边开始反向找
	str2.find(str1,2);
	str2.find("Hello", 1, 3);
	str2.find('a',2);
	//find_first_of方法，传入一个字符串，从左到右查找第一个出现的字符的位置
	//find_first_not_of方法，传入一个字符串，从左到右查找第一个没有出现的字符的位置
	//find_last_of方法，传入一个字符串，从右到左查找第一个出现的字符的位置
	//find_last_not_of方法，传入一个字符串，从右到左查找第一个没有出现的字符的位置

	//插入 insert方法，传入位置pos和要插入的字符串，还可以传入要插入字符串的起始位置和长度
	//insert（pos, str, (可选)subpos, (可选)sublen）
	//insert (pos, n, char) 可以在pos位置插入n个char字符
	//iterator insert (iterator p, char c) 可以在迭代器p所指向的位置插入字符c,并返回插入后迭代器的位置
	//iterator insert (iterator p, size_t n, char c) 可以在迭代器p所指向的位置插入n个字符c,并返回插入后迭代器的位置 
	
	//删除 erase方法，传入位置pos和长度len
	//erase(pos,len)
	//iterator erase (iterator p) 删除迭代器p所指向的字符，并返回删除后迭代器的位置
	//iterator erase (iterator p1, iterator p2) 删除迭代器p1和p2之间的字符，并返回删除后迭代器的位置
	str1.erase(str1.begin() + 1,str1.begin()+3);

	//替换 replace方法，传入位置pos和长度len，以及要替换成的字符串  
	//replace (pos, len, str)
	//iterator replace (iterator p1, iterator p2, const string& str) 替换迭代器p1和p2之间的字符为str，并返回替换后str的最后一个字符的下一个位置的迭代器

	//empty方法，判断字符串是否为空
	if(str1.empty()){
		cout<<"str1 is empty"<<endl;
	}
	//swap方法，交换两个字符串的内容
	str1.swap(str2);

	//清空 clear方法，清空字符串内容
	str2.clear();
	//输入 getline方法，读取一行字符串，包括空格，直到遇到换行符为止
	// getline(cin, str1);
	//输出 cout方法，直接输出字符串内容
	// cout << str1 << endl;

	//替换 replace方法，传入位置pos和长度len，以及要替换成的字符串(C风格、C++风格)
	// replace (pos, len, str)
	//iterator replace (iterator p1, iterator p2, const string& str) 替换迭代器p1和p2之间的字符为str，并返回替换后str的最后一个字符的下一个位置的迭代器
	
	//翻转 reverse方法，使用algorithm头文件中的reverse函数
	// #include<algorithm>
	// reverse(str1.begin(), str1.end());
	
	return 0; 
}