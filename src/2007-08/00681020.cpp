// from server: 100% by colin
struct CXTPDrawHelpers {
    int IsThemeActive();
};

int CXTPDrawHelpers::IsThemeActive()
{
    return 0;
}

extern "C" int __fastcall sub_738322(CXTPDrawHelpers* self);

void func_00681020(CXTPDrawHelpers* self, int* pValue)
{
    if (self == 0)
        return;
    if (*(int*)((char*)self + 0x20) == 0)
        return;
    if (*pValue == 0x25) {
        if (sub_738322(self) & 0x400000) {
            *pValue = 0x27;
            return;
        }
    }
    if (*pValue == 0x27) {
        if (sub_738322(self) & 0x400000) {
            *pValue = 0x25;
        }
    }
}
