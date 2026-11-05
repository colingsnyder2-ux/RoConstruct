// from server: 100% by colin
struct C1 {
    void m1(const char*, const char*, const char*);
};

extern C1 g1;

void f(const char*);

void func_0076eb50()
{
    g1.m1((const char*)0x79b6e4, (const char*)0x79b6dc, (const char*)0x79b6d4);
    f((const char*)0x7784d0);
}
