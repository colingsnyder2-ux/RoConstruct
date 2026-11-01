// from server: 85% by atomic.potato
struct Backpack {
    void* scriptShouldRun(void* script);
};

extern "C" void* __cdecl sub_48E0D0(void*);
extern "C" int __cdecl sub_4915F0(void*, int);
extern "C" void* __cdecl sub_495820(void*);
extern "C" void* __cdecl sub_630D36(void*, int, void*, void*, int);

void* Backpack::scriptShouldRun(void* script)
{
    char* self = (char*)this - 0x120;
    void* v = sub_48E0D0(self);
    if (!v)
        return 0;

    void* a = *(void**)((char*)this - 0x64);
    void* b = sub_495820(self);
    bool flag1 = (a == b);

    sub_4915F0(self, 1);

    void* r1 = sub_630D36(script, 0, (void*)0x884F70, (void*)0x89A7CC, 0);
    bool flag2 = (r1 != 0);

    void* inner = *(void**)((char*)script + 0xbc);
    void* r2 = sub_630D36(inner, 0, (void*)0x881F4C, (void*)0x89F650, 0);
    bool flag3 = (r2 != 0);

    if (flag2) {
        if (!flag1)
            return 0;
    } else {
        if (flag3 && flag1)
            return (void*)((char*)v + 0x2d0);
        if (!flag1)
            return 0;
    }

    return (void*)((char*)v + 0x2d0);
}
