// from server: 41% by colin
struct VClientSignalDesc {
    void construct();
};

extern "C" void __cdecl sub_4994D0();
extern "C" void* __cdecl sub_4991B0();

void VClientSignalDesc::construct()
{
    sub_4994D0();
    *(void**)((char*)this + 0x00) = (void*)0x79c2e4;
    *(void**)((char*)this + 0x04) = (void*)0x79c2dc;
    *(void**)((char*)this + 0x10) = (void*)0x79c2d4;
    *(void**)((char*)this + 0x14) = (void*)0x79c2c4;
    *(void**)((char*)this + 0x2c) = (void*)0x79c2b4;
    *(void**)((char*)this + 0x44) = (void*)0x79c2a4;
    *(void**)((char*)this + 0x5c) = (void*)0x79c294;
    *(void**)((char*)this + 0x74) = (void*)0x79c284;
    *(void**)((char*)this + 0x8c) = (void*)0x79c274;
    *(void**)((char*)this + 0xe8) = (void*)0x79c244;
    *(void**)((char*)this + 0xec) = (void*)0x79c238;
    *(void**)((char*)this + 0x0c) = sub_4991B0();
}
