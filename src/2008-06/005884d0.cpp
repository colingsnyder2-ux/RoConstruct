// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyundopropertymaps478b03b5d527bd39.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <map>
#include <list>
#include <deque>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
struct Instance{void setParent(Instance*);};struct Service;struct Record;
struct Variant{const void*type;boost::any content;};
struct Descriptor{virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void set(void*,const Variant&)const;};
extern Descriptor parentProperty;
typedef std::pair<const Descriptor*const,Variant> Value;
struct Record{Service*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;typedef std::map<const Descriptor*,Variant> Values;Values values;bool operator<(const Record&)const;void restore();void undo();void undoProperty(const Value&);};
struct Records:std::map<Instance*,Record>{__forceinline Record*lookup(Instance*key){iterator i=find(key);return i!=end()?&i->second:0;}};
struct Service{char prefix[0x138];std::list<Records*>records;std::list<Records*>::iterator forward,backward;};
void Record::undoProperty(const Value&key){bool isParent=key.first==&parentProperty;std::list<Records*>::iterator i=service->backward;while(i!=service->records.begin()){--i;Record*r=(*i)->lookup(object.get());if(r){Values::iterator found=r->values.find(key.first);if(found!=r->values.end()){Value v=*found;Instance*p=r->object.get();v.first->set(p?(char*)p+0x14:0,v.second);return;}if(isParent&&r->kind==1){object->setParent(r->parent.get());return;}}}}
