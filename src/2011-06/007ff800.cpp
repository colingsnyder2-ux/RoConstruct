// from server: 87% by atomic.potato
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void func_007ff800(char* destination)
{
    strncpy(destination, (const char*)0x00d16f6c, 0x7f);
    *(unsigned char*)0x00d16feb = 0;
}
