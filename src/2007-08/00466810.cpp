// from server: 75% by colin
struct CWebToolbox {
    char pad[0xf4];
    void* fieldF4;
    void method(int arg);
};

extern void __cdecl sub_00630A06(int arg);
extern void __cdecl sub_00630004(void* p);

void CWebToolbox::method(int arg)
{
    sub_00630A06(arg);
    if (fieldF4 != 0)
        sub_00630004(fieldF4);
}
