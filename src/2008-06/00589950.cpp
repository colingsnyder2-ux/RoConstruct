// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyrecordnativectordd6f7cbf753c4370.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <boost/shared_ptr.hpp>
struct Instance{};
struct Value{unsigned a,b;void*content;bool operator<(const Value&)const;};
struct Record{int header;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;std::set<Value>values;Record();};
Record::Record():kind(0){}
