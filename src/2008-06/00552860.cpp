// from server: 100% by king_originala
struct S
{
    void func_00552860(int, int, int);
    void func_0047b450(int, int, int, int);
    void func_00479c30();
    void func_00477f00(int, int);
};

#pragma optimize("", off)
void S::func_00552860(int a, int b, int c)
{
    do {} while (0);
    func_0047b450(a, 2, b, c);
    func_00479c30();
    func_00477f00(a, b);
}
#pragma optimize("", on)
