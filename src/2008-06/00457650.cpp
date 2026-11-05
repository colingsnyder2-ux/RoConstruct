// from server: 100% by EspClaude
// roc 2008-06 00457650  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 91 bytes
// roc-flags: /O2 /GS- /EHsc /MD

struct EventData;
struct SharedPtr {
    void* px;
    void* pn;
    SharedPtr(const SharedPtr& other);
    ~SharedPtr();
};
struct Listener {
    void unregister(EventData* data);
    virtual void v0();
    virtual void v1();
    virtual void process(int arg, SharedPtr instance);
};
struct EventData {
    virtual ~EventData();
    int arg;
    int getArg() const { return arg; }
    int reserved;
    Listener* listener;
    SharedPtr instance;
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
