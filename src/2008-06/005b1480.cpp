// from server: 100% by king_originala
void * __cdecl operator new(unsigned int);
void __cdecl operator delete(void *) throw();

extern unsigned char useFallback;
extern void *constructorKey;

struct S;

struct Ref {
    void *object;
    void *control;
    Ref(S *);
    Ref(const Ref &);
};

struct Result {
    unsigned char data[40];
    Result(void *, Ref);
};

struct S {
    Result *fallback();
    Result *f();
};

Result *S::f()
{
    if (!useFallback)
        return new Result(constructorKey, Ref(this));
    return fallback();
}
