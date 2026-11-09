// from server: 37% by colin
struct RakPeer {
    char pad0[0x22c];
    void* field_22c;
    char pad230[0x6d0 - 0x230];
    void* field_6d0;
    char pad6d4[0x6dc - 0x6d4];
    int field_6dc;

    bool method(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

struct Local {
    char pad0[0x18];
    int field_18;
    char pad1c[0x20 - 0x1c];
    int field_20;
    char pad24[0x34 - 0x24];
    int field_34;
};

extern "C" void __stdcall sub_49F850(void* p);
extern "C" void __stdcall sub_49F930(void* p);
extern "C" void __stdcall sub_4C4160(void* a, int b, int c, void* d);
extern "C" void __stdcall sub_4C7450(void* a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern "C" int __stdcall sub_6311B0(int a, int b, int c, int d);
extern "C" void __stdcall sub_630A1E();

bool RakPeer::method(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    Local local;
    char flag = 0;
    int esi = 0;

    if (this->field_6d0 != 0) {
        sub_49F850(&local);
        local.field_34 = 0;
        sub_4C4160(this->field_6d0, 0, a2, &local);
        int ecx = local.field_34;
        int eax = local.field_20;
        int edx = (ecx + 7) >> 3;
        this->field_6dc += edx;
        esi = *(int*)(eax + local.field_18 * 4);
        eax = (int)this->field_22c;
        esi *= 0x840;
        edx = *(int*)(eax + esi + 0x834);
        sub_4C7450((void*)(eax + esi + 0x18), ecx, a2, a3, a4, a5, 1, edx, a6, a7, a8);
        local.field_34 = -1;
        sub_49F930(&local);
    } else {
        if (a9 != 0 && local.field_34 == 0) {
            if (local.field_18 + 1 == local.field_20) {
                flag = 1;
            }
        }
        int eax = local.field_20;
        int ecx = local.field_18;
        esi = *(int*)(eax + ecx * 4);
        int edx = (int)this->field_22c;
        esi *= 0x840;
        ecx = a8;
        int tmp = *(int*)(esi + edx + 0x834);
        eax = esi + edx;
        edx = a7;
        sub_4C7450((void*)(eax + 0x18), local.field_34, a2, a3, a4, a5, (flag == 0), tmp, edx, ecx, a6);
        if (flag) {
            local.field_34 = 1;
        }
    }

    if (a4 == 2 || a4 == 3 || a4 == 4) {
        int r = sub_6311B0(a7, a8, 0x3e8, 0);
        *(int*)(esi + (int)this->field_22c + 0x808) = r;
    }

    return flag;
}
