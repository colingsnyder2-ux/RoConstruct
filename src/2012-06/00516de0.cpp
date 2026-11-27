// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { bool isA(const Desc* d) const; };
struct PadA { char pad[0x1c]; };
struct Base { char pad[0xc]; const Desc* desc; };
struct Inst : PadA, Base { static const Desc* classDescriptor(); };
struct Owner { char pad[0x38]; Inst* inst; Inst* getInst() const { return inst; } };
extern bool checkOwner(Owner* o);
struct Holder { Owner* p; Owner* operator->() const { return p; } Owner* get() const { return p; } };
struct SP { void* px; void* pn; ~SP(); };
extern SP makeSP(Inst* r);
struct Conn { void* a; Inst* b; void disconnect(); void reset(); };
struct PE {
    char pad[0x1c4];
    Conn conn;
    char pad2[0x1e0 - 0x1c4 - sizeof(Conn)];
    Holder h;
    void apply(const SP& sp, const Holder& holder);
    void update();
};
template<class T> inline T* fastCast(Base* p) {
    if (p) {
        const Desc* d = p->desc;
        if (d->isA(T::classDescriptor()))
            return static_cast<T*>(p);
    }
    return 0;
}

void PE::update()
{
    if (!checkOwner(h.get())) {
        conn.disconnect();
    } else if (h->getInst() != conn.b) {
        conn.reset();
        Inst* r = fastCast<Inst>(h->getInst());
        if (r) {
            SP sp = makeSP(r);
            apply(sp, h);
        } else {
            conn.disconnect();
        }
    }
}
