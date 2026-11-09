// from server: 100% by colin
// roc 2007-08 00420d40  unit: seg_00420000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00420d40

struct CRobloxTreeCtrl {
    int sub_420940(int);
    void sub_41dba0();
    int method(int);
};

extern "C" void* SetTimer;

int CRobloxTreeCtrl::method(int a)
{
    int r = sub_420940(a);
    if (r == -1) {
        return r;
    }
    ((CRobloxTreeCtrl*)((char*)this + 0xb8))->sub_41dba0();
    ((void (__stdcall*)(void*, unsigned int, unsigned int, void*))SetTimer)(*(void**)((char*)this + 0x20), 0, 0xc8, 0);
    return 0;
}
