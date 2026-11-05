// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historygetnative9b52452d98cd5fa6.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/any.hpp>
struct Instance{};struct Service{};struct Descriptor{};
struct Variant{const void*type;boost::any content;};
struct Record{Service*service;boost::shared_ptr<Instance>object;int kind;boost::shared_ptr<Instance>parent;std::map<const Descriptor*,Variant>values;Record(Service*,boost::shared_ptr<Instance>);Record(const Record&);~Record();};
Record::Record(Service*s,boost::shared_ptr<Instance>p):service(s),object(p),kind(0){}
struct Records:std::map<Instance*,Record>{Service*service;Record*get(boost::shared_ptr<Instance>);};
Record*Records::get(boost::shared_ptr<Instance>p){iterator i=find(p.get());if(i==end())i=insert(std::make_pair(p.get(),Record(service,p))).first;return &i->second;}
