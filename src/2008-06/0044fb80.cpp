// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

typedef void (__thiscall *StringConstructor)(String*, const char*);
typedef void (__thiscall *StringDestructor)(String*);
extern StringConstructor constructString;
extern StringDestructor destroyString;

__forceinline String::String(const char* text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

struct Counted {
    virtual ~Counted();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count;
    volatile long weak_count;
};

struct Object {
    virtual ~Object();
    virtual void set(const String&) = 0;
};

struct Pointer {
    Object* object;
    Counted* count;
    ~Pointer();
};

__forceinline Pointer::~Pointer()
{
    if (count) {
        Counted* p = count;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

struct Holder {
    Pointer get();
};

struct S {
    unsigned char padding[0x94];
    Holder* holder;
    void prior(const char*);
    void f(const char*);
};

void S::f(const char* text)
{
    prior(text);
    if (holder) {
        String value(text);
        holder->get().object->set(value);
    }
}
