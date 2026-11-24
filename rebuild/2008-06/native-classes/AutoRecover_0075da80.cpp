// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
typedef unsigned long DWORD;

class CXTPDockingPanePaintManager {
public:
    char pad[0x2c];
    int m_bShowCaption; // INFERRED: offset 0x2c tested by the target
};

class CXTPDockingPane {
public:
    DWORD GetOptions() const;
};

class CXTPDockingPaneBase {
public:
    CXTPDockingPanePaintManager* GetPaintManager() const;
    char pad[0x144]; // INFERRED: fills to 0x198 in the container
};

// INFERRED: layout stub; the real header is not available. Base subobject sits at 0x54.
struct TabbedContainerPrefix { char pad[0x54]; };

class CXTPDockingPaneTabbedContainer : public TabbedContainerPrefix, public CXTPDockingPaneBase {
public:
    int IsTitleVisible() const;
    int m_198;
    char pad2[8];
    CXTPDockingPane* m_pSelectedPane; // 0x1a4
};

int CXTPDockingPaneTabbedContainer::IsTitleVisible() const
{
    if (m_198 && m_pSelectedPane &&
        !(m_pSelectedPane->GetOptions() & 8) &&
        GetPaintManager()->m_bShowCaption)
        return 1;
    return 0;
}
