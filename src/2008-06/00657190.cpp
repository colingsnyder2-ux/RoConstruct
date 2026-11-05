// from server: 100% by king_originala
extern "C" {
    extern void* (__cdecl *malloc)(unsigned int);
    void __cdecl free(void*);
}

struct String {
    char storage[28];
    ~String();
};

extern void (__thiscall *destroyString)(String*);

__forceinline String::~String()
{
    destroyString(this);
}

struct S {
    unsigned long data[0x190 / 4];

    S(void*, void*, void*, void*, void*);
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
};

void* S::operator new(unsigned int size) throw()
{
    return malloc(size);
}

void S::operator delete(void* p)
{
    free(p);
}

struct Deleter {};

struct Shared {
    void* object;
    void* control;

    Shared(S*, Deleter);
    ~Shared();
};

Shared __cdecl create(void* a, String b, void* c, void* d, void* e)
{
    return Shared(new S(a, &b, c, d, e), Deleter());
}
