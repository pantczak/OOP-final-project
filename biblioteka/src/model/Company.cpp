//
// Created by student on 17.01.2020.
//

#include "Company.hpp"

double Company::discount(double totalValue, int totalRecentPurchase) {

    if (totalValue >= 4000 && totalRecentPurchase > 5 && totalRecentPurchase <= 10) return 0.15;
    else if (totalValue > 8000 && totalRecentPurchase > 10) return 0.2;
    else return 0.05;
}

Company::Company() {}

Company::~Company() {

}
