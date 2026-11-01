// from server: 100% by tester
struct CXTPReportRow_Batch {
    void* func_006d42a0(void* arg);
};

void* CXTPReportRow_Batch::func_006d42a0(void* arg)
{
    void* p = ((void* (__thiscall*)(void*))((*(void***)this)[0xb8 / 4]))(this);
    ((void (__thiscall*)(void*, void*))((*(void***)p)[0x60 / 4]))(p, arg);
    *(void**)((char*)arg + 0x4c) = this;
    return arg;
}
