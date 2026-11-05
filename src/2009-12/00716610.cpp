// from server: 25% by atomic.potato
struct VMotor {
    char pad0[0x20];
    void* field20;
    void* ctor();
};

extern "C" void __stdcall sub_637e60();
extern "C" void* __stdcall sub_64fc30();
extern int dword_B8FF50;

void* VMotor::ctor()
{
    sub_637e60();
    *(void**)this = (void*)0x9dea44;
    *(void**)((char*)this + 4) = (void*)0x9dea3c;
    *(void**)((char*)this + 0x18) = (void*)0x9dea30;
    *(void**)((char*)this + 0x1c) = (void*)0x9dea28;
    field20 = sub_64fc30();
    dword_B8FF50++;
    return this;
}
