// from server: 57% by atomic.potato
struct CWrapperView {
    char pad0[8];
    int field_8;
    char pad1[8];
    int field_14;
    void method(int);
};

extern "C" int __stdcall sub_64f610(int*);
extern "C" int __stdcall sub_53c540(int, int*);
extern "C" void __stdcall sub_46cda0(void*, int);

void CWrapperView::method(int arg) {
    int* p = (int*)field_14;
    if (p != 0) {
        int* ecx = *(int**)((char*)p + 0xfc);
        int eax = field_8;
        int esi;
        if (eax >= 0 && eax < ecx[0x2c/4]) {
            esi = *(int*)(ecx[0x28/4] + eax*4);
        } else {
            esi = 0;
        }
        int edx = *(int*)0xc54380;
        int tmp;
        sub_64f610(&tmp);
        int tmp2;
        sub_53c540(tmp, &tmp2);
        unsigned char b0 = ((unsigned char*)&tmp2)[0];
        unsigned char b1 = ((unsigned char*)&tmp2)[1];
        unsigned char b2 = ((unsigned char*)&tmp2)[2];
        int c = (b2 << 8) | b1;
        c = (c << 8) | b0;
        sub_46cda0((void*)esi, c);
    }
    int* edx2 = *(int**)this;
    int eax2 = *(int*)edx2;
    void (__stdcall *fn)(void*, int) = (void (__stdcall *)(void*, int))eax2;
    fn(this, 1);
}
