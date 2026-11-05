// from server: 100% by king_originala
struct S {
    int forward(int a, int b, int c, int d, int e);
};

int __stdcall dispatch(void* unused, int a, int b, int c, int d, int e)
{
    return reinterpret_cast<S*>(0x928754)->forward(a, b, c, d, e);
}
