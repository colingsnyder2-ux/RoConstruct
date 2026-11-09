// from server: 34% by atomic.potato
struct Inner {
    char pad0[0xc];
    char str[0x20];
};

struct Outer {
    char pad0[8];
    int field8;
    Inner inner;
};

extern "C" void __stdcall string_copy_ctor(void* dst, const void* src);

struct VInstance {
    void func(Outer* p);
};

extern "C" void __stdcall sub_6bd250(void* self, int arg);

void VInstance::func(Outer* p)
{
    Inner* in = &p->inner;
    char buf[0x20];
    string_copy_ctor(buf, in->str);
    *(int*)(buf + 0x1c) = *(int*)(in->str + 0x1c);
    sub_6bd250(this, p->field8);
}
