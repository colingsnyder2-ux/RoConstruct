// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7aae30(void*, void*);
extern "C" void __cdecl sub_80a058(void*);

struct S
{
};

void __cdecl f(void* p)
{
    if (p)
    {
        sub_7aae30(p, *(void**)((char*)p + 0x0c));
        sub_80a058(p);
    }
}
