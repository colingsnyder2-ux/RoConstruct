// from server: 45% by colin
// Minimal declarations for the target function.
// The function is a member of a class (ecx = this), but the body does not
// actually use `this`; it constructs a temporary std::string and calls a
// helper.  We model the std::string as an opaque 0x1c-byte object.

typedef unsigned int DWORD;

// std::string layout: 0x1c bytes (VS2005 basic_string with allocator).
struct StdString {
    char data[0x1c];
    StdString();
    ~StdString();
    StdString& operator=(const StdString&);
    StdString& operator=(const char*);
};

// The helper at 0x471880 takes a std::string* (returned in eax) plus
// several arguments.  We declare it as a free function returning StdString*.
extern "C" StdString* __cdecl sub_471880(
    StdString* out,
    void* a2,
    void* a3,
    void* a4,
    void* a5,
    void* a6,
    void* a7,
    void* a8,
    void* a9,
    void* a10,
    void* a11);

// CRT helpers used by the compiler-generated code.
extern "C" void* __cdecl sub_630bdc(void*, int, int, int, int, int);
extern "C" void* __cdecl sub_630af7(void*, int, int, int, int);
extern "C" void __cdecl sub_630a1e(void);

// Imported functions from MSVCP80.dll (std::string ctor/dtor/assign).
extern "C" void __stdcall string_ctor(StdString*);
extern "C" void __stdcall string_dtor(StdString*);
extern "C" void __stdcall string_assign_str(StdString*, const StdString*);
extern "C" void __stdcall string_assign_cstr(StdString*, const char*);

// The class whose member function this is.  We only need the member
// function signature; the body does not touch any fields.
struct G3DTexture {
    void* method(void* a1, void* a2, void* a3, void* a4, void* a5,
                 void* a6, void* a7, void* a8, void* a9, void* a10);
};

void* G3DTexture::method(void* a1, void* a2, void* a3, void* a4, void* a5,
                         void* a6, void* a7, void* a8, void* a9, void* a10)
{
    // Local std::string temporaries (five of them, each 0x1c bytes).
    StdString s0, s1, s2, s3, s4;
    StdString result;

    // The compiler-generated code initializes the strings and calls the
    // helper.  We reproduce the observable behavior: construct strings,
    // call the helper, then destroy them.
    string_ctor(&s0);
    string_ctor(&s1);
    string_ctor(&s2);
    string_ctor(&s3);
    string_ctor(&s4);

    // The helper at 0x471880 is called with the address of a local string
    // and several arguments.  We pass the first local string.
    sub_471880(&result, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);

    string_dtor(&s4);
    string_dtor(&s3);
    string_dtor(&s2);
    string_dtor(&s1);
    string_dtor(&s0);

    return &result;
}
