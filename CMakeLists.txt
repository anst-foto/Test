cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp User.h Product.h Order.h CSVExport.h CSVImport.h)
