// from server: 83% by atomic.potato
extern "C" void __cdecl sub_7F4058(void *);

struct CRBXHTMLControlSite
{
    int commandTarget;
    int reserved[58];
    int fieldEC;
    int fieldF0;

    CRBXHTMLControlSite *XOleCommandTarget(void *);
};

CRBXHTMLControlSite *CRBXHTMLControlSite::XOleCommandTarget(void *arg)
{
    sub_7F4058(arg);
    commandTarget = 0x9A264C;
    fieldEC = 0x9A25E4;
    fieldF0 = 0x9A2630;
    return this;
}
