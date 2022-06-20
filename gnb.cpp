//
// Created by ankolesn on 26.05.22.
//

#include "gnb.hpp"
#include <cstdio>
#include <valarray>

gNB::gNB() {
    coord.first = static_cast<float > (rand()) / RAND_MAX * 100 - 100;
    coord.second = static_cast<float > (rand()) / RAND_MAX * 100 - 100;
}

float calc_c(UE &ue, gNB &gnb) {
    float r = sqrt(pow((ue.coord.first - gnb.coord.first), 2) + pow((ue.coord.second - gnb.coord.second), 2));
    float c = gnb.c_max / (1 + pow(r, 2)) / (gnb.k + 1);
    return c;
}


void gNB::associate(std::vector<gNB> &gNBs, std::vector<UE> &UEs) {
    for (auto &ue: UEs) {
        float max = 0;
        size_t ind = 0;
        int count = 0;
        for (auto &gnb: gNBs) {
            float cc = calc_c(ue, gnb);
            if (cc > max) {
                max = cc;
                ind = count;
            }
            count++;
        }
        ue.gNB_ind = ind;
        gNBs[ind].k++;
    }
}


void gNB::associate_opt(std::vector<gNB> &gNBs, std::vector<UE> &UEs, size_t num) {
    while (num-- > 0) {
        auto copy = UEs;
        size_t rand_num = rand() % UEs.size();
        auto cur_i = UEs[rand_num].gNB_ind;
        auto next_i = (cur_i + 1) % gNBs.size();
        auto cur_c = calc_all_c(gNBs, UEs);
        gNBs[copy[rand_num].gNB_ind].k--;
        copy[rand_num].gNB_ind = (UEs[rand_num].gNB_ind + 1) % gNBs.size();
        gNBs[copy[rand_num].gNB_ind].k++;
        auto next_c = calc_all_c(gNBs, copy);
        if (next_c > cur_c) {
            UEs = copy;
        } else {
            gNBs[next_i].k--;
            gNBs[cur_i].k++;
        }
    }
}

float gNB::calc_all_c(std::vector<gNB> &gNBs, std::vector<UE> &UEs) {
    float sum = 0;
    for (auto &ue: UEs) {
        ue.C = calc_c(ue, gNBs[ue.gNB_ind]);
        sum += ue.C;
    }
    return sum;
}


UE::UE() {
    coord.first = static_cast<float > (rand()) / RAND_MAX * 100 - 100;
    coord.second = static_cast<float > (rand()) / RAND_MAX * 100 - 100;
}
