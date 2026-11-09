// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_(const CStringT_& p) { m_pszData = p.m_pszData; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) int Compare(const T* p) const { return p == m_pszData; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;

CString __cdecl operator+(const CString& a, const CString& b);
CString __cdecl operator+(const CString& a, const char* b);

inline bool operator!=(const CString& a, const char* b) { return a.Compare(b) != 0; }

__declspec(noreturn) void __stdcall AfxThrowInvalidArgException();

class CXTPReportColumn;
class CXTPReportRecordItem {
public:
    virtual ~CXTPReportRecordItem();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26();
    virtual CString GetCaption(CXTPReportColumn* pColumn);
};

class CXTPReportRecords;
template <class TYPE> class CArray_ {
public:
    virtual ~CArray_();
    TYPE* m_pData;
    int m_nSize;
    int GetSize() const { return m_nSize; }
    const TYPE& GetAt(int nIndex) const
    {
        if (nIndex >= 0 && nIndex < m_nSize)
            return m_pData[nIndex];
        AfxThrowInvalidArgException();
    }
};

class CXTPReportRecord {
public:
    char pad[0x20];
    CArray_<CXTPReportRecordItem*> m_arrItems;
    int GetItemCount() const { return (int)m_arrItems.GetSize(); }
    CXTPReportRecordItem* GetItem(int nIndex) const
    {
        return nIndex >= 0 && nIndex < GetItemCount() ? m_arrItems.GetAt(nIndex) : 0;
    }
    CXTPReportRecords* GetChilds();
};

class CXTPReportRecords {
public:
    int GetCount() const;
    CXTPReportRecord* GetAt(int nIndex) const;
};

extern FILE* statsFile;

class CRobloxReportView {
public:
    class CStatsItemRecord {
    public:
        class CNameItem : public CXTPReportRecordItem {};
        class CValueItem : public CXTPReportRecordItem {};
    };
    void dumpStats(CXTPReportRecords* records, CString prefix);
};

void CRobloxReportView::dumpStats(CXTPReportRecords* records, CString prefix)
{
    for (int i = 0; i < records->GetCount(); i++) {
        CXTPReportRecord* record = records->GetAt(i);
        CStatsItemRecord::CNameItem* nameItem;
        CStatsItemRecord::CValueItem* valueItem;
        for (int j = 0; j < record->GetItemCount(); j++) {
            CXTPReportRecordItem* item = record->GetItem(j);
            if (dynamic_cast<CStatsItemRecord::CNameItem*>(item))
                nameItem = dynamic_cast<CStatsItemRecord::CNameItem*>(item);
            if (dynamic_cast<CStatsItemRecord::CValueItem*>(item))
                valueItem = dynamic_cast<CStatsItemRecord::CValueItem*>(item);
        }
        if (valueItem->GetCaption(0) != "" && nameItem->GetCaption(0) != "Render" && nameItem->GetCaption(0) != "Sound") {
            CString line = prefix + nameItem->GetCaption(0) + " = " + valueItem->GetCaption(0) + "\n";
            fprintf(statsFile, "%s", (const char*)line);
        }
        if (nameItem->GetCaption(0) != "Render" && nameItem->GetCaption(0) != "Sound") {
            CXTPReportRecords* children = record->GetChilds();
            if (children)
                dumpStats(children, prefix + nameItem->GetCaption(0) + "::");
        }
    }
}
