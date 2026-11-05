// from server: 25% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_00476b90();
extern "C" void __stdcall G1_0066ff30();
extern "C" void __stdcall G1_0066aa30();
extern "C" void __stdcall G1_00683040();
extern "C" void __stdcall G1_00450960();

extern "C" void __stdcall G2_0098b6e8();
extern "C" void __stdcall G2_0098b6ec();
extern "C" void __stdcall G2_0098b6e4();
extern "C" void __stdcall G2_0098de74();
extern "C" void __stdcall G2_0098de80();
extern "C" void __stdcall G2_0098dec0();
extern "C" void __stdcall G2_0098d310();

struct CRobloxDoc
{
    char pad0[0x9c];
    void* field_9c;
    void func_004595b0(int);
};

void CRobloxDoc::func_004595b0(int)
{
    void* p = field_9c;
    G1_00476b90();
    G1_0066ff30();
    G1_00450960();
    G2_0098b6e8();
    G1_00683040();
    G2_0098de74();
    G2_0098b6ec();
    G2_0098d310();
    G2_0098de80();
    G2_0098dec0();
    G2_0098b6e4();
    G1_0066aa30();
    (void)p;
}
