// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native header for the XTP report classes. These minimal
// declarations carry only what the disassembly touches (offsets 0xe0/0x128, vtable slot 0x7c).

class CXTPReportRecord;
class CXTPReportRow;

class CXTPReportRecords
{
public:
    int GetCount() const;
    CXTPReportRecord* GetAt(int nIndex) const;
};

class CXTPReportSelectedRows
{
public:
    void Clear();
    void Add(CXTPReportRow* pRow);
};

// INFERRED: object at this+0xe0 is the report rows collection; slot 0x7c (index 31)
// takes a record and returns its row.
class CXTPReportRows
{
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30();
    virtual CXTPReportRow* FindRow(CXTPReportRecord* pRecord);
};

class CXTPReportControl
{
public:
    int SetFocusedRow(CXTPReportRow* pRow, int bSelectBlock);

protected:
    void _SelectRows(CXTPReportRecords* pRecords);

    char m_pad0[0xe0];                       // INFERRED: padding to m_pRows
    CXTPReportRows* m_pRows;                 // +0xe0
    char m_pad1[0x128 - 0xe4];               // INFERRED: padding to m_pSelectedRows
    CXTPReportSelectedRows* m_pSelectedRows; // +0x128
};

void CXTPReportControl::_SelectRows(CXTPReportRecords* pRecords)
{
    CXTPReportRows* pRows = m_pRows;
    CXTPReportSelectedRows* pSelectedRows = m_pSelectedRows;

    if (pRows == 0 || pSelectedRows == 0)
        return;

    pSelectedRows->Clear();

    int nCount = pRecords->GetCount();
    for (int i = 0; i < nCount; i++)
    {
        CXTPReportRecord* pRecord = pRecords->GetAt(i);
        CXTPReportRow* pRow = pRows->FindRow(pRecord);
        if (pRow)
        {
            pSelectedRows->Add(pRow);
            if (i == nCount - 1)
                SetFocusedRow(pRow, 1);
        }
    }
}
