// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historymergeendfirsta62d6518a32b006e.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
struct Instance{};
struct Value{unsigned a,b;void*content;bool operator<(const Value&)const;};
struct Record{int header;boost::shared_ptr<Instance> object;int kind;boost::shared_ptr<Instance> parent;std::set<Value> values;bool operator<(const Record&)const;void mergeValue(const Value&);void finish();};
struct History:std::map<Instance*,Record>{Record*insertRecord(Instance*const&,const Record&);__forceinline Record* lookup(Instance* key){iterator found=find(key);return found!=end()?&found->second:0;}void merge(History*);};
void History::merge(History* source){iterator last=source->end();for(iterator current=source->begin();current!=last;++current){const Record&value=current->second;Record*destination=lookup(value.object.get());if(destination){if(value.kind==3){Instance*eraseKey=value.object.get();erase(find(eraseKey));}else{if(value.parent)destination->parent=value.parent;std::for_each(value.values.begin(),value.values.end(),boost::bind(&Record::mergeValue,destination,_1));}}else{Instance*insertKey=value.object.get();insertRecord(insertKey,value)->finish();}}}
