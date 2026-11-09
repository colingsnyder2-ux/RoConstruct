// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct EventInstance {
    void* descriptor;
    void* source;
    void* a;
    void* b;
};

struct EventBridge {
    void* vptr;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
};

struct MarshaledListener {
    void* field0;
    EventBridge bridge;
    void* field1C;

    void cleanup();
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl unknown_433140(void* conn);
extern "C" void __cdecl unknown_464ec0(void* dest, void* src);
extern "C" void __cdecl unknown_41da00(void* p);
extern "C" void* __cdecl unknown_41e390(void* self, void* a, void* b);

void MarshaledListener::cleanup()
{
    void* mem = operator_new(0x20);
    void* result;
    if (mem != 0) {
        EventInstance inst;
        inst.descriptor = this;
        inst.source = 0;
        inst.a = 0;
        inst.b = 0;
        result = unknown_41e390(mem, this, &inst);
    } else {
        result = 0;
    }
    void* local = result;
    unknown_464ec0(&bridge.field4, &local);
    unknown_433140(bridge.field18);
    unknown_41da00(&bridge.field4);
}
