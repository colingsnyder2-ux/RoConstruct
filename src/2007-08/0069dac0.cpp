// from server: 100% by colin
struct CXTPPropertyGridItemColor {
    void sub_63023e();
    bool sub_710fd0();
    void OnInplaceButtonDown(int, int);
};

void CXTPPropertyGridItemColor::OnInplaceButtonDown(int a, int b)
{
    sub_63023e();
    if (a == 0) {
        if (!sub_710fd0()) {
            void (CXTPPropertyGridItemColor::*pmf)(int) = *(void (CXTPPropertyGridItemColor::**)(int))((char*)(*(void**)this) + 0x13c);
            (this->*pmf)(-1);
        }
    }
}
