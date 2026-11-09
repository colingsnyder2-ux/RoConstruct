// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00636820  unit: RBX::VScriptContext::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00636820
//
// 00636820  53                   push ebx
// 00636821  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00636825  56                   push esi
// 00636826  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0063682a  57                   push edi
// 0063682b  53                   push ebx
// 0063682c  56                   push esi
// 0063682d  e82e2a0800           call 0x6b9260
// 00636832  8bf8                 mov edi, eax
// 00636834  83c408               add esp, 8
// 00636837  85ff                 test edi, edi
// 00636839  7466                 je 0x6368a1
// 0063683b  53                   push ebx
// 0063683c  56                   push esi
// 0063683d  e8ce2e0800           call 0x6b9710
// 00636842  83c408               add esp, 8
// 00636845  85c0                 test eax, eax
// 00636847  744d                 je 0x636896
// 00636849  a1ec2aa200           mov eax, dword ptr [0xa22aec]
// 0063684e  50                   push eax
// 0063684f  68f0d8ffff           push 0xffffd8f0
// 00636854  56                   push esi
// 00636855  e8762d0800           call 0x6b95d0
// 0063685a  6afe                 push -2
// 0063685c  6aff                 push -1
// 0063685e  56                   push esi
// 0063685f  e8ec270800           call 0x6b9050
// 00636864  83c418               add esp, 0x18
// 00636867  85c0                 test eax, eax
// 00636869  7436                 je 0x6368a1
// 0063686b  6afd                 push -3
// 0063686d  56                   push esi
// 0063686e  e81d250800           call 0x6b8d90
// 00636873  ff052ca5a400         inc dword ptr [0xa4a52c]
// 00636879  83c408               add esp, 8
// 0063687c  e83ff6faff           call 0x5e5ec0
// 00636881  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00636885  8901                 mov dword ptr [ecx], eax
// 00636887  57                   push edi
// 00636888  83c104               add ecx, 4
// 0063688b  e850eefaff           call 0x5e56e0
// 00636890  5f                   pop edi
// 00636891  5e                   pop esi
// 00636892  b001                 mov al, 1
// 00636894  5b                   pop ebx
// 00636895  c3                   ret 
// 00636896  6afe                 push -2
// 00636898  56                   push esi
// 00636899  e8f2240800           call 0x6b8d90
// 0063689e  83c408               add esp, 8
// 006368a1  5f                   pop edi
// 006368a2  5e                   pop esi
// 006368a3  32c0                 xor al, al
// 006368a5  5b                   pop ebx
// 006368a6  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005ac1e0  unit: RBX::VScriptContext::?$FactoryProduct  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ac1e0
//
// 005ac1e0  53                   push ebx
// 005ac1e1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005ac1e5  56                   push esi
// 005ac1e6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ac1ea  57                   push edi
// 005ac1eb  53                   push ebx
// 005ac1ec  56                   push esi
// 005ac1ed  e82e5f0600           call 0x612120
// 005ac1f2  8bf8                 mov edi, eax
// 005ac1f4  83c408               add esp, 8
// 005ac1f7  85ff                 test edi, edi
// 005ac1f9  7460                 je 0x5ac25b
// 005ac1fb  53                   push ebx
// 005ac1fc  56                   push esi
// 005ac1fd  e8ae630600           call 0x6125b0
// 005ac202  83c408               add esp, 8
// 005ac205  85c0                 test eax, eax
// 005ac207  7447                 je 0x5ac250
// 005ac209  a1bcb19500           mov eax, dword ptr [0x95b1bc]
// 005ac20e  50                   push eax
// 005ac20f  68f0d8ffff           push 0xffffd8f0
// 005ac214  56                   push esi
// 005ac215  e876620600           call 0x612490
// 005ac21a  6afe                 push -2
// 005ac21c  6aff                 push -1
// 005ac21e  56                   push esi
// 005ac21f  e8bc5c0600           call 0x611ee0
// 005ac224  83c418               add esp, 0x18
// 005ac227  85c0                 test eax, eax
// 005ac229  7430                 je 0x5ac25b
// 005ac22b  6afd                 push -3
// 005ac22d  56                   push esi
// 005ac22e  e8ed590600           call 0x611c20
// 005ac233  83c408               add esp, 8
// 005ac236  e8050dfcff           call 0x56cf40
// 005ac23b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ac23f  8901                 mov dword ptr [ecx], eax
// 005ac241  57                   push edi
// 005ac242  83c104               add ecx, 4
// 005ac245  e81610fcff           call 0x56d260
// 005ac24a  5f                   pop edi
// 005ac24b  5e                   pop esi
// 005ac24c  b001                 mov al, 1
// 005ac24e  5b                   pop ebx
// 005ac24f  c3                   ret 
// 005ac250  6afe                 push -2
// 005ac252  56                   push esi
// 005ac253  e8c8590600           call 0x611c20
// 005ac258  83c408               add esp, 8
// 005ac25b  5f                   pop edi
// 005ac25c  5e                   pop esi
// 005ac25d  32c0                 xor al, al
// 005ac25f  5b                   pop ebx
// 005ac260  c3                   ret 

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
