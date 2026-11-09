// from server: 100% by atomic.potato
extern "C" void *(__stdcall *CreateEventA)(void *, int, int, const char *);

struct SequenceBase
{
    void *initialize(unsigned char);
};

extern "C" void __cdecl SequenceBase_Initialize();

void *SequenceBase::initialize(unsigned char manualReset)
{
    *(void **)this = 0;
    *(void **)this = CreateEventA(0, manualReset != 0, 0, 0);
    if (*(void **)this == 0)
        SequenceBase_Initialize();
    return this;
}
