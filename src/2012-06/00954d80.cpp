// from server: 68% by atomic.potato
struct MechToAssemblyStage {
    char pad0[8];
    void* field8;
    void method(void* arg);
};

void helper1(void* a, void* b, void* c);
void helper2(void* a, void* b);
void helper3(void* a, void* b);

void MechToAssemblyStage::method(void* arg) {
    void* p = field8;
    helper1((char*)arg + 8, (void*)0x925c40, p);
    helper2(field8, arg);
    helper3(arg, this);
}
