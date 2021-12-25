cmake_minimum_required(VERSION 3.12)
project(White_belt)

set(CMAKE_CXX_STANDARD 17)

set(WEEKS
        Week_1
        Week_2
        Week_3
        Week_4
        Week_5
        )

set(Week_1
        1_min_string
        2_equation
        3_division
        4_cost_calculation
        5_even_numbers
        6_second_occurrence
        7_gcd
        8_binary_numbers)

set(Week_2
        vector/average_temperature
        vector/queue
        vector/todo_list
        map/anagramms
        map/capitals_dict
        map/bus_routes
        map/bus_routes_2
        sets/unique_strings
        sets/map_values
        sets/sinonyms
        sets/bus_routes_3
        )

set(Week_3
        algorithms/sort_numbers
        algorithms/sort_strings
        structs_and_classes/sorted_strings
        structs_and_classes/name_history
        structs_and_classes/name_history_2
        6_revers_string
        7_name_history_3
        8_incognizable
        )

set(Week_4
        1_lecture_title
        2_function
        3_function_2
        4_1_print_file
        4_2_rw_file
        5_print_file_2
        6_read_csv_file
        7_student
        8_1_rational_1
        8_2_rational_2
        8_3_rational_3
        8_4_rational_4
        8_5_rational_5
        9_exception
        10_rational_6
        11_rational_7
        12_ack_time_server
        )

set(Week_5
        final_task
        )


# create a project file per tutorial
foreach(WEEK ${WEEKS})
    foreach(TASK ${${WEEK}})
        file(GLOB SOURCE
                "${WEEK}/${TASK}/*.h"
                "${WEEK}/${TASK}/*.cpp"
                )
        set(NAME "${WEEK}_${TASK}")
        string(REPLACE "/" "_" NAME "${NAME}")
        add_executable(${NAME} ${SOURCE})
    endforeach(TASK)
endforeach(WEEK)
