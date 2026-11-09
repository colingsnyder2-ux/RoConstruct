// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_00580000 {
    void sub_0058d5b0();
    seg_00580000* init();
};

seg_00580000* seg_00580000::init() {
    sub_0058d5b0();
    *(int*)((char*)this + 0x00) = 0x7b13b4;
    *(int*)((char*)this + 0x04) = 0x7b13ac;
    *(int*)((char*)this + 0x0c) = 0x7b13a4;
    *(int*)((char*)this + 0x18) = 0x7b139c;
    *(int*)((char*)this + 0x1c) = 0x7b138c;
    *(int*)((char*)this + 0x34) = 0x7b137c;
    *(int*)((char*)this + 0x4c) = 0x7b136c;
    *(int*)((char*)this + 0x64) = 0x7b135c;
    *(int*)((char*)this + 0x7c) = 0x7b134c;
    *(int*)((char*)this + 0x94) = 0x7b133c;
    return this;
}
