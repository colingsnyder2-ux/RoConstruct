// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S
{
    char storage[0xB0];
    S();
};

S* func_00433fc0()
{
    return new S;
}
