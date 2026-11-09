// from server: 100% by EspClaude
// roc 2009-06 004e3ab0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance;
class Base0 { public: virtual ~Base0(); char pad[0x14]; };
class Item { public: virtual ~Item(); };
class Derived : public Base0, public Item { };
struct Ref { Instance* instance; Derived* item; };
struct Frame {
    Instance* instance;
    Item* item;
    Frame(Instance* i, Item* t) : instance(i), item(t) {}
};
template<class T> struct ScopedPush {
    T*& head;
    T* prev;
    ScopedPush(T*& h, T* v) : head(h), prev(h) { head = v; }
    ~ScopedPush() { head = prev; }
};
namespace Network {
class Replicator {
public:
    void process(const Ref& r, int arg);
    void processScoped(const Ref& r, int arg);
    char pad[0x2c30];
    Frame* frames;
};
void Replicator::processScoped(const Ref& r, int arg)
{
    Frame frame(r.instance, r.item);
    ScopedPush<Frame> push(frames, &frame);
    process(r, arg);
}
}
}
