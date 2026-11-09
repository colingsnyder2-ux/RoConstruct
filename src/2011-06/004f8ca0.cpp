// from server: 44% by atomic.potato
struct SendDataJob
{
    void f();
    int m_0;
    int m_4;
};

extern "C" void __cdecl function_004f0de0(void*, void*);
extern "C" void __cdecl function_004f7390(void*);

void SendDataJob::f()
{
    char data[12];
    function_004f0de0(data, this);
    if (m_4 != 0)
        function_004f7390(data);
}
