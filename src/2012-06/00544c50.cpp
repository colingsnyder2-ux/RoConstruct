// from server: 100% by Xemicl
#define _SECURE_SCL 0
#include <set>
#include <string>

struct StrLess4 {
    char state[1];
    bool operator()(const std::string& a, const std::string& b) const { return a < b; }
};
template class std::_Tree<std::_Tset_traits<std::string, StrLess4,
    std::allocator<std::string>, false> >;