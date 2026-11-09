// from server: 91% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall Call44CCF0(DWORD, int);


struct CRbxDocTemplate
{
    int f(DWORD, DWORD);
int Call7A862A(DWORD, DWORD);
};

int CRbxDocTemplate::f(DWORD a, DWORD b)
{
    Call44CCF0(0xC01898, 1);
    return Call7A862A(a, b);
}
