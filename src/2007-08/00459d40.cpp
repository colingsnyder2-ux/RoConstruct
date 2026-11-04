// from server: 47% by Intel
struct VTextureArgs {
    void ctor();
    int pad0;
    int field4;
    int field8;
};

extern "C" void __cdecl func_00459700(void* thisptr);

void VTextureArgs::ctor()
{
    int cookie = *(int*)0x8b5188 ^ (int)&cookie;
    VTextureArgs* self = this;
    int* sehFrame = (int*)(&cookie + 1);
    *sehFrame = cookie;
    *(int*)0 = (int)sehFrame;

    self->field8 = 0;
    int* vtablePtr = (int*)((char*)self + 8);
    *vtablePtr = 0x793624;
    func_00459700(vtablePtr);

    *(int*)self = 0x7931b4;

    *(int*)0 = *sehFrame;
}
