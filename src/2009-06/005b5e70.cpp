// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <list>
template std::list<int>::iterator std::list<int>::insert(std::list<int>::const_iterator, const int&);
