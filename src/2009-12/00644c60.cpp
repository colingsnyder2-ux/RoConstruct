// from server: 50% by atomic.potato
struct Inner {
    virtual void f(int, int*);
};

extern "C" void __cdecl sub_6b2f50(int*, int);

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int get(int, int);
};

int Outer::get(int a, int b)
{
    int result = 0;
    inner->f(a, &result);
    sub_6b2f50(&result, result);
    return result;
}
