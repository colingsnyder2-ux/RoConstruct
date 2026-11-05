// from server: 26% by atomic.potato
struct JointsService
{
    void __cdecl f(void*);
};

extern "C" void* sub_0080A05E(unsigned int);
extern "C" void sub_004FE210(void*, void*, void*);

struct ManualGlue
{
    char pad0[0x90];
    void* field90;
    void* init(void*);
};

void* ManualGlue::init(void* a)
{
    return 0;
}

void JointsService::f(void* a)
{
    void* p = sub_0080A05E(0xb8);
    void* q;
    if (p)
        q = ((ManualGlue*)p)->init(a);
    else
        q = 0;
    sub_004FE210(this, q, 0);
}
