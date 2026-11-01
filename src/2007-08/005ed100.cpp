// from server: 100% by colin
struct BodyGyro_005ed100 {
    char pad0[0x10];
    int m_field10;
    void f(int a, int b);
};

struct Sub_005ebe00 {
    void g(int);
};

struct Sub_005ebad0 {
    void g(int);
};

void BodyGyro_005ed100::f(int a, int b)
{
    int v = *(int*)(m_field10 + 0x1d8);
    int s = *(int*)(v + 0x64);
    BodyGyro_005ed100* self = (BodyGyro_005ed100*)((char*)this - 0xe8);
    ((Sub_005ebe00*)self)->g(s);
    ((Sub_005ebad0*)self)->g(s);
}
