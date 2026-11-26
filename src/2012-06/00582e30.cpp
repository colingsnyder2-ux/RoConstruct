// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

// The lookup takes its key as a 4-byte class by value, built from a temporary;
// that gives the key eax and the pointer ecx.
struct Id { int v; Id(int q) : v(q) {} };

struct Counted {
    void* vtbl;
    long use_count;
};

struct SP {
    void* px;
    Counted* pn;
    SP(const SP& o) : px(o.px), pn(o.pn)
    {
        if (pn) _InterlockedIncrement(&pn->use_count);
    }
    ~SP();
};

struct Desc {
    int id;
    char pad[9];
    unsigned char flags;
};

struct Event {
    int a;
    SP sp;
};

struct PingJob {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual int check(Id id, void* px);
    virtual void apply(int id, void* px);

    void onAdded(SP sp);
    void onChanged(int id, void* px, Counted* pn);
    void handle(const Desc* d, int type, const Event* e);
};

void PingJob::handle(const Desc* d, int type, const Event* e)
{
    switch (type) {
    case 0:
        if (d->flags & 1)
            onAdded(e->sp);
        break;
    case 2:
        if (d->flags & 2) {
            if (!check(Id(d->id), e->sp.px))
                apply(d->id, e->sp.px);
        }
        break;
    case 3:
        if (d->flags & 2)
            onChanged(d->id, e->sp.px, e->sp.pn);
        break;
    }
}
