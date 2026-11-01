// from server: 100% by colin
struct S {
    char pad[0x14];
    void* field14;
    void init();
};

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

extern "C" void __cdecl sub_54d430();

void S::init()
{
    sub_54d430();
    field14 = g_77e4dc;
    field14 = g_77e4e0;
    g_77e4e4(&field14);
}
