// from server: 87% by atomic.potato
extern "C" int __stdcall closesocket(int);
extern "C" int __stdcall CloseHandle(void*);

struct S
{
    int socket;
    char pad[28];
    void* handle;
    void f();
};

void S::f()
{
    if (socket != -1)
        closesocket(socket);

    if (handle != (void*)-1)
    {
        CloseHandle(handle);
        handle = (void*)-1;
    }
}
