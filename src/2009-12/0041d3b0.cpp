// from server: 100% by atomic.potato
struct CRobloxTreeCtrl {
    char pad[0x90];
    char flag90;
    int sub_7f38e4(void*);
    int func(void*);
};

int CRobloxTreeCtrl::func(void* a) {
    int* p = (int*)a;
    p[8] = (p[8] & 0xffffffef) | 0x2d;
    if (sub_7f38e4(a) == 0) {
        return 0;
    }
    flag90 = 0;
    return 1;
}
