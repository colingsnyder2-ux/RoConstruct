// from server: 100% by colin
extern "C" void* __cdecl sub_500010(unsigned int size);
extern "C" void __cdecl sub_500580(void* ptr, int value, unsigned int size);

void* __cdecl sub_500670(unsigned int count, unsigned int size)
{
    unsigned int total = count * size;
    void* p = sub_500010(total);
    sub_500580(p, 0, total);
    return p;
}
