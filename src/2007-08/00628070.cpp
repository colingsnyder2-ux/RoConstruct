// from server: 100% by tester
struct Assembly;

struct IStage {
    void removeFromStage(IStage* stage);
};

struct AssemblyStage {
    char pad[8];
    void* field8;
    char pad2[4];
    void* field10;
    void onFixedAssemblyRootRemoving(Assembly* a);
    void onEngineChanged(Assembly* a);
};

struct Assembly {
    bool getAnchored();
};

struct Helper1 {
    void method(void* arg);
};

struct Helper2 {
    void method(void* arg);
};

struct SeparateStage {
    char pad[8];
    Helper1* field8;
    void process(void* arg);
};

void AssemblyStage::onEngineChanged(Assembly* a) {
    if (!a->getAnchored()) {
        ((SeparateStage*)field8)->process(a);
    }
    void* local;
    ((Helper2*)((char*)this + 0x10))->method(&local);
    ((IStage*)a)->removeFromStage((IStage*)this);
}
