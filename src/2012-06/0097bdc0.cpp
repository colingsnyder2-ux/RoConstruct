// from server: 60% by atomic.potato
typedef void *HANDLE;
typedef int BOOL;

extern "C" HANDLE __stdcall CreateEventA(void *, BOOL, BOOL, const char *);

struct S
{
    HANDLE event;
    S();
};

S::S()
{
    event = 0;
    event = CreateEventA(0, 0, *(bool *)((char *)this - 4) != 0, "N(+N$");
    if (!event)
        CreateEventA(0, 0, 0, 0);
}
