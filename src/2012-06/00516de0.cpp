// from server: 91% by tajop
struct Desc
{
    bool isA(const Desc* d) const;
};

extern const Desc* getDesc();

struct PadA
{
    char pad[0x1c];
};

struct Base
{
    char pad[0xc];
    const Desc* desc;
};

struct Inst : PadA, Base
{
};

struct Owner
{
    char pad[0x38];
    Inst* inst;
};

extern bool checkOwner(Owner* o);

struct Holder
{
    Owner* p;
};

struct SP
{
    void* px;
    void* pn;
    ~SP();
};

extern SP makeSP(Inst* r);

struct Conn
{
    void* a;
    Inst* b;
    void disconnect();
    void reset();
};

struct PE
{
    char pad[0x1c4];
    Conn conn;
    char pad2[0x1e0 - 0x1c4 - sizeof(Conn)];
    Holder h;
    void apply(const SP& sp, Holder* holder);
    void update();
};

void PE::update()
{
    if (!checkOwner(h.p))
    {
        conn.disconnect();
        return;
    }
    if (h.p->inst == conn.b)
        return;
    conn.reset();
    Inst* p = h.p->inst;
    Base* q = p;
    if (q)
    {
        const Desc* d = q->desc;
        if (d->isA(getDesc()))
        {
            Inst* r = static_cast<Inst*>(q);
            if (r)
            {
                SP sp = makeSP(r);
                apply(sp, &h);
                return;
            }
        }
    }
    conn.disconnect();
}
