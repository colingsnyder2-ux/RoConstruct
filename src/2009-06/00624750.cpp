// from server: 100% by EspClaude
// roc 2009-06 00624750  unit: RBX::VHopperBin::?$FactoryProduct  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00624750
//
// 00624750  83ec10               sub esp, 0x10
// 00624753  d90538e88b00         fld dword ptr [0x8be838]
// 00624759  8d0424               lea eax, [esp]
// 0062475c  50                   push eax
// 0062475d  d9542404             fst dword ptr [esp + 4]
// 00624761  8d4c240c             lea ecx, [esp + 0xc]
// 00624765  d95c2408             fstp dword ptr [esp + 8]
// 00624769  51                   push ecx
// 0062476a  e83131feff           call 0x6078a0
// 0062476f  d900                 fld dword ptr [eax]
// 00624771  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00624775  d910                 fst dword ptr [eax]
// 00624777  d95804               fstp dword ptr [eax + 4]
// 0062477a  83c418               add esp, 0x18
// 0062477d  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000000_005cf190@@YGPAUPair@@PAU1@@Z)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Pair
{
    float x;
    float y;
};

extern float value_00827490;
extern const float* __cdecl func_005736f0(Pair*, const Pair*);

Pair* __stdcall func_005cf190(Pair* result)
{
    Pair input;
    Pair temporary;
    input.x = value_00827490;
    input.y = value_00827490;

    float value = *func_005736f0(&temporary, &input);
    result->x = value;
    result->y = value;
    return result;
}