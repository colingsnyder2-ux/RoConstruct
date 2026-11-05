// from server: 86% by colin
struct Joint;

struct StepJointsStage {
    void onSimulateAssemblyAdded(Joint* j);
};

extern "C" void __stdcall func_00917430(StepJointsStage* stage, Joint* j);
extern "C" void __fastcall func_00928270(void* self, Joint* j);

void StepJointsStage::onSimulateAssemblyAdded(Joint* j)
{
    func_00917430(this, j);
    func_00928270(*(void**)((char*)this + 8), j);
}
