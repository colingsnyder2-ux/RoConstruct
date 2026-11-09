// from server: 47% by colin
struct std_string {
    void ctor(const std_string&);
    void dtor();
    char data[0x1c];
};

struct Backpack {
    char pad0[0xc];
    int field0c;
    int field10;
    int field14;
    int field18;
    void ctor(int, const std_string&);
};

extern "C" void __stdcall sub_564c50(int, int);
extern "C" void __stdcall sub_77e69c(int, int);
extern "C" void __stdcall sub_77e6ac(int);

void Backpack::ctor(int a1, const std_string& a2)
{
    int ebx;
    if (a1 != 0)
        ebx = a1 + 0x284;
    else
        ebx = 0;

    std_string local;
    local.ctor(a2);

    sub_564c50(ebx, (int)this);

    *(int*)this = 0x7a91fc;
    field0c = a1;
    field10 = a1;
    field14 = 0;
    field18 = 0;

    local.dtor();
}
