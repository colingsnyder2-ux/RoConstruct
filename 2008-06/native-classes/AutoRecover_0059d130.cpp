// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0059c490[];   // INFERRED: unnamed global at 0x0059c490 in the original
extern "C" char g_00832f74[];   // INFERRED: unnamed global at 0x00832f74 in the original
extern "C" char g_0097648c[];   // INFERRED: unnamed global at 0x0097648c in the original
#include <new>

typedef unsigned Word;

struct Triple
{
    Word a, b, c;
};

// boost::call_once(void(*)(), long&)
extern "C" void __cdecl fn_00557330(void*, void*);
// INFERRED: these two return descriptors (0059c430 first, 0059c7f0 second)
extern "C" Word __cdecl fn_0059c430();
extern "C" Word __cdecl fn_0059c7f0();
// operator delete
extern "C" void __cdecl fn_006a067a(void*);

struct Owner
{
    void* p;

    Owner(Owner&);
    ~Owner();
};

__forceinline Owner::Owner(Owner& other)
{
    void* value = other.p;
    other.p = 0;
    p = value;
}

__forceinline Owner::~Owner()
{
    if (p)
        fn_006a067a(p);
}

// INFERRED: struct return via hidden pointer, caller-cleaned stack args
extern "C" Owner __cdecl fn_0059a5e0(Triple, Triple);

struct Base
{
    Word table;
    Word data[5];
    Word descriptor;

    Base(Word, Word, Word);
    // INFERRED: real thiscall member (0056c650, PropertyDescriptor ctor)
    void initialize(Word, Word, Word, Word, Word);
    ~Base();
};

__forceinline Base::Base(Word name, Word attributes, Word flags)
{
    fn_00557330(reinterpret_cast<void*>(((int)&g_0059c490)),
                reinterpret_cast<void*>(((int)&g_0097648c)));
    Word classDescriptor = fn_0059c430();
    Word typeDescriptor = fn_0059c7f0();
    initialize(typeDescriptor, classDescriptor, name, attributes, flags);
    descriptor = classDescriptor;
}

struct Local_0059d130 : Base
{
    Owner binding;
    Word finalDescriptor;

    Local_0059d130(Word, Word, Triple, Triple, Word);
};

Local_0059d130::Local_0059d130(Word name, Word attributes, Triple first, Triple second, Word flags)
    : Base(name, attributes, flags),
      binding((table = ((int)&g_00832f74), fn_0059a5e0(first, second)))
{
    fn_00557330(reinterpret_cast<void*>(((int)&g_0059c490)),
                reinterpret_cast<void*>(((int)&g_0097648c)));
    finalDescriptor = fn_0059c430();
}

extern "C" Local_0059d130* __fastcall fn_0059d130(Local_0059d130* self, int unusedEdx,
                                                  Word name, Word attributes,
                                                  Word f0, Word f1, Word f2,
                                                  Word s0, Word s1, Word s2,
                                                  Word flags)
{
    Triple first = { f0, f1, f2 };
    Triple second = { s0, s1, s2 };
    return new (self) Local_0059d130(name, attributes, first, second, flags);
}
