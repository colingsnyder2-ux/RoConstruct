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
