// from server: 100% by king_originala
struct Base {
    unsigned char storage[0x130];
    Base();
    ~Base();
};

extern void (__thiscall *string_construct)(void *);

struct S : Base {
    double value;
    unsigned char text[28];
    S();
};

S::S() : value(0.0)
{
    unsigned long *p = reinterpret_cast<unsigned long *>(this);
    p[0x00 / 4] = 0x00819fc4;
    p[0x10 / 4] = 0x00819fb8;
    p[0x14 / 4] = 0x00819fb0;
    p[0x20 / 4] = 0x00819fa8;
    p[0x24 / 4] = 0x00819f98;
    p[0x44 / 4] = 0x00819f88;
    p[0x64 / 4] = 0x00819f78;
    p[0x84 / 4] = 0x00819f68;
    p[0xa4 / 4] = 0x00819f58;
    p[0xc4 / 4] = 0x00819f48;
    string_construct(text);
}
