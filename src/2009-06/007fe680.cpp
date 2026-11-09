// from server: 100% by tester
struct CXTColorHex {
    void base();
    void func();
    char pad[0x5c];
    char flag;
};

void CXTColorHex::func()
{
    base();
    if (flag != 0) {
        void (CXTColorHex::*p)() = *(void (CXTColorHex::**)())(*(char**)this + 0x14c);
        (this->*p)();
    }
}
