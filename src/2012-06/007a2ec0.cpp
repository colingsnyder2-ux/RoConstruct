// from server: 25% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    char _buf[28];
    String(const String&);
    ~String();
};

struct SlotBase {
    int vptr;
    int refCount;
    int weakCount;
    String name;
    char pad[4];
    SlotBase();
    ~SlotBase();
};

struct Controller {
    char pad[140];
    SlotBase slot;
    void func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void __stdcall func_007a01e0(int*);
void __stdcall func_007a0710(int, int*);
void __stdcall func_007a0d90(int, int*, int*);
void __stdcall func_007a2510(int);

void Controller::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    int v1 = 0;
    int v2[3];
    v2[0] = a1;
    v2[1] = 0;
    v2[2] = 0;
    func_007a0710(a1, v2);
    int* esi = v2;
    int edx = esi[0];
    int eax = esi[1];
    char cl = *((char*)esi + 8);
    int* edx2 = esi + 3;
    int v3[3];
    v3[0] = edx;
    v3[1] = eax;
    v3[2] = cl;
    func_007a01e0(v3);
    int eax2 = esi[10];
    int esi2 = esi[11];
    int v4[2];
    v4[0] = eax2;
    v4[1] = esi2;
    if (esi2 != 0) {
        esi2 += 4;
        _InterlockedExchangeAdd((volatile long*)esi2, 1);
    }
    func_007a0d90((int)this + 140, v4, v3);
    func_007a01e0(v4);
    func_007a01e0(v3);
    func_007a2510((int)this);
    func_007a01e0((int*)((int)this + 148));
}
