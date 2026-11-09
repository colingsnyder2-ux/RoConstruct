// from server: 28% by atomic.potato
struct TreeStage
{
    void func_00928160(int, int, int);
};

void TreeStage::func_00928160(int, int, int)
{
}

TreeStage* __stdcall func_00928250(TreeStage* stage, int a, int b)
{
    stage->func_00928160(b, a, 100);
    return stage;
}
