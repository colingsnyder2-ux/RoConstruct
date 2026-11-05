// from server: 48% by atomic.potato
struct VCXTPReportRows {
    char pad0[0x30];
    int* m_pRows;
    int m_nCount;
    char pad38[0x8];
    int m_bChanged;
    int m_pReportRecord;
    char pad4c[0x24];
    void SetChanged();
    void SetReportRecord(void*);
    void RemoveAll();

    void SetReportRecord2(void* pRecord);
};

void VCXTPReportRows::SetChanged() {
    m_bChanged = 1;
}

void VCXTPReportRows::SetReportRecord(void* p) {
    m_pReportRecord = (int)p;
}

void VCXTPReportRows::RemoveAll() {
}

void VCXTPReportRows::SetReportRecord2(void* pRecord) {
    if (pRecord == 0)
        return;
    if (m_pReportRecord != *(int*)((char*)pRecord + 0x70))
        SetChanged();
    if (m_nCount == 1) {
        if (m_nCount <= 0)
            return;
        int* p = m_pRows;
        int v = p[1] - 1;
        if (*p != v)
            goto doSet;
        if (m_nCount <= 0)
            return;
        int r = ((int (__thiscall*)(void*))*(int*)(*(int*)pRecord + 0x6c))(pRecord);
        if (*p == r)
            return;
    }
doSet:
    SetChanged();
    RemoveAll();
    m_bChanged = 1;
    m_pReportRecord = *(int*)((char*)pRecord + 0x70);
}
