// from server: 47% by atomic.potato
struct VPlayer_EventDesc {
    void* vfptr0;
    void* vfptr1;
    char pad0[0x18 - 8];
    void* vfptr18;
    void* vfptr1c;
    void* field20;
    char pad1[0x94 - 0x24];
    void* vfptr94;
};

extern "C" void __stdcall sub_690000();
extern "C" void* __stdcall sub_650250();
extern int dword_B900EC;

VPlayer_EventDesc* sub_694680(VPlayer_EventDesc* self);

VPlayer_EventDesc* sub_694680(VPlayer_EventDesc* self)
{
    sub_690000();
    self->vfptr0 = (void*)0x9d1cb4;
    self->vfptr1 = (void*)0x9d1cac;
    self->vfptr18 = (void*)0x9d1ca0;
    self->vfptr1c = (void*)0x9d1c98;
    self->vfptr94 = (void*)0x9d1c90;
    self->field20 = sub_650250();
    dword_B900EC++;
    return self;
}
