// from server: 31% by colin
// Minimal declarations for the imports used by the target function.
// These are declared as plain function pointers to avoid needing headers.

typedef void* (__stdcall *Fn_77ddac)();
typedef void* (__stdcall *Fn_77d59c)(unsigned int);
typedef void* (__stdcall *Fn_77dd98)();
typedef void* (__stdcall *Fn_77ddbc)();
typedef void* (__stdcall *Fn_77e658)();
typedef void* (__stdcall *Fn_77e65c)();
typedef void* (__stdcall *Fn_77e69c)();
typedef void* (__stdcall *Fn_77e6ac)();

extern Fn_77ddac g_77ddac;
extern Fn_77d59c g_77d59c;
extern Fn_77dd98 g_77dd98;
extern Fn_77ddbc g_77ddbc;
extern Fn_77e658 g_77e658;
extern Fn_77e65c g_77e65c;
extern Fn_77e69c g_77e69c;
extern Fn_77e6ac g_77e6ac;

// Internal helper functions referenced by the target.
extern "C" void __cdecl sub_6303f4();
extern "C" int  __cdecl sub_6303ee();
extern "C" void __cdecl sub_6303e8();
extern "C" void __cdecl sub_6303dc();
extern "C" void __cdecl sub_630a1e();
extern "C" void __cdecl sub_438c80();
extern "C" void __cdecl sub_408740();
extern "C" void __cdecl sub_547ca0();

// The class whose member function we are reconstructing.
struct TextureItem {
    void sub_4418b0();
    void sub_440440(void*);
};

void TextureItem::sub_4418b0()
{
    // The function constructs a temporary ifstream, reads a line,
    // and if successful, parses it and calls sub_440440.
    // The exact stack layout is reproduced by the compiler from the
    // local objects and calls below.

    // Local buffers and objects (sizes chosen to match the stack frame).
    char path[0x84];
    char line[0x100];
    char temp[0x100];

    // The following calls mirror the observed sequence.
    // They are declared as function pointers to avoid headers.
    g_77ddac();                     // construct something (maybe locale)
    g_77d59c(0x84);                 // allocate / construct path buffer
    g_77dd98();                     // get something
    g_77dd98();                     // get something
    sub_6303f4();                   // construct ifstream
    if (sub_6303ee() == 1) {
        sub_6303e8();               // get line
        g_77dd98();                 // get something
        g_77e658();                 // open file
        g_77ddbc();                 // close / destroy
        sub_6303e8();               // get line
        g_77dd98();                 // get something
        sub_438c80();               // parse
        sub_408740();               // process
        sub_547ca0();               // convert
        g_77e69c();                 // copy string
        g_77e6ac();                 // destroy string
        g_77ddbc();                 // destroy something
        sub_440440(temp);           // call member function
        g_77e6ac();                 // destroy string
        g_77e65c();                 // destroy something
    }
    sub_6303dc();                   // destroy ifstream
    g_77ddbc();                     // destroy something
    sub_630a1e();                   // stack check
}
