// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    char storage[76];
    S();
};

S* instance;

void initialize()
{
    instance = new S;
}
