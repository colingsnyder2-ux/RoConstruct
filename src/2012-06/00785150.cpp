// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00784cf0  unit: RBX::SkateboardPlatform::W4MoveState::?$EnumDesc  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00784cf0
//
// 00784cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00784cf4  53                   push ebx
// 00784cf5  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 00784cf8  7311                 jae 0x784d0b
// 00784cfa  8b8990000000         mov ecx, dword ptr [ecx + 0x90]
// 00784d00  8b1481               mov edx, dword ptr [ecx + eax*4]
// 00784d03  89542408             mov dword ptr [esp + 8], edx
// 00784d07  b301                 mov bl, 1
// 00784d09  eb02                 jmp 0x784d0d
// 00784d0b  32db                 xor bl, bl
// 00784d0d  68300e7700           push 0x770e30
// 00784d12  68f485e400           push 0xe485f4
// 00784d17  e884c8c7ff           call 0x4015a0
// 00784d1c  83c408               add esp, 8
// 00784d1f  e8acc0feff           call 0x770dd0
// 00784d24  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00784d28  8901                 mov dword ptr [ecx], eax
// 00784d2a  8d442408             lea eax, [esp + 8]
// 00784d2e  50                   push eax
// 00784d2f  83c104               add ecx, 4
// 00784d32  e8298cfeff           call 0x76d960
// 00784d37  8ac3                 mov al, bl
// 00784d39  5b                   pop ebx
// 00784d3a  c20800               ret 8


struct Any { void assign(const unsigned*); };
struct Variant { const void* type; Any value; };
extern int once_flag;
void init_type();
void call_once(int&, void (*)());
const void* get_type();
struct S {
    char a[0x2c];
    unsigned count;
    char b[0x90 - 0x30];
    unsigned* values;
    bool f(unsigned, Variant&) const;
};
bool S::f(unsigned index, Variant& out) const {
    bool ok;
    if (index < count) {
        index = values[index];
        ok = true;
    } else {
        ok = false;
    }
    call_once(once_flag, init_type);
    out.type = get_type();
    out.value.assign(&index);
    return ok;
}
