// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_eventdequecomplete_a69694a1f98b5af2.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <deque>
struct Record { unsigned value; std::string first,second; };
struct Element { unsigned first,second; std::string name; std::list<Record> values; };
bool operator==(const Record&,const Record&);
bool operator<(const Record&,const Record&);
bool operator==(const Element&,const Element&);
bool operator<(const Element&,const Element&);
template class std::list<Record>;
template class std::deque<Element>;
