// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00636710  unit: RBX::VScriptContext::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00636710
//
// 00636710  53                   push ebx
// 00636711  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00636715  56                   push esi
// 00636716  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0063671a  57                   push edi
// 0063671b  53                   push ebx
// 0063671c  56                   push esi
// 0063671d  e83e2b0800           call 0x6b9260
// 00636722  8bf8                 mov edi, eax
// 00636724  83c408               add esp, 8
// 00636727  85ff                 test edi, edi
// 00636729  7466                 je 0x636791
// 0063672b  53                   push ebx
// 0063672c  56                   push esi
// 0063672d  e8de2f0800           call 0x6b9710
// 00636732  83c408               add esp, 8
// 00636735  85c0                 test eax, eax
// 00636737  744d                 je 0x636786
// 00636739  a1f02aa200           mov eax, dword ptr [0xa22af0]
// 0063673e  50                   push eax
// 0063673f  68f0d8ffff           push 0xffffd8f0
// 00636744  56                   push esi
// 00636745  e8862e0800           call 0x6b95d0
// 0063674a  6afe                 push -2
// 0063674c  6aff                 push -1
// 0063674e  56                   push esi
// 0063674f  e8fc280800           call 0x6b9050
// 00636754  83c418               add esp, 0x18
// 00636757  85c0                 test eax, eax
// 00636759  7436                 je 0x636791
// 0063675b  6afd                 push -3
// 0063675d  56                   push esi
// 0063675e  e82d260800           call 0x6b8d90
// 00636763  ff0550a6a400         inc dword ptr [0xa4a650]
// 00636769  83c408               add esp, 8
// 0063676c  e8fff5faff           call 0x5e5d70
// 00636771  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00636775  8901                 mov dword ptr [ecx], eax
// 00636777  57                   push edi
// 00636778  83c104               add ecx, 4
// 0063677b  e880eefaff           call 0x5e5600
// 00636780  5f                   pop edi
// 00636781  5e                   pop esi
// 00636782  b001                 mov al, 1
// 00636784  5b                   pop ebx
// 00636785  c3                   ret 
// 00636786  6afe                 push -2
// 00636788  56                   push esi
// 00636789  e802260800           call 0x6b8d90
// 0063678e  83c408               add esp, 8
// 00636791  5f                   pop edi
// 00636792  5e                   pop esi
// 00636793  32c0                 xor al, al
// 00636795  5b                   pop ebx
// 00636796  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005ac150  unit: RBX::VScriptContext::?$FactoryProduct  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ac150
//
// 005ac150  53                   push ebx
// 005ac151  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005ac155  56                   push esi
// 005ac156  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ac15a  57                   push edi
// 005ac15b  53                   push ebx
// 005ac15c  56                   push esi
// 005ac15d  e8be5f0600           call 0x612120
// 005ac162  8bf8                 mov edi, eax
// 005ac164  83c408               add esp, 8
// 005ac167  85ff                 test edi, edi
// 005ac169  7460                 je 0x5ac1cb
// 005ac16b  53                   push ebx
// 005ac16c  56                   push esi
// 005ac16d  e83e640600           call 0x6125b0
// 005ac172  83c408               add esp, 8
// 005ac175  85c0                 test eax, eax
// 005ac177  7447                 je 0x5ac1c0
// 005ac179  a1c0b19500           mov eax, dword ptr [0x95b1c0]
// 005ac17e  50                   push eax
// 005ac17f  68f0d8ffff           push 0xffffd8f0
// 005ac184  56                   push esi
// 005ac185  e806630600           call 0x612490
// 005ac18a  6afe                 push -2
// 005ac18c  6aff                 push -1
// 005ac18e  56                   push esi
// 005ac18f  e84c5d0600           call 0x611ee0
// 005ac194  83c418               add esp, 0x18
// 005ac197  85c0                 test eax, eax
// 005ac199  7430                 je 0x5ac1cb
// 005ac19b  6afd                 push -3
// 005ac19d  56                   push esi
// 005ac19e  e87d5a0600           call 0x611c20
// 005ac1a3  83c408               add esp, 8
// 005ac1a6  e8b50cfcff           call 0x56ce60
// 005ac1ab  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ac1af  8901                 mov dword ptr [ecx], eax
// 005ac1b1  57                   push edi
// 005ac1b2  83c104               add ecx, 4
// 005ac1b5  e81610fcff           call 0x56d1d0
// 005ac1ba  5f                   pop edi
// 005ac1bb  5e                   pop esi
// 005ac1bc  b001                 mov al, 1
// 005ac1be  5b                   pop ebx
// 005ac1bf  c3                   ret 
// 005ac1c0  6afe                 push -2
// 005ac1c2  56                   push esi
// 005ac1c3  e8585a0600           call 0x611c20
// 005ac1c8  83c408               add esp, 8
// 005ac1cb  5f                   pop edi
// 005ac1cc  5e                   pop esi
// 005ac1cd  32c0                 xor al, al
// 005ac1cf  5b                   pop ebx
// 005ac1d0  c3                   ret 

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
