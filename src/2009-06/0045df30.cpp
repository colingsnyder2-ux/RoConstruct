// from server: 100% by tester
struct CRobloxWnd_FrameRateManagerStatsItem
{
    char pad[0xb8];
    void* ptrB8;
    char pad2[0x8];
    void* ptrC4;
    int fieldC8;
    int fieldCC;

    void sub_45b810();
    void* destroy(char flags);
};

extern "C" void __cdecl free_718a32(void*);

void* CRobloxWnd_FrameRateManagerStatsItem::destroy(char flags)
{
    if (this->ptrC4)
    {
        free_718a32(this->ptrC4);
    }
    void* p = this->ptrB8;
    this->ptrC4 = 0;
    this->fieldC8 = 0;
    this->fieldCC = 0;
    free_718a32(p);
    this->sub_45b810();
    if (flags & 1)
    {
        free_718a32(this);
    }
    return this;
}
