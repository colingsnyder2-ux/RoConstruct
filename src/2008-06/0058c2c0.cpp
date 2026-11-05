// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historycommitnative0a62f5b584aac21f.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
struct Instance{};struct Service;struct Record{char data[56];};
struct Records:std::map<Instance*,Record>{Service*owner;std::string name;Records(Service*);bool empty();};
struct Service{char prefix[0x134];Records*current;std::list<Records*>records;std::list<Records*>::iterator forward,backward;bool blocked,enabled;void prepare();void commit(const char*);};
void Service::commit(const char*name){if(enabled){prepare();if(current&&!current->empty()){current->name=name;records.push_back(current);forward=records.end();backward=++records.end();current=new Records(this);}}}
