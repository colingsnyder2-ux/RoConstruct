// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct CXTPReportPaintManager {
    char pad_000[0x1e8];
    int offset_1e8;
    char pad_1ec[0x238 - 0x1ec];
    int offset_238;
    char pad_23c[0x28c - 0x23c];
    int offset_28c;
    int GetRowHeight(void* pDC, void* pRow);
};

int CXTPReportPaintManager::GetRowHeight(void* pDC, void* pRow)
{
    int result = (*(int (__thiscall **)(void*))((*(int*)pRow) + 0x88))(pRow);
    if (result == 0)
    {
        return (this->offset_28c != 0 ? 1 : 0) + this->offset_238;
    }
    if (this->offset_1e8 != 0)
    {
        return this->offset_238 + 6;
    }
    return this->offset_238 + 0x10;
}
