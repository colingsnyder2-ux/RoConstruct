// from server: 100% by colin
// from server: 80% by colin
// roc 2008-06 00443b50  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00443b50
//
// 00443b50  8b8930010000         mov ecx, dword ptr [ecx + 0x130]
// 00443b56  56                   push esi
// 00443b57  8b742408             mov esi, dword ptr [esp + 8]
// 00443b5b  85c9                 test ecx, ecx
// 00443b5d  7411                 je 0x443b70
// 00443b5f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00443b62  8b4004               mov eax, dword ptr [eax + 4]
// 00443b65  83c004               add eax, 4
// 00443b68  50                   push eax
// 00443b69  e8e23d1100           call 0x557950
// 00443b6e  eb02                 jmp 0x443b72
// 00443b70  33c0                 xor eax, eax
// 00443b72  85c0                 test eax, eax
// 00443b74  741d                 je 0x443b93
// 00443b76  8bc8                 mov ecx, eax
// 00443b78  e843fdffff           call 0x4438c0
// 00443b7d  85c0                 test eax, eax
// 00443b7f  7412                 je 0x443b93
// 00443b81  8b5604               mov edx, dword ptr [esi + 4]
// 00443b84  83c204               add edx, 4
// 00443b87  5e                   pop esi
// 00443b88  89542404             mov dword ptr [esp + 4], edx
// 00443b8c  8bc8                 mov ecx, eax
// 00443b8e  e9bd3d1100           jmp 0x557950
// 00443b93  33c0                 xor eax, eax
// 00443b95  5e                   pop esi
// 00443b96  c20400               ret 4

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
#include <intrin.h>
extern char instance_type;
extern char properties_type;

struct Entry {
    void* object;
    void* other;
};

struct S {
    char pad[0x130];
    void* field130;
    void* f(void* arg);
};

struct T {
    void* sub_557950(void* a);
    void* sub_4438c0();
};

void* S::f(void* arg) {
    void* ecx = this->field130;
    void* eax;
    if (ecx != 0) {
        Entry* e = *(Entry**)((char*)arg + 0xc);
        void* p = (void*)((char*)e->other + 4);
        eax = ((T*)ecx)->sub_557950(p);
    } else {
        eax = 0;
    }
    _ReadWriteBarrier();
    if (eax != 0) {
        void* r = ((T*)eax)->sub_4438c0();
        if (r != 0) {
            void* d = (void*)((char*)(*(void**)((char*)arg + 4)) + 4);
            return ((T*)r)->sub_557950(d);
        }
    }
    return 0;
}
