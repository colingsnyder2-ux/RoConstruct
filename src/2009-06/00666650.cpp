// from server: 100% by EspClaude
// from server: 75% by EspClaude
// roc 2009-06 00666650  unit: RBX::KernelJoint  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00666650
//
// 00666650  8b442404             mov eax, dword ptr [esp + 4]
// 00666654  85c0                 test eax, eax
// 00666656  741e                 je 0x666676
// 00666658  8b4048               mov eax, dword ptr [eax + 0x48]
// 0066665b  6a00                 push 0
// 0066665d  6888619e00           push 0x9e6188
// 00666662  6840be9d00           push 0x9dbe40
// 00666667  6a00                 push 0
// 00666669  50                   push eax
// 0066666a  e80b360b00           call 0x719c7a
// 0066666f  83c414               add esp, 0x14
// 00666672  85c0                 test eax, eax
// 00666674  7502                 jne 0x666678
// 00666676  33c0                 xor eax, eax
// 00666678  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005d7670  unit: RBX::Humanoid  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d7670
//
// 005d7670  8b442404             mov eax, dword ptr [esp + 4]
// 005d7674  85c0                 test eax, eax
// 005d7676  7421                 je 0x5d7699
// 005d7678  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 005d767e  6a00                 push 0
// 005d7680  68402a9300           push 0x932a40
// 005d7685  687c909200           push 0x92907c
// 005d768a  6a00                 push 0
// 005d768c  50                   push eax
// 005d768d  e834a10c00           call 0x6a17c6
// 005d7692  83c414               add esp, 0x14
// 005d7695  85c0                 test eax, eax
// 005d7697  7502                 jne 0x5d769b
// 005d7699  33c0                 xor eax, eax
// 005d769b  c3                   ret 

extern char instanceType;
extern char modelType;

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct S {
    char padding[0x48];
    void* instance;
};

void* func_005d7670(S* object)
{
    if (object) {
        void* model = __RTDynamicCast(object->instance, 0,
                                     &instanceType, &modelType, 0);
        if (model)
            return model;
    }
    return 0;
}
