// from server: 100% by colin
struct UnifiedImageWidget {
    void construct();
};

void UnifiedImageWidget::construct() {
    *(int*)((char*)this + 0x00) = 0x7bbfdc;
    *(int*)((char*)this + 0x04) = 0x7bbfd4;
    *(int*)((char*)this + 0x10) = 0x7bbfcc;
    *(int*)((char*)this + 0x14) = 0x7bbfbc;
    *(int*)((char*)this + 0x2c) = 0x7bbfac;
    *(int*)((char*)this + 0x44) = 0x7bbf9c;
    *(int*)((char*)this + 0x5c) = 0x7bbf8c;
    *(int*)((char*)this + 0x74) = 0x7bbf7c;
    *(int*)((char*)this + 0x8c) = 0x7bbf6c;
    *(int*)((char*)this + 0xe8) = 0x7bbf54;
    extern void __stdcall sub_5b0170();
    sub_5b0170();
}
