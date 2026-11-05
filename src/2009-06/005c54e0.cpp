// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /MD /EHsc
#define __analysis_assume(e) do {} while (0)
#include <list>
template class std::list<int>::_Const_iterator<true>;
