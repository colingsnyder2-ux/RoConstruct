// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_try_e30ba7cfa3240599.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <vector>
#include <algorithm>
typedef std::pair<void*,float> Entry;
struct Less { bool operator()(const Entry& a, const Entry& b) const { return a.second < b.second; } };
void heapPush(std::vector<Entry>& v) { std::push_heap(v.begin(), v.end(), Less()); }
void heapPop(std::vector<Entry>& v) { std::pop_heap(v.begin(), v.end(), Less()); }
