// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyrecordalignment9ea6b04d3cefe074.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
#include <boost/bind.hpp>
struct Value {unsigned a,b;void* content;bool operator<(const Value&)const;};
struct Instance {void setParent(Instance*);};
struct __declspec(align(8)) Record {char prefix[4];Instance* object;int reserved;int mode;Instance* parent;int reserved14;std::set<Value> values;void restoreValue(const Value&);void restore();void processValue(const Value&);void process();bool operator<(const Record&)const;};

struct History {std::set<Record> records;void process();};
void History::process(){for(std::set<Record>::iterator i=records.begin();i!=records.end();++i){Record& r=const_cast<Record&>(*i);switch(r.mode){case 1:r.object->setParent(0);break;case 2:std::for_each(r.values.begin(),r.values.end(),boost::bind(&Record::processValue,&r,_1));break;case 3:r.process();break;}}}
