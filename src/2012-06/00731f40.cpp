// from server: 31% by Intel
struct std_string {
    void* _Myptr;
    unsigned int _Mysize;
    unsigned int _Myres;
    std_string() {}
    std_string(const std_string&) {}
    ~std_string() {}
};

struct BoundFuncDesc {
    int field_30;
    int field_34;
    int field_38;
    std_string field_3C;
};

extern "C" void __stdcall sub_533B80(int, std_string*, int);
extern "C" void __stdcall sub_533590(int, int*, int, int*);
extern "C" void __stdcall func_B22644(int);
extern "C" void __stdcall func_B2263C(int*);

int __stdcall BoundFuncDesc_method(BoundFuncDesc* this_ptr, int a2, int a3) {
    int v_esi_30 = this_ptr->field_30;
    int v_esi_34 = this_ptr->field_34;
    int v_edi = a2;
    int v_ebx = 0;

    sub_533B80(0, &this_ptr->field_3C, v_edi);
    int local_1C[7];
    sub_533590(0, &this_ptr->field_38, v_edi, local_1C);

    int v_ecx = local_1C[0];
    if (v_ecx == 0) {
        v_ebx = v_ecx - 0x1C;
    }

    int v_ecx2 = local_1C[1];
    func_B22644(v_ecx2);

    int v_call_ecx = v_ebx + v_esi_34;
    typedef void (__thiscall *FuncPtr)(int);
    FuncPtr func = (FuncPtr)v_esi_30;
    func(v_call_ecx);

    int* v_cleanup_ecx = &local_1C[3];
    func_B2263C(v_cleanup_ecx);

    return 0;
}
