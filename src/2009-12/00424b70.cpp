// from server: 73% by atomic.potato
struct CXTPControl {
    virtual int vf0();
    virtual int vf1();
};

extern "C" int __cdecl sub_423960(int, int);
extern "C" int __cdecl sub_424820(int, int, int, int, int, int);

void __cdecl sub_424B70(int a, CXTPControl* p, int c)
{
    int v = p->vf1();
    sub_423960(1, v);
    sub_424820(a, v, 0, 0, 0x9f1740, 0);
}
