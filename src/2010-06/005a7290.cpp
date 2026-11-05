// from server: 50% by atomic.potato
struct Inner {
    virtual void f(int, int*);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int method(int, int);
};

extern "C" void __cdecl sub_620B40(int*, int);

int Outer::method(int a, int b)
{
    int result = 0;
    inner->f(a, &result);
    sub_620B40(&result, result);
    return result;
}
