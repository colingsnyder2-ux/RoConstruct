// from server: 100% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct DxUserInput
{
    void *field0;
    CRITICAL_SECTION *field4;
    unsigned char field8;

    void f();
};

void DxUserInput::f()
{
    if (field8)
    {
        LeaveCriticalSection(field4);
        field8 = 0;
    }
}
