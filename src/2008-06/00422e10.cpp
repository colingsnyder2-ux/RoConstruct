// from server: 100% by colin
struct CRobloxTreeCtrl {
    char pad[0x90];
    char field_90;
    int sub_6a070a(void*);
    int func(void*);
};

int CRobloxTreeCtrl::func(void* arg) {
    int* p = (int*)arg;
    p[8] = (p[8] & 0xffffffef) | 0x2d;
    if (sub_6a070a(arg) == 0)
        return 0;
    field_90 = 0;
    return 1;
}
