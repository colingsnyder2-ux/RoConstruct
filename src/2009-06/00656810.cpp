// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c8f20  unit: RBX::LaserTool  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c8f20
//
// 005c8f20  6aff                 push -1
// 005c8f22  6809e77c00           push 0x7ce709
// 005c8f27  64a100000000         mov eax, dword ptr fs:[0]
// 005c8f2d  50                   push eax
// 005c8f2e  64892500000000       mov dword ptr fs:[0], esp
// 005c8f35  83ec1c               sub esp, 0x1c
// 005c8f38  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005c8f3c  8d44243c             lea eax, [esp + 0x3c]
// 005c8f40  50                   push eax
// 005c8f41  51                   push ecx
// 005c8f42  8d542408             lea edx, [esp + 8]
// 005c8f46  52                   push edx
// 005c8f47  e8a40af4ff           call 0x5099f0
// 005c8f4c  83c40c               add esp, 0xc
// 005c8f4f  dd442430             fld qword ptr [esp + 0x30]
// 005c8f53  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005c8f57  dd9930010000         fstp qword ptr [ecx + 0x130]
// 005c8f5d  50                   push eax
// 005c8f5e  81c138010000         add ecx, 0x138
// 005c8f64  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005c8f6c  ff150c248000         call dword ptr [0x80240c]
// 005c8f72  8d0c24               lea ecx, [esp]
// 005c8f75  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005c8f7d  ff1568248000         call dword ptr [0x802468]
// 005c8f83  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c8f87  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8f8e  83c428               add esp, 0x28
// 005c8f91  c3                   ret 

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
        basic_string& operator=(const basic_string&);
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *destroyString)(String*);
extern String& (__thiscall *assignString)(String*, const String&);

namespace std {
    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::~basic_string()
    {
        destroyString(this);
    }

    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>&
    basic_string<T, Traits, Allocator>::operator=(const basic_string& other)
    {
        return assignString(this, other);
    }
}

struct S {
    char reserved[0x90];
    double value;
    String text;
};

String __cdecl formatText(const char*, char*);

static __forceinline void setText(S* object, double value,
                                 const String& text)
{
    object->value = value;
    object->text = text;
}

void __cdecl f(S* object, double value, const char* format, ...)
{
    setText(object, value, formatText(format, (char*)(&format + 1)));
}
