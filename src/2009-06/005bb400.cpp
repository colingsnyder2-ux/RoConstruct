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
template void std::sort<SortItem*>(SortItem*, SortItem*);
template void std::make_heap<SortItem*>(SortItem*, SortItem*);
template void std::sort_heap<SortItem*>(SortItem*, SortItem*);
