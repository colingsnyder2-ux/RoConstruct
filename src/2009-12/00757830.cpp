// from server: 47% by atomic.potato
struct VFrame {
    void* vf0;
    void* vf4;
    char pad8[0x10];
    void* vf18;
    void* vf1c;
    char pad20[0x74];
    void* vf94;
    void* vf98;
    void* field20;
    void construct(void* a, void* b);
};

extern "C" void __stdcall sub_771530(void* a, void* b);
extern "C" void* __stdcall sub_651a60();

extern int dword_B8FF04;

VFrame* __stdcall VFrame_ctor(VFrame* self, void* a, void* b)
{
    self->construct(a, b);
    self->vf0 = (void*)0x9e541c;
    self->vf4 = (void*)0x9e5410;
    self->vf18 = (void*)0x9e5404;
    self->vf1c = (void*)0x9e53fc;
    self->vf94 = (void*)0x9e53ec;
    self->vf98 = (void*)0x9e53d4;
    self->field20 = sub_651a60();
    dword_B8FF04++;
    return self;
}
