// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_00580000 {
    void sub_00585e50();
    seg_00580000* init();
};

seg_00580000* seg_00580000::init() {
    sub_00585e50();
    *(int*)((char*)this + 0x00) = 0x7b0064;
    *(int*)((char*)this + 0x04) = 0x7b0058;
    *(int*)((char*)this + 0x0c) = 0x7b0050;
    *(int*)((char*)this + 0x18) = 0x7b0048;
    *(int*)((char*)this + 0x1c) = 0x7b0038;
    *(int*)((char*)this + 0x34) = 0x7b0028;
    *(int*)((char*)this + 0x4c) = 0x7b0018;
    *(int*)((char*)this + 0x64) = 0x7b0008;
    *(int*)((char*)this + 0x7c) = 0x7afff8;
    *(int*)((char*)this + 0x94) = 0x7affe8;
    return this;
}
