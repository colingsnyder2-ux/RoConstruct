// from server: 63% by atomic.potato
extern "C" void* __cdecl fn_809f98(int);
extern "C" void __cdecl fn_5a3740(void*);

struct Creator
{
    void* pad[8];

    void __cdecl Create(void* arg);
};

void Creator::Create(void* arg)
{
    void** value = (void**)((char*)arg + 0x20);
    if (*value)
    {
        *value = fn_809f98((int)*value);
        fn_5a3740(*value);
        *value = 0;
    }
}
