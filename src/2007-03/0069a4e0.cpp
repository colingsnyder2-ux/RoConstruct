// from server: 100% by tester
struct CXTPRibbonBar {
    int GetSomething(int arg1, int arg2);
};

int CXTPRibbonBar::GetSomething(int arg1, int arg2) {
    typedef int (__stdcall *Fn)(int, int);
    Fn fn = *(Fn*)(*(char**)this + 0x1c4);
    arg2 = 0;
    return fn(arg1, arg2);
}