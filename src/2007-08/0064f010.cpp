// from server: 100% by colin
struct CXTPToolBar
{
    char pad[0x130];
    int field_130;
    char pad2[0x188 - 0x134];
    int field_188;
    int field_18c;
    void sub_643b00(void*, int);
    void func_0064f010(void* param1, int param2);
};

void CXTPToolBar::func_0064f010(void* param1, int param2)
{
    sub_643b00(param1, param2);
    field_188 = *(int*)((char*)param1 + 0x188);
    field_18c = *(int*)((char*)param1 + 0x18c);
    field_130 = *(int*)((char*)param1 + 0x130);
}
