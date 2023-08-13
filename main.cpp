#include <iostream>

#include "CSVExport.h"
#include "CSVImport.h"

int main() {
    /*map<int, User*>* users = new map<int, User*>();
    map<int, Product*>* products = new map<int, Product*>();
    map<int, Order*>* orders = new map<int, Order*>();

    users->insert(pair<int, User*>(9, new User(9, "user 9")));
    products->insert(pair<int, Product*>(1, new Product(1, "Product 1")));
    orders->insert(pair<int, Order*>(10, new Order(10, products->at(1), users->at(9), "2023-08-13")));

    auto exp = new CSVExport();
    exp->UsersToCSV(users);
    exp->ProductsToCSV(products);
    exp->OrdersToCSV(orders);*/

    auto imp = new CSVImport();
    auto users2 = imp->CSVToUsers();
    auto products2 = imp->CSVToProducts();
    auto orders2 = imp->CSVToOrders(users2, products2);

    auto order = orders2->at(10);
    cout << order->id << " " << order->product->name << ", " << order->user->name << ", " << order->date << endl;

    return 0;
}
