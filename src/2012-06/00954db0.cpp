// from server: 71% by atomic.potato
struct MechToAssemblyStage;

extern "C" void __stdcall sub_00917430(MechToAssemblyStage*);
extern "C" void __stdcall sub_00925b60(int, MechToAssemblyStage*);
extern "C" void __stdcall sub_00954cc0(void*, void*, int);

struct MechToAssemblyStage {
    char pad[8];
    int field8;
    void method(MechToAssemblyStage* other);
};

void MechToAssemblyStage::method(MechToAssemblyStage* other)
{
    sub_00917430(other);
    sub_00925b60(field8, other);
    sub_00954cc0((void*)0x925ba0, (char*)other + 8, field8);
}
