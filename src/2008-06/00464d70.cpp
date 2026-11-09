// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_eventdispatchdirect_2aa7fd57483e2cca.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 81% by king_originala
struct EventData;

struct Listener
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void dispatch(void*, int) = 0;

    void prepare(EventData*);
};

struct EventData
{
    int field0;
    boost::shared_ptr<void> argument;
    Listener* listener;
    int value;

    void invoke();
};

void EventData::invoke()
{
    if (listener)
    {
        try
        {
            listener->prepare(this);
            listener->dispatch(argument.get(), value);
        }
        catch (...)
        {
        }
        listener = 0;
    }
}
