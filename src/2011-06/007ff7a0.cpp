// from server: 91% by atomic.potato
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

char g_buffer[1];
char g_flag;

void f(char* source)
{
    strncpy(g_buffer, source, 127);
    g_flag = 0;
}
