// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_eventdispatchshared_8ab0cbe995a41f96.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 86% by colin
struct EventData;

struct Value
{
    void* first;
    void* second;

    Value(const Value& other);
    Value(void* a, void* b);
};

inline Value::Value(const Value& other)
{
    *this = other;
}

inline Value::Value(void* a, void* b)
{
    first = a;
    second = b;
}

struct Listener
{
    virtual void slot0();
    virtual void slot1();
    virtual void dispatch(void* source, Value value);
    void prepare(EventData* event);
};

struct EventData
{
    void* field0;
    boost::shared_ptr<void> source;
    Listener* listener;
    Value value;

    void invoke();
    void finish();
};

void EventData::invoke()
{
    if (listener)
    {
        try
        {
            listener->prepare(this);
            Value temp(value.first, value.second);
            listener->dispatch(source.get(), temp);
        }
        catch (...)
        {
        }
        listener = 0;
    }
}
