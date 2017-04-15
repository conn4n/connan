//
// Created by ben on 4/14/17.
//

#include <boost/filesystem.hpp>
#include <sys/mount.h>
#include <sstream>
#include "StringException.hpp"
#include "OverlayMount.hpp"

using std::vector;
using std::stringstream;
using namespace std::string_literals;
using boost::filesystem::path;
using boost::filesystem::create_directories;
using boost::filesystem::is_directory;

OverlayMount::OverlayMount(path target, vector<path> lowers, path upper) {
    stringstream overlay_options;
    overlay_options << "lowerdir=";
    bool first = true;
    for (path p : lowers) {
        if (first) {
            first = false;
        } else {
            overlay_options << ":";
        }
        assert(is_directory(p));
        overlay_options << p.string();
    }

    path work = upper.parent_path() / ("."s + upper.filename().string() + ".work"s);
    overlay_options << ",workdir=";
    overlay_options << work.string();

    overlay_options << ",upperdir=";
    overlay_options << upper.string();

    create_directories(target);
    create_directories(work);
    create_directories(upper);

    auto ret = mount("overlay", target.c_str(), "overlay", 0, overlay_options.str().c_str());

    if (ret != 0) {
        throw StringException("mount returned error "s + std::to_string(ret));
    }
}
