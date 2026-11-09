// from server: 100% by colin
struct VCWorkspaceComObject {
    void* m_pVtbl;
    unsigned char m_bInitialized;
    int Initialize();
};

extern "C" void (__stdcall *EnterCriticalSection)(void* lpCriticalSection);

int VCWorkspaceComObject::Initialize()
{
    EnterCriticalSection(m_pVtbl);
    m_bInitialized = 1;
    return 0;
}
