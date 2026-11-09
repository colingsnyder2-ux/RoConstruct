// from server: 91% by atomic.potato
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void func_007ff7c0(char* value)
{
    strncpy((char*)0x00d16de4, value, 0x7f);
    *(unsigned char*)0x00d16e63 = 0;
}
