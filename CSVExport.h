//
// Created by Stari on 13.08.2023.
//

#ifndef TEST_CSVEXPORT_H
#define TEST_CSVEXPORT_H

#include <fstream>
#include <string>
#include <map>

#include "User.h"
#include "Product.h"
#include "Order.h"

using namespace std;

class CSVExport {
public:
    void UsersToCSV(map<int, User*>* users, string path = "users.csv") {
        ofstream file;
        file.open(path);

        for (auto item : *users) {
            auto id = item.first;
            auto user = item.second;
            file << id << "|" << user->name << endl;
        }

        file.close();
    }

    void ProductsToCSV(map<int, Product*>* products, string path = "products.csv") {
        ofstream file;
        file.open(path);

        for (auto item : *products) {
            auto id = item.first;
            auto product = item.second;
            file << id << "|" << product->name << endl;
        }

        file.close();
    }

    void OrdersToCSV(map<int, Order*>* orders, string path = "orders.csv") {
        ofstream file;
        file.open(path);

        for (auto item : *orders) {
            auto id = item.first;
            auto order = item.second;
            file << id << "|" << order->product->id << "|" << order->user->id << "|" << order->date << endl;
        }

        file.close();
    }
};


#endif //TEST_CSVEXPORT_H
