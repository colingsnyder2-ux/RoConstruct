// from server: 100% by colin
struct CXTPRibbonControlTab {
    int GetSomething();
};

extern "C" int __fastcall sub_643980(int);
extern "C" int __fastcall sub_633900(int);

int CXTPRibbonControlTab::GetSomething()
{
    int v = sub_643980(*(int*)((char*)this - 0x7c));
    int r = sub_633900(v);
    return (*(int*)(r + 4) > 0) ? 1 : 0;
}
