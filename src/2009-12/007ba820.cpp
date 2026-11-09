// from server: 100% by atomic.potato
struct TreeStage
{
    TreeStage* f(int, int);
    TreeStage* g(int, int, int);
};

TreeStage* TreeStage::f(int a, int b)
{
    g(a, b, 100);
    return this;
}
