#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;
const int SIZE = 97;

int gen_hash_index(const std::string &s){
    int sum = 0;
    for (char c : s){
        sum+=(int)c;
    }
    return sum % SIZE;
}

void print100(const map<int, list<string>> &hash_table){
cout << "First 100 entries: " << endl;
int count = 0;

    for (const auto val: hash_table){
        for (const string &s : val.second) {
        if (count >= 100) break;
        cout << "hash index " << ": " << s << endl;
        count++;
        }
        if (count >= 10) break;
    }
}

void search(const map<int, list<string>> &hash_table){
   string key;
    cout << "Enter key to search for: ";
    cin >> key;
    int hashidx = gen_hash_index(key);
    auto it = hash_table.find(hashidx);
    for (const string &s : it->second) {
        if (s==key){
            cout << "key found at hash index " << hashidx << endl;
            return;
        }
    }
    cout << "key not found" << endl;
}

void addKey(map<int, list<string>> &hash_table){
    string key;
    cout << "Enter a key to add: ";
    cin >> key;

    int hashidx = gen_hash_index(key);
    hash_table[hashidx].push_back(key);

    cout << "key " << key << " added at " << hashidx << endl;
}

void removeKey(map<int, list<string>> &hash_table){
    string key;
    cout << "Enter a key to remove: ";
    cin >> key;

    int hashidx = gen_hash_index(key);
    auto it = hash_table.find(hashidx);

    for (const string &s : it->second) {
        if (s==key){
            hash_table.erase(it);
            cout << "key " << key << " removed at hash index " << hashidx << endl;
            return;
        }
    }
   
}

void modifyKey(map<int, list<string>> &hash_table){
    string old_key;
    cout << "Enter a key to remove: ";
    cin >> old_key;

    int old_hashidx = gen_hash_index(old_key);
    auto it = hash_table.find(old_hashidx);
    for (const string &s : it->second) {
        if (s==old_key){
            hash_table.erase(it);
            break;
        }
    }
    string new_key;
    cout << "Enter a new key: ";
    cin >> new_key;
    int new_hashidx = gen_hash_index(new_key);
    auto it2 = hash_table.find(new_hashidx);
     hash_table[new_hashidx].push_back(new_key);
     cout << "Key " << old_key << " changed to " << new_key << " at " << new_hashidx << endl;
}

int main() {
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

int choice = 0;
do {
    cout << "======Hash Table Menu=======" << endl;
    cout << "1. Print first 100 entries" << endl;
    cout << "2. Search for key" << endl;
    cout << "3. Add key" << endl;
    cout << "4. Remove key" << endl;
    cout << "5. Modify key" << endl;
    cout << "6. Exit" << endl;
    cout << "enter choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
        print100(hash_table);
        break;
        case 2:
        search(hash_table);
        break;
        case 3:
        addKey(hash_table);
        break;
        case 4:
        removeKey(hash_table);
        break;
        case 5:
        modifyKey(hash_table);
        break;
    }
}while (choice !=6);
    

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
