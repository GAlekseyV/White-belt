/*
 * ��� ����� �����. ������� ���������� ���������� ����� � ���� ������.
 * ������ �����
 * ������� �������� ���������� ����� N, ����� � ���� N �����, ���������� ��������.
 * ��� ������ ������� ���� �� ��������� ����, ���� � �������� �������������.
 * ������ ������
 * �������� ������������ ����� ����� � ���������� ���������� ����� � ������ ������.
 */
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    string word;
    set<string> words;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> word;
        words.insert(word);
    }
    cout << words.size();
}
