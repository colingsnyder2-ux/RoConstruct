// from server: 100% by colin
struct CXTCaptionButtonTheme {
    void sub_5B4820(int);
    void sub_5E24B0(int);
    void sub_605B30(void*);
    char sub_60BB80();
    void SetTheme(void*);
};

void CXTCaptionButtonTheme::SetTheme(void* p) {
    if (p == *(void**)((char*)this + 0x24)) {
        *(void**)((char*)this + 0x24) = 0;
    }
    *(char*)((char*)this + 0x4c) = 1;
    ((CXTCaptionButtonTheme*)p)->sub_5B4820(0);
    ((CXTCaptionButtonTheme*)(*(void**)((char*)p + 0x64)))->sub_5E24B0(0);
    void* tmp;
    ((CXTCaptionButtonTheme*)((char*)this + 0x30))->sub_605B30(&tmp);
    *(char*)((char*)this + 0x2c) = sub_60BB80();
}
