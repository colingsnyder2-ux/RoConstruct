// from server: 100% by atomic.potato
struct CRbxPlayDocTemplate
{
    void ReleaseDocument(void *);
    char padding[0x90];
    void *document;
};

void CRbxPlayDocTemplate::ReleaseDocument(void *p)
{
    ReleaseDocument(p);
    if (p == document)
        document = 0;
}
