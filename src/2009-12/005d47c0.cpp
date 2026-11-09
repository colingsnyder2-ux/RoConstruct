// from server: 35% by atomic.potato
struct Inner1 { char pad[0x40]; void dtor(); };
struct Inner2 { char pad[0x20]; void dtor(); };

struct S {
    char pad0[0x1c];
    void* handle;
    Inner2 inner2;
    Inner1 inner1;
    void dtor();
};

extern "C" void __stdcall CloseHandle(void*);

void S::dtor()
{
    inner1.dtor();
    inner2.dtor();
    void* h = handle;
    handle = 0;
    if (h) CloseHandle(h);
    *(void**)this = (void*)0x9c1198;
    ((void(*)(void*))0x5d18b0)(this);
}
