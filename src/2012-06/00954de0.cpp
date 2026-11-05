// from server: 66% by atomic.potato
struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void method(void* arg);
};

extern "C" void (__thiscall *sub_954CC0)(void*, void*);
extern "C" void __stdcall sub_925B80(void*, void*);
extern "C" void __stdcall sub_917560(void*, void*);

void MechToAssemblyStage::method(void* arg) {
    void* p = field8;
    sub_954CC0((void*)0x925bc0, (char*)arg + 8);
    sub_925B80(field8, arg);
    sub_917560(arg, this);
}
