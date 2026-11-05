// from server: 58% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

// Forward declarations of helper functions used by the target.
// These are declared as free functions with the observed calling conventions.
extern "C" void* __cdecl sub_62FEF6(unsigned int size);
extern "C" void* __cdecl sub_4CF840(void* self, void* arg);
extern "C" void* __cdecl sub_459CE0(void* self, void* arg);

// Minimal declaration for the class owning the target function.
struct AdornG3D {
    // Layout offsets used by the target:
    //   +0x68  : pointer (refcounted object)
    //   +0x6c  : pointer to refcount block
    //   +0x9c  : pointer (passed to sub_459CE0)
    //   +0xa0  : pointer (refcounted object)
    //   +0xa4  : pointer (refcounted object)
    char pad_0000[0x68];
    void* field_68;
    void* field_6c;
    char pad_0070[0x2c];
    void* field_9c;
    void* field_a0;
    void* field_a4;

    void func_00459dc0();
};

void AdornG3D::func_00459dc0()
{
    void* local_0 = 0;
    void* local_1 = 0;

    // First allocation: 0x58 bytes
    void* p1 = sub_62FEF6(0x58);
    local_0 = p1;

    void* new_a0 = 0;
    if (p1 != 0) {
        // Prepare a two-word structure on the stack: {field_68, field_6c}
        void* pair[2];
        pair[0] = this->field_68;
        pair[1] = this->field_6c;
        if (pair[1] != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)pair[1] + 4), 1);
        }
        new_a0 = sub_4CF840(p1, pair);
    }

    // Replace field_a0
    void* old_a0 = this->field_a0;
    if (new_a0 != old_a0) {
        if (old_a0 != 0) {
            // Virtual destructor call: first vtable entry with argument 1
            void** vtbl = *(void***)old_a0;
            typedef void (__thiscall *DtorFn)(void*, int);
            DtorFn dtor = (DtorFn)vtbl[0];
            dtor(old_a0, 1);
        }
    }
    this->field_a0 = new_a0;

    // Second allocation: 0x20 bytes
    void* p2 = sub_62FEF6(0x20);
    local_1 = p2;

    void* new_a4 = 0;
    if (p2 != 0) {
        new_a4 = sub_459CE0(p2, this->field_9c);
    }

    // Replace field_a4
    void* old_a4 = this->field_a4;
    if (new_a4 != old_a4) {
        if (old_a4 != 0) {
            void** vtbl = *(void***)old_a4;
            typedef void (__thiscall *DtorFn)(void*, int);
            DtorFn dtor = (DtorFn)vtbl[0];
            dtor(old_a4, 1);
        }
    }
    this->field_a4 = new_a4;
}
