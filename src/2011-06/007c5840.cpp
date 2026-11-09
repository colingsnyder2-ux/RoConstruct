// from server: 64% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;
typedef void* LPVOID;

struct CRITICAL_SECTION
{
    DWORD reserved[6];
};

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

struct BallVertexConnector
{
    BallVertexConnector* next;
    char padding[20];
    CRITICAL_SECTION* lock;
    BallVertexConnector* link;
    BallVertexConnector* f(int);
};

extern "C" BallVertexConnector* GetConnector(BallVertexConnector*);

BallVertexConnector* BallVertexConnector::f(int flags)
{
    BallVertexConnector* result = this;
    if (flags & 1)
    {
        BallVertexConnector* value = GetConnector(this);
        EnterCriticalSection(value->lock);
        this->next = value->link;
        value->link = this;
        LeaveCriticalSection(value->lock);
    }
    return result;
}
