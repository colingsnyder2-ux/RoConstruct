// from server: 56% by atomic.potato
struct MechToAssemblyStage
{
    int unused0;
    int unused1;
    int pipeline;
    int f(int stage);
};

struct Pipeline
{
    int unused0;
    int unused1;
};

extern "C" void removeFromStage(Pipeline *, int);
extern "C" void processStage(int *, MechToAssemblyStage *);

int MechToAssemblyStage::f(int stage)
{
    removeFromStage((Pipeline *)pipeline, stage);
    processStage(&stage, this);
    return 0;
}
