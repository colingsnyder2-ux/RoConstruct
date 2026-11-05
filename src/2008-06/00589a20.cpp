// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyundoearlylookupe327dc0eb25427bc.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <map>
#include <list>
#include <deque>
#include <boost/shared_ptr.hpp>
struct Instance{};struct Service;struct Record;
struct Value{unsigned a,b;void*content;bool operator<(const Value&)const;};
struct Record{Service*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;std::set<Value>values;bool operator<(const Record&)const;void restore();void undo();};
struct Records:std::map<Instance*,Record>{__forceinline Record*lookup(Instance*key){iterator i=find(key);if(i==end())return 0;return &i->second;}};
struct Service{char prefix[0x138];std::list<Records*>records;std::list<Records*>::iterator forward,backward;};
void Record::undo(){std::deque<Record*>pending;std::list<Records*>::iterator i=service->backward;while(i!=service->records.begin()){--i;Record*r=(*i)->lookup(object.get());if(r){if(r->kind==1){r->restore();break;}pending.push_back(r);}}while(!pending.empty()){pending.back()->restore();pending.pop_back();}}
