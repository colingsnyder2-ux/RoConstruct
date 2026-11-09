// from server: 85% by atomic.potato
typedef unsigned short word;

extern "C" void __cdecl sub_532f10(void*, void*);
extern "C" void __cdecl sub_532d00(void*, void*);

void* __cdecl sub_533b50(void* a, void* b)
{
    word w;
    sub_532f10(a, b);
    sub_532d00(a, &w);
    *(word*)((char*)b + 4) = w;
    b = (char*)b + 8;
    sub_532f10(a, b);
    sub_532d00(a, &w);
    *(word*)((char*)b + 4) = w;
    return a;
}
