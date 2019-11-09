/*
 * Два слова назывыются синонимами друг друга, если они имеют похожие значения. � еализуйте следующие
 * операции над словарём синонимов:
 * ADD word1 word2 - добавить в словарь пару синонимов (word1, word2)
 * COUNT word - узнать количество синонимов слова word
 * СHECK word1 word2 - проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2
 * считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или
 * ADD word2 word1
 *
 * Формат ввода
 * Сначала вводится количество запросов Q, затем Q строк с описаниями запросов. Гарантируется, что
 * в каждом запросу CHECK и ADD слова word1 и word2 различны. Все слова состоят лишь из латинских
 * букв, цифр и символов подчёркивания.
 *
 * Формат вывода
 * Для каждого запроса в соответствующей строке выведите ответ на него:
 * - В ответ на запрос COUNT word выведите единственное целое число - количество синонимов слова word
 * - В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и
 * NO в противном случае
 *
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, set<string>> m;

    string operation_code, word1, word2;
    for(int i = 0; i < q; ++i){
        cin >> operation_code;
        if(operation_code == "COUNT"){
            cin >> word1;
            unsigned int count = m[word1].size();
            cout << count << endl;
        }else if(operation_code == "ADD"){
            cin >> word1 >> word2;
            m[word1].insert(word2);
            m[word2].insert(word1);
        }else if(operation_code == "CHECK"){
            cin >> word1 >> word2;
            if(m[word1].count(word2) > 0 || m[word2].count(word1) > 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
