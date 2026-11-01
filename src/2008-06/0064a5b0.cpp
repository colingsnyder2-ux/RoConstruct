// from server: 100% by king_originala
struct Edge {
    int pad0;
    void* prim0;
    int pad8;
    int padC;
    int pad10;
    int pad14;
    void* joint;
};

struct IStage {
    virtual int getStageType();
    virtual int getPriority();
};

struct CleanStage : IStage {
    int getPriority();
    void* primitivesAreOk(Edge* e);
};

void* CleanStage::primitivesAreOk(Edge* e)
{
    if (e->prim0 != 0) {
        if (((IStage*)e->prim0)->getPriority() >= getPriority())
            return *(void**)e->joint;
    }
    return 0;
}
