// from server: 76% by atomic.potato
struct Stage;

struct IPipelined {
    void removeFromStage(Stage*);
};

struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void func(Stage*);
};

extern "C" void __stdcall sub_7efc60(void*, void*, void*);
extern "C" void __stdcall sub_7b41d0(void*, void*);

void MechToAssemblyStage::func(Stage* s) {
    void* p = this->field8;
    sub_7efc60((char*)s + 8, (void*)0x7b41f0, p);
    sub_7b41d0(this->field8, s);
    ((IPipelined*)s)->removeFromStage((Stage*)this);
}
