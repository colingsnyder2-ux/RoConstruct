// from server: 93% by colin
struct VCSecureHtmlView_CXTPCommandBarsSiteBase {
    int sub_41BD60(int);
    int sub_63066A(int, int, int, int, int, int);
    int f(int, int, int, int, int, int);
};

int VCSecureHtmlView_CXTPCommandBarsSiteBase::f(int a1, int a2, int a3, int a4, int a5, int a6) {
    if (sub_41BD60(a1)) {
        *(int*)a6 = 1;
        return 0;
    }
    return sub_63066A(a1, a2, a3, a4, a5, a6);
}
