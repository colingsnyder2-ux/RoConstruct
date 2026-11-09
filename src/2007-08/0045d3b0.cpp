// from server: 100% by colin
struct CScintillaView_Sub {
    int method(int);
};

struct CScintillaView {
    char pad[0x58];
    CScintillaView_Sub sub;
    void sub_45D3B0(int* p);
};

void CScintillaView::sub_45D3B0(int* p) {
    int* v = *(int**)p;
    int r = sub.method(1);
    ((void (__thiscall*)(int*, int))v[0])(p, r);
}
