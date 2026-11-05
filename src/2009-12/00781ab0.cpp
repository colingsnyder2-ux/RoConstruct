// from server: 50% by atomic.potato
struct S_func_00781ab0 {
    char pad0[8];
    char field8[0x18];
    char field20;
    char pad21[3];
    int field24;
    int field28;
    void f();
};

extern "C" void __cdecl sub_00782f20(void*);
extern "C" int __cdecl sub_00782a60(void*);
extern "C" char __cdecl sub_007826e0(void*);
extern "C" void* __cdecl sub_00782f90(void*, void*);
extern "C" void __cdecl sub_0068c500(void*);

extern float g_9af2dc;

void S_func_00781ab0::f()
{
    if (field24 == 1) {
        sub_00782f20(field8);
    }
    sub_00782a60(field8);
    if (sub_007826e0(field8)) {
        float tmp[4];
        void* p = sub_00782f90(tmp, field8);
        float x = *(float*)((char*)p + 0xc) + *(float*)p;
        float y = *(float*)((char*)p + 0x10) + *(float*)((char*)p + 4);
        float z = *(float*)((char*)p + 0x14) + *(float*)p + 8;
        x *= g_9af2dc;
        y *= g_9af2dc;
        z *= g_9af2dc;
        float out[4];
        out[0] = x;
        out[1] = y;
        out[2] = z;
        out[3] = *(float*)((char*)p + 0x10);
        sub_0068c500(out);
    }
    field20 = 1;
}
