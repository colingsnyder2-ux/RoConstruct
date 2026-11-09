// from server: 100% by colin
struct PAVCXTPToolBar_CArray {
    void construct_sub();
    void construct_base();
    PAVCXTPToolBar_CArray* init(int arg);
};

extern "C" void __fastcall sub_73833a(void* p);
extern "C" void __fastcall sub_632d80(void* p);

PAVCXTPToolBar_CArray* PAVCXTPToolBar_CArray::init(int arg) {
    sub_73833a(this);
    sub_632d80((char*)this + 0x24);
    *(int*)((char*)this + 0x20) = arg;
    *(int*)this = 0x7c5164;
    return this;
}
