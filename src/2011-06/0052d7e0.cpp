// from server: 87% by atomic.potato
extern "C" int __stdcall CloseHandle(int);
extern "C" int __stdcall closesocket(int);

struct S_func_0052d7e0 {
    int m_handle;
    char pad4[12];
    int m_socket;
    void f();
};

void S_func_0052d7e0::f()
{
    if (m_handle != -1)
        CloseHandle(m_handle);
    if (m_socket != -1) {
        closesocket(m_socket);
        m_socket = -1;
    }
}
