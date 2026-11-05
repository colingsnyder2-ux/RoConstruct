// from server: 74% by atomic.potato
extern "C" void __cdecl sub_00535570(const char*, unsigned int*);

void __stdcall sub_005375a0(const char* a, const char* b)
{
    unsigned int value[2];
    sub_00535570(b, &value[0]);
}
