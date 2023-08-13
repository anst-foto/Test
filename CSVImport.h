//
// Created by Stari on 13.08.2023.
//

#ifndef TEST_CSVIMPORT_H
#define TEST_CSVIMPORT_H

#include <fstream>
#include <string>
#include <map>

#include "User.h"
#include "Product.h"
#include "Order.h"

class CSVImport {
public:
    map<int, User*>* CSVToUsers(string path = "users.csv") {
        map<int, User*>* users = new map<int, User*>();

        ifstream file;
        file.open(path);

        string line;

        while (getline(file, line)) {
            int pos = line.find('|');
            int id = stoi(line.substr(0, pos));
            string name = line.substr(pos + 1);

            users->insert(pair<int, User*>(id, new User(id, name)));
        }

        return users;
    }

    map<int, Product*>* CSVToProducts(string path = "products.csv") {
        map<int, Product*>* products = new map<int, Product*>();

        ifstream file;
        file.open(path);

        string line;

        while (getline(file, line)) {
            int pos = line.find('|');
            int id = stoi(line.substr(0, pos));
            string name = line.substr(pos + 1);

            products->insert(pair<int, Product*>(id, new Product(id, name)));
        }

        return products;
    }

    map<int, Order*>* CSVToOrders(map<int, User*>* users, map<int, Product*>* products, string path = "orders.csv") {
        map<int, Order*>* orders = new map<int, Order*>();

        ifstream file;
        file.open(path);

        string line;

        while (getline(file, line)) {
            int pos = line.find('|');
            int id = stoi(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
            int product_id = stoi(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
            int user_id = stoi(line.substr(0, pos));
            string date = line.substr(pos + 1);

            auto p = products->at(product_id);
            auto u = users->at(user_id);

            orders->insert(pair<int, Order*>(id, new Order(id, p, u, date)));
        }

        return orders;
    }
};


#endif //TEST_CSVIMPORT_H
