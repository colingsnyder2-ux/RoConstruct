// from server: 33% by atomic.potato
struct OgreRoot {
    static OgreRoot& getSingleton();
};

struct Inner {
    char pad0[0x10];
    int m_field10;
};

struct Mid {
    char pad0[0x3c];
    int m_field3c;
};

struct Holder {
    char pad0[0x820];
    Mid* m_p820;
};

struct List {
    char pad0[0x10];
    int m_field10;
};

struct S_00497950 {
    char pad0[0x50];
    int m_field50;
    char pad54[0x10];
    int m_field64;
    char pad68[0x2c];
    Holder* m_field94;
    int f();
};

extern "C" void __stdcall sub_0089E9AC();
extern "C" void __stdcall sub_00718A32(void* p);
extern "C" void __stdcall sub_004973E0(void* a, void* b, void* c);
extern "C" char __stdcall sub_00478420(void* p);
extern "C" void __stdcall sub_00497850(void* p, void* q);
extern "C" void __stdcall sub_0047D9B0(void* p);
extern "C" void __stdcall sub_00496F30(void* a, void* b, int c);

int S_00497950::f()
{
    OgreRoot& root = OgreRoot::getSingleton();
    int v14 = *(int*)((char*)&root + 0xc0);
    Holder* h = m_field94;
    Mid* m = h->m_p820;
    int v18 = m->m_field3c;
    int v20 = v18;

    int v13;
    int v17;
    sub_004973E0(&v13, &v17, &v20);

    int* ebp = (int*)m_field64;
    int ebx = m_field50;
    int* edi = (int*)m_field64;
    int eax2 = m_field50;

    while (true) {
        if (ebx != 0) {
            if (ebx == eax2) {
                goto check;
            }
        }
        sub_0089E9AC();
    check:
        if (ebp == edi) break;
        if (ebx == 0) {
            sub_0089E9AC();
            if (ebp == (int*)0x14) {
                sub_0089E9AC();
            }
            edi = (int*)ebp[2];
            if (*(unsigned int*)((char*)edi + 0x284) < (unsigned int)v14) {
                if (v18 > 1) {
                    if (sub_00478420(edi)) {
                        sub_00497850(edi, &v13);
                    }
                }
            } else {
                sub_0047D9B0(edi);
            }
        } else {
            eax2 = *ebp;
        }
        if (ebx == 0) {
            sub_0089E9AC();
            if (ebp == (int*)0x14) {
                sub_0089E9AC();
            }
            ebp = (int*)*ebp;
        } else {
            eax2 = *ebp;
        }
    }

    int v = *(int*)((char*)m_field94 + 0x10);
    int local20 = v;
    int local1c = 0;
    sub_00496F30(&local1c, &local20, 1);

    int a = *(int*)((char*)&local1c + 0x14);
    if (a != 0) {
        sub_00718A32((void*)a);
    }
    int b = *(int*)((char*)&local1c + 0x8);
    sub_00718A32((void*)b);

    int* c = (int*)((char*)&local1c + 0x4);
    int* d = (int*)*c;
    *c = (int)c;
    *(int*)((char*)c + 4) = (int)c;
    if (d != c) {
        do {
            int* next = (int*)*d;
            sub_00718A32(d);
            d = next;
        } while (d != c);
    }
    sub_00718A32(c);
    sub_00718A32((void*)v13);
    return 0;
}
