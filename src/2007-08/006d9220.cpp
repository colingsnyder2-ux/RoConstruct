// from server: 100% by EspClaude
// roc 2007-08 006d9220  unit: CXTPDockingPaneSplitterContainer  size: 317 bytes
// Rewritten from the target bytes (see roc check diff):
//  - virtual override called on the second-base subobject; _InsertPane is
//    called on [this - 0x20] (lea ecx,[ebp-0x20]);
//  - list head/count at subobject +0x3c/+0x44, BOOL at +0x70, pane int at +0x34;
//  - cdecl PX helpers: PX_Bool 4 args, PX_Int 3 args (storing) / 4 args (loading);
//  - wsprintfA through the IAT; layout reader map at pPX+0x20, loading flag at +0x24;
//  - frame 0x10c: nCount [esp+0x10], nIndex [esp+0x14], buffer [esp+0x18..0x108).

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char *lpOut, const char *lpFmt, ...);

struct CXTPDockingPaneBase;

struct PaneMap {
    CXTPDockingPaneBase *&operator[](int key);
};

struct CXTPPropExchange {
    char pad[0x20];
    PaneMap *m_pPrivateData;
    int m_bLoading;
    int IsLoading() const { return m_bLoading; }
};

int PX_Bool(CXTPPropExchange *pPX, const char *pszPropName, int &bValue, int bDefault);
int PX_Int(CXTPPropExchange *pPX, const char *pszPropName, int &nValue);
int PX_Int(CXTPPropExchange *pPX, const char *pszPropName, int &nValue, int nDefault);

struct CPrimaryBase {
    virtual ~CPrimaryBase();
    char pad[0x1c];
};

struct CXTPDockingPaneBase {
    virtual int DoPropExchange(CXTPPropExchange *pPX);
    char pad[0x30];
    int m_nIndex;
};

struct PaneNode {
    PaneNode *pNext;
    PaneNode *pPrev;
    CXTPDockingPaneBase *data;
};

struct PaneList {
    void *vtbl;
    PaneNode *m_pNodeHead;
    PaneNode *m_pNodeTail;
    int m_nCount;
    void *GetHeadPosition() const { return m_pNodeHead; }
    CXTPDockingPaneBase *&GetNext(void *&rPosition)
    {
        PaneNode *pNode = (PaneNode *)rPosition;
        rPosition = (void *)pNode->pNext;
        return pNode->data;
    }
};

struct CXTPDockingPaneSplitterContainer : CPrimaryBase, CXTPDockingPaneBase {
    PaneList m_lstPanes;
    char pad2[0x28];
    int m_bHoriz;

    virtual int DoPropExchange(CXTPPropExchange *pPX);
    void _InsertPane(CXTPDockingPaneBase *pPane, CXTPDockingPaneBase *pNeighbour, int bAfter);
};

int CXTPDockingPaneSplitterContainer::DoPropExchange(CXTPPropExchange *pPX)
{
    CXTPDockingPaneBase::DoPropExchange(pPX);
    PX_Bool(pPX, "Horiz", m_bHoriz, 0);

    char szItem[256];
    int nCount = 0;

    if (!pPX->IsLoading()) {
        nCount = m_lstPanes.m_nCount;
        PX_Int(pPX, "Panes", nCount);

        int i = 1;
        void *pos = m_lstPanes.GetHeadPosition();
        while (pos) {
            CXTPDockingPaneBase *pPane = m_lstPanes.GetNext(pos);
            wsprintfA(szItem, "Pane-%d", i++);
            PX_Int(pPX, szItem, pPane->m_nIndex);
        }
    } else {
        PX_Int(pPX, "Panes", nCount, 0);
        PaneMap *pMap = pPX->m_pPrivateData;
        int nIndex = 0;
        for (int i = 1; i <= nCount; i++) {
            wsprintfA(szItem, "Pane-%d", i);
            PX_Int(pPX, szItem, nIndex, 0);
            CXTPDockingPaneBase *pPane = (*pMap)[nIndex];
            if (pPane == 0)
                return 0;
            _InsertPane(pPane, 0, 1);
        }
    }
    return 1;
}
