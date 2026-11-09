// from server: 37% by Intel
struct W4_D3DDEVTYPE_EnumDesc {
    int get(int, int*, int*);
};

extern "C" int __stdcall sub_96E630();
extern "C" void __stdcall sub_96C5B0(int*, int*);

int W4_D3DDEVTYPE_EnumDesc::get(int index, int* out1, int* out2) {
    if (index >= *(int*)((char*)this + 0x2C)) {
        sub_96E630();
        *out1 = 0;
        sub_96C5B0(out1 + 1, out2);
        return 0;
    }
    int val = *(int*)(*(int*)((char*)this + 0x90) + index * 4);
    *out1 = val;
    sub_96E630();
    *out2 = val;
    sub_96C5B0(out1 + 1, out2);
    return 1;
}
