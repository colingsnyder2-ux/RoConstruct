// from server: 28% by colin
struct RBX_ClumpStage {
    void sub_606C70(int);
    void sub_605D00(int);
    void sub_605C80(int);
    void sub_605670(int);
    void sub_6056F0(int);
    void sub_607B00(int);
    bool f();
};

extern "C" void __stdcall sub_587C30(int);
extern "C" void __stdcall sub_604800(int);
extern "C" void __stdcall sub_60BCA0(int, int);
extern "C" int __stdcall sub_5B4DC0(int);
extern "C" int __stdcall sub_5B4DE0(int, int);
extern "C" void __stdcall sub_5375C0(int, int, int, int, int, int);
extern "C" void __stdcall sub_5B3A60(int, int, int, int, int);
extern "C" void __stdcall sub_5E29B0(int, int, int);
extern "C" void __stdcall _invalid_parameter_noinfo();

bool RBX_ClumpStage::f() {
    if (*(int*)((char*)this + 0x58) == 0)
        return true;

    int* p54 = (int*)((char*)this + 0x54);
    int* p50 = (int*)((char*)this + 0x50);
    int v30 = *p54;
    int v2c = (int)p50;
    sub_587C30((int)&v2c);
    int ebx = v2c;
    if (ebx == 0)
        _invalid_parameter_noinfo();
    int edi = v30;
    if (edi == *(int*)(ebx + 4))
        _invalid_parameter_noinfo();
    edi = *(int*)(edi + 0xc);
    int edx = *(int*)(edi + 8);
    int eax = *(int*)(edx + 0x20);
    int ebp;
    if (eax != 0) {
        ebp = eax;
    } else {
        eax = *(int*)(edi + 0xc);
        ebp = *(int*)(eax + 0x20);
    }
    eax = *(int*)(ebp + 0x20);
    if (eax != 0) {
        sub_606C70(eax);
    }
    eax = *(int*)(edi + 8);
    int ebx2;
    if (*(int*)(eax + 0x20) == ebp) {
        ebx2 = *(int*)(edi + 0xc);
    } else {
        ebx2 = eax;
    }
    int v18;
    if (ebx2 == eax) {
        v18 = *(int*)(edi + 0xc);
    } else {
        v18 = eax;
    }
    sub_605D00(ebx2);
    int v38;
    sub_604800(*(int*)(ebp + 0x24));
    int v40;
    sub_604800(ebx2);
    if (*(unsigned char*)v40 != *(unsigned char*)v38) {
        if (*(unsigned char*)v40 != *(unsigned char*)v38) {
            goto fail;
        }
    } else {
        if (*(int*)(v40 + 4) < *(int*)(v38 + 4)) {
            goto fail;
        }
    }
    sub_60BCA0(v18, ebx2);
    int edi2 = sub_5B4DC0(ebx2);
    unsigned char v17 = 1;
    if (edi2 == 0)
        goto check;
    while (1) {
        eax = *(int*)(edi2 + 8);
        if (ebx2 == eax)
            eax = *(int*)(edi2 + 0xc);
        if (eax == v18) {
            sub_605C80(edi2);
            goto next;
        }
        eax = *(int*)(eax + 0x20);
        if (eax != 0) {
            if (eax == ebp) {
                sub_605C80(edi2);
            } else {
                sub_605C80(edi2);
                int v28 = 0;
                sub_5E29B0((int)((char*)this + 0x44), (int)&v28, (int)&edi2);
                v17 = 0;
            }
            goto next;
        }
        int ecx = *(int*)((char*)this + 0x60);
        eax = *(int*)(ecx + 4);
        int esi2 = (int)((char*)this + 0x5c);
        ebx = ecx;
        while (*(unsigned char*)(eax + 0x11) == 0) {
            if ((unsigned int)edi2 < *(unsigned int*)(eax + 0xc)) {
                ebx = eax;
                eax = *(int*)eax;
            } else {
                eax = *(int*)(eax + 8);
            }
        }
        ebp = ecx;
        eax = *(int*)(ebp + 4);
        while (*(unsigned char*)(eax + 0x11) == 0) {
            if (*(unsigned int*)(eax + 0xc) < (unsigned int)edi2) {
                eax = *(int*)(eax + 8);
            } else {
                ebp = eax;
                eax = *(int*)eax;
            }
        }
        int v28b = 0;
        sub_5375C0(esi2, ebp, esi2, ebx, (int)&v28b, (int)&v28b);
        sub_5B3A60(esi2, (int)&v28b, ebp, esi2, ebx);
        sub_605670(edi2);
        ebp = *(int*)((char*)this + 0x1c);
        esi2 = *(int*)((char*)this + 0x24);
        ebx2 = *(int*)((char*)this + 0x20);
    next:
        edi2 = sub_5B4DE0(ebx2, edi2);
        if (edi2 != 0)
            continue;
        if (v17 == 0)
            goto fail;
        break;
    }
check:
    if (*(int*)((char*)this + 0x58) != 0)
        return f();
    return true;
fail:
    sub_6056F0(ebx2);
    sub_607B00(ebp);
    return false;
}
