// from server: 46% by atomic.potato
struct Vslot {
    char pad0[0x28];
    void* field28;
    bool check();
    int invoke();
};

struct Helper {
    bool method(void* arg);
};

extern "C" void* __cdecl sub_52ACB0();

int __cdecl sub_798700(Vslot* p)
{
    if (!p)
        return 0;
    void* f = p->field28;
    void* a = sub_52ACB0();
    if (!((Helper*)f)->method(a))
        return 0;
    if (!p)
        return 0;
    return p->invoke();
}
