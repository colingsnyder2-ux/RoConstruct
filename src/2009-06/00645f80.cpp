// from server: 25% by atomic.potato
struct SoundService {
    void* ctor();
    char pad0[0x14];
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
};

extern "C" void __stdcall sub_5d2e80();
extern "C" void* __stdcall sub_645f10();
extern unsigned int dword_a4c260;

void* SoundService::ctor()
{
    sub_5d2e80();
    *(void**)this = (void*)0x8de36c;
    *(void**)((char*)this + 0x14) = (void*)0x8de35c;
    *(void**)((char*)this + 0x18) = (void*)0x8de354;
    *(void**)((char*)this + 0x20) = (void*)0x8de34c;
    *(void**)((char*)this + 0x1c) = sub_645f10();
    dword_a4c260++;

    return this;
}
