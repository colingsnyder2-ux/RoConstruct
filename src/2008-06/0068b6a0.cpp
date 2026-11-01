// from server: 100% by atomic.potato
extern "C" void Function_006A067A(void *);

struct SceneMgrQueuedRenderableVisitor
{
    void *vptr;
    SceneMgrQueuedRenderableVisitor *f(unsigned char);
};

void *Global_00804794;

SceneMgrQueuedRenderableVisitor *
SceneMgrQueuedRenderableVisitor::f(unsigned char flag)
{
    vptr = (void *)0x84e9a4;
    vptr = Global_00804794;
    if (flag & 1)
        Function_006A067A(this);
    return this;
}
