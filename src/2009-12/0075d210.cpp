// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_6966f0(void*);

struct S
{
    int f(void*);
};

int S::f(void* arg)
{
    void* p = sub_6966f0(arg);
    void* q = *(void**)((char*)p + 0x140);
    return *(int*)((char*)q + 0xd0);
}
