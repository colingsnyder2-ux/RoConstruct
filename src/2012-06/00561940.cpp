// from server: 92% by Intel
struct RBX_VHint_FactoryProduct_Creator {
    int func_00561940();
};

int RBX_VHint_FactoryProduct_Creator::func_00561940() {
    int eax = (*(short*)this == 2) ? 0 : 1;
    eax = eax + eax + 4;
    return eax;
}
