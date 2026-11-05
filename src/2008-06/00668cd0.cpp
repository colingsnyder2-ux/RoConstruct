// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    char storage[0x78];
    S(void* arg);
};

S* __stdcall create(void* arg)
{
    return new S(arg);
}
