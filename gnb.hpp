//
// Created by ankolesn on 26.05.22.
//

#ifndef ASSOCIATION_GNB_HPP
#define ASSOCIATION_GNB_HPP
#include <vector>

class UE {
public:
    float C = 0;
    std::pair <float, float> coord;
    size_t gNB_ind = -1;

public:
    UE();
};

class gNB {
public:
    size_t k = 0;
    float c_max = 20000;
    std::pair <float, float> coord;
    gNB();

    static void associate(std::vector<gNB> &gNBs, std::vector<UE> &UEs);

    static void associate_opt(std::vector<gNB> &gNBs, std::vector<UE> &UEs, size_t num);

    static float calc_all_c(std::vector<gNB> &gNBs, std::vector<UE> &UEs);
};

#endif //ASSOCIATION_GNB_HPP
