// from server: 60% by atomic.potato
extern "C" void* __cdecl sub_7f4aaa(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_6e5270(void*);

void* sub_6e55b0(void* arg)
{
    void* result;

    if (arg == 0)
        return 0;

    result = sub_7f4aaa(arg, 0, (void*)0xaffe40, (void*)0xb0ab40, 0);
    if (result == 0)
        return 0;

    return sub_6e5270(result);
}
