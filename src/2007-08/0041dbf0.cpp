// from server: 50% by colin
struct CInstanceExplorer {
    void func_0041dbf0(int, int, int, int, int);
};

extern "C" int __stdcall sub_00663c50(int);
extern "C" int __stdcall sub_00661700(int, int);
extern "C" int __stdcall sub_00661880(int, int);
extern "C" void __stdcall sub_0041da00(int);

void CInstanceExplorer::func_0041dbf0(int a1, int a2, int a3, int a4, int a5)
{
    char *base = (char *)this - 0x2e8;
    int v1 = *(int *)(base + 0x18c);
    int v2 = (*(int (__thiscall **)(char *))v1)(base);
    int v3 = *(int *)(v2 + 0xa8);
    int v4 = sub_00663c50(v3);
    int v5 = v4 - 1;
    if (v5 >= 0) {
        do {
            int v6 = sub_00661700(v3, v5);
            if (*(int *)(v6 + 0x54) == a4)
                break;
            v5--;
        } while (v5 >= 0);
        if (v5 >= 0)
            sub_00661880(v3, v5);
    }
    if (*(char *)(base + 0x30c) == 0) {
        int v7 = *(int *)base;
        int v8 = *(int *)(v7 + 0x18c);
        int v9 = (*(int (__thiscall **)(char *))v8)(base);
        int v10 = *(int *)v9;
        int v11 = *(int *)(v10 + 0x150);
        (*(void (__thiscall **)(int))v11)(v9);
    }
    sub_0041da00((int)&a1);
}
