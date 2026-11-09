// from server: 44% by atomic.potato
struct HumanoidStage {
    void* vfptr;
    int field4;
    void* field8;
    void* fieldC;
    HumanoidStage* ctor(void* a2, void* a3);
};

extern "C" void* __cdecl func_00718a38(unsigned int size);
extern "C" void* __cdecl func_006daf20(void* self, void* a2, void* a3);

HumanoidStage* HumanoidStage::ctor(void* a2, void* a3)
{
    void* mem = func_00718a38(0x30);
    void* obj;
    if (mem) {
        obj = func_006daf20(mem, this, a2);
    } else {
        obj = 0;
    }
    this->field4 = (int)a3;
    this->fieldC = a2;
    this->field8 = obj;
    this->vfptr = (void*)0x8ee984;
    return this;
}
