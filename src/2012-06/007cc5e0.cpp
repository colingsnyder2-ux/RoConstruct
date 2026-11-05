// from server: 26% by Intel
struct RBX_MegaCluster {
    char padding0[0x324];
    unsigned short val1;
    char padding1[2];
    unsigned short val2;
    char padding2[2];
    unsigned short val3;
    char padding3[1];

    int f();
};

extern "C" int __stdcall func_b226c(void*, int, int);
extern "C" int __stdcall func_972290(void*, int, void*, int, int);
extern "C" int __stdcall func_07cb930(void*, int, int);

int RBX_MegaCluster::f() {
    unsigned int ebx, esi, edi, eax, edx;
    unsigned short v1, v2, v3;
    unsigned char b1, b2, b3;
    unsigned int stack_var[13];

    ebx = *(unsigned int*)((char*)this + 8);

    eax = *(unsigned short*)((char*)this + 0x324);
    edx = (int)eax & 0x1f;
    eax += edx;
    esi = eax;

    eax = *(unsigned short*)((char*)this + 0x326);
    edx = (int)eax & 0xf;
    eax += edx;
    edi = eax;

    eax = *(unsigned short*)((char*)this + 0x328);
    edx = (int)eax & 0x1f;
    eax += edx;
    eax >>= 5;
    stack_var[10] = (unsigned short)eax;

    stack_var[6] = (unsigned int)(stack_var + 0x1c);
    stack_var[4] = esi;
    stack_var[2] = edi;

    eax = ebx;
    esi >>= 5;
    edi >>= 4;
    func_b226c((void*)eax, (int)esi, (int)edi);

    eax = *(unsigned int*)((char*)ebx + 0x14);
    edx = *(unsigned int*)((char*)eax + 4);
    stack_var[13] = eax;
    stack_var[14] = edx;

    if (edx != 0) {
        b1 = *(unsigned char*)((char*)this + 0xe8b3);
        if (b1 == 0) {
            eax = *(unsigned int*)((char*)this + 0xe89c);
            if (eax != 0) {
                func_972290((void*)eax, 0x4f5, (void*)0xbbcb, 0xbb0, 0x4a);
            } else {
                b2 = *(unsigned char*)((char*)this + 0xe8b3);
                func_972290((void*)ebx, 0x410, (void*)0xbe41, 0x10e, 0xb0);
            }
        }
    } else {
        edx = (unsigned int)esi;
        eax = *(unsigned int*)this;
        stack_var[1] = eax;
        stack_var[3] = edx;
        if (edx <= 0) {
            edi = (unsigned int)edi;
            stack_var[5] = edi;
            ebx = 0;
            if (edi != 0) {
                v3 = (unsigned short)stack_var[10];
                esi = 0;
                if (v3 != 0) {
                    // Logic continues based on assembly
                }
            }
        }
    }

    return 0;
}
