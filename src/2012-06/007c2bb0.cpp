// from server: 78% by atomic.potato
typedef unsigned char byte;

extern byte g_00e31abe;

struct Inner
{
    byte method();
};

struct S
{
    byte pad[0x84];
    Inner* p;
    byte f();
};

byte S::f()
{
    if (g_00e31abe)
        return 1;
    Inner* q = p;
    void* v = *(void**)q;
    return ((byte (__thiscall*)(void*))0x464d90)((char*)v + (int)this + 0x84);
}
