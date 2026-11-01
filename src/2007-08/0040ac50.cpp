// from server: 92% by colin
struct VCSecureHtmlView
{
    char pad[0xf4];
    void* field_f4;
    int sub_62fddc(int, int, int, int);
    int sub_634050(int, int, int, int);
    int method(int, int, int, int);
};

int VCSecureHtmlView::method(int a, int b, int c, int d)
{
    if (field_f4 != 0)
    {
        if (sub_634050(a, b, c, d) != 0)
            return 1;
    }
    return sub_62fddc(a, b, c, d);
}
