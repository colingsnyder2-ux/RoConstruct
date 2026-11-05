// from server: 82% by atomic.potato
struct S
{
    int f(int);
    bool g(int);
};

extern "C" bool __fastcall S_f(S*, int, int);
extern "C" bool __fastcall S_g(S*, int, int);

int S::f(int a)
{
    if (S_f(this, 0, a))
    {
        return S_g(this, 0, a) ? 1 : 2;
    }
    return 0;
}
