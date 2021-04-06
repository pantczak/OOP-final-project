//
// Created by student on 17.01.2020.
//

#include "Individual.hpp"

double Individual::discount(double totalValue, int totalRecentPurchase) {
    if (totalValue >= 5000 && totalRecentPurchase >= 3 && totalRecentPurchase <= 15) return 0.05;
    else if (totalValue >= 10000 && totalRecentPurchase > 15) return 0.1;
    else return 0;
}

Individual::Individual() = default;

Individual::~Individual() = default;
