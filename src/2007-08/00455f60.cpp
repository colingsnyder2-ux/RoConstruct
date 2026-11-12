// from server: 100% by EspClaude
// from server: 40% by 41k
// roc 2007-08 00455f60  unit: InsertModelFromRobloxVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00455f60
//
// 00455f60  6aff                 push -1
// 00455f62  68c8197400           push 0x7419c8
// 00455f67  64a100000000         mov eax, dword ptr fs:[0]
// 00455f6d  50                   push eax
// 00455f6e  83ec08               sub esp, 8
// 00455f71  56                   push esi
// 00455f72  a188518b00           mov eax, dword ptr [0x8b5188]
// 00455f77  33c4                 xor eax, esp
// 00455f79  50                   push eax
// 00455f7a  8d442410             lea eax, [esp + 0x10]
// 00455f7e  64a300000000         mov dword ptr fs:[0], eax
// 00455f84  8bf1                 mov esi, ecx
// 00455f86  89742408             mov dword ptr [esp + 8], esi
// 00455f8a  83ec1c               sub esp, 0x1c
// 00455f8d  8bcc                 mov ecx, esp
// 00455f8f  89642428             mov dword ptr [esp + 0x28], esp
// 00455f93  68182b7900           push 0x792b18
// 00455f98  ff1598e67700         call dword ptr [0x77e698]
// 00455f9e  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00455fa2  50                   push eax
// 00455fa3  8bce                 mov ecx, esi
// 00455fa5  e8a6ec1000           call 0x564c50
// 00455faa  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00455fb2  c706042b7900         mov dword ptr [esi], 0x792b04
// 00455fb8  e8339f0a00           call 0x4ffef0
// 00455fbd  dd5e10               fstp qword ptr [esi + 0x10]
// 00455fc0  8bc6                 mov eax, esi
// 00455fc2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00455fc6  64890d00000000       mov dword ptr fs:[0], ecx
// 00455fcd  59                   pop ecx
// 00455fce  5e                   pop esi
// 00455fcf  83c414               add esp, 0x14
// 00455fd2  c20400               ret 4

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
struct Verb {
    virtual ~Verb();
    virtual void execute();
    unsigned int data[2];
    Verb(void *, std::string);
};
double getTime();   // 0x4ffef0, returns on the x87 stack
struct TogglePlayModeVerb : Verb {
    double lastTime;   // +0x10
    virtual void execute();
    TogglePlayModeVerb(void* container);
};
TogglePlayModeVerb::TogglePlayModeVerb(void* container)
    : Verb(container, std::string("TogglePlayMode"))
{
    lastTime = getTime();
}
