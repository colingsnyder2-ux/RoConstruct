// from server: 82% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;

    void init();
};

void S::init()
{
    a = 0x9d072c;
    b = 0x9d0720;
    d = 0x9d0714;
    e = 0x9d070c;
    if (c)
        ((void (**)(int))c)[0](1);
}
