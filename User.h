//
// Created by Stari on 13.08.2023.
//

#ifndef TEST_USER_H
#define TEST_USER_H

#include <string>

using namespace std;

class User {
public:
    int id;
    string name;

    User(int id, const string &name) : id(id), name(name) {}
};

#endif //TEST_USER_H
