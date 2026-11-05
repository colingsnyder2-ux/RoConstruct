// from server: 35% by colin
struct LDraw2RobloxMapRoot {
    void* vtable;
    char pad[0x54];
    int field58;
    int field60;
    int field64;
    int field68;
    void construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v);
};

extern "C" {
    void __stdcall sub_77E69C(void*);
    void __stdcall sub_77E6AC(void*);
}

void LDraw2RobloxMapRoot::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v)
{
    char buf1[0x1c];
    char buf2[0x1c];
    char buf3[0x1c];

    this->vtable = (void*)0x7961a0;

    sub_77E69C(buf1);
    sub_77E69C(buf2);
    sub_77E69C(buf3);

    this->field58 = v;
    this->field60 = 0;
    this->field64 = 0;
    this->field68 = 0;

    sub_77E6AC(buf1);
    sub_77E6AC(buf2);
    sub_77E6AC(buf3);
}
