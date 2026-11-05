// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    char data[0x374];
    Base();
    virtual ~Base();
};

struct ListenerA {
    char data[0x20];
    ListenerA();
    virtual ~ListenerA();
};

struct ListenerB {
    char data[0x20];
    ListenerB();
    virtual ~ListenerB();
};

struct ReportViewBase : Base, ListenerA, ListenerB {
    char data[0x14];
    ReportViewBase();
    virtual ~ReportViewBase();
};

struct CRobloxReportView : ReportViewBase {
    virtual ~CRobloxReportView();
};

CRobloxReportView* __cdecl CreateReportView()
{
    return new CRobloxReportView;
}
