// from server: 100% by colin
struct C1 {
    void m1(const char*, const char*, const char*);
};

extern C1 g1;

void f(const char*);

void func_0076f380()
{
    g1.m1((const char*)0x79c550, (const char*)0x79c548, (const char*)0x79c534);
    f((const char*)0x778750);
}
