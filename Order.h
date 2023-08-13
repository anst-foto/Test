//
// Created by Stari on 13.08.2023.
//

#ifndef TEST_ORDER_H
#define TEST_ORDER_H

#include <string>

#include "Product.h"
#include "User.h"

using namespace std;

class Order {
public:
    int id;
    Product* product;
    User* user;
    string date;

    Order(int id, Product *product, User *user, const string &date) : id(id), product(product), user(user),
                                                                      date(date) {}
};


#endif //TEST_ORDER_H
