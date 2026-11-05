// from server: 69% by atomic.potato
extern "C" void call_982d5c(void *);
extern "C" void __cdecl call_982114(void *);

struct CRbxPlayDocTemplate
{
    char padding[0x94];
    void *member;
    CRbxPlayDocTemplate *f(unsigned char);
};

CRbxPlayDocTemplate *CRbxPlayDocTemplate::f(unsigned char flag)
{
    call_982d5c(member);
    if (flag & 1)
        call_982114(this);
    return this;
}
