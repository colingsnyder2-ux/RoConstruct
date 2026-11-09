// from server: 54% by atomic.potato
struct Inner {
    virtual void f(int, int*);
};

extern "C" void __cdecl sub_61f450(int*, int);

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int get(int a, int b);
};

int Outer::get(int a, int b)
{
    int result = 0;
    inner->f(a, &result);
    int tmp = result;
    sub_61f450(&tmp, result);
    return result;
}
