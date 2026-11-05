// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// VS2008 <algorithm> std::sort on float* (family of 006789e0 _Unguarded_partition<float*>).
#include <algorithm>

template void std::sort<float*>(float*, float*);
template void std::_Sort<float*, int>(float*, float*, int);
template void std::_Median<float*>(float*, float*, float*);
template void std::_Med3<float*>(float*, float*, float*);
template void std::_Insertion_sort<float*>(float*, float*);
template void std::make_heap<float*>(float*, float*);
template void std::sort_heap<float*>(float*, float*);
template std::pair<float*, float*> std::_Unguarded_partition<float*>(float*, float*);
