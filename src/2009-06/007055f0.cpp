// from server: 100% by tester
struct S {
    void* vfptr;
    int pad[2];
    int field_c;
    S* init();
};

extern "C" void (__stdcall *sub_77e6f8)();
extern void* sub_78527c;

S* S::init()
{
    sub_77e6f8();
    field_c = 0;
    vfptr = &sub_78527c;
    return this;
}
