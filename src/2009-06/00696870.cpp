// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Store {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual bool has(int id);
    virtual void set(int id, bool value);
};
struct Event {
    int type;
    Store* store;
    int id;
    int extra;
    short a;
    short b;
    Event(int t, Store* s, int i) : type(t), store(s) { extra = b = a = 0; id = i; }
};
struct Service { void raise(const Event& e); };
struct Instance;
template<class T> T* __fastcall findService(const Instance* context);
struct Owner {
    char pad[0x8c];
    Store* store;
    int parse(const std::string& s);
    void add(std::string s);
};
void Owner::add(std::string s)
{
    int id = parse(s);
    if (!store->has(id)) {
        store->set(id, true);
        findService<Service>((const Instance*)this)->raise(Event(10, store, id));
    }
}
}
