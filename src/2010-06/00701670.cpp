// from server: 27% by atomic.potato
typedef unsigned char byte;

extern "C" void __stdcall sub_00700010(void*, void*);

struct EventDesc
{
    void __stdcall f(void* a, void* b);
};

void __stdcall EventDesc::f(void* a, void* b)
{
    if (a)
    {
        void* ecx = *(void**)((char*)a + 0x38);
        int eax = *(int*)((char*)a + 0x38 - 0x1c);
        ((byte*)a)[4] = 0;
        ((byte*)a)[5] = 0;
        *(int*)a = 0x00BE0120;
        sub_00700010(ecx, b);
        return;
    }

    void* ecx = *(void**)((char*)a + 0x38);
    *(int*)a = 0;
    sub_00700010(ecx, b);
}
