// from server: 100% by atomic.potato
struct CRbxPlayDocTemplate
{
    void Release(void *);
    char padding[0x90];
    void *value;
};

void CRbxPlayDocTemplate::Release(void *p)
{
    Release(p);
    if (p == value)
        value = 0;
}
