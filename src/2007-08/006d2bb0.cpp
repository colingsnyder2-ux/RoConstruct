// from server: 100% by colin
struct CXTPReportHyperlinks
{
    char pad[0x20];

    int func_006d26b0(int, int);
    int func_006301e4();

    void func_006d2bb0(int index);
};

void CXTPReportHyperlinks::func_006d2bb0(int index)
{
    if (index < 0)
        return;

    int count = ((int (__thiscall*)(CXTPReportHyperlinks*))((*(void***)this)[0x58 / 4]))(this);
    if (index >= count)
        return;

    int* p = (int*)((int (__thiscall*)(CXTPReportHyperlinks*, int))((*(void***)this)[0x64 / 4]))(this, index);
    if (p != 0)
    {
        ((CXTPReportHyperlinks*)p)->func_006301e4();
    }

    ((CXTPReportHyperlinks*)((char*)this + 0x20))->func_006d26b0(index, 1);
}
