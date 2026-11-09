// from server: 87% by atomic.potato
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void Function007ff780(char* destination)
{
    strncpy(destination, (const char*)0x00d16ce4, 0x7f);
    *(unsigned char*)0x00d16d63 = 0;
}
