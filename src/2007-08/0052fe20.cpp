// from server: 100% by colin
struct ICameraSubject {
    char pad[0xec];
    void* field_ec;
    void construct();
};

extern "C" void __cdecl func_005bb520();

void ICameraSubject::construct()
{
    void* p = field_ec;
    *(void**)((char*)this + 0x00) = (void*)0x7a4d74;
    *(void**)((char*)this + 0x04) = (void*)0x7a4d6c;
    *(void**)((char*)this + 0x10) = (void*)0x7a4d64;
    *(void**)((char*)this + 0x14) = (void*)0x7a4d54;
    *(void**)((char*)this + 0x2c) = (void*)0x7a4d44;
    *(void**)((char*)this + 0x44) = (void*)0x7a4d34;
    *(void**)((char*)this + 0x5c) = (void*)0x7a4d24;
    *(void**)((char*)this + 0x74) = (void*)0x7a4d14;
    *(void**)((char*)this + 0x8c) = (void*)0x7a4d04;
    *(void**)((char*)this + 0xe8) = (void*)0x7a4cf8;
    void* v1 = *(void**)((char*)p + 4);
    *(void**)((char*)v1 + (int)this + 0xec) = (void*)0x7a4cec;
    void* v2 = *(void**)((char*)field_ec + 8);
    *(void**)((char*)v2 + (int)this + 0xec) = (void*)0x7a4ce4;
    func_005bb520();
}
