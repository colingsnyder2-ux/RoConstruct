// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_00615d50();
extern "C" void* __stdcall func_0098211a(unsigned int);
extern "C" void __stdcall func_00617470();
extern "C" void __stdcall func_004f4480();
extern "C" void __stdcall func_0059a790();
extern "C" void __stdcall func_004f4f80();
extern "C" void __stdcall func_006061b0();
extern "C" void __stdcall func_00605bc0();

struct RbxMeshPartAdapter {
    void func_004f6a60(int, int, int, int, int, int);
};

void RbxMeshPartAdapter::func_004f6a60(int a1, int a2, int a3, int a4, int a5, int a6)
{
    char buf[0x38];
    void* p;
    int* pi;
    int* pj;

    func_00615d50();
    p = func_0098211a(0x64);
    if (p) {
        if (this) {
            func_00617470();
        } else {
            func_00617470();
        }
    }
    func_004f4480();
    func_0059a790();
    p = func_0098211a(0x20);
    if (p) {
        func_004f4f80();
    }
    func_006061b0();
    func_00605bc0();
    pi = (int*)buf;
    if (pi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)pi + 4), -1) == 1) {
            (*(void(**)(void))(*pi))();
            if (_InterlockedExchangeAdd((volatile long*)((char*)pi + 8), -1) == 1) {
                (*(void(**)(void))(*pi))();
            }
        }
    }
    pj = (int*)(buf + 0x48);
    if (pj) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)pj + 4), -1) == 1) {
            (*(void(**)(void))(*pj))();
            if (_InterlockedExchangeAdd((volatile long*)((char*)pj + 8), -1) == 1) {
                (*(void(**)(void))(*pj))();
            }
        }
    }
}
