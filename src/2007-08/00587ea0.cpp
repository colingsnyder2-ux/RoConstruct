// from server: 100% by colin
struct Inner {
    void* ptr;
};

struct Outer {
    char pad[0x20];
    Inner* inner;
};

extern "C" void __stdcall sub_0062fc08(void* p);

void __cdecl sub_00587ea0(Outer* obj)
{
    Inner* in = obj->inner;
    void* p = in->ptr;
    if (p != 0) {
        sub_0062fc08(p);
        in->ptr = 0;
    }
}
