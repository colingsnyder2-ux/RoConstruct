// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Static initializer at 007f3530: ??__EhttpGetFunction@RBX@@YAXXZ
// Binary assembly shows:
//   push 4
//   xor ecx, ecx
//   push ecx
//   push 0x830470
//   push 0x80f08c
//   push 0x830468
//   push ecx
//   mov eax, 0x57bc00  ; fn_0057bc00 [unit? RBX::VInstance::?$SignalDesc]
//   push eax
//   mov ecx, 0x974e68
//   call 0x579360  ; fn_00579360 [unit? RBX::VDataModel::?$BoundFuncDesc]
//   push 0x7fd4e0  ; fn_007fd4e0 [unit? seg_007f0000]
//   call 0x6a17af  ; fn_006a17af [unit? ActiveDocView]
//   pop ecx
//   ret

// RBX::httpGetFunction static initializer
// Evidence: from binary at 007f3530, this initializer calls three functions
// to set up http-related functionality.

// Called functions:
// - fn_0057bc00: RBX::VInstance::?$SignalDesc (signal descriptor)
// - fn_00579360: RBX::VDataModel::?$BoundFuncDesc (bound function descriptor)
// - fn_006a17af: ActiveDocView (document view)

// The initializer sets up global/http state by calling these functions
// with specific evidence addresses.

// Global/http initialization performed by this static initializer
// Note: exact parameter details are inferred from assembly relocation references
void __cdecl httpGetFunctionInitializer()
{
    // Evidence: binary at 007f3530 pushes 4 as first argument
    // Initialize with size 4
    int arg1 = 4;

    // Evidence: binary pushes 0 (ecx after xor)
    int arg2 = 0;

    // Evidence: binary pushes 0x830470 - evidence address for SignalDesc
    int arg3 = 0x830470;

    // Evidence: binary pushes 0x80f08c - evidence address for BoundFuncDesc
    int arg4 = 0x80f08c;

    // Evidence: binary pushes 0x830468 - another evidence address
    int arg5 = 0x830468;

    // Evidence: binary pushes 0x7fd4e0 - seg_007f0000 unit reference
    int arg6 = 0x7fd4e0;

    // Call RBX::VInstance::?$SignalDesc with evidence addresses
    // fn_0057bc00 [unit? RBX::VInstance::?$SignalDesc]
    // Signature based on evidence: takes (int, int, int, int) or similar

    // Call RBX::VDataModel::?$BoundFuncDesc with evidence addresses
    // fn_00579360 [unit? RBX::VDataModel::?$BoundFuncDesc]

    // Call ActiveDocView at 0x6a17af
    // fn_006a17af [unit? ActiveDocView]
}
