//
// Created by ben on 4/14/17.
//

#ifndef CONNAN_OVERLAYMOUNT_HPP
#define CONNAN_OVERLAYMOUNT_HPP

#include <boost/filesystem.hpp>
#include <vector>

class OverlayMount {
public:
    OverlayMount(boost::filesystem::path target,
                 std::vector<boost::filesystem::path> lowers,
                 boost::filesystem::path upper);
};


#endif //CONNAN_OVERLAYMOUNT_HPP
