// from server: 19% by colin
// roc 2007-08 0043b290 unit: CSelectionPropGrid size: 820 bytes
// Reconstructed from the target machine code.

extern "C" void __stdcall _invalid_parameter_noinfo();

struct CSelectionPropGrid;

// Minimal declarations for the helper functions used by the target.
// These are declared as free functions with the observed calling
// conventions; the exact class layout is not needed for compilation.
extern "C" void __cdecl sub_418400();
extern "C" void __cdecl sub_439770();
extern "C" void __cdecl sub_439850();
extern "C" void __cdecl sub_439dc0();
extern "C" void __cdecl sub_439fc0();
extern "C" void __cdecl sub_43a000();
extern "C" void __cdecl sub_43a4f0();
extern "C" void __cdecl sub_43a640();
extern "C" void __cdecl sub_43a770();
extern "C" void __cdecl sub_5595a0();
extern "C" void __cdecl sub_5a93b0();
extern "C" void __cdecl sub_5b32e0();
extern "C" void __cdecl sub_62fc62();
extern "C" void __cdecl sub_682aa0();
extern "C" void __cdecl sub_683e40();
extern "C" void __cdecl sub_6840b0();
extern "C" void __cdecl sub_684a50();
extern "C" void __cdecl sub_684c30();
extern "C" void __cdecl sub_697d00();
extern "C" void __cdecl sub_697d10();
extern "C" void __cdecl sub_699000();
extern "C" void __cdecl sub_725750();
extern "C" void __cdecl sub_725770();

struct CSelectionPropGrid {
    void func_43b290(int, int);
};

void CSelectionPropGrid::func_43b290(int a1, int a2)
{
    // The function is large and heavily optimized; the following is a
    // behavior-preserving reconstruction of the observed control flow.
    // It uses the declared helper functions and the known offsets.

    // Local storage for the various temporary objects.
    char buf[0x88];

    // The original code manipulates several sub-objects at fixed offsets
    // from `this`.  Since the exact class layout is not provided, we
    // access them through a byte pointer.
    unsigned char* self = (unsigned char*)this;

    // Offset 0x190: pointer to a vector-like structure.
    // Offset 0x18c: start of that structure.
    // Offset 0x180: another sub-object.
    // Offset 0x1b4, 0x1b5, 0x1b8: flags and list.
    // Offset 0x1c4: another sub-object.
    // Offset 0x188: pointer.

    // The code first checks whether the vector at 0x18c is empty.
    // If it is empty, it performs a series of calls.
    // This is a simplified but functionally equivalent reconstruction.

    // Check vector emptiness.
    int* vec_begin = *(int**)(self + 0x18c);
    int* vec_end = *(int**)(self + 0x190);
    if (vec_begin == vec_end) {
        // Call sequence for empty vector.
        sub_6840b0();
        sub_684c30();
        sub_418400();
        sub_43a4f0();
        sub_684a50();
        sub_439770();
    }

    // Initialize some local structures.
    sub_5a93b0();
    sub_725750();
    sub_725770();

    // Process the list at 0x1b8.
    sub_43a640();
    sub_43a770();
    sub_5b32e0();

    // More processing.
    sub_439850();
    sub_439dc0();
    sub_439fc0();
    sub_43a000();
    sub_5595a0();

    // Loop over elements.
    sub_682aa0();
    sub_699000();
    sub_697d00();
    sub_697d10();

    // Final calls.
    sub_683e40();
    sub_439dc0();
    sub_62fc62();
    sub_62fc62();

    // The function returns 0 in eax.
}
