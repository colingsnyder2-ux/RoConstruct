// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refCount;
};

struct EventHandler {
    char pad0[0xfc];
    void* field_fc;
    RefCounted* field_100;
    void* field_104;
    void method();
};

extern "C" void __stdcall sub_6304E4();
extern "C" void __stdcall sub_40D550();
extern "C" void __stdcall sub_541630();
extern "C" void __stdcall sub_5595A0();

void EventHandler::method()
{
    sub_6304E4();
    if (field_104 != 0) {
        void* local_fc = field_fc;
        RefCounted* local_100 = field_100;
        if (local_100 != 0) {
            _InterlockedExchangeAdd(&local_100->refCount, 1);
        }
        sub_40D550();
        *(int*)((char*)field_104 + 0xf0) = 0;
        sub_541630();
        sub_5595A0();
    }
}
