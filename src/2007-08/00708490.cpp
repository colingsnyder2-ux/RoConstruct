// from server: 100% by colin
struct CXTColorHex {
    void base();
    void func();
    char pad[0x64];
    char flag;
};

void CXTColorHex::func()
{
    base();
    if (flag != 0) {
        void (CXTColorHex::*p)() = *(void (CXTColorHex::**)())(*(char**)this + 0x144);
        (this->*p)();
    }
}
