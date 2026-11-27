// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" __declspec(dllimport) int __stdcall closesocket(unsigned int);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct S
{
    unsigned int socket;
    char pad[28];
    void* handle;
    void f();
};
void S::f()
{
    if (socket != (unsigned int)-1)
        closesocket(socket);
    if (handle != (void*)-1)
    {
        CloseHandle(handle);
        handle = (void*)-1;
    }
}
