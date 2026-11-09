// from server: 6% by colin
struct CXTPPrintPageHeaderFooter
{
    char pad[0x64];
    int field64;
    int field68;
    int field6c;
    void Method70();
    void Method74(int* p);
    void Method78(int* p);
};

extern "C" void __stdcall sub_77DD74();
extern "C" void __stdcall sub_77DC7C(int* self, const char* a, const char* b);
extern "C" void __stdcall sub_77DDBD(int* self);

extern const char str_7CED74[];
extern const char str_7CED78[];
extern const char str_7CED84[];

void CXTPPrintPageHeaderFooter::Method70()
{
    sub_77DD74();
    (this->*(void (CXTPPrintPageHeaderFooter::*)())0)( );
}
