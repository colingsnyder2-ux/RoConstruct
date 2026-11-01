// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);
namespace boost {
struct once_flag { long status; };
template<typename Function> void call_once(once_flag& flag, Function f);
namespace detail {
struct thread_data_base { virtual ~thread_data_base(); };
struct externally_launched_thread : thread_data_base { };
template<typename T> T* heap_new();
}
static once_flag current_thread_tls_init_flag;
static unsigned long current_thread_tls_key = 0;
void create_current_thread_tls_key();
inline detail::thread_data_base* get_current_thread_data()
{
    if (!current_thread_tls_key)
        return 0;
    return (detail::thread_data_base*)TlsGetValue(current_thread_tls_key);
}
inline void set_current_thread_data(detail::thread_data_base* new_data)
{
    boost::call_once(current_thread_tls_init_flag, create_current_thread_tls_key);
    TlsSetValue(current_thread_tls_key, new_data);
}
inline void make_external_thread_data()
{
    detail::externally_launched_thread* me = detail::heap_new<detail::externally_launched_thread>();
    set_current_thread_data(me);
}
detail::thread_data_base* get_or_make_current_thread_data()
{
    detail::thread_data_base* current_thread_data(get_current_thread_data());
    if (!current_thread_data)
    {
        make_external_thread_data();
        current_thread_data = get_current_thread_data();
    }
    return current_thread_data;
}
}
