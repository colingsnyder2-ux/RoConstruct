// from server: 63% by atomic.potato
struct KernelJoint {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
};

extern "C" void __stdcall sub_005f49b0();
extern "C" void __fastcall sub_005f3900(void*, int, const void*);

extern float g_9af2dc;

KernelJoint* __stdcall sub_006e3210(KernelJoint* self, const void* src)
{
    sub_005f49b0();
    sub_005f3900(self, 0, src);
    self->f24 = 0.0f;
    self->f28 = g_9af2dc;
    self->f2c = 0.0f;
    return self;
}
