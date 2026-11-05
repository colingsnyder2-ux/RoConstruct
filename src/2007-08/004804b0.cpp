// from server: 100% by colin
extern "C" __declspec(dllimport) void __stdcall glGetBooleanv(unsigned int pname, unsigned char* params);

unsigned char __cdecl sub_004804b0(unsigned int pname)
{
    unsigned char buf[32];
    glGetBooleanv(pname, buf);
    return buf[0];
}
