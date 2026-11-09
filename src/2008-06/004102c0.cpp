// from server: 100% by king_originala
struct S {
    int forward(int a, int b, int c, int d, int e);
};

extern S globalObject;

int __stdcall dispatch(int unused, int a, int b, int c, int d, int e)
{
    return globalObject.forward(a, b, c, d, e);
}
