// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct CSourceStream {
    char pad0[4];
    void* hThread;
    char pad8[4];
    int field_c;
    int f();
};

int CSourceStream::f() {
    WaitForSingleObject(hThread, (unsigned long)-1);
    return field_c;
}