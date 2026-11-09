// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00554290  unit: RBX::RenderBase::AggregateChunk  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00554290
//
// 00554290  64a100000000         mov eax, dword ptr fs:[0]
// 00554296  6aff                 push -1
// 00554298  6809e77c00           push 0x7ce709
// 0055429d  50                   push eax
// 0055429e  8b442410             mov eax, dword ptr [esp + 0x10]
// 005542a2  64892500000000       mov dword ptr fs:[0], esp
// 005542a9  83ec1c               sub esp, 0x1c
// 005542ac  85c0                 test eax, eax
// 005542ae  7526                 jne 0x5542d6
// 005542b0  682c3a9700           push 0x973a2c
// 005542b5  6860415500           push 0x554160
// 005542ba  e871300000           call 0x557330
// 005542bf  a1d0399700           mov eax, dword ptr [0x9739d0]
// 005542c4  83c408               add esp, 8
// 005542c7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005542cb  64890d00000000       mov dword ptr fs:[0], ecx
// 005542d2  83c428               add esp, 0x28
// 005542d5  c3                   ret 
// 005542d6  56                   push esi
// 005542d7  50                   push eax
// 005542d8  8d4c2408             lea ecx, [esp + 8]
// 005542dc  ff1558248000         call dword ptr [0x802458]
// 005542e2  50                   push eax
// 005542e3  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005542eb  e890feffff           call 0x554180
// 005542f0  83c404               add esp, 4
// 005542f3  8d4c2404             lea ecx, [esp + 4]
// 005542f7  8bf0                 mov esi, eax
// 005542f9  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00554301  ff1568248000         call dword ptr [0x802468]
// 00554307  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055430b  8bc6                 mov eax, esi
// 0055430d  5e                   pop esi
// 0055430e  64890d00000000       mov dword ptr fs:[0], ecx
// 00554315  83c428               add esp, 0x28
// 00554318  c3                   ret 

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        __declspec(dllimport) basic_string(const T*);
        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern int defaultValue;
extern int initializationState;

void __cdecl initializeDefault();
void __cdecl ensureInitialized(void (__cdecl*)(), int*);
int __cdecl findValue(const String&);

int __cdecl lookupValue(const char* text)
{
    if (!text) {
        ensureInitialized(initializeDefault, &initializationState);
        return defaultValue;
    }

    return findValue(String(text));
}