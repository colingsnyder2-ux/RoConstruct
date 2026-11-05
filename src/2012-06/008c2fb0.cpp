// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_7adc40(void*, void*);
extern "C" void __stdcall sub_8c1aa0(void*, void*);
extern "C" void* __stdcall sub_722dc0(void*);
extern "C" void* __stdcall sub_6e2f80(void*);
extern "C" void* __stdcall sub_54a920(void*);
extern "C" void* __stdcall sub_439330(void*, void*);
extern "C" void __stdcall sub_6dde00(void*);
extern "C" void* __stdcall sub_54bea0(void*);
extern "C" void __stdcall sub_62d950(void*);
extern "C" void __stdcall sub_8c1690(void*, void*);
extern "C" void* __stdcall sub_68fab0(void*, void*);
extern "C" void __stdcall sub_4c1bc0(void*, void*);
extern "C" void* __stdcall sub_68fc20(void*, void*);
extern "C" void __stdcall sub_8c17d0(void*, void*);
extern "C" void* __stdcall sub_751730(void*);
extern "C" void __stdcall sub_751770(void*);
extern "C" void* __stdcall sub_4e7870(void*);
extern "C" void* __stdcall sub_5a6fa0(void*);
extern "C" void __stdcall sub_517700(void*, void*);
extern "C" void __stdcall sub_a96de0(void*, void*, void*);
extern "C" void* __stdcall sub_a96ee0(void*, void*);
extern "C" void __stdcall sub_8aff10(void*, void*);
extern "C" void __stdcall sub_8c2f60(void*);

struct S_func_008c2fb0 {
    char pad0[0x30];
    char m_30[0x18];
    char pad48[4];
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    char pad5c[0x20];
    char m_7c;
    char pad7d[3];
    char m_80[4];
    char m_84[0x84];
    int f(int);
};

int S_func_008c2fb0::f(int a1)
{
    char* base = (char*)this;
    int* p5c = (int*)(base + 0x5c);
    int v = *p5c;
    unsigned int neg = (unsigned int)(-(int)v);
    int sbb = (int)(neg - (neg != 0 ? 0 : 0));
    sbb = (v != 0) ? 0xffffffff : 0;
    if ((sbb & 0x59a790) != 0) {
        sub_7adc40(base - 0x84, (void*)a1);
        return 0;
    }
    if (*(char*)(base + 0x7c) == 0)
        return 0;

    char* self = base - 0x84;
    char buf1[8];
    sub_8c1aa0(self, buf1);
    void* p1 = *(void**)buf1;
    void* r1 = sub_722dc0(p1);
    void* p2 = *(void**)(buf1 + 4);
    void* r2 = sub_6e2f80(p2);
    void* r3 = sub_54a920(r2);
    void* ebx = r3;
    if (ebx != 0) {
        char tmp[8];
        void* r4 = sub_439330(base + 0x80, tmp);
        void* ebp = *(void**)r4;
        sub_6dde00(tmp);
        if (ebp != 0) {
            void* r5 = sub_54bea0((char*)ebp + 0x1c);
            if (ebx == r5) {
                sub_6dde00(buf1);
                return 0;
            }
        }
    }
    void* ebp2 = *(void**)(buf1 + 4);

    char buf2[0x40];
    sub_62d950(buf2);

    float fx = 0.0f, fy = 0.0f, fz = 0.0f;

    if (p1 != 0 && ebp2 != 0) {
        char tmp2[8];
        sub_8c1690(self, tmp2);
        void* q1 = *(void**)tmp2;
        if (q1 != 0) {
            char tmp3[0x40];
            void* r6 = sub_68fab0(q1, tmp3);
            sub_4c1bc0(buf2, r6);
            void* r7 = sub_68fc20(q1, tmp2 + 8);
            fx = *(float*)r7;
            fy = *(float*)((char*)r7 + 4);
            fz = *(float*)((char*)r7 + 8);
        } else {
            char tmp4[8];
            sub_8c17d0(self, tmp4);
            void* q2 = *(void**)tmp4;
            if (q2 != 0) {
                void* r8 = sub_751730(q2);
                sub_4c1bc0(buf2, r8);
                sub_751770(q2);
            } else {
                void* q3 = (p1 != 0) ? (char*)p1 + 0x1c : 0;
                void* r9 = sub_4e7870(q3);
                if (r9 != 0) {
                    void* r10 = sub_751730(r9);
                    sub_4c1bc0(buf2, r10);
                    sub_751770(r9);
                } else {
                    void* q4 = (p1 != 0) ? (char*)p1 + 0x1c : 0;
                    void* r11 = sub_5a6fa0(q4);
                    if (r11 != 0) {
                        char tmp5[0x40];
                        void* r12 = sub_68fab0(r11, tmp5);
                        sub_4c1bc0(buf2, r12);
                        void* r13 = sub_68fc20(r11, tmp5 + 0x28);
                        fx = *(float*)r13;
                        fy = *(float*)((char*)r13 + 4);
                        fz = *(float*)((char*)r13 + 8);
                    }
                }
            }
            sub_6dde00(tmp4);
        }
        sub_6dde00(tmp2);
    }

    float vx = fx, vy = fy, vz = fz;

    int g = *(int*)(base + 0x48);
    char tmp6[0x30];
    sub_517700(tmp6, buf2);
    char tmp7[0xc];
    *(int*)(tmp7) = *(int*)(tmp6);
    *(int*)(tmp7 + 4) = *(int*)(tmp6 + 4);
    *(int*)(tmp7 + 8) = *(int*)(tmp6 + 8);
    void* vt = *(void**)((char*)ebp2 + 0x150);
    void* fn = *(void**)((char*)vt + 8);
    void* r14 = ((void*(*)(void*, void*, void*, void*, int))fn)((char*)ebp2 + 0x150, tmp7, tmp6, tmp7, g);
    sub_a96de0(buf2, r14, (void*)a1);
    void* r15 = sub_a96ee0(buf2, tmp6);
    *(float*)(base + 0x4c) = *(float*)r15;
    *(float*)(base + 0x50) = *(float*)((char*)r15 + 4);
    *(float*)(base + 0x54) = *(float*)((char*)r15 + 8);
    *(float*)(base + 0x58) = *(float*)((char*)r15 + 0xc);
    sub_8aff10(base + 0x30, tmp6);
    sub_8c2f60(tmp6);

    void* esi = *(void**)(buf1 + 4);
    if (esi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void* vt2 = *(void**)esi;
            void* fn2 = *(void**)((char*)vt2 + 4);
            ((void(*)(void*))fn2)(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void* vt3 = *(void**)esi;
                void* fn3 = *(void**)((char*)vt3 + 8);
                ((void(*)(void*))fn3)(esi);
            }
        }
    }
    return 0;
}
