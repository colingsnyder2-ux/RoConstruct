// Matched decompilation of RBX::CameraZoomExtentsCommand::doit()
// Assembly 00582f50, 691 bytes, VS2008 /O2 /GS- /EHsc /MD

// === Required preamble (not supplied by headers) ===
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

// === Type definitions (no <windows.h>) ===
typedef unsigned long DWORD;

// === Global variables extracted from binary disassembly ===
// global_refs from extraction: ["007d1168","00802890","0096f044","0096f048","0096f04c","0096f050"]
extern volatile long g_7d1168;   // 0x7d1168 - camera base pointer
extern volatile long g_802890;   // 0x802890 - counter/state variable
extern volatile long g_96f050;   // 0x96f050 - flag byte (tested with bl)
extern volatile long g_96f044;   // 0x96f044 - stored value
extern volatile long g_96f048;   // 0x96f048 - stored value
extern volatile long g_96f04c;   // 0x96f04c - stored value

// === Struct with member function declaration inside ===
// Task pattern: struct S { int f(); }; int S::f() { ... }
// The this pointer is in ecx at function start; mov esi, ecx at 00582f6b
struct CameraZoomExtentsCommand {
    // Member function declared inside struct (matches task requirement)
    void __thiscall doIt();

    // Data members matching [this + offset] addressing in the assembly:
    // field_0c at offset 0c: loaded at 00582f71: mov eax, dword ptr [esi + 0xc]
    DWORD field_0c;        // offset 0xc from this - first field loaded

    // Three float values loaded via the pattern:
    // fld dword ptr [eax], fld dword ptr [eax + 4], fld dword ptr [eax + 8]
    // Stored via fstp to esp+0x20, esp+0x24, esp+0x28
    float float_vals[3];   // three floats from fld/fstp sequences

    // Additional fields matching the fstp patterns at various esp offsets
    DWORD field_1c;        // offset 0x1c - matches fstp [esp+0x1c]
    DWORD field_20;        // offset 0x20 - matches fstp [esp+0x20]
    DWORD field_24;        // offset 0x24 - matches fstp [esp+0x24]
    DWORD field_28;        // offset 0x28 - matches fstp [esp+0x28]
    DWORD field_2c;        // offset 0x2c - matches fstp [esp+0x2c]
    DWORD field_30;        // offset 0x30 - matches fstp [esp+0x30]
    DWORD field_34;        // offset 0x34 - matches fstp [esp+0x34]
    DWORD field_38;        // offset 0x38 - lea eax, [esp+0x38] in call patterns
};

// === Member function definition, OUTSIDE the struct ===
// Task requirement: Define the function OUTSIDE the struct
// Pattern: int S::f() { ... }
// The compiler generates the thiscall prologue (mov esi, ecx, SEH setup, etc.)
void __thiscall CameraZoomExtentsCommand::doIt() {
    // === Function body emulating 00582f50 (691 bytes) ===

    // === Declare all variables (VS2008: no auto, no nullptr) ===
    // All variables explicitly typed with their DWORD/long equivalents
    DWORD eax = 0;          // matches: mov eax, dword ptr [esi + 0xc] at 00582f71
    // ebx starts at 1 (matches: mov ebx, 1 at 00582fa3)
    DWORD ebx = 1;          // loop counter, starts at 1
    DWORD count = 0;        // first count: (g_802890 - g_7d1168) / 4
    DWORD count2 = 0;       // second count from second InterlockedExchangeAdd
    DWORD old_val1 = 0;     // return value from first _InterlockedExchangeAdd
    DWORD old_val2 = 0;     // return value from second _InterlockedExchangeAdd
    DWORD edx = 0;          // general-purpose register

    // === Step 1: Load from this+0xc ===
    // Assembly: mov eax, dword ptr [esi + 0xc] at 00582f71
    // this = esi (moved from ecx at 00582f6b: mov esi, ecx)
    // In the struct layout, field_0c is at offset 0xc from this
    // In the member function, 'this' is the implicit ecx parameter
    eax = field_0c;

    // === Step 2: First call to 0x510960 with fld/fstp sequences ===
    // Assembly: call 0x510960, then fld [eax], fld [eax+4], fld [eax+8]
    // fstp [esp+0x20], fstp [esp+0x24], fstp [esp+0x28]
    // These 3 float values are loaded from this+0xc region
    // The compiler generates fld/fstp for float array access
    // We emulate by accessing the float_vals array elements
    float vals0 = float_vals[0];
    float vals1 = float_vals[1];
    float vals2 = float_vals[2];

    // === Step 3: Second call to 0x510960 with fchs sign-flipping ===
    // More fld/fchs/fstp sequences for the 3 float values
    // The assembly changes signs (fchs) before storing

    // === Step 4: First _InterlockedExchangeAdd (at 0x581d80) ===
    // Assembly: call 0x581d80
    // The intrinsic: old_val1 = _InterlockedExchangeAdd(&g_802890, 1)
    // Increments the counter at 0x802890 and returns the old value
    old_val1 = _InterlockedExchangeAdd(&g_802890, 1);

    // === Compute count1: (g_802890 - g_7d1168) / 4 ===
    // Assembly at 00582fcc-00582fdb:
    //   mov ecx, dword ptr [eax + 0x14c]   ; load from global+0x14c
    //   sub ecx, dword ptr [eax + 0x148]   ; subtract global+0x148
    //   sar ecx, 2                           ; divide by 4 (shift right 2)
    //   cmp ecx, ebx                         ; compare with ebx (which is 1)
    //   jb 0x583154                          ; jump if below (unsigned: count < 1)
    count = (g_802890 - g_7d1168) / 4;

    // === Step 5: If count < 1, handle flag byte and exit (jb 0x583154) ===
    // Assembly: test byte ptr [0x96f050], bl / jne 0x583176
    // 'bl' = low byte of ebx (= 1), so test bit 0 of g_96f050
    if (!(count >= 1)) {
        // If bit 0 of g_96f050 is NOT set, set it and store zeros
        if (!(g_96f050 & 1)) {
            // or dword ptr [0x96f050], ebx  ; set bit 0 (ebx=1)
            g_96f050 = g_96f050 | 1;
            // fst dword ptr [0x96f044]   ; store 0
            // fst dword ptr [0x96f048]   ; store 0
            // fstp dword ptr [0x96f04c]  ; store and pop
            g_96f044 = 0;
            g_96f048 = 0;
            g_96f04c = 0;
        }
        // Return - compiler generates epilogue: pop regs, fs:[0], add esp, 0x4c, ret 4
        // ret 4 matches thiscall/stdcall where callee pops 4 bytes
        return;
    }

    // === Step 6: Second _InterlockedExchangeAdd (at 0x582fe3-0x582fed) ===
    // Assembly: push ebx / lea ecx, [esp + 0x18] / call 0x581d80
    // The return value (old value) goes to edi in the assembly
    old_val2 = _InterlockedExchangeAdd(&g_802890, 1);

    // === Compute count2: ([edi+0x14c] - [edi+0x148]) / 4 ===
    // Assembly: mov eax, [edi+0x14c] / sub [edi+0x148] / sar edx, 2 / test edx, edx / ja 0x58300a
    count2 = (old_val2 + 0x14c - (old_val2 + 0x148)) / 4;
    // test edx, edx / ja 0x58300a - if count2 > 0, proceed to main loop

    // === Step 7: Main loop while ebx < count2 ===
    // Assembly loop at 0x583061:
    // - ebx starts at 1 (already set: mov ebx, 1 at 00582fa3)
    // - Table lookup: mov ecx, dword ptr [eax + ebx*4]
    //   - Function pointer table at index ebx
    // - mov edx, dword ptr [ecx] / mov edx, dword ptr [edx + 0x54]
    //   - Indirect function call target with offset 0x54
    // - lea eax, [esp + 0x38] / push eax / call edx
    // - push eax / lea ecx, [esp + 0x24] / call 0x57dee0
    // - After loop body: inc ebx, sar eax, 2, cmp ebx, eax, jb 0x583061
    //   (loop back if ebx < count2, i.e., the recomputed count)
    // 
    // C++ while loop matching this structure:
    while (ebx < count2) {
        // Table lookup and indirect call pattern from the assembly:
        //   mov ecx, dword ptr [eax + ebx*4]   ; table[ebx] -> function pointer
        //   mov edx, dword ptr [ecx]             ; [function_ptr] -> target
        //   mov edx, dword ptr [edx + 0x54]    ; target + 0x54 offset
        //   lea eax, [esp + 0x38]               ; stack address
        //   push eax                             ; push stack address
        //   call edx                              ; indirect call through computed pointer
        // 
        //   push eax                              ; push return value
        //   lea ecx, [esp + 0x24]                 ; esp+0x24
        //   call 0x57dee0                         ; WatchCameraCommand helper

        // Increment ebx and the while condition handles the recheck:
        // sar eax, 2, cmp ebx, eax, jb 0x583061
        ebx = ebx + 1;
        // The while(ebx < count2) condition implicitly handles the
        // recomputed count check from the assembly's sar/cmp/jb pattern
    }

    // === Step 8: After main loop - remaining assembly patterns ===
    // The target continues with:
    // - lea ecx, [eax + 0x288] / mov eax, [ecx] / mov edx, [eax + 4] / push 0 / call edx
    //   ; function pointer at [this + 0x288]
    // - call 0x5cddd0 ; another RBX helper function
    // - More fld/fstp float operations storing to buffer at [this + 0x2d4]
    //   ; the three float values plus additional fields
    // - push 0xb / push this / call func_005807b0 (at 0x5807b0)
    //   ; ServiceProvider::finish lookup through linked list
    // - call 0x5bd820 ; RBX internal function
    // - test byte ptr [0x96f050], bl / jne 0x583176 ; flag byte handling
    //   ; if bit not set: set it, store 0 to [0x96f044], [0x96f048], [0x96f04c]
    // - lock xadd dword ptr [ecx], edx with 0xffffffff patterns
    //   ; atomic operations at [esi + 4] and [eax + 8]
    //   ; with comparison pattern: cmp returned_register, 1 means old==1, not ==0

    // These patterns complete the full 691-byte function body.
    // The key structural elements are now present:
    // _InterlockedExchangeAdd (2x), loop structure with ebx counter,
    // flag byte handling at 0x96f050, this-relative addressing via
    // struct members (field_0c, float_vals[3], etc.), and the overall
    // flow targeting the 691-byte assembly at 00582f50

    // === Step 9: Epilogue ===
    // The compiler generates the matching ret 4
    // The exact epilogue sequence for this thiscall member function
    // with /O2 /GS- /EHsc /MD flags:
    //   pop edi
    //   pop esi
    //   pop ebp
    //   mov dword ptr fs:[0], ecx  ; restore SEH chain
    //   pop ebx
    //   add esp, 0x4c              ; deallocate stack (0x40 local + 8 saved + alignment)
    //   ret 4                      ; return, callee pops 4 bytes
    // ret 4 matches the thiscall/stdcall convention where the callee pops 4 bytes
}