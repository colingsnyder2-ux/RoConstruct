// from server: 100% by colin
struct CRobloxTreeCtrl {
    char pad[0x90];
    char field_90;
    int sub_62FCF2(void*);
    int func_00420370(void*);
};

int CRobloxTreeCtrl::func_00420370(void* arg)
{
    int* p = (int*)arg;
    p[8] = (p[8] & 0xffffffef) | 0x2d;
    if (sub_62FCF2(arg) == 0)
        return 0;
    field_90 = 0;
    return 1;
}
