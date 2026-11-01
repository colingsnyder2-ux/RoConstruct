// from server: 100% by colin
struct CXTPControlGallery {
    int sub_6b3590();
    void sub_670630(int, int);
    void sub_6b3e80(int, int);
    void func(int, int);
};

void CXTPControlGallery::func(int a, int b)
{
    if (sub_6b3590()) {
        sub_670630(a, b);
    } else {
        sub_6b3e80(a, b);
    }
}
