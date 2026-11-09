// from server: 75% by Intel
extern "C" void __stdcall InitializeCriticalSection(void*);

void __cdecl sub_4018D0(void* thisptr)
{
    __try
    {
        InitializeCriticalSection(thisptr);
    }
    __except (0)
    {
    }
}
