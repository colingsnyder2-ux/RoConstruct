// from server: 33% by atomic.potato
struct Sub {
    char pad[0x170];
};

struct CObjectBrowser {
    char pad0[0x58];
    Sub sub58;
    Sub sub170;
    CObjectBrowser();
    ~CObjectBrowser();
};

extern "C" void __stdcall sub_85d7d0(void*);
extern "C" void __stdcall sub_7f4232(void*);

CObjectBrowser::~CObjectBrowser()
{
    *(void**)this = (void*)0x9a5a94;
    sub_85d7d0(&sub170);
    sub_85d7d0(&sub58);
    sub_7f4232(this);
}
