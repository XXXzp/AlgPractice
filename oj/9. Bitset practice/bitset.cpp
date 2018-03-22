#include<iostream>
#include<bitset>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int cmp(string s, string t) {
	bitset<10000> t_bits(t);
	bitset<10000> s_bits(s);
	bitset<10000> filter;
	for (size_t i = 0; i < t.size(); i++) {
		filter.set(i, true);
	}
	int result = 0;
	for (size_t i = 0; i < s.size()-t.size()+1; i++) {
		result+=((s_bits^t_bits)&filter).count();
		t_bits <<= 1;
		filter <<= 1;
	}
	return result;
	
}
void string2bits(string &source) {
	for (size_t i = 0; i < source.size(); i++) {
		source[i] = (source[i] == 'a') ? '0' : '1';
	}
}
int main() {
	ifstream cin("D://test//in.txt");
	string source;
	string templat;
	char ch = 'a';
	int t = ch-48;
	cin >> source;
	cin >> templat;
	string2bits(source);
	string2bits(templat);
	int temp = cmp(source, templat);

	cout << temp << endl;
	return 0;
}