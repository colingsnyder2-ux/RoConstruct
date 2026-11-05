// from server: 76% by atomic.potato
extern "C" void Initialize(void *, void *);

struct CRBXHTMLControlSite
{
    int value0;
    char padding[232];
    int valueEC;
    int valueF0;

    CRBXHTMLControlSite *XOleCommandTarget(void *);
};

CRBXHTMLControlSite *CRBXHTMLControlSite::XOleCommandTarget(void *arg)
{
    Initialize(this, arg);
    value0 = 0xA03324;
    valueEC = 0xA032BC;
    valueF0 = 0xA03308;
    return this;
}
