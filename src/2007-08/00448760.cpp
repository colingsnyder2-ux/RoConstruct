// from server: 100% by colin
struct CRbxDocTemplate {
    void sub_630796(int, int);
    void func(int, int);
};

struct GlobalObj {
    void sub_448120(int);
};

extern GlobalObj g_obj;

void CRbxDocTemplate::func(int a, int b) {
    g_obj.sub_448120(1);
    sub_630796(a, b);
}
