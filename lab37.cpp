#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
const int SIZE = 97;
using namespace std;
int gen_hash_index(const std::string &s){
    int sum = 0;
    for (char c : s){
        sum+=(int)c;
    }
    return sum % SIZE;
}

int main() {
    cout << "test" << endl;
ifstream fin("lab-37-data-2.txt");
if (!fin.is_open()) {
    cerr << "could not open file\n";
    return 1;
}
string text;
long total = 0;
while (fin >> text){
    total += gen_hash_index(text);
}
cout << "Total ASCII sum = " << total << endl;

fin.clear();
fin.seekg(0); 
map<int, list<string>> hash_table;
while (fin >> text){
    int hash_index = gen_hash_index(text);
    hash_table[hash_index].push_back(text);
}
fin.close();

cout << "First 100 entries: " << endl;
int count = 0;

    for (const auto val: hash_table){
        if (count >= 10) break;
        cout << "hash index " << val.first << ": ";
        for (const string &s : val.second) {
            cout << s << " " << endl;
        }
        count++;
    }
    

return 0;
}

/*char a = 'A';
cout << a << endl;
cout << (int) a << endl;
int b = 66;
cout << b << endl;
cout << (char) b << endl;

string test = "hello";
cout << "sum test" << test << sum_ascii(test) << endl;*/


/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
