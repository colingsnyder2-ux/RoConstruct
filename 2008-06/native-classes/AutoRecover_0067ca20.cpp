// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 8-byte POD element, copy-constructed via placement new in a fill_n loop
struct Elem8 {
    unsigned int a;
    unsigned int b;
};

extern "C" void fn_0067ca20(Elem8* dest, unsigned int count, const Elem8* value)
{
    if (count > 0) {
        do {
            if (dest) {
                dest->a = value->a;
                dest->b = value->b;
            }
            --count;
            ++dest;
        } while (count > 0);
    }
}
