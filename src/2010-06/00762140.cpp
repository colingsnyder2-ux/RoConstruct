// from server: 72% by atomic.potato
struct TreeStage
{
    TreeStage *f(void *, void *);
};

TreeStage *TreeStage::f(void *a, void *b)
{
    ((void (__thiscall *)(TreeStage *, void *, void *, int))0x905b00)(this, b, a, 100);
    return this;
}
