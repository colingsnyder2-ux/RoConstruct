// from server: 100% by king_originala
typedef unsigned long DWORD;

extern "C" void* __stdcall factory(DWORD, DWORD);
extern "C" void* __cdecl holderType();
extern "C" void* __cdecl fieldType();
extern "C" void* __cdecl makeValue(DWORD, int);

void* __cdecl operator new(unsigned int);

struct Holder;

struct Field {
    void* type;
    void set(void*, void*, Holder*);
};

struct Base {
    virtual void invoke();
    char padding[16];
    Field field;
    char tail[32];

    Base(void*);
    ~Base();
};

struct Callback {
    virtual void invoke();
    DWORD value;

    Callback(DWORD);
};

struct Holder {
    void* type;
    Callback* callback;

    Holder(DWORD);
    ~Holder();
};

struct S : Base {
    DWORD first;
    DWORD second;
    Holder holder;

    virtual void invoke();
    S(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
};

__forceinline Callback::Callback(DWORD argument)
    : value(argument)
{
}

__forceinline Holder::Holder(DWORD argument)
{
    type = holderType();
    callback = new Callback(argument);
}

S::S(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e, DWORD f)
    : Base(factory(c, f)), first(a), second(b), holder(e)
{
    field.type = fieldType();
    field.set(makeValue(d, -1), holderType(), &holder);
}
