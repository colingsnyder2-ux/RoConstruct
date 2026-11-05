// from server: 100% by colin
extern "C" int (__stdcall *WSAStartup)(unsigned short, void*);

static int g_initCount;

void InitWSA()
{
    char wsaData[0x190];
    int count = g_initCount + 1;
    g_initCount = count;
    if (count == 1)
    {
        WSAStartup(0x202, wsaData);
    }
}
