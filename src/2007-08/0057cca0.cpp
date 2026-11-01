// from server: 100% by colin
struct RBX_Workspace {
    char pad[0xac];
    void sub_00558b60(int);
    void sub_0057cca0();
};

void RBX_Workspace::sub_0057cca0()
{
    char flag = 0;
    ((RBX_Workspace*)((char*)this + 0xac))->sub_00558b60(*(int*)&flag);
}
