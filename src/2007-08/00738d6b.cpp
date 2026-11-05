// from server: 87% by colin
extern "C" int __cdecl sub_0062ff02();

extern "C" void __stdcall sub_0077e768(int);

struct CSpinButtonCtrl {
    char set(int, int);
};

char CSpinButtonCtrl::set(int a, int b) {
    int* p = (int*)sub_0062ff02();
    *(char*)((char*)p + 0x14) = (char)a;
    *(int*)((char*)p + 0x44) = b;
    if (a == 0) {
        sub_0077e768(-3);
    }
    return 1;
}
