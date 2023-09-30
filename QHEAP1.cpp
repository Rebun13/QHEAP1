#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

set<int> heap;

/*
 * The function accepts STRING query as parameter.
 */

void qheap(string query) {
    int action = query.at(0) - '0';
    switch (action)
    {
    case 1:
        heap.insert(stoi(query.substr(2, query.size() - 2)));
        break;
    case 2:
        heap.erase(stoi(query.substr(2, query.size() - 2)));
        break;
    case 3:
        if(!heap.empty()) {
            set<int>::iterator iter = heap.begin();
            cout << *iter << endl;
        }
        break;
    default:
        break;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string q_temp;
        getline(cin, q_temp);

        string q = ltrim(rtrim(q_temp));

        qheap(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}
