// from server: 47% by colin
// roc 2007-08 0070d990  unit: CXTColorLum  size: 308 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070d990

extern "C" {
    int __stdcall GetParent(int);
    int __cdecl sub_6301c0(int);
    int __cdecl sub_63026e(int);
    int __cdecl sub_70d210(int);
    int __cdecl sub_738ce8(int, int);
}

extern int dword_8C9750;
extern int (__stdcall *dword_77EBF8)(int);

struct CXTColorLum {
    int field_0;
    char pad_4[0x1C];
    int field_20;
    char pad_24[0x5C];
    int field_80;
    int field_84;
    int OnKeyDown(int);
};

int CXTColorLum::OnKeyDown(int param) {
    int local_8;
    int local_4;

    if (dword_8C9750 != 2) {
        sub_63026e(param);
        return 0;
    }

    sub_70d210((int)&local_8);

    if (*(int*)(param + 4) != 0x100) {
        sub_63026e(param);
        return 0;
    }

    {
        int key = *(signed char*)(param + 8) - 0x0D;
        if ((unsigned)key > 0x1B) {
            sub_63026e(param);
            return 0;
        }

        switch (key) {
        case 0:
            this->field_84 -= 1;
            if (this->field_84 < 0) {
                this->field_84 = 0;
            }
            {
                int v = this->field_84;
                int w = this->field_80;
                int vt = *(int*)this;
                int fn = *(int*)(vt + 0x14C);
                typedef int (__thiscall *Fn)(CXTColorLum*, int, int, int);
                ((Fn)fn)(this, w, v, 1);
            }
            return 1;

        case 1:
            this->field_84 += 1;
            if (this->field_84 > local_4) {
                this->field_84 = local_4;
            }
            {
                int v = this->field_84;
                int w = this->field_80;
                int vt = *(int*)this;
                int fn = *(int*)(vt + 0x14C);
                typedef int (__thiscall *Fn)(CXTColorLum*, int, int, int);
                ((Fn)fn)(this, w, v, 1);
            }
            return 1;

        case 2:
            {
                int p1 = dword_77EBF8(this->field_20);
                int p2 = sub_6301c0(p1);
                int p3 = *(int*)(p2 + 0x20);
                int p4 = dword_77EBF8(p3);
                int p5 = sub_6301c0(p4);
                sub_738ce8(p5, 1);
            }
            break;

        default:
            break;
        }
    }

    sub_63026e(param);
    return 0;
}
