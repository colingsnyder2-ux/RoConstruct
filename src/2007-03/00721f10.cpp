// from server: 100% by tester
struct CXTCaptionButtonTheme {
    int f(void*);
};


struct VTableCallView {
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int call(void*);
};
int CXTCaptionButtonTheme::f(void* arg)
{
    if (((VTableCallView*)this)->call(arg))
        return 1;
    return (((unsigned char (__thiscall*)(void*))*(void**)(*(char**)arg + 0x160))(arg) & 3) != 0;
}
