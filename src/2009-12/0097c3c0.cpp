// from server: 100% by atomic.potato
struct ErrorCategory
{
};

extern "C" __declspec(dllimport) ErrorCategory& __cdecl get_system_category();

ErrorCategory* g_system_category;

void f()
{
    g_system_category = &get_system_category();
}
