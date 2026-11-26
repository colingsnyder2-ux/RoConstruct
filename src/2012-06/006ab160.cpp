// from server: 100% by Xemicl
#define _SECURE_SCL 0
#include <map>
#include <string>

struct Pad { char b[44]; };

struct StrLess4 {
    char state[1];
    bool operator()(const std::string& a, const std::string& b) const { return a < b; }
};
template class std::_Tree<std::_Tmap_traits<std::string, Pad, StrLess4,
    std::allocator<std::pair<const std::string, Pad> >, false> >;