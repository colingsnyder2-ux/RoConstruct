// from server: 47% by colin
struct S {
    char pad0[0x34];
    float f34;
    char pad38[0x20];
    float f58;
    float f5c;
    float f60;
    float f64;
    unsigned char b68;
    char pad69[0x7];
    float f70;
    float f74;
    char pad78[0x108];
    int* p180;
    char pad184[0x8];
    int* p18c;
    void f(int* arg);
};

extern "C" void __stdcall sub_41d870(void*);
extern "C" int __stdcall sub_6309fa(int*);
extern "C" void __stdcall sub_77d2f8(void*);

void S::f(int* arg) {
    void* local8;
    unsigned char localc;
    float local10;
    float local14;
    float local18;
    float local1c;
    float local20;
    float local24;

    local8 = (void*)((char*)this + 0x34);
    localc = 0;
    sub_41d870(&local8);

    if (b68 != 0) {
        int* p = p18c;
        int* vt = *(int**)p;
        int (*fn)(int*) = (int (*)(int*))vt[7];
        int r = fn(p);
        if (r < 0) {
            b68 = 0;
        }
        if (b68 != 0) {
            goto cleanup;
        }
    }

    if (sub_6309fa(p180) == 0) {
        goto cleanup;
    }

    {
        int* p = p18c;
        int* vt = *(int**)p;
        void (*fn)(int*) = (void (*)(int*))vt[8];
        fn(p);
    }

    {
        int* p = p18c;
        int* vt = *(int**)p;
        int (*fn)(int*) = (int (*)(int*))vt[7];
        int r = fn(p);
        b68 = (r >= 0) ? 1 : 0;
        if (b68 == 0) {
            goto cleanup;
        }
    }

    local18 = f58;
    local1c = f5c;
    local20 = f60;
    local24 = f64;

    local10 = local20 + local18;
    local14 = local24 + local1c;

    {
        double d = *(double*)0x795b48;
        local18 = (float)(local10 * d);
        local1c = (float)(local14 * d);
    }

    local10 = *(float*)arg - local18;
    local14 = *(float*)((char*)arg + 4) - local1c;

    f70 = local10;
    f74 = local14;

cleanup:
    if (localc != 0) {
        sub_77d2f8(local8);
    }
}
