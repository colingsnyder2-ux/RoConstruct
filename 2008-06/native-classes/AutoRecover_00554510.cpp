// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the third stack argument is an object whose first virtual method
// is a __thiscall taking (outer object, arg1, arg2) and popping 12 bytes.
struct FnCallback_00554510 {
    virtual void invoke(void* outer, int a, int b) = 0;
};

// INFERRED: self is a secondary-base subobject located 0x130 bytes into the
// outer object. The function adjusts it back (null-safe) and forwards to the
// callback inside a try block. The catch handler body is not visible in the
// listing, so it is guessed as a swallow-all handler.
extern "C" void __fastcall fn_00554510(void* self, int unusedEdx, int arg1, int arg2, FnCallback_00554510* cb)
{
    try {
        void* outer = 0;
        if (self != 0)
            outer = (char*)self - 0x130;
        cb->invoke(outer, arg1, arg2);
    }
    catch (...) {
        // INFERRED: handler body not shown in the disassembly
    }
}
