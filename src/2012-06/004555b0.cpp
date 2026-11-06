// from server: 100% by tajop
struct CREATESTRUCTA;

extern "C" long (__stdcall *__imp__InterlockedIncrement)(long volatile* lpAddend);

struct CXTPImageManager
{
    void* vtbl;
    long m_dwRef;
};

CXTPImageManager* XTPImageManager();

struct CXTPPropertyGridItemEnumXItem
{
    int Default();
    void SetTheme(int nTheme);
    void SetImageManager(CXTPImageManager* pImageManager);
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
};

int CXTPPropertyGridItemEnumXItem::OnCreate(CREATESTRUCTA* lpCreateStruct)
{
    if (Default() == -1)
        return -1;

    SetTheme(6);
    __imp__InterlockedIncrement(&XTPImageManager()->m_dwRef);
    SetImageManager(XTPImageManager());
    return 0;
}
