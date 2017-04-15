#include "OverlayMount.hpp"
#include <iostream>

using namespace std::string_literals;

int main() {
    boost::filesystem::path target = "/root/overlay_test/merged"s;
    boost::filesystem::path upper = "/root/overlay_test/upper"s;
    std::vector<boost::filesystem::path> lower_vec;
    lower_vec.push_back(boost::filesystem::path("/root/overlay_test/lower1"s));
    lower_vec.push_back(boost::filesystem::path("/root/overlay_test/lower2"s));

    for (auto p : lower_vec) {
        std::cout << "lower: " << p << std::endl;
    }
    std::cout << "upper: " << upper << std::endl;
    std::cout << "target: " << target << std::endl;

    OverlayMount(target, lower_vec, upper);
    return 0;
}