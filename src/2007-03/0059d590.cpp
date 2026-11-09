// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_00590000 {
    void sub_0059d480();
    seg_00590000* init();
};

seg_00590000* seg_00590000::init() {
    sub_0059d480();
    *(int*)((char*)this + 0x00) = 0x7b21ec;
    *(int*)((char*)this + 0x04) = 0x7b21e0;
    *(int*)((char*)this + 0x0c) = 0x7b21d8;
    *(int*)((char*)this + 0x18) = 0x7b21d0;
    *(int*)((char*)this + 0x1c) = 0x7b21c0;
    *(int*)((char*)this + 0x34) = 0x7b21b0;
    *(int*)((char*)this + 0x4c) = 0x7b21a0;
    *(int*)((char*)this + 0x64) = 0x7b2190;
    *(int*)((char*)this + 0x7c) = 0x7b2180;
    *(int*)((char*)this + 0x94) = 0x7b2170;
    *(int*)((char*)this + 0xf0) = 0x7b2168;
    return this;
}
