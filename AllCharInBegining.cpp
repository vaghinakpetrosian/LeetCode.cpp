#include <iostream>
void swap(char& a, char& b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }

void Change(std::string& start)
{
    int n = start.size();
    int j = 0;
    for(int i = 1; i < n; ++i)
    {
        if(start[j] != '_')
        {
            ++j;
            continue;
        }
        if(start[i] == '_')
            continue;
        swap(start[j], start[i]);
    }
}

int main()
{
    std::string start;
    int n = 0;
    char k;
    for(; std::cin >> k;)
    {
        if(k != '_' && k != 'R' && k != 'L')
        break;
        start.push_back(k);
    }
    n = start.size();
    Change(start);
    for(int i = 0; i < n; ++i)
    {
        std::cout << start[i];
    }
}
