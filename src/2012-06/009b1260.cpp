// from server: 71% by atomic.potato
extern "C" void __stdcall ImportedCall(void *);
extern "C" void CallA(void *);
extern "C" void CallB(void *);

struct CXTPReportGroupRow_Batch
{
    int Method(int);
};

int CXTPReportGroupRow_Batch::Method(int arg)
{
    ImportedCall((char *)this + 0x74);
    CallA(this);
    if (arg & 1)
        CallB(this);
    return (int)this;
}
