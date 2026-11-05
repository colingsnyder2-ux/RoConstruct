// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    unsigned char storage[0x48];
    S(void* arg);
};

S* __cdecl create(void* arg)
{
    return new S(arg);
}
