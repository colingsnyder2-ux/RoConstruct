// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_event_handler_for_each_044c64d9154ca774.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <list>
#include <boost/bind.hpp>

struct EventArgument;

struct EventHandlerItem
{
    void invoke(const EventArgument* argument);
};

__declspec(noinline) void __cdecl roc_event_handler_list_for_each(
    std::list<EventHandlerItem*>::iterator first,
    std::list<EventHandlerItem*>::iterator last,
    const EventArgument* argument)
{
    std::for_each(
        first,
        last,
        boost::bind(&EventHandlerItem::invoke, _1, argument));
}
