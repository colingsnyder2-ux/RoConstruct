// from server: 100% by colin
struct SurfaceGetSet {
    int m_pad;
    int m_get;
    int m_set;
    void method(int, int);
};

extern "C" int __fastcall sub_00573890(int);

void SurfaceGetSet::method(int a, int b)
{
    int base;
    if (a != 0) {
        base = a - 4;
    } else {
        base = 0;
    }
    int r = sub_00573890(base);
    int* p = (int*)b;
    int v = *p;
    int fn = m_set;
    ((void (__thiscall*)(int, int))fn)(r, v);
}
