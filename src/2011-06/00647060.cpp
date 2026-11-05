// from server: 80% by atomic.potato
// roc 2011-06 00647060  unit: RBX::VPlayerGui::?$FactoryProduct  size: 170 bytes

extern "C" {
    void __stdcall sub_00A404C4();
    void __stdcall sub_00A404D0();
}

struct String {
    char pad[0x1c];
    String(const char*);
    ~String();
};

struct Base {
    char pad[0x90];
    void sub_00646EB0();
    void sub_00598250(String*);
};

struct S : Base {
    char pad2[0x0c];
    char f0xa0;
    char f0xa1;
    S();
};

S::S()
{
    sub_00646EB0();
    f0xa0 = 1;
    String s("StarterGui");
    *(void**)this = (void*)0xa98874;
    *(void**)((char*)this + 4) = (void*)0xa98868;
    *(void**)((char*)this + 0x18) = (void*)0xa9885c;
    *(void**)((char*)this + 0x1c) = (void*)0xa98850;
    *(void**)((char*)this + 0x90) = (void*)0xa98848;
    *(void**)((char*)this + 0x94) = (void*)0xa98840;
    f0xa1 = 1;
    sub_00A404C4();
    sub_00598250(&s);
    sub_00A404D0();
}
