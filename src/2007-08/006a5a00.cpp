// from server: 100% by colin
struct CXTPMenuBar {
    char pad[0xf8];
    void* field_f8;
    int method(int, int, int, int);
};

struct Sub {
    int method(int, int, int, int, int);
};

int CXTPMenuBar::method(int a, int b, int c, int d) {
    return ((Sub*)field_f8)->method(a, b, c, d, 1);
}
