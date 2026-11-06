// from server: 100% by tajop



#define _SECURE_SCL 0
#include <map>
#include <string>

struct StrLess4 {
    int state;
    bool operator()(const std::string& a, const std::string& b) const { return a < b; }
};
template class std::_Tree<std::_Tmap_traits<std::string, std::string, StrLess4,
    std::allocator<std::pair<const std::string, std::string> >, false> >;
