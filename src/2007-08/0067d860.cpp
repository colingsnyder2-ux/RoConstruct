// from server: 100% by colin
struct CXTPControlWindowList {
    int f(int, int, int, int*);
};

int CXTPControlWindowList::f(int a, int b, int c, int* out) {
    if (*(int*)((char*)a + 0xf4) != 2) {
        *out = 0;
        return 0;
    }
    return 1;
}
