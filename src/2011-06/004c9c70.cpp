// from server: 66% by atomic.potato
typedef unsigned long DWORD;

struct VBitStream
{
    int f();
    DWORD pad[119];
};

struct GlobalObject
{
    DWORD vtable;
};

extern GlobalObject* g_object;

int VBitStream::f()
{
    DWORD value = pad[118];
    if (value)
    {
        DWORD* table = (DWORD*)g_object->vtable;
        return ((int (__thiscall *)(DWORD))table[2])(value + 0x1c);
    }
    return 0;
}
