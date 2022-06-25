#include <iostream>
#include <vector>
#include <set>

using namespace std;

short int n = 6;
short int m = 2;
int q = 2;
vector<vector<short int>> p;
vector<short int> a;
vector<short int> b;
short int dest;
set<short int> poss;

bool check_destination(short int a, short int b)
{
    poss.insert(a);
    short int k = 0;
    
    while (k<m)
    {
        dest = p.at(k).at(a);
        if (dest == b)
        {
            poss.clear();
            return true;
        }
        if (poss.find(dest) == poss.end())
        {
            if (check_destination(dest, b)) return true;
        }
        k++;
    }
    return false;
}

int main()
{
    p.push_back({0, 2, 1, 4, 5, 3, 6});
    p.push_back({0, 3, 2, 4, 1, 5, 6});
    a.push_back(1);
    b.push_back(5);
    a.push_back(6);
    b.push_back(3);

    for (short int i=0; i < q; i++)
    {
        if (check_destination(a.at(i), b.at(i)))
        {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
    return 0;
}
