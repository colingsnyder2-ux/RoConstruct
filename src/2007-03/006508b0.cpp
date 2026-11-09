// from server: 100% by tester
struct VCXTPReportRows_CXTPHeapObjectT
{
    int func_00664700(int);
    void func_006644f0(int);
    void func_006644c0(int);
    void func_00664780(int);
};

void VCXTPReportRows_CXTPHeapObjectT::func_00664780(int arg)
{
    if (func_00664700(arg))
    {
        func_006644f0(arg);
        *(int*)((char*)this + 0x24) = -1;
        *(int*)((char*)this + 0x40) = 1;
    }
    else
    {
        func_006644c0(arg);
        *(int*)((char*)this + 0x24) = -1;
        *(int*)((char*)this + 0x40) = 1;
    }
}
