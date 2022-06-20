#include <iostream>
#include <vector>
#include "gnb.hpp"

using namespace std;

int main() {
    vector<gNB> vec(10);
    vector<UE> vec2(100);
    gNB::associate(vec, vec2);
    for (auto &i: vec2) {
       // cout << i.gNB_ind << endl;
    }
    cout << gNB::calc_all_c(vec,vec2) << endl;
    gNB::associate_opt(vec, vec2, 100000);
    for (auto &i: vec2) {
       // cout << i.gNB_ind << endl;
    }
    cout << gNB::calc_all_c(vec,vec2) << endl;

}
