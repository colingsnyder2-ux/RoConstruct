// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall WSACleanup();

struct ProfiledRakPeer
{
    void f();
};

int g_0052cb9650;

void ProfiledRakPeer::f()
{
    if (g_0052cb9650)
    {
        if (g_0052cb9650 > 1)
            --g_0052cb9650;
        else
        {
            WSACleanup();
            g_0052cb9650 = 0;
        }
    }
}
