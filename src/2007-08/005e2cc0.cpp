// from server: 100% by auto
// from server: 62% by colin
// roc 2007-08 005e2cc0  unit: seg_005e0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e2cc0
//
// 005e2cc0  83ec08               sub esp, 8
// 005e2cc3  56                   push esi
// 005e2cc4  57                   push edi
// 005e2cc5  8bf9                 mov edi, ecx
// 005e2cc7  8d7704               lea esi, [edi + 4]
// 005e2cca  c70730cf7b00         mov dword ptr [edi], 0x7bcf30
// 005e2cd0  8b4604               mov eax, dword ptr [esi + 4]
// 005e2cd3  8b08                 mov ecx, dword ptr [eax]
// 005e2cd5  50                   push eax
// 005e2cd6  56                   push esi
// 005e2cd7  51                   push ecx
// 005e2cd8  56                   push esi
// 005e2cd9  8d442418             lea eax, [esp + 0x18]
// 005e2cdd  50                   push eax
// 005e2cde  8bce                 mov ecx, esi
// 005e2ce0  e87b0dfdff           call 0x5b3a60
// 005e2ce5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2ce8  51                   push ecx
// 005e2ce9  e874cf0400           call 0x62fc62
// 005e2cee  33c0                 xor eax, eax
// 005e2cf0  83c404               add esp, 4
// 005e2cf3  f644241401           test byte ptr [esp + 0x14], 1
// 005e2cf8  894604               mov dword ptr [esi + 4], eax
// 005e2cfb  894608               mov dword ptr [esi + 8], eax
// 005e2cfe  7409                 je 0x5e2d09
// 005e2d00  57                   push edi
// 005e2d01  e85ccf0400           call 0x62fc62
// 005e2d06  83c404               add esp, 4
// 005e2d09  8bc7                 mov eax, edi
// 005e2d0b  5f                   pop edi
// 005e2d0c  5e                   pop esi
// 005e2d0d  83c408               add esp, 8
// 005e2d10  c20400               ret 4
// library rbxgs/v8world\IMoving.cpp (function ??1IMovingManager@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs v8world/IMoving.cpp

struct IMovingManager {
    void* vtable;
    void* moving_lo;
    void* moving_hi;
    void* current;
    void* pad;
    void destroy(char flag);
};

extern "C" void __stdcall sub_5B3A60(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_62FC62(void*);

void IMovingManager::destroy(char flag)
{
    this->vtable = (void*)0x7bcf30;
    void* p = this->moving_hi;
    void* q = *(void**)p;
    sub_5B3A60(&p, &this->moving_lo, q, &this->moving_lo, &p);
    sub_62FC62(this->moving_hi);
    this->moving_hi = 0;
    this->current = 0;
    if (flag & 1) {
        sub_62FC62(this);
    }
}
