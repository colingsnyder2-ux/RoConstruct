// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

struct boost_thread_resource_error
{
    void* handle;
    int field_4;
    char flag_8;
    void destroy();
};

void boost_thread_resource_error::destroy()
{
    if (flag_8 != 0)
    {
        CloseHandle(handle);
    }
}
