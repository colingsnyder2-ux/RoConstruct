// from server: 66% by atomic.potato
extern void *G_0078c1e0;
extern int G_00676790(void *);
extern void G_00699fa0(void *, void *, void *);

struct AssemblyStage
{
    void f(void *);
};

void AssemblyStage::f(void *arg)
{
    int value = G_00676790(arg);
    G_00699fa0(arg, this, G_0078c1e0);
    (void)value;
}
