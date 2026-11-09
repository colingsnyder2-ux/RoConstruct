// from server: 72% by atomic.potato
struct CRBXHTMLControlSite
{
    void XOleCommandTarget(void*);
};

void CRBXHTMLControlSite::XOleCommandTarget(void* p)
{
    ((void (__thiscall *)(void*))((char*)p - 240))(p);
}
