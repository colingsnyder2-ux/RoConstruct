// from server: 25% by atomic.potato
struct P_func_006edb90 { void g(); };
struct S_func_006edb90 {
    char pad[244];
    P_func_006edb90* m_p;
    void f();
};

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __cdecl sub_7B5D00();
extern "C" void __cdecl sub_7B4DD0();
extern "C" void __cdecl sub_7B4E30();
extern "C" float __cdecl sub_7AAB00();

struct RBX_RotateJoint {
    void* create(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

void* RBX_RotateJoint::create(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
    if (a1 == 6) {
        void* p = sub_7F3860(0xd0);
        if (p) {
            sub_7B5D00();
            *(unsigned int*)p = 0x9ee02c;
            *(unsigned int*)((char*)p + 0x20) = 0x9ee00c;
            return p;
        }
        return 0;
    }

    float f1 = 0.0f;
    float f2 = 0.0f;
    float f3 = 0.0f;
    float f4 = 0.0f;

    S_func_006edb90* s1 = (S_func_006edb90*)a2;
    S_func_006edb90* s2 = (S_func_006edb90*)a3;
    s1->f();
    s2->f();
    f4 = sub_7AAB00();

    if (a1 == 8) {
        void* p = sub_7F3860(0xdc);
        if (p) {
            sub_7B4DD0();
            return p;
        }
    }
    else if (a1 == 7) {
        void* p = sub_7F3860(0xdc);
        if (p) {
            sub_7B4E30();
            return p;
        }
    }
    return 0;
}
