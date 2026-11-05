// from server: 45% by atomic.potato
struct Sub {
    char pad[4];
    void init(int);
};

struct S {
    Sub sub;
    int method(int, int);
};

extern "C" void __stdcall sub_init(void*, int);
extern "C" int __stdcall sub_call(void*, int, int);

int S::method(int a, int b)
{
    sub_init(&sub, 1);
    return sub_call(this, a, b);
}
