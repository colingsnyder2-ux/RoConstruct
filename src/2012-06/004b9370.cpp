// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

#include <new>
class CBaseList {
public:
    class CNode {
        CNode *m_pPrev; CNode *m_pNext; void *m_pObject;
    public:
        CNode() {}
        CNode *Prev() const { return m_pPrev; }
        CNode *Next() const { return m_pNext; }
        void SetPrev(CNode *p) { m_pPrev = p; }
        void SetNext(CNode *p) { m_pNext = p; }
        void *GetData() const { return m_pObject; }
        void SetData(void *p) { m_pObject = p; }
    };
    class CNodeCache {
    public:
        CNode *RemoveFromCache() {
            CNode *node = m_pHead;
            if (node != 0) { m_pHead = node->Next(); m_iUsed--; }
            return node;
        }
        int m_iCacheSize; int m_iUsed; CNode *m_pHead;
    };
    CNode *m_pFirst; CNode *m_pLast; long m_Count; CNodeCache m_Cache;
    void *AddTailI(void *pObject);
};
void *CBaseList::AddTailI(void *pObject)
{
    CNode *pNode = (CNode *) m_Cache.RemoveFromCache();
    if (pNode == 0) {
        pNode = new CNode;
    }
    if (pNode == 0) { return 0; }
    pNode->SetData(pObject);
    pNode->SetNext(0);
    pNode->SetPrev(m_pLast);
    if (m_pLast == 0) { m_pFirst = pNode; } else { m_pLast->SetNext(pNode); }
    m_pLast = pNode;
    ++m_Count;
    return pNode;
}
