// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
struct Sink { void run(); };
Sink* __stdcall sub_4019d0(void**);
struct Creator {
    virtual ~Creator();
    virtual void f1();
    virtual void f2();
    void* base();

};
extern unsigned char byte_E580B3;
extern int dword_E1E0B8;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);

Creator::~Creator()
{
    if (byte_E580B3 != 0 && dword_E1E0B8 != 0x29a) {
        if (dword_E5809C == 0 || !dword_E5809C("wasConstructed()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Include\\Util/Object.h", 0xe2))
            sub_972290(byte_E580B3, "wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Include\\Util/Object.h line: 226");
    }
    void* p = base();
    sub_4019d0(&p)->run();
}