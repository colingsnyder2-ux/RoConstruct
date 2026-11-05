// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    void* __stdcall sub_4D96A0(void*, void*, void*);
    void  __stdcall sub_4D9A30(void*, int);
    void  __stdcall sub_4D9720(void*);
    void  __stdcall sub_4DD520(void*, void*);
    void  __stdcall sub_5E1CC0(void*);
    void  __stdcall sub_5E1A60(void*, int, void*, void*, void*);
    char  __stdcall sub_4DED20(void*, void*, void*, void*);
    void* __stdcall sub_4CFF90(void);
    void  __stdcall sub_4E0BF0(void*, void*, int);
    void  __stdcall sub_632E00(void*, void*, int);
    void  __stdcall sub_6247B0(void*);
    void  __stdcall sub_705590(void*, void*, void*, void*);
    void  __stdcall sub_719A4A(void*, void*);
    void  __stdcall sub_409410(void*, void*);
    void  __stdcall sub_4F1850(void*, void*);
    void  __stdcall sub_4FB130(void*);
    void  __stdcall sub_89E4B4(void*, const char*);
    void  __stdcall sub_89E4C4(void*);
}

struct S {
    char pad0[0x2f14];
    int  field_2f14;
    char pad1[0x2f20 - 0x2f14 - 4];
    char field_2f20[0x20];
    void method(void* arg);
};

void S::method(void* arg)
{
    char* p = (char*)arg;
    unsigned char c = *(unsigned char*)(*(int*)(p + 0x24));
    if (c == 0x60) {
        char buf[0x574];
        sub_4D96A0(buf, *(void**)(p + 0x1c), *(void**)(p + 0x24));
        sub_4D9A30(buf + 8, 8);
        char b2[8];
        char b3[8];
        if (sub_4DED20(this, buf, b2, b3)) {
            char* g = (char*)sub_4CFF90();
            if (g[0x8d]) {
                char tmp1[0x40];
                char tmp2[0x40];
                sub_4E0BF0(p + 4, tmp1, 1);
                sub_632E00(tmp2, tmp1, 4);
                char tmp3[0x40];
                sub_5E1CC0(tmp3);
                char* s1 = tmp1;
                if (*(int*)(tmp1 + 0x18) >= 0x10) s1 = *(char**)(tmp1 + 4); else s1 = tmp1 + 4;
                char* s2 = tmp2;
                if (*(int*)(tmp2 + 0x18) >= 0x10) s2 = *(char**)(tmp2 + 4); else s2 = tmp2 + 4;
                sub_5E1A60(tmp3, 1, (void*)0x8c8cf0, s2, s1);
                sub_6247B0(tmp2);
                sub_89E4C4(tmp1);
                sub_89E4C4(tmp3);
            }
            int v = this->field_2f14;
            if (v == 0) {
                char tmp4[0x40];
                sub_89E4B4(tmp4, (const char*)0x8c8cd8);
                char tmp5[0x40];
                sub_409410(tmp5, tmp4);
                sub_719A4A(tmp5, (void*)0x97a750);
                v = this->field_2f14;
            }
            if (v != *(int*)(b2)) {
                char tmp6[0x40];
                sub_89E4B4(tmp6, (const char*)0x8c8cc0);
                char tmp7[0x40];
                sub_409410(tmp7, tmp6);
                sub_719A4A(tmp7, (void*)0x97a750);
            }
            sub_4FB130(this);
        } else {
            char tmp1[0x40];
            char tmp2[0x40];
            sub_4E0BF0(p + 4, tmp1, 1);
            sub_632E00(tmp2, tmp1, 4);
            char* s1 = tmp1;
            if (*(int*)(tmp1 + 0x18) >= 0x10) s1 = *(char**)(tmp1 + 4); else s1 = tmp1 + 4;
            char* s2 = tmp2;
            if (*(int*)(tmp2 + 0x18) >= 0x10) s2 = *(char**)(tmp2 + 4); else s2 = tmp2 + 4;
            char tmp3[0x40];
            sub_705590(tmp3, (void*)0x8c8c94, s2, s1);
            char tmp4[0x40];
            sub_409410(tmp4, tmp3);
            sub_719A4A(tmp4, (void*)0x97a750);
        }
        sub_4D9720(buf);
    } else if (c == 0x68) {
        char buf[0x160];
        sub_4D96A0(buf, *(void**)(p + 0x1c), *(void**)(p + 0x24));
        sub_4D9A30(buf + 8, 8);
        char* esi = this->field_2f20;
        char tmp[0x40];
        sub_4DD520(tmp, esi);
        char tmp2[0x40];
        sub_5E1CC0(tmp2);
        char* s1 = esi;
        if (*(int*)(esi + 0x18) >= 0x10) s1 = *(char**)(esi + 4); else s1 = esi + 4;
        sub_5E1A60(tmp2, 1, (void*)0x8c8d14, s1, 0);
        sub_4D9720(buf);
    } else {
        sub_4F1850(this, p);
    }
}
