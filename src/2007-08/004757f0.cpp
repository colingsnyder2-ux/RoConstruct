// from server: 100% by colin
struct CInstanceRecord_CNameItem {
    char pad[0x30];
    int field30;
    int field34;
    char pad2[0x38];
    int field70;
    char pad3[4];
    int field78;
    char pad4[0x94];
    unsigned char field110;
    void sub_475470();
    void sub_474c30(int, int);
    void method();
};

extern "C" void (__stdcall *glEnd)();

void CInstanceRecord_CNameItem::method()
{
    int v = field34;
    field78 += v;
    field70 += v;
    sub_474c30(field30, v);
    glEnd();
    field110 = 0;
    sub_475470();
}
