// from server: 100% by colin
struct DescribedBase;

struct ClassDescriptor
{
    char pad[0x138];
    void* field138;
};

struct Target
{
    void* field160;
};

extern "C" void* __fastcall sub_40e590(void*);
extern "C" void* __cdecl sub_486830(void*);
extern "C" double __cdecl sub_4fff30();

void func_0048e550(void* arg)
{
    void* p = sub_40e590(arg);
    if (p)
    {
        void* q = *(void**)((char*)p + 0x138);
        if (q)
        {
            void* r = sub_486830(q);
            if (r)
            {
                double d = sub_4fff30();
                *(double*)((char*)q + 0x160) = d;
            }
        }
    }
}
