// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct EventData {
    void* vtable;
    unsigned int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1c;
};

struct Listener {
    void (__thiscall *fn)(void*, EventData*);
};

extern "C" void __cdecl func_00437b80(void*);

void EventData_emit(EventData* self)
{
    if (self->field_c) {
        func_00437b80(self);
        EventData local;
        local.vtable = self->field_10;
        local.field_4 = (int)self->field_14;
        if (self->field_14) {
            _InterlockedExchangeAdd((volatile long*)((char*)self->field_14 + 4), 1);
        }
        local.field_8 = self->field_18;
        local.field_c = self->field_1c;
        if (self->field_1c) {
            _InterlockedExchangeAdd((volatile long*)((char*)self->field_1c + 4), 1);
        }
        Listener* l = (Listener*)self->field_c;
        l->fn(self->field_c, &local);
    }
}
