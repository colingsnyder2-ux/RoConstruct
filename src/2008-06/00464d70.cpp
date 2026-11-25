// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef int Value;
struct EventData;
struct Listener {
    void unregister(EventData* data);
    virtual void v0();
    virtual void v1();
    virtual void process(int arg, Value instance);
};
struct EventData {
    virtual ~EventData();
    int arg;
    int getArg() const { return arg; }
    int reserved;
    Listener* listener;
    Value instance;
    void fire();
};

void EventData::fire()
{
    if (listener) {
        try {
            listener->unregister(this);
            listener->process(getArg(), instance);
        } catch (...) {
        }
        listener = 0;
    }
}
