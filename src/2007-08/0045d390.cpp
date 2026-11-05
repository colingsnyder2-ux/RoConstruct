// from server: 100% by colin
struct CScintillaView_Inner {
    int method_45cb40(int);
};

struct CScintillaView {
    char pad[0x58];
    CScintillaView_Inner inner;
    int method_45d390(int* arg);
};

int CScintillaView::method_45d390(int* arg) {
    int* p = arg;
    int v = *p;
    int r = inner.method_45cb40(1);
    return (*(int (__thiscall**)(int*, int))v)(p, r);
}
