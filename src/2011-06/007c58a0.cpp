// from server: 91% by atomic.potato
extern "C" void* sub_7c55d0(void);
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct BallPlaneConnector
{
    BallPlaneConnector* next;
    char padding[20];
    BallPlaneConnector* linked;
    BallPlaneConnector* f(int);
};

BallPlaneConnector* BallPlaneConnector::f(int flag)
{
    if (flag & 1)
    {
        BallPlaneConnector* p = (BallPlaneConnector*)sub_7c55d0();
        EnterCriticalSection(p);
        next = p->linked;
        p->linked = this;
        LeaveCriticalSection(p);
    }
    return this;
}
