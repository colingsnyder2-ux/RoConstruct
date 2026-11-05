// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_try_15110fb6a0b86d4e.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <vector>
#include <algorithm>
struct Entry {
    void* object;
    float priority;
    bool operator<(const Entry& other) const { return priority < other.priority; }
};
void heapPush(std::vector<Entry>& values) { std::push_heap(values.begin(), values.end()); }
void heapPop(std::vector<Entry>& values) { std::pop_heap(values.begin(), values.end()); }
void heapSort(Entry* first, Entry* last) { std::sort_heap(first, last); }
void heapMake(Entry* first, Entry* last) { std::make_heap(first, last); }
