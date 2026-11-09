// from server: 88% by atomic.potato
extern "C" void __stdcall sub_570790(void*, char*, void*, int);

struct RakPeer
{
    char pad0[0xa40];
    void f(char*, void*);
};

void RakPeer::f(char* a, void* b)
{
    if (a != 0 && a[0] != 0 && b != 0)
        sub_570790((char*)this + 0xa40, a, b, 0);
}
