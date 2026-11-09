// from server: 79% by atomic.potato
struct S_func_0081dc40 {
};

void __cdecl f(void* a, void* b, void (*fn)(void*))
{
    char* esi = (char*)a;
    char* edi = (char*)b;
    if (esi == edi)
        return;
    do {
        void* arg;
        if (esi != 0)
            arg = esi - 0x34;
        else
            arg = 0;
        fn(arg);
        esi = *(char**)esi;
    } while (esi != edi);
}
