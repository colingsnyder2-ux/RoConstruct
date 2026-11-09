// from server: 100% by EspClaude
// roc 2009-06 00413a40  unit: CutVerb  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413a40
//
// 00413a40  51                   push ecx
// 00413a41  56                   push esi
// 00413a42  57                   push edi
// 00413a43  83ec1c               sub esp, 0x1c
// 00413a46  8bf1                 mov esi, ecx
// 00413a48  8bcc                 mov ecx, esp
// 00413a4a  89642424             mov dword ptr [esp + 0x24], esp
// 00413a4e  68c8f68a00           push 0x8af6c8
// 00413a53  ff15b4e48900         call dword ptr [0x89e4b4]
// 00413a59  8b4e08               mov ecx, dword ptr [esi + 8]
// 00413a5c  e8ffce1f00           call 0x610960
// 00413a61  8b10                 mov edx, dword ptr [eax]
// 00413a63  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00413a67  8bc8                 mov ecx, eax
// 00413a69  8b4210               mov eax, dword ptr [edx + 0x10]
// 00413a6c  57                   push edi
// 00413a6d  ffd0                 call eax
// 00413a6f  57                   push edi
// 00413a70  8bce                 mov ecx, esi
// 00413a72  e8b9a71f00           call 0x60e230
// 00413a77  5f                   pop edi
// 00413a78  5e                   pop esi
// 00413a79  59                   pop ecx
// 00413a7a  c20400               ret 4
// copied from an identical function in another client (function ?execute@CutVerb@ns_ROCX000012@@QAEXH@Z)

namespace ns_ROCX000012 {
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
struct Action {
    void (__thiscall **table)(Action*, int);
};
struct Context {
    Action* find(std::string);
};
struct CutVerb {
    char padding[8];
    Context* context;
    void execute(int);
    void finish(int);
};
void CutVerb::execute(int argument) {
    Action* action = context->find(std::string("Copy"));
    action->table[4](action, argument);
    finish(argument);
}
}
