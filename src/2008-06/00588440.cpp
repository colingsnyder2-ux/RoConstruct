// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyrestorenative3d466afab51f9f69.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
#include <boost/bind.hpp>
struct Value {unsigned a,b;void* content;bool operator<(const Value&)const;};
struct Instance {void setParent(Instance*);};
struct Record {char prefix[4];Instance* object;int reserved;int mode;Instance* parent;int reserved14;std::set<Value> values;void restoreValue(const Value&);void restore();};
void Record::restore(){switch(mode){case 1:std::for_each(values.begin(),values.end(),boost::bind(&Record::restoreValue,this,_1));object->setParent(parent);break;case 2:std::for_each(values.begin(),values.end(),boost::bind(&Record::restoreValue,this,_1));break;case 3:object->setParent(0);break;}}
