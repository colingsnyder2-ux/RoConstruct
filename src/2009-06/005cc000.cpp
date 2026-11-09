// from server: 32% by atomic.potato
extern "C" void* __stdcall G1_718a38(unsigned int);
extern "C" void* __stdcall G1_5e59f0();
extern "C" void* __stdcall G1_5e5c20();
extern "C" void* __stdcall G1_89e22c(void*, void*);

struct S {
    void f(void*);
};

void S::f(void* a)
{
    void* p = G1_718a38(4);
    if (p) *(void**)p = a;
    else p = 0;
    *(void**)a = p;
    *(int*)((char*)a + 0xc) = 0;
    *(int*)((char*)a + 0x10) = 0;
    *(int*)((char*)a + 0x14) = 0;

    void* (*fn)(void*, void*) = (void* (*)(void*, void*))G1_89e22c;

    void* r1 = fn(0, (void*)0xa44688);
    ++*(int*)0xa4a670;
    void* v1 = G1_5e59f0();
    void* q1 = G1_718a38(8);
    if (q1) { *(void**)q1 = (void*)0x8b0cb0; *(void**)((char*)q1 + 4) = r1; }
    else q1 = 0;
    void* tmp1 = q1;
    ((void (*)(void*, void**))0x426b20)(a, &tmp1);
    void* c1 = tmp1;
    if (c1) {
        void** vt = *(void***)c1;
        ((void (*)(void*, int))vt[0])(c1, 1);
    }

    void* r2 = fn(0, (void*)0xa4468c);
    *(int*)0xa4a670 += 1;
    void* v2 = G1_5e59f0();
    void* q2 = G1_718a38(8);
    if (q2) { *(void**)q2 = (void*)0x8b0cb0; *(void**)((char*)q2 + 4) = r2; }
    else q2 = 0;
    void* tmp2 = q2;
    ((void (*)(void*, void**))0x426b20)(a, &tmp2);
    void* c2 = tmp2;
    if (c2) {
        void** vt = *(void***)c2;
        ((void (*)(void*, int))vt[0])(c2, 1);
    }

    *(int*)0xa4a714 += 1;
    void* v3 = G1_5e5c20();
    void* q3 = G1_718a38(16);
    if (q3) {
        *(void**)q3 = (void*)0x8c4984;
        *(double*)((char*)q3 + 8) = *(double*)0xa44690;
    }
    else q3 = 0;
    void* tmp3 = q3;
    ((void (*)(void*, void**))0x426b20)(a, &tmp3);
    void* c3 = tmp3;
    if (c3) {
        void** vt = *(void***)c3;
        ((void (*)(void*, int))vt[0])(c3, 1);
    }

    *(double*)0xa44690 = 0.0;
}
