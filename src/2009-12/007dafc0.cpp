// from server: 74% by atomic.potato
struct IPipelined {
    void removeFromStage(void* stage);
};

struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void func(void* stage);
};

void func_007daf10(void* a, void* b, void* c);
void func_007b8ff0(void* a, void* b);

void MechToAssemblyStage::func(void* stage)
{
    func_007daf10((char*)stage + 8, (void*)0x7b8f90, field8);
    func_007b8ff0(field8, stage);
    ((IPipelined*)stage)->removeFromStage(this);
}
