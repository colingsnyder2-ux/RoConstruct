// from server: 37% by atomic.potato
struct TreeStage
{
    int Get(int);
};

int TreeStage::Get(int index)
{
    if (index == 3)
        return *(int *)((char *)this + 0x28);

    struct VTable
    {
        int (*get)(void *, int);
    };

    return ((VTable *)(*(int **)((char *)this + 8)))->get(
        *(void **)((char *)this + 8), index);
}
