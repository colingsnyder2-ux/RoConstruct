// from server: 100% by colin
struct XTPPaintThemes_CXTPNativeXPTheme {
    XTPPaintThemes_CXTPNativeXPTheme* construct();
};

extern "C" void __fastcall sub_63d8c0(void*);

XTPPaintThemes_CXTPNativeXPTheme* XTPPaintThemes_CXTPNativeXPTheme::construct()
{
    sub_63d8c0(this);
    *(int*)((char*)this + 0x78) = 1;
    *(int*)((char*)this + 0x128) = 1;
    *(int*)((char*)this + 0x130) = 1;
    *(int*)((char*)this + 0x12c) = 1;
    *(int*)((char*)this + 0x134) = 1;
    *(int*)((char*)this) = 0x7d731c;
    *(int*)((char*)this + 0x10c) = 0;
    *(int*)((char*)this + 0x110) = 3;
    *(int*)((char*)this + 0x7c) = 8;
    return this;
}
