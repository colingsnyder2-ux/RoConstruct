// from server: 73% by EspClaude
// from server: 100% by 2gx
// roc 2008-06 00623e30  unit: lua_exception  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623e30
//
// 00623e30  8b442404             mov eax, dword ptr [esp + 4]
// 00623e34  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00623e37  56                   push esi
// 00623e38  8b7170               mov esi, dword ptr [ecx + 0x70]
// 00623e3b  8b5620               mov edx, dword ptr [esi + 0x20]
// 00623e3e  57                   push edi
// 00623e3f  52                   push edx
// 00623e40  56                   push esi
// 00623e41  e8bab70300           call 0x65f600
// 00623e46  6a01                 push 1
// 00623e48  56                   push esi
// 00623e49  e862780300           call 0x65b6b0
// 00623e4e  83c410               add esp, 0x10
// 00623e51  c7467400000000       mov dword ptr [esi + 0x74], 0
// 00623e58  8b4628               mov eax, dword ptr [esi + 0x28]
// 00623e5b  894614               mov dword ptr [esi + 0x14], eax
// 00623e5e  8b00                 mov eax, dword ptr [eax]
// 00623e60  894608               mov dword ptr [esi + 8], eax
// 00623e63  89460c               mov dword ptr [esi + 0xc], eax
// 00623e66  33c0                 xor eax, eax
// 00623e68  50                   push eax
// 00623e69  68803d6200           push 0x623d80
// 00623e6e  56                   push esi
// 00623e6f  66894634             mov word ptr [esi + 0x34], ax
// 00623e73  e8a8daffff           call 0x621920
// 00623e78  83c40c               add esp, 0xc
// 00623e7b  85c0                 test eax, eax
// 00623e7d  75d9                 jne 0x623e58
// 00623e7f  8b46f4               mov eax, dword ptr [esi - 0xc]
// 00623e82  ff08                 dec dword ptr [eax]
// 00623e84  8b7ef8               mov edi, dword ptr [esi - 8]
// 00623e87  85ff                 test edi, edi
// 00623e89  742a                 je 0x623eb5
// 00623e8b  8d4f04               lea ecx, [edi + 4]
// 00623e8e  83caff               or edx, 0xffffffff
// 00623e91  f00fc111             lock xadd dword ptr [ecx], edx
// 00623e95  751e                 jne 0x623eb5
// 00623e97  8b07                 mov eax, dword ptr [edi]
// 00623e99  8b5004               mov edx, dword ptr [eax + 4]
// 00623e9c  8bcf                 mov ecx, edi
// 00623e9e  ffd2                 call edx
// 00623ea0  8d4708               lea eax, [edi + 8]
// 00623ea3  83c9ff               or ecx, 0xffffffff
// 00623ea6  f00fc108             lock xadd dword ptr [eax], ecx
// 00623eaa  7509                 jne 0x623eb5
// 00623eac  8b17                 mov edx, dword ptr [edi]
// 00623eae  8b4208               mov eax, dword ptr [edx + 8]
// 00623eb1  8bcf                 mov ecx, edi
// 00623eb3  ffd0                 call eax
// 00623eb5  5f                   pop edi
// 00623eb6  8bc6                 mov eax, esi
// 00623eb8  5e                   pop esi
// 00623eb9  e992fdffff           jmp 0x623c50

/* 2gx, 2026 */

typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void __cdecl lua_reset_a(void*, void*);
extern "C" void __cdecl lua_reset_b(void*, int);
extern "C" int __cdecl lua_retry(void*, void*, int);
extern "C" void __cdecl lua_callback();

struct LuaState {
    unsigned char pad00[0x08];
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    unsigned char pad18[0x08];
    void* field20;
    unsigned char pad24[0x04];
    u32* field28;
    unsigned char pad2C[0x08];
    u16 field34;
    unsigned char pad36[0x3E];
    u32 field74;
};

struct LuaOwner {
    unsigned char pad00[0x10];
    void* state;
};

extern "C" long __cdecl _InterlockedDecrement(volatile long*);

struct RefControl {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release() {
        if (_InterlockedDecrement(&strong) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

extern "C" void __cdecl finish_step_a(LuaState*, void*);
extern "C" void __cdecl finish_step_b(LuaState*);
extern "C" void __cdecl finish_step_c(LuaState*, void*, u32, void*);
extern "C" void* __cdecl finish_realloc(LuaState*, void*, u32, void*);
struct LuaGlobal {
    void* data00;
    u32 field04;
    u32 count08;
    void* (__cdecl *frealloc)(void*, void*, u32, u32);
    void* ud;
    unsigned char pad14[0x20];
    void* data34;
    unsigned char pad38[0x04];
    u32 size3c;
};

static __declspec(noinline) void __cdecl lua_finish(LuaState* state) {
    finish_step_a(state, state->field20);
    
}


void __cdecl func_00623e30(LuaOwner* owner) {
    unsigned char* raw = static_cast<unsigned char*>(owner->state);
    LuaState* state = *reinterpret_cast<LuaState**>(raw + 0x70);
    lua_reset_a(state, state->field20);
    lua_reset_b(state, 1);
    state->field74 = 0;
    do {
        u32* current = state->field28;
        state->field14 = reinterpret_cast<u32>(current);
        state->field08 = *current;
        state->field0C = state->field08;
        state->field34 = 0;
    } while (lua_retry(state, reinterpret_cast<void*>(&lua_callback), 0) != 0);
    --**reinterpret_cast<u32**>(reinterpret_cast<unsigned char*>(state) - 0x0C);
    RefControl* control = *reinterpret_cast<RefControl**>(
        reinterpret_cast<unsigned char*>(state) - 0x08);
    if (control)
        control->release();
    lua_finish(state);
}
