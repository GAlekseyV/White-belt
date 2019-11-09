/*
 * �������
 * � ����������� ������ ���� ���� ������, ��������� �� N + 1 ����� �����.
 * ������ ������ ��� ���� ����� N. ����� ������� ��� N �����, ��������� �� �� ������ A.
 * ����� ����� ����� ��������� ��������.
 * ������������ ������ � �� ������ � �������� ��� � ����������� �����.
 * �����������
 * 0 <= N <= 1000
 * -1000000 <= A[i] <= 1000000
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long num;
    vector<int> nums;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        nums.push_back(num);
    }

    sort(begin(nums), end(nums), [](long i, long j){return abs(i) < abs(j);});

    for(const auto num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
