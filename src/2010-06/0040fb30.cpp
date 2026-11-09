// from server: 0% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_7A7F70();
extern "C" void __stdcall sub_7A7D54();
extern "C" void __stdcall sub_7A7D42();
extern "C" void __stdcall sub_7A7F88();
extern "C" void __stdcall sub_5D7C30();
extern "C" void __stdcall sub_4CCC20();
extern "C" void __stdcall sub_4CCEB0();
extern "C" void __stdcall sub_5D19E0();

extern "C" void* __stdcall sub_9ECEA4();
extern "C" char __stdcall sub_9ECDEC();
extern "C" char __stdcall sub_9EC558();
extern "C" void* __stdcall sub_9ECEB0();
extern "C" void __stdcall sub_9EA410();
extern "C" void __stdcall sub_9EA400();

extern "C" void __stdcall sub_97E3DA();

extern void* g_b7b754;

struct CBrush {
    char pad_000[0x88];
    void* field_088;
    char pad_08C[0x9C - 0x8C];
    void* field_09C;
    void* field_0A0;
    void* field_0A4;
    int method(int, int, int);
};

int CBrush::method(int a, int b, int c)
{
    if (a == 0xd) {
        sub_9ECEA4();
        sub_7A7F88();
        if (field_0A4 != 0) {
            if (!sub_9ECDEC()) {
                void* p9c = field_09C;
                void* pa0 = field_0A0;
                if (pa0 != 0) {
                    _InterlockedExchangeAdd((volatile long*)((char*)pa0 + 4), 1);
                }
                sub_5D7C30();
                sub_9EC558();
                if (sub_9EC558() == 0x25) {
                    sub_9ECEB0();
                    sub_9EA410();
                    sub_4CCC20();
                    sub_9EA400();
                } else {
                    sub_9ECEB0();
                    sub_9EA410();
                    sub_4CCEB0();
                }
                sub_5D19E0();
                sub_7A7D54();
            }
        }
    } else if (a == 0x1b) {
        sub_7A7D54();
        sub_7A7D42();
    } else {
        sub_7A7F70();
    }
    return 0;
}
