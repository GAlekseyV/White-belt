/*
 * Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

    NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count
    остановками с названиями stop1, stop2, ...
    BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
    STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов,
    на которые можно пересесть на каждой из остановок.
    ALL_BUSES — вывести список всех маршрутов с остановками.

Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.
Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков
подчёркивания.
Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus
отсутствует, количество остановок больше 0, а после числа stop_count следует именно такое
количество названий остановок, причём все названия в каждом списке различны.
Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:
    На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту
    остановку, в том порядке, в котором они создавались командами NEW_BUS. Если остановка stop
    не существует, выведите No stop.
    На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в
    том порядке, в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой
    остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов,
    проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS,
    за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус,
    кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не
    существует, выведите No bus.
    На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
    Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ...,
    где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы
    в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.

Предупреждение
Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили
ни одной, перечитайте условие ещё раз.
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;



int main()
{
    int q;
    string operation_code;
    map<string, vector<string>> bus_to_stops;
    map<string, vector<string>> stop_to_busses;
    cin >> q;

    for(int i = 0; i < q; ++i){
        cin >> operation_code;
        if(operation_code == "NEW_BUS"){
            string bus, stop;
            int stop_count;
            cin >> bus >> stop_count;
            bus_to_stops[bus];
            for(int j = 0; j < stop_count; ++j){
                cin >> stop;
                bus_to_stops[bus].push_back(stop);
                stop_to_busses[stop].push_back(bus);
            }

        }else if(operation_code == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            if(stop_to_busses.count(stop) > 0){
                for(auto b : stop_to_busses[stop]){
                    cout << b << " ";
                }
                cout << endl;
            }else{
                cout << "No stop" << endl;
            }
        }else if(operation_code == "STOPS_FOR_BUS"){
            string bus;
            cin >> bus;
            if(bus_to_stops.count(bus) > 0){ // Автобус существует
                for(auto stop : bus_to_stops[bus]){
                    cout << "Stop " << stop << ": ";
                    if(stop_to_busses[stop].size() > 1){
                        for(auto b : stop_to_busses[stop]){
                            if(b != bus){
                                cout << b << " ";
                            }
                        }
                    }else{
                        cout << "no interchange";
                    }
                    cout << endl;
                }
            }else{
                cout << "No bus" << endl;
            }

        }else if(operation_code == "ALL_BUSES"){
            if(bus_to_stops.size() > 0){
                for(auto b : bus_to_stops){
                    cout << "Bus " << b.first << ": ";
                    for(auto stop : b.second){
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }else{
                cout << "No buses" << endl;
            }

        }
    }
    return 0;
}
