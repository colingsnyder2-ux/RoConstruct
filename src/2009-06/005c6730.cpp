// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#define __analysis_assume(e) do {} while (0)
#include <list>
typedef std::list<int>::const_iterator It;
template bool It::operator==(const It&) const;
