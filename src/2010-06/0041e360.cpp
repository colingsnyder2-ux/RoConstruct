// from server: 100% by tester
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
    ((CRobloxTreeCtrl*)((char*)this + 0xd4))->sub_41dba0();
    ((void (__stdcall*)(void*, unsigned int, unsigned int, void*))SetTimer)(*(void**)((char*)this + 0x20), 0, 0xc8, 0);
    return 0;
}
