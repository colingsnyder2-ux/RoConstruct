// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historyresetnativefixe3eed368d446fece.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <string>
#include <algorithm>
#include <boost/checked_delete.hpp>
struct Service;
struct Base{char mapAndOwner[36];~Base();};
struct Records:Base{std::string name;Records(Service*);};
typedef std::list<Records*>::iterator Iter;
namespace std{template<> __forceinline boost::checked_deleter<Records> for_each(Iter first,Iter last,boost::checked_deleter<Records> f){_Checked_iterator_base_helper<Iter>::_Checked_iterator_base_type b(_CHECKED_BASE(first));_Checked_iterator_base_helper<Iter>::_Checked_iterator_base_type e(_CHECKED_BASE(last));for(;b!=e;++b)f(*b);return f;}}
struct Service{char prefix[0x134];Records*current;std::list<Records*>records;Iter forward,backward;void reset();};
void Service::reset(){if(current){delete current;current=new Records(this);}std::for_each(records.begin(),records.end(),boost::checked_deleter<Records>());records.clear();forward=records.end();backward=records.begin();}
