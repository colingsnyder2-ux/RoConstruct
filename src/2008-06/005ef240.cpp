// from server: 100% by colin
// from server: 92% by king_originala
struct TypeInfo {};

typedef bool (__thiscall *TypeEqual)(const TypeInfo *, const TypeInfo *);
extern TypeEqual typeEqual;
extern TypeInfo surfaceType;

struct Metadata {
    void *reserved[2];
    const TypeInfo *type;
};

struct Holder {
    virtual ~Holder();
    virtual void reserved();
    virtual Holder *clone();
};

struct S {
    Metadata *metadata;
    Holder *holder;

    S(const S &other);
    ~S();
    Holder *copyHolder() const;
    int *convert();
    int value();
};

extern int *__cdecl getValue(Holder **);

inline Holder *S::copyHolder() const
{
    Holder *p = holder;
    if (p)
        return p->clone();
    return 0;
}

inline S::S(const S &other)
    : metadata(other.metadata), holder(other.copyHolder())
{
}

inline S::~S()
{
    if (holder)
        delete holder;
}

int S::value()
{
    const TypeInfo* t = metadata->type;
    if (typeEqual(&surfaceType, t))
        return *getValue(&holder);

    S copy(*this);
    return *copy.convert();
}
