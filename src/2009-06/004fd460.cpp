// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall inet_addr(const char*);

struct NetworkOwnerJob {
    void g(int, int, int, unsigned long, int, int);
    void f(int, int, int, const char*, int, int);
};

void NetworkOwnerJob::f(int a, int b, int c, const char* host, int e, int f)
{
    unsigned long addr = inet_addr(host);
    g(a, b, c, addr, e, f);
}
