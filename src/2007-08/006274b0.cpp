// from server: 100% by colin
struct SeparateStage {
    void doStage(void*);
};

struct StageTarget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
};

struct ChildHolder {
    char pad[0x1c];
    void addChild(void**);
};

struct FinalTarget {
    void finalize(SeparateStage*);
};

extern "C" void __stdcall sub_609140(void*, void*);

void SeparateStage::doStage(void* arg) {
    StageTarget* t = (StageTarget*)arg;
    void* p = *(void**)((char*)this + 8);
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[5];
    fn(p, t);
    int r = t->v3();
    if (r == 1) {
        void* tmp = t;
        ((ChildHolder*)((char*)this + 0x1c))->addChild(&tmp);
    }
    ((FinalTarget*)t)->finalize(this);
}
