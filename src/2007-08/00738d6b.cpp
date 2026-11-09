// from server: 100% by Intel
// roc-cl: 50727
// roc-flags: /O1 /GS /EHsc /MD
extern "C" int __cdecl sub_0062ff02();

extern "C" __declspec(dllimport) void __cdecl SetLastError(unsigned int);

struct CSpinButtonCtrl {
    int set(int, int);
};

int CSpinButtonCtrl::set(int a, int b) {
    int* p = (int*)sub_0062ff02();
    *(char*)((char*)p + 0x14) = (char)a;
    *(int*)((char*)p + 0x44) = b;
    if (a == 0) {
        SetLastError((unsigned)-3);
    }
    return 1;
}
