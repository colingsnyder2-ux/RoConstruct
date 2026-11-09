// from server: 100% by colin
struct SubObj {
    void Method();
};

struct CWebToolbox {
    char pad[0xf4];
    SubObj* field_0xf4;
    int Func(int, int, int);
};

int CWebToolbox::Func(int, int, int)
{
    if (field_0xf4 != 0)
        field_0xf4->Method();
    return 3;
}
