// from server: 100% by atomic.potato
struct CXTTreeBase {
    int Get(int index);
};

struct CXTPStatusBar {
    int getColor();
};

extern "C" CXTTreeBase* __stdcall sub_668F70();

int CXTPStatusBar::getColor()
{
    int v = *(int*)((char*)this + 0x90);
    if (v != -1)
        return v;
    if (*(int*)((char*)this + 0x2c) == 5)
        return 0x4c4c4c;
    CXTTreeBase* p = sub_668F70();
    return p->Get(0x17);
}
