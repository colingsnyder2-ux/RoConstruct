// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    unsigned char data[220];
    S();
};

extern S* instance;

void __cdecl initialize()
{
    instance = new S;
}
