// from server: 100% by why2
extern "C" unsigned long (__stdcall *TlsAlloc)();

char g_flag;
unsigned long g_index;

void set_flag_and_alloc(char v)
{
    g_flag = v;
    g_index = TlsAlloc();
}
