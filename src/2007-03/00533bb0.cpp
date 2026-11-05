// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_00530000 {
    char pad[0xf4];
    int field_f4;
    void init();
};

void seg_00530000::init() {
    int* p = (int*)field_f4;
    *(int*)((char*)this + 0x00) = 0x7a5144;
    *(int*)((char*)this + 0x04) = 0x7a513c;
    *(int*)((char*)this + 0x0c) = 0x7a5134;
    *(int*)((char*)this + 0x18) = 0x7a512c;
    *(int*)((char*)this + 0x1c) = 0x7a511c;
    *(int*)((char*)this + 0x34) = 0x7a510c;
    *(int*)((char*)this + 0x4c) = 0x7a50fc;
    *(int*)((char*)this + 0x64) = 0x7a50ec;
    *(int*)((char*)this + 0x7c) = 0x7a50dc;
    *(int*)((char*)this + 0x94) = 0x7a50cc;
    *(int*)((char*)this + 0xf0) = 0x7a50c0;
    int edx = p[1];
    *(int*)((char*)this + edx + 0xf4) = 0x7a50b4;
    int* q = (int*)field_f4;
    int edx2 = q[2];
    *(int*)((char*)this + edx2 + 0xf4) = 0x7a50ac;
    extern void __stdcall sub_5b6390();
    sub_5b6390();
}
