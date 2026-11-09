// from server: 100% by tester
struct CXTPControlTabWorkspace {
    int f();
};

int CXTPControlTabWorkspace::f() {
    return *(int*)((char*)this - 0x7c);
}