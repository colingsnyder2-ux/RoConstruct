// from server: 84% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);
extern "C" void *__cdecl sub_450AC0();

struct BallBlockConnector
{
    BallBlockConnector *next;
    BallBlockConnector *filler1;
    BallBlockConnector *filler2;
    BallBlockConnector *link;
    BallBlockConnector *filler3;
    BallBlockConnector *filler4;
    BallBlockConnector *filler5;
    BallBlockConnector *filler6;
    BallBlockConnector *filler7;
    BallBlockConnector *f(int);
};

BallBlockConnector *BallBlockConnector::f(int remove)
{
    BallBlockConnector *p;
    BallBlockConnector *q;

    if (remove & 1)
    {
        p = (BallBlockConnector *)sub_450AC0();
        EnterCriticalSection(p);
        q = p->link;
        next = q;
        q->link = this;
        LeaveCriticalSection(p);
    }
    return this;
}
