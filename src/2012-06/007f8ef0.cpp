// from server: 23% by atomic.potato
extern "C" {
    void __stdcall sub_7f8520(void*, void*);
    void __stdcall sub_7f8830(void*, void*);
    void __stdcall sub_7f87b0(void*, void*);
    void __stdcall sub_7f7300(void*, void*, void*, void*);
    void __stdcall sub_7f7190(void*, int);
    void __stdcall sub_7f85b0(void*, void*, void*);
    void* __stdcall sub_74c010(void*, void*);
    void __stdcall sub_b22644(void*, void*);
    void __stdcall sub_b2263c(void*);
}

struct S {
    char pad0[4];
    char pad4[4];
    char pad8[4];
    char padC[4];
    char pad10[0x14];
    int field24;
    int field28;
    char pad2C[8];
    int field34;
    void func(int, int, int);
};

void S::func(int a, int b, int c) {
    char buf[0x80];
    int local10;
    int local14;
    sub_7f8520(this, &local14);
    int idx = field28;
    int* arr = (int*)field24;
    if (local14 != arr[idx]) {
        sub_7f8830(this, &local10);
    }
    int* p = (int*)a;
    int v0 = p[0];
    int v1 = p[1];
    int v2 = p[2];
    int v3 = b;
    char tmp[0x10];
    *(int*)(tmp + 0) = v3;
    *(int*)(tmp + 4) = v0;
    *(int*)(tmp + 8) = v1;
    *(int*)(tmp + 12) = v2;
    char tmp2[0x1c];
    sub_b22644(tmp2, tmp);
    char tmp3[0x1c];
    sub_7f87b0(tmp3, &tmp3);
    int* node = *(int**)((char*)this + 8);
    int* n = (int*)*node;
    int* n4 = (int*)n[1];
    sub_7f7300((char*)this + 4, n, n4, tmp3);
    int* result = (int*)0;
    sub_7f7190((char*)this + 4, 1);
    n[1] = (int)result;
    *(int*)(result + 1) = (int)result;
    sub_b2263c(&local10);
    int* head = *(int**)((char*)this + 8);
    int* h = (int*)*head;
    sub_b22644(&local10, (void*)c);
    void* r = sub_74c010(&local10, &local10);
    sub_b22644(&local10, r);
    int ecx_val = *(int*)((char*)r + 0x1c);
    int local40 = ecx_val;
    sub_7f85b0((char*)this + 0x10, &local10, &local40);
    sub_b2263c(&local10);
    sub_b2263c(&local10);
    field34 += c;
}
