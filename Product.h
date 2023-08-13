//
// Created by Stari on 13.08.2023.
//

#ifndef TEST_PRODUCT_H
#define TEST_PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    int id;
    string name;

    Product(int id, const string &name) : id(id), name(name) {}
};


#endif //TEST_PRODUCT_H
