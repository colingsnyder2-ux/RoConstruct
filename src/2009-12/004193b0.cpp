// from server: 52% by atomic.potato
extern "C" int __cdecl sub_007f404c(void*);

struct CRBXHTMLControlSite
{
    int XOleCommandTarget();
};

int CRBXHTMLControlSite::XOleCommandTarget()
{
    return sub_007f404c((char*)this - 240);
}
