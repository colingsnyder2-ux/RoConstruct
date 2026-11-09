// from server: 34% by colin
struct StandardOutMessage {
    int type;
    int pad;
    char data[0x20];
};

struct StandardOut {
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    char string14[0x1C];
    int field30;
    int field34;

    StandardOut(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

extern "C" void __stdcall string_copy_ctor(void* dest, const void* src);
extern "C" void __stdcall string_dtor(void* self);
extern "C" void __stdcall sub_4378F0(StandardOut* self, int arg);

StandardOut::StandardOut(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    vtable = (void*)0x78ce10;
    field4 = 0;
    field8 = 0;
    fieldC = a;
    field10 = b;
    string_copy_ctor(string14, &c);
    field30 = d;
    field34 = e;
    sub_4378F0(this, f);
    string_dtor(string14);
}
