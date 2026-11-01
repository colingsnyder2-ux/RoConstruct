// from server: 65% by atomic.potato
struct CXTPDockingPaneManager
{
    void Update();
};

struct CXTPDockingPaneBase
{
    int unused;
    int count;
    CXTPDockingPaneManager* manager;
    void* unused2;
    void Release(void*);
};

void CXTPDockingPaneBase::Release(void* value)
{
    *(void**)value = manager;
    if (--count == 0)
        manager->Update();
}
