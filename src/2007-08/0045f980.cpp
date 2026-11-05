// from server: 100% by colin
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);

struct CObjectBrowser {
    int sub_45EC70(int);
    int method(int);
};

int g_8bc0a0;
void* g_8bc09c;

int CObjectBrowser::method(int arg)
{
    if (g_8bc0a0 == 0) {
        g_8bc09c = LoadLibraryA((const char*)0x794a28);
        if (g_8bc09c == 0) {
            return -1;
        }
    }
    g_8bc0a0++;
    int r = sub_45EC70(arg);
    return (r != -1) ? 0 : -1;
}
