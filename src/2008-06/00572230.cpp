// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_signalsremovealias2fb7f9c9abeeb1a5.cpp

// Candidate translation unit (score above; library headers required).
#define BOOST_SIGNALS_SOURCE
#include <boost/signals/detail/named_slot_map.hpp>
namespace boost { namespace signals { namespace detail {
typedef std::list<connection_slot_pair>::iterator slot_pair_iterator;
void named_slot_map::remove_disconnected_slots(){group_iterator g=groups.begin();while(g!=groups.end()){slot_pair_iterator s=g->second.begin();while(s!=g->second.end()){if(s->first.connected())++s;else g->second.erase(s++);}if(empty(g))groups.erase(g++);else++g;}}
}}}
