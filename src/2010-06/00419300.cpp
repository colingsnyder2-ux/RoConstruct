// from server: 64% by atomic.potato
struct CRBXHTMLControlSite_XDocHostUIHandler {
    void f(int, int, int, int);
};

void CRBXHTMLControlSite_XDocHostUIHandler::f(int a1, int a2, int a3, int a4)
{
    int* p = *(int**)(a1 - 0xcc);
    int* q = *(int**)((char*)p + 0x20);
    int* vt = *(int**)q;
    void (__stdcall *fn)(int*, int, int, int) = *(void (__stdcall**)(int*, int, int, int))((char*)vt + 0x1bc);
    fn(q, a2, a3, a4);
}
