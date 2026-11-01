// from server: 100% by EspClaude
// from server: 72% by EspClaude
// roc 2009-06 00426230  unit: boost::any::H::?$holder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00426230
//
// 00426230  ff05a8a5a400         inc dword ptr [0xa4a5a8]
// 00426236  56                   push esi
// 00426237  8bf1                 mov esi, ecx
// 00426239  e872f91b00           call 0x5e5bb0
// 0042623e  6a08                 push 8
// 00426240  8906                 mov dword ptr [esi], eax
// 00426242  e8f1272f00           call 0x718a38
// 00426247  83c404               add esp, 4
// 0042624a  85c0                 test eax, eax
// 0042624c  7418                 je 0x426266
// 0042624e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00426252  c700900c8b00         mov dword ptr [eax], 0x8b0c90
// 00426258  d901                 fld dword ptr [ecx]
// 0042625a  d95804               fstp dword ptr [eax + 4]
// 0042625d  894604               mov dword ptr [esi + 4], eax
// 00426260  8bc6                 mov eax, esi
// 00426262  5e                   pop esi
// 00426263  c20400               ret 4
// 00426266  33c0                 xor eax, eax
// 00426268  894604               mov dword ptr [esi + 4], eax
// 0042626b  8bc6                 mov eax, esi
// 0042626d  5e                   pop esi
// 0042626e  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0042d200  unit: boost::any::H::?$holder  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042d200
//
// 0042d200  56                   push esi
// 0042d201  8bf1                 mov esi, ecx
// 0042d203  e898fa1300           call 0x56cca0
// 0042d208  6a08                 push 8
// 0042d20a  8906                 mov dword ptr [esi], eax
// 0042d20c  e80f372700           call 0x6a0920
// 0042d211  83c404               add esp, 4
// 0042d214  85c0                 test eax, eax
// 0042d216  7418                 je 0x42d230
// 0042d218  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042d21c  c700bc068100         mov dword ptr [eax], 0x8106bc
// 0042d222  d901                 fld dword ptr [ecx]
// 0042d224  d95804               fstp dword ptr [eax + 4]
// 0042d227  894604               mov dword ptr [esi + 4], eax
// 0042d22a  8bc6                 mov eax, esi
// 0042d22c  5e                   pop esi
// 0042d22d  c20400               ret 4
// 0042d230  33c0                 xor eax, eax
// 0042d232  894604               mov dword ptr [esi + 4], eax
// 0042d235  8bc6                 mov eax, esi
// 0042d237  5e                   pop esi
// 0042d238  c20400               ret 4

extern "C" void* __cdecl get_type();
void* __cdecl operator new(unsigned int);
extern unsigned int holder_table[];

struct Holder {
    void* table;
    float value;
    Holder(const float& v);
};

inline Holder::Holder(const float& v)
{
    table = holder_table;
    value = v;
}

struct S {
    void* type;
    Holder* holder;
    S(const float& value);
};

extern int exeCounter;
S::S(const float& value)
{
    ++exeCounter;
    type = get_type();
    holder = new Holder(value);
}
