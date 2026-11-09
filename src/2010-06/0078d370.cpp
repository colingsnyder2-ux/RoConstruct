// from server: 65% by atomic.potato
struct Stage {
    char pad0[8];
};

struct IPipelined {
    char pad0[4];
    void* field4;
    void removeFromStage(Stage* s);
};

struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void func(Stage* s);
};

extern "C" void __stdcall sub_78d2c0(void*, void*, void*);
extern "C" void __stdcall sub_760cb0(void*, void*);

void MechToAssemblyStage::func(Stage* s) {
    void* a = this->field8;
    sub_78d2c0((char*)s + 8, (void*)0x760c80, a);
    sub_760cb0(this->field8, s);
    ((IPipelined*)s)->removeFromStage(s);
}
