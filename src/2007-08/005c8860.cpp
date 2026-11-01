// from server: 100% by Yeetserama
// roc 2007-08 005c8860  unit: lua_exception  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c8860
//
// 005c8860  8b442404             mov eax, dword ptr [esp + 4]
// 005c8864  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005c8867  56                   push esi
// 005c8868  8b7170               mov esi, dword ptr [ecx + 0x70]
// 005c886b  8b5620               mov edx, dword ptr [esi + 0x20]
// 005c886e  57                   push edi
// 005c886f  52                   push edx
// 005c8870  56                   push esi
// 005c8871  e84aa80400           call 0x6130c0
// 005c8876  6a01                 push 1
// 005c8878  56                   push esi
// 005c8879  e872680400           call 0x60f0f0
// 005c887e  83c410               add esp, 0x10
// 005c8881  c7467400000000       mov dword ptr [esi + 0x74], 0
// 005c8888  8b4628               mov eax, dword ptr [esi + 0x28]
// 005c888b  6a00                 push 0
// 005c888d  894614               mov dword ptr [esi + 0x14], eax
// 005c8890  8b00                 mov eax, dword ptr [eax]
// 005c8892  68b0875c00           push 0x5c87b0
// 005c8897  56                   push esi
// 005c8898  894608               mov dword ptr [esi + 8], eax
// 005c889b  89460c               mov dword ptr [esi + 0xc], eax
// 005c889e  66c746340000         mov word ptr [esi + 0x34], 0
// 005c88a4  e827d0ffff           call 0x5c58d0
// 005c88a9  83c40c               add esp, 0xc
// 005c88ac  85c0                 test eax, eax
// 005c88ae  75d8                 jne 0x5c8888
// 005c88b0  8b46f4               mov eax, dword ptr [esi - 0xc]
// 005c88b3  8300ff               add dword ptr [eax], -1
// 005c88b6  8b7ef8               mov edi, dword ptr [esi - 8]
// 005c88b9  85ff                 test edi, edi
// 005c88bb  742a                 je 0x5c88e7
// 005c88bd  8d4704               lea eax, [edi + 4]
// 005c88c0  83c9ff               or ecx, 0xffffffff
// 005c88c3  f00fc108             lock xadd dword ptr [eax], ecx
// 005c88c7  751e                 jne 0x5c88e7
// 005c88c9  8b17                 mov edx, dword ptr [edi]
// 005c88cb  8b4204               mov eax, dword ptr [edx + 4]
// 005c88ce  8bcf                 mov ecx, edi
// 005c88d0  ffd0                 call eax
// 005c88d2  8d4f08               lea ecx, [edi + 8]
// 005c88d5  83caff               or edx, 0xffffffff
// 005c88d8  f00fc111             lock xadd dword ptr [ecx], edx
// 005c88dc  7509                 jne 0x5c88e7
// 005c88de  8b07                 mov eax, dword ptr [edi]
// 005c88e0  8b5008               mov edx, dword ptr [eax + 8]
// 005c88e3  8bcf                 mov ecx, edi
// 005c88e5  ffd2                 call edx
// 005c88e7  5f                   pop edi
// 005c88e8  8bc6                 mov eax, esi
// 005c88ea  5e                   pop esi
// 005c88eb  e990fdffff           jmp 0x5c8680
// copied from an identical function in another client (function ?fn_ROCX000003_00623e30@ns_ROCX000003@@YAXPAULuaOwner@1@@Z)

namespace ns_ROCX000003 {
// from server: 100% by 2gx
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


void __cdecl fn_ROCX000003_00623e30(LuaOwner* owner) {
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
}
