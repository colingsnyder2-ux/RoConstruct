// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class Base { public: virtual void v0(); };
class Prim : public Base {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual bool isX();
};
class PSet { public: unsigned int erase(Base* const& k); };
class Listener { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void onRemoved(Prim* p); };
class Stage {
public:
    char pad[0x54];
    PSet set;
    char pad2[0x74 - 0x58];
    int count;
    char pad3[0xb8 - 0x78];
    Listener* listener;
    void remove(Prim* p);
};
void Stage::remove(Prim* p)
{
    Base* k = p;
    if (p->isX())
        set.erase(k);
    listener->onRemoved(p);
    count--;
}
