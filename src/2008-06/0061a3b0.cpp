// from server: 100% by tester
extern int g_7e8ff0;

struct boost_thread_resource_error {
    int f();
};

int boost_thread_resource_error::f()
{
    int tmp = g_7e8ff0;
    *(volatile int*)&tmp = tmp;
    return 0;
}
