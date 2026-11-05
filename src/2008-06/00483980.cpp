// from server: 81% by king_originala
extern void* g96fa78;
extern void* g96fa60;
extern void* g96fabc;
extern void* g96fa80;
extern void* g96fa6c;
extern void* g96fac4;
extern void* g96faa0;
extern void* g96fa94;
extern void* g96fa88;
extern void* g96fa74;

extern "C" void __cdecl release(void*);

void cleanup()
{
    release(g96fa78);
    release(g96fa60);
    release(g96fabc);
    release(g96fa80);
    release(g96fa6c);
    release(g96fac4);
    release(g96faa0);
    release(g96fa94);
    release(g96fa88);
    release(g96fa74);
}
