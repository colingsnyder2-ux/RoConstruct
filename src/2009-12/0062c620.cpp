// from server: 80% by atomic.potato
extern "C" void* __cdecl sub_005dc670(void*);
extern "C" void __cdecl sub_0062bea0(void*);

int sub_0062c620(void* p)
{
    char buffer[136];
    void* value = sub_005dc670(buffer);
    int result = *(int*)((char*)value + 0x68);
    sub_0062bea0(buffer);
    return result;
}
