// from server: 34% by atomic.potato
struct StepJointsStage {
    void* vfptr;
    int field_4;
    void* field_8;
    void* field_c;
    StepJointsStage* ctor(void* a, void* b);
};

struct Helper {
    void init(void* a, void* b);
};

extern "C" void* __cdecl func_0098211a(unsigned int size);

StepJointsStage* StepJointsStage::ctor(void* a, void* b)
{
    void* mem = func_0098211a(0x10);
    void* obj;
    if (mem) {
        ((Helper*)mem)->init(this, b);
        obj = mem;
    } else {
        obj = 0;
    }
    this->field_4 = (int)a;
    this->field_c = b;
    this->field_8 = obj;
    this->vfptr = (void*)0xbfae70;
    return this;
}
