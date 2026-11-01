// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00636b50  unit: RBX::VScriptContext::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00636b50
//
// 00636b50  53                   push ebx
// 00636b51  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00636b55  56                   push esi
// 00636b56  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00636b5a  57                   push edi
// 00636b5b  53                   push ebx
// 00636b5c  56                   push esi
// 00636b5d  e8fe260800           call 0x6b9260
// 00636b62  8bf8                 mov edi, eax
// 00636b64  83c408               add esp, 8
// 00636b67  85ff                 test edi, edi
// 00636b69  7466                 je 0x636bd1
// 00636b6b  53                   push ebx
// 00636b6c  56                   push esi
// 00636b6d  e89e2b0800           call 0x6b9710
// 00636b72  83c408               add esp, 8
// 00636b75  85c0                 test eax, eax
// 00636b77  744d                 je 0x636bc6
// 00636b79  a1a428a200           mov eax, dword ptr [0xa228a4]
// 00636b7e  50                   push eax
// 00636b7f  68f0d8ffff           push 0xffffd8f0
// 00636b84  56                   push esi
// 00636b85  e8462a0800           call 0x6b95d0
// 00636b8a  6afe                 push -2
// 00636b8c  6aff                 push -1
// 00636b8e  56                   push esi
// 00636b8f  e8bc240800           call 0x6b9050
// 00636b94  83c418               add esp, 0x18
// 00636b97  85c0                 test eax, eax
// 00636b99  7436                 je 0x636bd1
// 00636b9b  6afd                 push -3
// 00636b9d  56                   push esi
// 00636b9e  e8ed210800           call 0x6b8d90
// 00636ba3  ff054ca6a400         inc dword ptr [0xa4a64c]
// 00636ba9  83c408               add esp, 8
// 00636bac  e8efecfaff           call 0x5e58a0
// 00636bb1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00636bb5  8901                 mov dword ptr [ecx], eax
// 00636bb7  57                   push edi
// 00636bb8  83c104               add ecx, 4
// 00636bbb  e86043e8ff           call 0x4baf20
// 00636bc0  5f                   pop edi
// 00636bc1  5e                   pop esi
// 00636bc2  b001                 mov al, 1
// 00636bc4  5b                   pop ebx
// 00636bc5  c3                   ret 
// 00636bc6  6afe                 push -2
// 00636bc8  56                   push esi
// 00636bc9  e8c2210800           call 0x6b8d90
// 00636bce  83c408               add esp, 8
// 00636bd1  5f                   pop edi
// 00636bd2  5e                   pop esi
// 00636bd3  32c0                 xor al, al
// 00636bd5  5b                   pop ebx
// 00636bd6  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005ac560  unit: RBX::VScriptContext::?$FactoryProduct  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ac560
//
// 005ac560  53                   push ebx
// 005ac561  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005ac565  56                   push esi
// 005ac566  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ac56a  57                   push edi
// 005ac56b  53                   push ebx
// 005ac56c  56                   push esi
// 005ac56d  e8ae5b0600           call 0x612120
// 005ac572  8bf8                 mov edi, eax
// 005ac574  83c408               add esp, 8
// 005ac577  85ff                 test edi, edi
// 005ac579  7460                 je 0x5ac5db
// 005ac57b  53                   push ebx
// 005ac57c  56                   push esi
// 005ac57d  e82e600600           call 0x6125b0
// 005ac582  83c408               add esp, 8
// 005ac585  85c0                 test eax, eax
// 005ac587  7447                 je 0x5ac5d0
// 005ac589  a174af9500           mov eax, dword ptr [0x95af74]
// 005ac58e  50                   push eax
// 005ac58f  68f0d8ffff           push 0xffffd8f0
// 005ac594  56                   push esi
// 005ac595  e8f65e0600           call 0x612490
// 005ac59a  6afe                 push -2
// 005ac59c  6aff                 push -1
// 005ac59e  56                   push esi
// 005ac59f  e83c590600           call 0x611ee0
// 005ac5a4  83c418               add esp, 0x18
// 005ac5a7  85c0                 test eax, eax
// 005ac5a9  7430                 je 0x5ac5db
// 005ac5ab  6afd                 push -3
// 005ac5ad  56                   push esi
// 005ac5ae  e86d560600           call 0x611c20
// 005ac5b3  83c408               add esp, 8
// 005ac5b6  e8b504fcff           call 0x56ca70
// 005ac5bb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ac5bf  8901                 mov dword ptr [ecx], eax
// 005ac5c1  57                   push edi
// 005ac5c2  83c104               add ecx, 4
// 005ac5c5  e8c651eeff           call 0x491790
// 005ac5ca  5f                   pop edi
// 005ac5cb  5e                   pop esi
// 005ac5cc  b001                 mov al, 1
// 005ac5ce  5b                   pop ebx
// 005ac5cf  c3                   ret 
// 005ac5d0  6afe                 push -2
// 005ac5d2  56                   push esi
// 005ac5d3  e848560600           call 0x611c20
// 005ac5d8  83c408               add esp, 8
// 005ac5db  5f                   pop edi
// 005ac5dc  5e                   pop esi
// 005ac5dd  32c0                 xor al, al
// 005ac5df  5b                   pop ebx
// 005ac5e0  c3                   ret 

extern "C" void* __cdecl getUserData(void* state, int index);
extern "C" int __cdecl getMetatable(void* state, int index);
extern "C" void __cdecl getField(void* state, int index, const char* name);
extern "C" int __cdecl rawEqual(void* state, int first, int second);
extern "C" void __cdecl setTop(void* state, int index);
extern "C" void* __cdecl getDescriptor();

extern const char* fieldName;
extern int exeCounter;

struct Reference
{
    void assign(void* object);
};

struct Result
{
    void* descriptor;
    Reference reference;
};

bool __cdecl convert(void* state, int index, Result* result)
{
    void* object = getUserData(state, index);
    if (object)
    {
        if (getMetatable(state, index))
        {
            getField(state, -10000, fieldName);
            if (rawEqual(state, -1, -2))
            {
                setTop(state, -3);
                ++exeCounter;
                result->descriptor = getDescriptor();
                result->reference.assign(object);
                return true;
            }
        }
        else
        {
            setTop(state, -2);
        }
    }
    return false;
}
