// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /MT
#include <algorithm>
#pragma pack(push,4)
class SortItem {
public:
    int data[14];
    double key;
    int tail[2];
    bool operator<(const SortItem& o) const;
};
#pragma pack(pop)
template void std::_Adjust_heap<SortItem*, int, SortItem>(SortItem*, int, int, SortItem);
template void std::_Push_heap<SortItem*, int, SortItem>(SortItem*, int, int, SortItem);
