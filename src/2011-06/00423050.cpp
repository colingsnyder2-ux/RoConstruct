// from server: 66% by atomic.potato
struct CRBXHTMLControlSite {
    void* XOleCommandTarget(void*);
};

void* CRBXHTMLControlSite::XOleCommandTarget(void* value)
{
    return (char*)value - 240;
}
