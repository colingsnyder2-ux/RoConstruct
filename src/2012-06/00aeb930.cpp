// from server: 100% by tester
extern "C" void* (__cdecl *g_boost_get_system_category)();

void* g_boost_system_category;

void __cdecl sub_00aeb930()
{
    g_boost_system_category = g_boost_get_system_category();
}
