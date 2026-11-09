// from server: 47% by colin
struct CSelectionPropGrid {
    void sub_43FF40();
};

extern "C" void __stdcall sub_5592D0(void*, void*);
extern "C" void __stdcall sub_5595A0(void*);
extern "C" void __stdcall sub_410BB0(void*);
extern "C" void __stdcall sub_40F800(void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __stdcall sub_77E69C(void*, const void*, unsigned int);

void CSelectionPropGrid::sub_43FF40()
{
    char* base = (char*)this;
    int* p128 = *(int**)(base + 0x128);
    if (*(int*)((char*)p128 + 0x188) != 0) {
        int* obj = *(int**)((char*)p128 + 0x188);
        char buf[0x1C];
        *(int*)(buf + 0) = 0;
        *(int*)(buf + 4) = 0;
        *(int*)(buf + 8) = 0;
        sub_5592D0(buf, obj);
        int* p12c = *(int**)(base + 0x12C);
        int* src = *(int**)((char*)p12c + 4);
        sub_77E69C(buf, src + 1, 0x1C);
        int* p128b = *(int**)(base + 0x128);
        int* obj2 = *(int**)((char*)p128b + 0x188);
        sub_410BB0((char*)obj2 + 0x160);
        int* p128c = *(int**)(base + 0x128);
        int* obj3 = *(int**)((char*)p128c + 0x188);
        int* vt = *(int**)((char*)obj3 + 0x160);
        void (__stdcall *fn)(void*, int) = *(void (__stdcall **)(void*, int))(vt + 4);
        fn((char*)obj3 + 0x160, 1);
        sub_5595A0(buf);
    }
    int* a = *(int**)(base + 0x18);
    if (a != 0) {
        sub_40F800((char*)a + 8);
        sub_62FC62(a);
    }
    int* b = *(int**)(base + 0x1C);
    if (b != 0) {
        sub_40F800((char*)b + 8);
        sub_62FC62(b);
    }
}
