// from server: 57% by atomic.potato
struct Inner {
    virtual int f(int, int*);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    int method(int, int*);
};

extern "C" int __cdecl sub_6c1590();
extern "C" void __cdecl sub_521060(int);

int Outer::method(int a, int* b)
{
    int tmp;
    int r = inner->f(a, &tmp);
    *b = sub_6c1590();
    sub_521060(r);
    return r;
}
