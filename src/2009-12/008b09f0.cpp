// from server: 66% by atomic.potato
struct S
{
    int state;
    int GetDockingPaneManager();
    int f();
};

int S::GetDockingPaneManager()
{
    return state ? *(int *)(state + 0x84) : 0;
}

int S::f()
{
    if (*(int *)((char *)this + 0x18) == 4)
        if (GetDockingPaneManager() && *(int *)(GetDockingPaneManager() + 0xe8))
            return 1;
    return 0;
}
