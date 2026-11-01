// from server: 100% by tester
struct Workspace {
    char pad[0x344];
    int field_2d4;
    void sub_0053e2a0(int, int);
    void sub_00558b60(int);
    void sub_0057bfa0(int, int);
};

void Workspace::sub_0057bfa0(int a, int b)
{
    sub_0053e2a0(a, b);
    char flag = 0;
    ((Workspace*)((char*)this + 0x344))->sub_00558b60(*(int*)&flag);
}
