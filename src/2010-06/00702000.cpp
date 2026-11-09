// from server: 100% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl sub_006FFF20(void*, void*, int);

struct EventDesc
{
    void __cdecl f(void*, int);
};

void __cdecl EventDesc::f(void* value, int type)
{
    if (type != 4)
    {
        sub_006FFF20(this, value, type);
        return;
    }

    *(int*)value = 0x00BE0120;
    ((byte*)value)[4] = 0;
    ((byte*)value)[5] = 0;
}
