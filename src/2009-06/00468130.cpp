// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct HandlePair {
    void* a;
    void* b;
    void close();
};
void HandlePair::close()
{
    if (b != 0 || a != 0) {
        CloseHandle(b);
        CloseHandle(a);
        b = 0;
        a = 0;
    }
}
