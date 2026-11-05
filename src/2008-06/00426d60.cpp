// from server: 100% by tester
struct CSelectionTreeCtrl
{
    void sub_423B70();
    void sub_423D00();
    void func_004258C0(void* arg1, int* arg2);
};

void CSelectionTreeCtrl::func_004258C0(void* arg1, int* arg2)
{
    char* p = (char*)arg1;
    char* esi = *(char**)(p + 0x5c);
    if ((p[0xc] & 2) != 0)
    {
        if (esi[0x55] == 0)
        {
            ((CSelectionTreeCtrl*)esi)->sub_423B70();
            ((CSelectionTreeCtrl*)esi)->sub_423D00();
            *arg2 = 0;
            return;
        }
        *arg2 = 0;
        return;
    }
    *arg2 = 0;
}
