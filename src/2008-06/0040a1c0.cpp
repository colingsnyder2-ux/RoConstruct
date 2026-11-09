// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_1747c59ef36cda34.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<xstring>, <roc_unit_3da8e64d105bf835.cpp>)
#include <string>
#include <exception>
struct StandardOut {
    void print(int, const char *, ...);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();


// from server: 100% by colin
// roc 2008-06 0040a1c0  unit: VAuthoringSettings::?$FactoryProduct  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040a1c0
//
// 0040a1c0  55                   push ebp
// 0040a1c1  8bec                 mov ebp, esp
// 0040a1c3  6aff                 push -1
// 0040a1c5  6821d17b00           push 0x7bd121
// 0040a1ca  64a100000000         mov eax, dword ptr fs:[0]
// 0040a1d0  50                   push eax
// 0040a1d1  64892500000000       mov dword ptr fs:[0], esp
// 0040a1d8  83ec30               sub esp, 0x30
// 0040a1db  53                   push ebx
// 0040a1dc  56                   push esi
// 0040a1dd  33d2                 xor edx, edx
// 0040a1df  57                   push edi
// 0040a1e0  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040a1e3  8955fc               mov dword ptr [ebp - 4], edx
// 0040a1e6  3bca                 cmp ecx, edx
// 0040a1e8  7406                 je 0x40a1f0
// 0040a1ea  8d913cffffff         lea edx, [ecx - 0xc4]
// 0040a1f0  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0040a1f3  8b7508               mov esi, dword ptr [ebp + 8]
// 0040a1f6  83ec08               sub esp, 8
// 0040a1f9  8bc4                 mov eax, esp
// 0040a1fb  894804               mov dword ptr [eax + 4], ecx
// 0040a1fe  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0040a201  8930                 mov dword ptr [eax], esi
// 0040a203  8b01                 mov eax, dword ptr [ecx]
// 0040a205  8965ec               mov dword ptr [ebp - 0x14], esp
// 0040a208  52                   push edx
// 0040a209  8b10                 mov edx, dword ptr [eax]
// 0040a20b  ffd2                 call edx

// from server: 93% by king_originala
struct Arguments {
    unsigned int second;
    unsigned int first;

    Arguments(const Arguments& other);
};

inline Arguments::Arguments(const Arguments& other)
{
    unsigned int b = other.second;
    unsigned int a = other.first;
    second = b;
    first = a;
}

struct Callback {
    virtual void invoke(void* object, Arguments arguments) = 0;
};

struct S {
    void f(Arguments arguments, Callback* callback);
};

void S::f(Arguments arguments, Callback* callback)
{
    try {
        void* object = 0;
        if (this)
            object = reinterpret_cast<char*>(this) - 0xC4;
        callback->invoke(object, arguments);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
