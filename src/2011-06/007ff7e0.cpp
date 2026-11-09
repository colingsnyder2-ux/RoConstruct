// from server: 91% by atomic.potato
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

char g_00d16e68[1];
unsigned char g_00d16ee7;

void func_007ff7e0(const char* source)
{
    strncpy(g_00d16e68, source, 127);
    g_00d16ee7 = 0;
}
