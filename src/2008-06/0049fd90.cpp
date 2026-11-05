// from server: 100% by EspClaude
// from server: 61% by colin
// roc 2008-06 0049fd90  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$TSignalDesc::TSignalInstance  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049fd90
//
// 0049fd90  6aff                 push -1
// 0049fd92  682b787c00           push 0x7c782b
// 0049fd97  64a100000000         mov eax, dword ptr fs:[0]
// 0049fd9d  50                   push eax
// 0049fd9e  64892500000000       mov dword ptr fs:[0], esp
// 0049fda5  51                   push ecx
// 0049fda6  83ec1c               sub esp, 0x1c
// 0049fda9  8d442454             lea eax, [esp + 0x54]
// 0049fdad  8bcc                 mov ecx, esp
// 0049fdaf  8964241c             mov dword ptr [esp + 0x1c], esp
// 0049fdb3  50                   push eax
// 0049fdb4  c744242c01000000     mov dword ptr [esp + 0x2c], 1
// 0049fdbc  ff155c248000         call dword ptr [0x80245c]
// 0049fdc2  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0049fdc6  51                   push ecx
// 0049fdc7  83ec1c               sub esp, 0x1c
// 0049fdca  8d542454             lea edx, [esp + 0x54]
// 0049fdce  8bcc                 mov ecx, esp
// 0049fdd0  89642470             mov dword ptr [esp + 0x70], esp
// 0049fdd4  52                   push edx
// 0049fdd5  c644244c02           mov byte ptr [esp + 0x4c], 2
// 0049fdda  ff155c248000         call dword ptr [0x80245c]
// 0049fde0  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0049fde4  c644244801           mov byte ptr [esp + 0x48], 1
// 0049fde9  e852fcffff           call 0x49fa40
// 0049fdee  8d4c2418             lea ecx, [esp + 0x18]
// 0049fdf2  c644240c00           mov byte ptr [esp + 0xc], 0
// 0049fdf7  ff1568248000         call dword ptr [0x802468]
// 0049fdfd  8d4c2438             lea ecx, [esp + 0x38]
// 0049fe01  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0049fe09  ff1568248000         call dword ptr [0x802468]
// 0049fe0f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0049fe13  64890d00000000       mov dword ptr fs:[0], ecx
// 0049fe1a  83c410               add esp, 0x10
// 0049fe1d  c3                   ret 

// from server: 59% by colin
// roc 2008-06 0049fd90  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$TSignalDesc::TSignalInstance  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049fd90
//
// 0049fd90  6aff                 push -1
// 0049fd92  682b787c00           push 0x7c782b
// 0049fd97  64a100000000         mov eax, dword ptr fs:[0]
// 0049fd9d  50                   push eax
// 0049fd9e  64892500000000       mov dword ptr fs:[0], esp
// 0049fda5  51                   push ecx
// 0049fda6  83ec1c               sub esp, 0x1c
// 0049fda9  8d442454             lea eax, [esp + 0x54]
// 0049fdad  8bcc                 mov ecx, esp
// 0049fdaf  8964241c             mov dword ptr [esp + 0x1c], esp
// 0049fdb3  50                   push eax
// 0049fdb4  c744242c01000000     mov dword ptr [esp + 0x2c], 1
// 0049fdbc  ff155c248000         call dword ptr [0x80245c]
// 0049fdc2  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0049fdc6  51                   push ecx
// 0049fdc7  83ec1c               sub esp, 0x1c
// 0049fdca  8d542454             lea edx, [esp + 0x54]



#include <string>

struct Functor {
    void operator()(std::string, int, std::string);
};

union function_buffer {
    void* obj_ptr;
    char data[12];
};

struct invoker {
    static void invoke(function_buffer& function_obj_ptr, std::string a0, int a1, std::string a2)
    {
        Functor* f = reinterpret_cast<Functor*>(&function_obj_ptr.data);
        (*f)(a0, a1, a2);
    }
};

void (*roc_ptr)(function_buffer&, std::string, int, std::string) = &invoker::invoke;
