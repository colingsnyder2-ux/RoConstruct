// from server: 39% by colin
struct MarshaledListener
{
    void init();
};

static char g_initGuard;

extern "C" void* __cdecl sub_418690(const char* name);
extern "C" void __cdecl sub_630D23(void* arg);

struct Sub570C00
{
    void method(void* arg);
};

void MarshaledListener::init()
{
    if (!(g_initGuard & 1))
    {
        g_initGuard |= 1;
        void* p = sub_418690("Stats");
        ((Sub570C00*)0x8bbf18)->method(p);
        sub_630D23((void*)0x777e10);
    }
}
