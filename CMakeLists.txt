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
        # sets/map_values
        sets/sinonyms
        sets/bus_routes_3
        )

set(Week_3
        algorithms/sort_numbers
        algorithms/sort_strings
        # structs_and_classes/sorted_strings
        structs_and_classes/name_history
        # structs_and_classes/name_history_2
        # constructors/revers_string
        # constructors/name_history_3
        # constructors/incognizable
        )

set(Week_4
        # structs_and_classes/lecture_title
        structs_and_classes/function
        # structs_and_classes/function_2
        files_and_streams/print_file
        files_and_streams/rw_file
        files_and_streams/print_file_2
        files_and_streams/read_csv_file
        files_and_streams/students
        overload/rational_1
        overload/rational_2
        overload/rational_3
        overload/rational_4
        overload/rational_5
        # exceptions/exception
        exceptions/rational_6
        exceptions/rational_7
        exceptions/ack_time_server
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
