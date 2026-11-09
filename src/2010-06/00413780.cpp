// from server: 100% by Yeetserama
// roc 2010-06 00413780  unit: CutVerb  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413780
//
// 00413780  51                   push ecx
// 00413781  56                   push esi
// 00413782  57                   push edi
// 00413783  83ec1c               sub esp, 0x1c
// 00413786  8bf1                 mov esi, ecx
// 00413788  8bcc                 mov ecx, esp
// 0041378a  89642424             mov dword ptr [esp + 0x24], esp
// 0041378e  68082fa000           push 0xa02f08
// 00413793  ff1510a49e00         call dword ptr [0x9ea410]
// 00413799  8b4e08               mov ecx, dword ptr [esi + 8]
// 0041379c  e81f351d00           call 0x5e6cc0
// 004137a1  8b10                 mov edx, dword ptr [eax]
// 004137a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004137a7  8bc8                 mov ecx, eax
// 004137a9  8b4210               mov eax, dword ptr [edx + 0x10]
// 004137ac  57                   push edi
// 004137ad  ffd0                 call eax
// 004137af  57                   push edi
// 004137b0  8bce                 mov ecx, esi
// 004137b2  e8390c1d00           call 0x5e43f0
// 004137b7  5f                   pop edi
// 004137b8  5e                   pop esi
// 004137b9  59                   pop ecx
// 004137ba  c20400               ret 4
// copied from an identical function in another client (function ?execute@CutVerb@ns_ROCX000010@@QAEXH@Z)

namespace ns_ROCX000010 {
// from server: 100% by colin
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
