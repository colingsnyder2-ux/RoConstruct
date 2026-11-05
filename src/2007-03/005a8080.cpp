// from server: 100% by tester
extern "C" unsigned int __cdecl sub_5ac4d0(float x);

unsigned int __cdecl sub_5ac550(float* p)
{
    unsigned int esi;
    unsigned int eax;
    unsigned int ecx;
    unsigned int edx;

    esi = sub_5ac4d0(p[0]);
    esi -= 0x61c88647;
    eax = sub_5ac4d0(p[1]);
    ecx = esi << 6;
    edx = esi >> 2;
    ecx += edx;
    eax = eax + ecx - 0x61c88647;
    esi ^= eax;
    eax = sub_5ac4d0(p[2]);
    ecx = esi << 6;
    edx = esi >> 2;
    ecx += edx;
    eax = eax + ecx - 0x61c88647;
    eax ^= esi;
    return eax;
}
