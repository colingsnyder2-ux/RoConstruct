// from server: 80% by atomic.potato
struct EdgeStage
{
    EdgeStage();
    int value;
    int field0c;
    int field10;
    int field14;
};

extern void func_007219d0(void *);

EdgeStage::EdgeStage()
{
    *(int *)this = 0xc06c48;
    func_007219d0((char *)this + 4);
    field14 = 0;
}
