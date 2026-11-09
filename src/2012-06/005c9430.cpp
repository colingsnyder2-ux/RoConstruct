// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall WSAStartup(unsigned short, void *);

int dword_e273bc;

void Function005c9430()
{
    ++dword_e273bc;
    if (dword_e273bc == 1)
    {
        char data[0x190];
        WSAStartup(0x202, data);
    }
}
