// from server: 31% by colin
struct CSelectionPropGrid;

extern "C" {
    int __stdcall sub_4397D0(int);
    int __stdcall sub_438E10(int, int);
    int __stdcall sub_699000(int);
    int __stdcall sub_699320(int, int, int);
    int __stdcall sub_4339D0(int, int);
    int __stdcall sub_464EC0(int, int);
    int __stdcall sub_77DD98();
    int __stdcall sub_77DCB8(int, int);
    int __stdcall sub_77DDBC(int);
}

struct CSelectionPropGrid {
    char pad[0x19c];
    int field_19c;
    int field_18c;
    void func(int);
};

void CSelectionPropGrid::func(int arg) {
    int local14;
    int local18;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;
    int local30;
    int local34;
    int local38;
    int i;
    int count;
    int obj;
    int other;
    int cmp;

    obj = sub_4397D0(*(int*)(arg + 0x12c));
    local14 = obj;
    count = *(int*)(*(int*)(obj + 0xb8) + 0x28);
    i = 0;
    if (count > 0) {
        do {
            other = sub_699000(i);
            sub_438E10(other, (int)&local1c);
            local20 = 0;
            sub_438E10(arg, (int)&local18);
            local2c = 1;
            cmp = sub_77DCB8(sub_77DD98(), local18);
            local2c = -1;
            sub_77DDBC((int)&local18);
            sub_77DDBC((int)&local1c);
            if (cmp < 0) break;
            i++;
        } while (i < *(int*)(*(int*)(local14 + 0xb8) + 0x28));
    }
    sub_699320(local14, i, arg);
    local34 = *(int*)(arg + 0x12c);
    sub_4339D0((int)&field_19c, (int)&local34);
    local38 = arg + 0x114;
    *(int*)(sub_4339D0((int)&field_19c, (int)&local34)) = arg + 0x114;
    sub_464EC0((int)&field_18c, (int)&local38);
}
