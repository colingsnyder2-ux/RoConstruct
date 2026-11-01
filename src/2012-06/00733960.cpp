// from server: 83% by tajop
struct Desc { bool isA(const Desc* other) const; };
const Desc* getDesc();

struct A { char pad[0x1c]; };
struct B {
    char pad[0xc];
    const Desc* desc;
    bool matches() const { const Desc* d = desc; return d->isA(getDesc()); }
};
struct Instance : A, B {};

struct Ptr { Instance* p; Instance* get() const { return p; } };

struct Connection { void disconnect(); };
struct Node { Node* left; Node* parent; Node* right; Instance* key; Connection value; };
struct Iter { Node* node; Iter() {} };
struct Map {
    Iter find(Instance* const& key);
    Iter erase(Node* where);
};

struct S {
    char pad[0xf0];
    Map connections;
    void onRemoved(Instance* child);
    void f(const Ptr& child);
};

void S::f(const Ptr& child) {
    Instance* raw = child.get();
    B* base = raw ? static_cast<B*>(raw) : 0;
    Instance* inst = (base && base->matches()) ? static_cast<Instance*>(base) : 0;
    if (inst) {
        onRemoved(inst);
        Map* m = &connections;
        Iter it = m->find(child.get());
        it.node->value.disconnect();
        m->erase(it.node);
    }
}
