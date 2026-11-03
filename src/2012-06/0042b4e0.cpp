// from server: 27% by Intel





extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedBase {
    long refCount;
    virtual void Release() = 0;
    virtual void DeleteThis() = 0;
};

struct TreeNode {
    RefCountedBase* pData;
    int nIndex;
};

struct TreeCtrl {
    virtual TreeNode* GetItemData(int nIndex) = 0;
    virtual int FindItem(TreeNode* pNode, int nStartIndex, int nEndIndex) = 0;
};

int __stdcall CRobloxTreeCtrl_FindItem(TreeCtrl* pThis, int nStartIndex, int nEndIndex, TreeNode* pNode, unsigned char* pbFound) {
    TreeNode* pItemData = 0;
    __try {
        pItemData = pThis->GetItemData(nStartIndex);
    }
    __except(1) {
    }

    RefCountedBase* pData = 0;
    int nIndex = 0;
    if (pItemData) {
        pData = pItemData->pData;
        nIndex = pItemData->nIndex;
        if (pData) {
            _InterlockedExchangeAdd(&pData->refCount, 1);
        }
    }

    unsigned char bFlag = 1;
    RefCountedBase* pNodeData = 0;
    if (pNode) {
        pNodeData = pNode->pData;
        if (pNodeData) {
            if (_InterlockedExchangeAdd(&pNodeData->refCount, -1) == 1) {
                pNodeData->Release();
                if (_InterlockedExchangeAdd((volatile long*)((char*)pNodeData + 8), -1) == 1) {
                    pNodeData->DeleteThis();
                }
            }
        }
    }

    int nResult = pThis->FindItem(pNode, nStartIndex, nEndIndex);
    if (nResult) {
        int nFound = pThis->FindItem((TreeNode*)nResult, 0, 0);
        if (nFound >= 0) {
            *pbFound = 1;
        }
    }

    bFlag = 0;
    if (pData) {
        if (_InterlockedExchangeAdd(&pData->refCount, -1) == 1) {
            pData->Release();
            if (_InterlockedExchangeAdd((volatile long*)((char*)pData + 8), -1) == 1) {
                pData->DeleteThis();
            }
        }
    }

    TreeNode* pTemp = (TreeNode*)nEndIndex;
    if (pTemp) {
        if (_InterlockedExchangeAdd(&pTemp->pData->refCount, -1) == 1) {
            pTemp->pData->Release();
            if (_InterlockedExchangeAdd((volatile long*)((char*)pTemp->pData + 8), -1) == 1) {
                pTemp->pData->DeleteThis();
            }
        }
    }

    return 0;
}
