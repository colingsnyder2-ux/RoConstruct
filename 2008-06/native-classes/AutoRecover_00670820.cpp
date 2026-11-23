// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: element is an 8-byte POD (two 32-bit words); copied word by word.
struct Elem8 {
    int a;
    int b;
};

extern "C" void fn_00670820(Elem8* first, Elem8* last, const Elem8* value)
{
    if (first != last) {
        do {
            first->a = value->a;
            first->b = value->b;
            ++first;
        } while (first != last);
    }
}
