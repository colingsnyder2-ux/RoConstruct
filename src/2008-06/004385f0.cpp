// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedIncrement)(volatile long *);
extern long * __cdecl GetSharedObject();

struct S {
    int QueryState();
    void SetMode(int);
    void SetSharedObject(long *);
    int Create(void *);
};

int S::Create(void *)
{
    if (QueryState() == -1)
        return -1;

    SetMode(6);
    InterlockedIncrement(GetSharedObject() + 1);
    SetSharedObject(GetSharedObject());
    return 0;
}
