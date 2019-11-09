/*
 * ���������� ���������� ������ �����.
 * �� ���� ��������� ��������� ��������� �������:
   - CHANGE_CAPITAL country new_capital � ��������� ������� ������ country �� new_capital,
   ���� ���������� ����� ������ � ����� ��������, ���� ������ � �� ����.
   - RENAME old_country_name new_country_name � �������������� ������ �� old_country_name
   � new_country_name.
   - ABOUT country � ����� ������� ������ country.
   - DUMP � ����� ������ ���� �����.
   ������ �����
   � ������ ������ ���������� ���������� �������� Q, � ��������� Q ������� � �������� ��������.
   ��� �������� ����� � ������ ������� ���� �� ��������� ����, ���� � �������� �������������.
   ������ ������
   �������� ��������� ��������� ������� �������:
   � ����� �� ������ CHANGE_CAPITAL country new_capital ��������
   - Introduce new country country with capital new_capital, ���� ������ country ������ ��
   ������������;
   - Country country hasn't changed its capital, ���� ������ country �� �������� �������
   ����� ������� new_capital;
   - Country country has changed its capital from old_capital to new_capital, ���� ������
   country �� �������� ������� ����� ������� old_capital, �������� ������� �� ��������� �
   ��������� new_capital.
   � ����� �� ������ RENAME old_country_name new_country_name ��������
   - Incorrect rename, skip, ���� ����� �������� ������ ��������� �� ������,
   ������ old_country_name �� ���������� ��� ������ new_country_name ��� ����������;
   - Country old_country_name with capital capital has been renamed to new_country_name,
   ���� ������ ��������� � ������ ����� ������� capital.
   � ����� �� ������ ABOUT country ��������
   - Country country doesn't exist, ���� ������ � ��������� country �� ����������;
   - Country country has capital capital, ���� ������ country ���������� � ����� ������� capital.
   � ����� �� ������ DUMP ��������
   - There are no countries in the world, ���� ���� �� ���� ��������� �� ����� ������;
   ���������� ��������� ���� country/capital, ����������� ������� ���� ����� � �������������
   �� �������� ������, ���� � ���� ��� ���� ���� �� ���� ������.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
//  ����� ������ ���� �����.
void dump(const map<string, string>& m){
    if(m.size() > 0){
        for(auto item : m){
            cout << item.first << "/" << item.second<<" ";
        }
        cout << endl;
    }else{
        cout << "There are no countries in the world" << endl;
    }
}

// ����� ������� ������ country.
void about(map<string, string>& m, const string& country){
    if(m.count(country) > 0){
        cout << "Country " << country << " has capital " << m[country] << endl;
    }else{
        cout << "Country " << country << " doesn't exist" << endl;
    }
}

//  �������������� ������ �� old_country_name � new_country_name
void rename(map<string, string>& m, const string& o_c_name, const string& n_c_name){
    if(o_c_name == n_c_name || m.count(o_c_name) < 1 || m.count(n_c_name) > 0){
        cout << "Incorrect rename, skip" << endl;
    }else{
        string cap = m[o_c_name];
        cout << "Country " << o_c_name << " with capital "
             << cap << " has been renamed to "
             << n_c_name << endl;
        m.erase(o_c_name);
        m[n_c_name] = cap;
    }
}

//  ��������� ������� ������ country �� new_capital, ���� ���������� ����� ������
//  � ����� ��������, ���� ������ � �� ����.
void change_capital(map<string, string>& m, const string& country, const string& cap){
    if(m.count(country) == 0){
        m[country] = cap;
        cout << "Introduce new country " << country << " with capital "
             << m[country] << endl;
    }else if(m[country] == cap){
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }else if(m[country] != cap){
        cout << "Country " << country << " has changed its capital from "
             << m[country] << " to " << cap << endl;
        m[country] = cap;
    }
}


int main()
{
    map<string, string> capBook;
    int q;
    cin >> q;
    string command, country, new_capital, old_country, new_coutnry;

    for(int i = 0; i < q; ++i){
        cin >> command;
        if(command == "CHANGE_CAPITAL"){
            cin >> country >> new_capital;
            change_capital(capBook, country, new_capital);
        }else if(command == "RENAME"){
            cin >> old_country >> new_coutnry;
            rename(capBook, old_country, new_coutnry);
        }else if(command == "ABOUT"){
            cin >> country;
            about(capBook, country);
        }else if(command == "DUMP"){
            dump(capBook);
        }
    }



    return 0;
}
