// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct String {
    char data[28];
};

extern const char* (__thiscall *string_c_str)(const String*);

struct RefCount {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Holder {
    RefCount* ptr;
    Holder& __thiscall assign(const Holder&);
    ~Holder();
};

Holder::~Holder()
{
    if (ptr) {
        RefCount* p = ptr;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Document {
    char padding[0x110];
    String name;
};

struct S;
typedef void (__thiscall *NameFunction)(S*, const char*);

struct Table {
    char padding[0x58];
    NameFunction setName;
};

struct S {
    Table* table;
    char padding[0x50];
    Document* document;
    Holder holder;

    void __thiscall update(int, int, int);
    void __thiscall f(Document* volatile, Holder);
};

void S::f(Document* volatile value, Holder reference)
{
    document = value;
    holder.assign(reference);
    NameFunction* slot = &table->setName;
    const char* name = string_c_str(&value->name);
    (*slot)(this, name);
    update(0, 1, 0);
}
