// from server: 0% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_009826de();
extern "C" void __stdcall func_009824bc();
extern "C" void __stdcall func_009824a4();
extern "C" void __stdcall func_009826f6();
extern "C" void __stdcall func_006e2960();
extern "C" void __stdcall func_00554c20();
extern "C" void __stdcall func_00554e40();
extern "C" void __stdcall func_006dc6d0();

extern "C" int __stdcall func_00b244e8();
extern "C" int __stdcall func_00b24660();
extern "C" void __stdcall func_00b24784();
extern "C" void __stdcall func_00b24798();
extern "C" void __stdcall func_00b22648();

extern "C" void __stdcall func_00982114();

struct ChatEnter {
    char pad0[0x88];
    int field_88;
    char pad8c[0x9c - 0x8c];
    int field_9c;
    int field_a0;
    int field_a4;

    void func_00417170(int a, int b, int c);
};

void ChatEnter::func_00417170(int a, int b, int c)
{
    if (a == 0xd) {
        func_00b24784();
        func_009826f6();
        if (field_a4 != 0) {
            if (func_00b24660() == 0) {
                int v9c = field_9c;
                int va0 = field_a0;
                int tmp[2];
                tmp[0] = v9c;
                tmp[1] = va0;
                if (va0 != 0) {
                    _InterlockedExchangeAdd((volatile long*)(va0 + 4), 1);
                }
                func_006e2960();
                if (func_00b244e8() == 0x25) {
                    func_00b24798();
                    func_00b22648();
                    func_00554c20();
                } else {
                    func_00b24798();
                    func_00b22648();
                    func_00554e40();
                }
                func_006dc6d0();
                func_009824bc();
            }
        }
    } else if (a == 0x1b) {
        func_009824bc();
        func_009824a4();
    } else {
        func_009826de();
    }
}
