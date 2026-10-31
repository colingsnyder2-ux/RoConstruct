// from server: 84% by EspClaude
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
