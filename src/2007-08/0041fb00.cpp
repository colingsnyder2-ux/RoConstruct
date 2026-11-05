// from server: 100% by colin
struct CSelectionTreeCtrl {
    int field0;
    int field4;
    void sub_41ED90();

    void sub_41FB00(int a, int b);
};

extern "C" int __stdcall sub_62FF02(int, int, int);

void CSelectionTreeCtrl::sub_41FB00(int a, int b) {
    int esi;
    if (b == 0) {
        esi = 0;
    } else {
        esi = *(int*)(b + 4);
    }
    int edx;
    if (a == 0) {
        edx = 0;
    } else {
        edx = *(int*)(a + 4);
    }
    int eax = *(int*)((char*)this + 4);
    int result = sub_62FF02(eax, edx, esi);
    int* p = *(int**)(result + 0x94);
    int ecx = *p;
    ((CSelectionTreeCtrl*)ecx)->sub_41ED90();
}
