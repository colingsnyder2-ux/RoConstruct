// from server: 95% by colin
struct CAboutRobloxDialog {
    CAboutRobloxDialog* construct(int);
};

extern CAboutRobloxDialog* g_8bae44;

extern "C" void __stdcall sub_466de0();

CAboutRobloxDialog* CAboutRobloxDialog::construct(int)
{
    sub_466de0();
    *(int*)((char*)this + 0) = 0x784b4c;
    *(int*)((char*)this + 4) = 0x784b34;
    *(int*)((char*)this + 8) = 0x784b1c;
    *(int*)((char*)this + 0xc) = 0x784af8;
    *(int*)((char*)this + 0x18) = 0x784ae0;
    *(int*)((char*)this + 0x20) = 0x784ac4;
    *(int*)((char*)this + 0x28) = 0x784ab8;
    *(int*)((char*)this + 0x2c) = 0x784aac;
    int* p = (int*)g_8bae44;
    int* vt = (int*)*p;
    void (__stdcall *fn)() = (void (__stdcall *)())vt[1];
    fn();
    return this;
}
