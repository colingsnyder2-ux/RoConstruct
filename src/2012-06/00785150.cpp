// from server: 59% by Intel
struct EnumDesc {
    unsigned int field_2C;
    char pad_30[96];
    int* field_90;

    bool func_785150(int arg0, int* outPtr1, int* outPtr2);
};

extern "C" void __cdecl sub_4015a0(int, int);
extern "C" int __cdecl sub_771460();
extern "C" void __cdecl sub_76FBE0(int*, int*);

bool EnumDesc::func_785150(int arg0, int* outPtr1, int* outPtr2) {
    int eax = arg0;
    if (eax < this->field_2C) {
        goto LABEL_FAIL;
    }
    int* ecx = this->field_90;
    int edx = ecx[eax];
    outPtr2[0] = edx;
    bool bl = true;
    goto LABEL_CONTINUE;

LABEL_FAIL:
    bl = false;

LABEL_CONTINUE:
    sub_4015a0(0x7714C0, 0xE48630);
    int eax_ret = sub_771460();
    *outPtr1 = eax_ret;
    sub_76FBE0(outPtr1 + 1, outPtr2);
    return bl;
}
