// from server: 76% by atomic.potato
struct Stage;

struct IPipelined {
    char pad0[4];
    Stage* stage;
    void removeFromStage(Stage*);
};

struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void func(void*);
};

extern "C" void __stdcall sub_78d2c0(void*, void*, void*);
extern "C" void __stdcall sub_760bf0(void*, void*);

void MechToAssemblyStage::func(void* arg) {
    void* p = field8;
    sub_78d2c0((char*)arg + 8, (void*)0x760c30, p);
    sub_760bf0(field8, arg);
    ((IPipelined*)arg)->removeFromStage((Stage*)this);
}
