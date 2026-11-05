// from server: 44% by atomic.potato




struct S {
    char pad0[0x1d0];
    char pad1[0x10];
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    char pad2[0xc];
    int f1fc;
    char pad3[0x2c];
    char f22c;
    char pad4[3];
    int f230;
    char f234;
    char pad5[3];
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    char pad6[0x4];
    char f24c[4];
    char f250[4];
    char f254[4];
    char f258[4];
    S* ctor();
};

extern "C" void __stdcall sub_633b30();
extern "C" void __stdcall sub_784b90();
extern "C" void __stdcall sub_541890();
extern "C" void __stdcall sub_4ad120();
extern "C" void __stdcall sub_4ad1b0();
extern "C" void __stdcall sub_598250();

extern "C" void __stdcall string_ctor(void*, const char*);
extern "C" void __stdcall string_dtor(void*);

extern char byte_ccc3a9;

S* S::ctor() {
    sub_633b30();
    *(int*)((char*)this + 0) = 0xa968e4;
    *(int*)((char*)this + 4) = 0xa968dc;
    *(int*)((char*)this + 0x18) = 0xa968d0;
    *(int*)((char*)this + 0x1c) = 0xa968c4;
    *(int*)((char*)this + 0x90) = 0xa968bc;
    sub_784b90();
    *(int*)((char*)this + 0x1e0) = -1;
    *(int*)((char*)this + 0x1e4) = -1;
    *(int*)((char*)this + 0x1e8) = -1;
    *(int*)((char*)this + 0x1ec) = 0;
    *(int*)((char*)this + 0) = 0xa96aa4;
    *(int*)((char*)this + 4) = 0xa96a98;
    *(int*)((char*)this + 0x18) = 0xa96a8c;
    *(int*)((char*)this + 0x1c) = 0xa96a80;
    *(int*)((char*)this + 0x90) = 0xa96a78;
    *(int*)((char*)this + 0x1d0) = 0xa96a70;
    *(int*)((char*)this + 0x1dc) = 0xa96a48;
    *(int*)((char*)this + 0x1f0) = 0xa96a40;
    *(int*)((char*)this + 0x1f4) = 0;
    *(int*)((char*)this + 0x1f8) = 0;
    sub_541890();
    *(char*)((char*)this + 0x22c) = 1;
    *(int*)((char*)this + 0x230) = 0;
    *(char*)((char*)this + 0x234) = byte_ccc3a9;
    *(int*)((char*)this + 0x238) = 0;
    *(int*)((char*)this + 0x23c) = 0;
    *(int*)((char*)this + 0x240) = 0;
    *(int*)((char*)this + 0x244) = 0;
    *(int*)((char*)this + 0x248) = 0;
    sub_4ad120();
    sub_4ad1b0();
    sub_4ad1b0();
    sub_4ad1b0();
    {
        char buf[16];
        string_ctor(buf, (const char*)0xa962ec);
        sub_598250();
        string_dtor(buf);
    }
    return this;
}
