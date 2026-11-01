// from server: 100% by colin
struct CXTPControlTabWorkspace {
    int f();
};

int CXTPControlTabWorkspace::f() {
    return *(int*)((char*)this - 0x6c);
}
