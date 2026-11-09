// from server: 50% by atomic.potato
extern "C" void __cdecl TreeStage(void *, void *);

struct Creator
{
    int Create();
};

int Creator::Create()
{
    int a;
    int b;
    *(int *)this = 0x99f56c;
    b = (int)this;
    TreeStage((void *)0xb794d8, &b);
    return (int)this;
}
