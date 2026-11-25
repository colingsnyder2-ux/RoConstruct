// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Value { int a; int b; Value(int x, int y) : a(x), b(y) {} Value(const Value& o) : a(o.a), b(o.b) {} };
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
    int x;
    int y;
    void fire();
};

void EventData::fire()
{
    if (listener) {
        try {
            listener->unregister(this);
            listener->process(getArg(), Value(x, y));
        } catch (...) {
        }
        listener = 0;
    }
}
