// from server: 19% by atomic.potato
typedef unsigned char byte;

extern "C" void* __stdcall make_desc_005b6db0(int, int);
extern "C" int __cdecl func_00618710();
extern "C" void __cdecl sub_00618780();

extern "C" void __cdecl sub_00594140(int);
extern "C" int __cdecl sub_005a5900();
extern "C" void __cdecl sub_0067a180();
extern "C" void __cdecl sub_004a6b50();
extern "C" void __cdecl sub_004a54b0();

extern int dword_00C1835C;

struct VAnimationTrackState
{
    void __cdecl f(int, int, int, int, int);
};

void __cdecl VAnimationTrackState::f(int a1, int a2, int a3, int a4, int a5)
{
    char pad[0x38];
    int v;
    void* p;

    p = make_desc_005b6db0(a2, a1);
    sub_0067a180();
    *(int*)((char*)this + 0x38) = a3;
    sub_00594140(a4);
    dword_00C1835C++;
    v = sub_005a5900();
    sub_00618780();
    sub_004a6b50();
    sub_004a54b0();
    if (v)
    {
        (*(void(__cdecl**)(int))v)(1);
    }
}
