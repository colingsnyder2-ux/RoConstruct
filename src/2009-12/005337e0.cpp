// from server: 100% by atomic.potato
extern "C" void __cdecl sub_533780(void*, unsigned short);

void* sub_5337e0(void* a, void* b)
{
    unsigned short x = *(unsigned short*)b;
    sub_533780(a, x);
    x = *(unsigned short*)((char*)b + 2);
    sub_533780(a, x);
    return a;
}
