// from server: 100% by tester
struct CRobloxTreeCtrl
{
    char pad[0xa4];
    char field_a4;
    char pad2[44];
    char field_c9;
    char pad3[0x1a];
    int field_e4;
    void sub_420780(void*, int);
    void sub_4208e0(void*, void*);
};

void CRobloxTreeCtrl::sub_4208e0(void* arg1, void* arg2)
{
    *(int*)arg2 = 0;
    if (field_c9 != 0)
        return;
    if (field_a4 != 0)
        return;
    if (field_e4 == 0)
        return;
    if (*(int*)((char*)arg1 + 0x3c) != 0)
        sub_420780((char*)arg1 + 0x38, 1);
    if (*(int*)((char*)arg1 + 0x14) != 0)
    {
        if (*(int*)((char*)arg1 + 0xc) != 0)
            sub_420780((char*)arg1 + 0x10, 0);
    }
}
