// from server: 59% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Tool {
    char pad[0x1a8];
    void* field_1a8;
    RefCounted* field_1ac;

    void sub_5d3090();
    void* sub_5d1ae0();
};

extern "C" void* __cdecl sub_6ffa50(void*);
extern "C" void* __cdecl sub_630d36(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_541630(void*, int);
extern "C" void* __cdecl sub_5a56b0(void*);
extern "C" void __cdecl sub_509640(void*, void*, int);
extern "C" void __cdecl sub_5bae60(void*, float, float, float);
extern "C" void __cdecl sub_578000(void*, float*);

extern float g_79f2fc;
extern float g_7a32e8;
extern float g_7a34b8;

void* Tool::sub_5d1ae0()
{
    void* p = field_1a8;
    void* result = 0;
    if (p) {
        void* r = sub_6ffa50(p);
        if (r) {
            void* v = *(void**)((char*)r + 0xbc);
            result = sub_630d36(v, 0, (void*)0x881f4c, (void*)0x88c6b8, 0);
        }
    }
    if (field_1a8) {
        sub_541630(field_1a8, 0);
        field_1a8 = 0;
    }
    RefCounted* rc = field_1ac;
    field_1ac = 0;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = *(void***)rc;
            ((void(__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void(__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }
    void* r2 = sub_5a56b0(result);
    if (r2) {
        char* base = (char*)result;
        void* ecx_val = *(void**)(base + 0xec);
        void* edx_val = *(void**)((char*)ecx_val + 8);
        void* edx2 = *(void**)((char*)edx_val + (int)base + 0xec);
        void* edx3 = *(void**)edx2;
        float f1, f2, f3;
        ((void(__thiscall*)(void*, float*))edx3)((char*)edx_val + (int)base + 0xec, &f1);
        float a = f1;
        float b = f2;
        float c = f3 + g_79f2fc;
        float d = g_7a32e8;
        float out[3];
        sub_509640(out, &a, 2);
        float x = out[0] * d;
        float y = out[1] * d;
        float z = out[2] * d;
        float rx = x + a;
        float ry = y + b;
        float rz = z + c;
        void* inst = sub_5d1ae0();
        if (inst) {
            sub_5bae60(inst, rx, ry, rz);
            float one = 1.0f;
            float v[3];
            v[0] = one;
            v[1] = one;
            v[2] = one;
            sub_578000(inst, v);
        }
    }
    sub_5d3090();
    return 0;
}
