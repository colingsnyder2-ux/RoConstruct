// from server: 100% by king_originala
extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void *);
    extern void (__stdcall *LeaveCriticalSection)(void *);
}

unsigned char criticalSection[24];

#pragma pack(push, 4)
struct CRobloxWnd {
    unsigned char padding[0x3c];
    double value;
    void setValue(double v);
};
#pragma pack(pop)

void CRobloxWnd::setValue(double v)
{
    EnterCriticalSection(criticalSection);
    value = v;
    LeaveCriticalSection(criticalSection);
}
