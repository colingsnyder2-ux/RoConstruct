// from server: 33% by atomic.potato
struct LegacyHopperService {
    void* field0;
    char pad4[0x10];
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    char pad24[0x6c];
    void* field8c;
    void* init();
};

extern "C" void __stdcall sub_625960();
extern "C" void* __stdcall sub_5ea4f0();
extern int dword_a4a6bc;

void* LegacyHopperService::init()
{
    sub_625960();
    field0 = (void*)0x8d9ea4;
    field14 = (void*)0x8d9e98;
    field18 = (void*)0x8d9e90;
    field20 = (void*)0x8d9e88;
    field8c = (void*)0x8d9e80;
    field1c = sub_5ea4f0();
    dword_a4a6bc++;

    return this;
}
