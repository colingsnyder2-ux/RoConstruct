// from server: 43% by atomic.potato
struct S
{
    int __cdecl f(int, int);
};

extern "C" int __cdecl sub_71A57A(int);

int S::f(int a, int b)
{
    return sub_71A57A(a ^ *reinterpret_cast<int *>(reinterpret_cast<char *>(b) - 0x38));
}
