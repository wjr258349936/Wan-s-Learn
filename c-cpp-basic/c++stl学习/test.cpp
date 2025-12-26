#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int main(void) 
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		v[i] = i;
	}

	v.push_back(11);

	for (auto pv = v.begin(); pv != v.end(); pv++) {
		cout << *pv << " ";
	}

	cout << endl;
	cout << endl;

	unordered_set<int> s;
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	for (auto ps = s.begin(); ps != s.end(); ps++) {
		cout << *ps << " ";
	}
	cout << endl;
	cout << endl;

	cout << (s.find(2) != s.end()) << endl;
	cout << (s.find(4) != s.end()) << endl;
	cout << endl;
	cout << endl;

	/*s.erase(1);*/
	for (auto ps = s.begin(); ps != s.end(); ps++) {
		cout << *ps << endl;
	}
	cout << endl;
	cout << endl;

	unordered_map<string, int>m;
	m["hello"] = 2;
	m["world"] = 3;
	cout << "hello : " << m["hello"] << endl;
	cout << endl;
	cout << endl;

	for (auto p = m.begin(); p != m.end();p++) {
		cout << p->first << " : " << p->second <<endl;
	}
	cout << endl;
	cout << endl;

	cout << "map的长度为" << m.size() << endl;

	stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.pop();
	cout << a.top() <<endl;
	cout << endl;
	cout << endl;

	queue<int>q;
	for (int i = 1; i <= 10; i++) {
		q.push(i);
	}
	cout << "队列的队首为 ： " << q.front() << endl << "队列的队尾为 ： " << q.back() << endl;
	q.pop();
	cout << "队列的队首为 ： " << q.front() << endl << "队列的队尾为 ： " << q.back() << endl;
	return 0;
}