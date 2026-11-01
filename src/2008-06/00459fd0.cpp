// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S
{
    char storage[0x1f0];
    S();
};

S* __cdecl f()
{
    return new S;
}
