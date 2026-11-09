// from server: 100% by atomic.potato
struct CXTPReportRecords {
    int GetCount() const;
    void* GetAt(int nIndex);
    void SetIndex(int nIndex);
};

void CXTPReportRecords::SetIndex(int nIndex) {
    int i = nIndex;
    if (i < GetCount()) {
        do {
            void* p = GetAt(i);
            *(int*)((char*)p + 0x4c) = i;
            ++i;
        } while (i < GetCount());
    }
}
