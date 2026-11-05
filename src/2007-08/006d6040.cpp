// from server: 31% by colin
// roc 2007-08 006d6040  unit: CXTPReportGroupRow_Batch  size: 323 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d6040

extern "C" {
    void* __stdcall sub_62fef6(unsigned int);
    void __stdcall sub_73833a(void*);
    void __stdcall sub_6301e4(void*);
    void __stdcall sub_653860(void*);
    int __stdcall sub_77ddac();
    int __stdcall sub_77d434(void*, const char*);
    int __stdcall sub_77ddbc(void*);
}

struct CXTPReportGroupRow_Batch {
    void func(int, int, int, int, int, int);
};

void CXTPReportGroupRow_Batch::func(int a1, int a2, int a3, int a4, int a5, int a6) {
    char* esi = (char*)this;
    char* ebx = (char*)a1;
    char* ebp = (char*)a2;
    int edi;

    int v38 = *(int*)(esi + 0x38);
    void* p = sub_62fef6(0x38);
    edi = (int)p;
    if (edi == 0) {
        sub_73833a((void*)edi);
        *(int*)edi = 0x7c7dcc;
        sub_77ddac();
        *(int*)(edi + 0x20) = 0;
        *(int*)(edi + 0x24) = -1;
        *(int*)(edi + 0x28) = -1;
        *(int*)(edi + 0x30) = -1;
        *(int*)(edi + 0x34) = 0x208;
    } else {
        edi = 0;
    }

    int* vtbl = *(int**)esi;
    int (*fn)(void*, void*) = (int (*)(void*, void*))*(int*)((char*)vtbl + 0xfc);
    void* tmp = 0;
    fn(esi, &tmp);
    sub_77d434((void*)(edi + 0x2c), (const char*)tmp);
    sub_77ddbc(&tmp);

    int v = *(int*)(ebx + 0xc);
    int* vtbl2 = *(int**)ebp;
    int (*fn2)(void*, void*, int, int) = (int (*)(void*, void*, int, int))*(int*)((char*)vtbl2 + 0x84);
    fn2(ebp, (void*)esi, edi, v);

    int ecx = *(int*)(esi + 0x24);
    if (ecx != 0) {
        int* vtbl3 = *(int**)ecx;
        int (*fn3)(void*, void*, int) = (int (*)(void*, void*, int))*(int*)((char*)vtbl3 + 0x194);
        int tmp2;
        fn3((void*)ecx, &tmp2, edi);
    }

    int c1 = *(int*)(esi + 0x2c);
    int* vtbl4 = *(int**)ebp;
    int (*fn4)(void*, void*, int, int, int, int, int) = (int (*)(void*, void*, int, int, int, int, int))*(int*)((char*)vtbl4 + 0x80);
    int args[4];
    args[0] = c1;
    args[1] = *(int*)(esi + 0x30);
    args[2] = *(int*)(esi + 0x34);
    args[3] = *(int*)(esi + 0x38);
    fn4(ebp, (void*)ebx, edi, args[0], args[1], args[2], args[3]);

    sub_6301e4((void*)edi);
    sub_653860(&tmp);
}
