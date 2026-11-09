// from server: 100% by atomic.potato
struct VSpecialShape {
    void *vtbl0;
    void *vtbl4;
    char pad[0x10];
    void *vtbl18;
    void *vtbl1c;
    void destroy();
    VSpecialShape *release(int);
};

extern "C" void __cdecl sub_6dfb50();
extern "C" void __cdecl sub_7f385a(void *);

VSpecialShape *VSpecialShape::release(int flag)
{
    vtbl0 = (void*)0x9da474;
    vtbl4 = (void*)0x9da468;
    vtbl18 = (void*)0x9da45c;
    vtbl1c = (void*)0x9da454;
    sub_6dfb50();
    if (flag & 1) {
        sub_7f385a(this);
    }
    return this;
}
