// from server: 45% by atomic.potato
extern "C" void __stdcall sub_630490(void*);
extern "C" void __stdcall sub_63048a(void*);
extern "C" void __stdcall sub_630a1e(void*);

struct CXTPReportRows {
    char pad[0x60];
    void* field_60;
    void Method();
};

void CXTPReportRows::Method()
{
    char buf[0x58];
    sub_630490(buf);
    void* p = field_60;
    void* fn = *(void**)((char*)p + 0x68);
    ((void (__thiscall*)(void*, int))fn)(&field_60, 1);
    sub_63048a(buf);
}
