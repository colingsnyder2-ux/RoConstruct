// from server: 57% by atomic.potato
extern "C" void __stdcall func_009824da(int, int, int, int);
extern "C" void __stdcall func_009826de();

struct CMultiPlayerPane {
    int func_00448c70(int);
};

int CMultiPlayerPane::func_00448c70(int a1)
{
    if (a1 == 1) {
        goto loc_448c96;
    }
    if (*((int*)this + 0x15)) {
        int v2 = *(&a1 + 3);
        int v3 = *(&a1 + 2);
        func_009824da(v3, v2, 0, 0);
    }
loc_448c96:
    func_009826de();
    return 0;
}
