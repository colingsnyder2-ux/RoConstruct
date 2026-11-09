// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    bool operator<(const SystemAddress& right) const;
};
struct Val { double d; char pad[0x140]; };
template class std::_Tree<std::_Tmap_traits<SystemAddress,Val,std::less<SystemAddress>,std::allocator<std::pair<const SystemAddress,Val> >,false> >;
