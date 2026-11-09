// from server: 57% by atomic.potato
struct IStage;

struct IPipelined {
    void removeFromStage(IStage*);
};

struct AssemblyStage {
    void removeFromStage(IStage*);
};

void AssemblyStage::removeFromStage(IStage* stage)
{
    if (*(IStage**)((char*)stage + 4) != 0 && this != 0) {
        int a = (*(int**)((char*)stage + 4))[1];
        int b = (*(int**)this)[1];
        if (a > b) {
            typedef void (__thiscall *Fn)(void*, IStage*);
            void* p = *(void**)((char*)this + 8);
            ((Fn)(*(void***)p)[4])(p, stage);
        }
    }
    ((IPipelined*)stage)->removeFromStage((IStage*)this);
}
