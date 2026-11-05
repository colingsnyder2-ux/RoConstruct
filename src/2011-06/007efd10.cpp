// from server: 59% by atomic.potato
struct Stage {
    char pad0[8];
    void removeFromStage(Stage*);
};

struct IPipelined {
    char pad0[4];
    Stage* stage;
    void removeFromStage(Stage*);
};

struct MechToAssemblyStage {
    char pad0[8];
    IPipelined* pipelined;
    void func(Stage*);
};

void __stdcall sub_7efc60(void*, void*);
void __stdcall sub_7b42a0(void*, void*);

void MechToAssemblyStage::func(Stage* s) {
    IPipelined* p = this->pipelined;
    sub_7efc60((void*)0x7b4270, p->stage);
    sub_7b42a0(p->stage, s);
    p->removeFromStage(s);
}
