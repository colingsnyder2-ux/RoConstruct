// from server: 49% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

struct AsyncHttpCache {
    char pad_0[0x108];
    void* field_108;
    char pad_10C[4];
    void* field_110;
    char pad_114[4];

    void method_7F9A90(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5);
};

void AsyncHttpCache::method_7F9A90(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    void* v108 = (char*)this + 0x108;
    char local_c = 0;
    int state = 1;
    void* local_8 = v108;

    ((void(__thiscall*)(void*, void*, void*))0x413890)(this, &local_8, &local_c);

    void* v38 = arg1;
    void* v48 = arg2;

    void* temp1[2];
    temp1[0] = v38;
    temp1[1] = v48;
    if (v48) {
        _InterlockedExchangeAdd((volatile long*)((char*)v48 + 4), 1);
    }

    void* v3c = arg3;
    void* v48_2 = arg4;

    void* temp2[2];
    temp2[0] = v3c;
    temp2[1] = v48_2;
    if (v48_2) {
        _InterlockedExchangeAdd((volatile long*)((char*)v48_2 + 4), 1);
    }

    ((void(__thiscall*)(AsyncHttpCache*, void*, void*))0x7F6E20)(this, &state, temp2);

    void* v110 = *(void**)((char*)this + 0x110);
    void* v110_4 = *(void**)((char*)v110 + 4);
    void* ecx_val = (char*)this + 0x110;

    ((void(__thiscall*)(void*, void*, void*))v110_4)(ecx_val, temp1[0], temp2[0]);

    local_c = 1;
    if (!local_c) {
        void* v8 = local_8;
        long old = _InterlockedExchangeAdd((volatile long*)v8, 0x80000000);
        if (!(old & 0x40000000)) {
            if (old != 0x80000000 && old < 0x80000000) {
                _InterlockedExchangeAdd((volatile long*)v8, 0x40000000);
                void* evt = ((void*(__cdecl*)())0x40B9C0)();
                SetEvent(evt);
            }
        }
    }

    void* v34 = temp1[0];
    state = 0;
    if (v34) {
        long dec = _InterlockedExchangeAdd((volatile long*)((char*)v34 + 4), -1);
        if (dec == 1) {
            void* vtable = *(void**)v34;
            void* dtor = *(void**)((char*)vtable + 4);
            ((void(__thiscall*)(void*))dtor)(v34);
            long dec2 = _InterlockedExchangeAdd((volatile long*)((char*)v34 + 8), -1);
            if (dec2 == 1) {
                void* vtable2 = *(void**)v34;
                void* delete_fn = *(void**)((char*)vtable2 + 8);
                ((void(__thiscall*)(void*))delete_fn)(v34);
            }
        }
    }

    void* v3c_2 = temp2[0];
    state = -1;
    if (v3c_2) {
        long dec = _InterlockedExchangeAdd((volatile long*)((char*)v3c_2 + 4), -1);
        if (dec == 1) {
            void* vtable = *(void**)v3c_2;
            void* dtor = *(void**)((char*)vtable + 4);
            ((void(__thiscall*)(void*))dtor)(v3c_2);
            long dec2 = _InterlockedExchangeAdd((volatile long*)((char*)v3c_2 + 8), -1);
            if (dec2 == 1) {
                void* vtable2 = *(void**)v3c_2;
                void* delete_fn = *(void**)((char*)vtable2 + 8);
                ((void(__thiscall*)(void*))delete_fn)(v3c_2);
            }
        }
    }
}
