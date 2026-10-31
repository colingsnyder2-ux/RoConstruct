// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0046f110  unit: RBX::LDraw2Lua::LDrawCommand  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046f110
//
// 0046f110  6aff                 push -1
// 0046f112  68a73f7c00           push 0x7c3fa7
// 0046f117  64a100000000         mov eax, dword ptr fs:[0]
// 0046f11d  50                   push eax
// 0046f11e  64892500000000       mov dword ptr fs:[0], esp
// 0046f125  83ec08               sub esp, 8
// 0046f128  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046f12c  56                   push esi
// 0046f12d  57                   push edi
// 0046f12e  8bf9                 mov edi, ecx
// 0046f130  50                   push eax
// 0046f131  8d4f04               lea ecx, [edi + 4]
// 0046f134  897c240c             mov dword ptr [esp + 0xc], edi
// 0046f138  c70774cb8100         mov dword ptr [edi], 0x81cb74
// 0046f13e  ff1558248000         call dword ptr [0x802458]
// 0046f144  833d60ee960000       cmp dword ptr [0x96ee60], 0
// 0046f14b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046f153  755e                 jne 0x46f1b3
// 0046f155  6a7c                 push 0x7c
// 0046f157  e8c4172300           call 0x6a0920
// 0046f15c  8bf0                 mov esi, eax
// 0046f15e  83c404               add esp, 4
// 0046f161  89742420             mov dword ptr [esp + 0x20], esi
// 0046f165  c644241801           mov byte ptr [esp + 0x18], 1
// 0046f16a  85f6                 test esi, esi
// 0046f16c  7422                 je 0x46f190
// 0046f16e  83ec1c               sub esp, 0x1c
// 0046f171  8bcc                 mov ecx, esp
// 0046f173  89642428             mov dword ptr [esp + 0x28], esp
// 0046f177  6878cb8100           push 0x81cb78
// 0046f17c  51                   push ecx
// 0046f17d  e82edf0e00           call 0x55d0b0
// 0046f182  83c408               add esp, 8
// 0046f185  8bce                 mov ecx, esi
// 0046f187  e884e5ffff           call 0x46d710
// 0046f18c  8bf0                 mov esi, eax
// 0046f18e  eb02                 jmp 0x46f192
// 0046f190  33f6                 xor esi, esi
// 0046f192  8b0d60ee9600         mov ecx, dword ptr [0x96ee60]
// 0046f198  c644241800           mov byte ptr [esp + 0x18], 0
// 0046f19d  3bf1                 cmp esi, ecx
// 0046f19f  740c                 je 0x46f1ad
// 0046f1a1  85c9                 test ecx, ecx
// 0046f1a3  7408                 je 0x46f1ad
// 0046f1a5  8b11                 mov edx, dword ptr [ecx]
// 0046f1a7  8b02                 mov eax, dword ptr [edx]
// 0046f1a9  6a01                 push 1
// 0046f1ab  ffd0                 call eax
// 0046f1ad  893560ee9600         mov dword ptr [0x96ee60], esi
// 0046f1b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046f1b7  8bc7                 mov eax, edi
// 0046f1b9  5f                   pop edi
// 0046f1ba  64890d00000000       mov dword ptr fs:[0], ecx
// 0046f1c1  5e                   pop esi
// 0046f1c2  83c414               add esp, 0x14
// 0046f1c5  c20400               ret 4

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string();
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
typedef unsigned int size_t;




extern std::string __cdecl makeString(const char *);
void *__cdecl operator new(size_t);
void __cdecl operator delete(void *);

struct Resource
{
    virtual ~Resource();
    char storage[120];
    Resource(std::string);
};

extern Resource *current;

struct Command
{
    void *table;
    std::string text;
    Command(const char *);
};

Command::Command(const char *value)
    : table((void *)0x81cb74), text(value)
{
    if (!current)
    {
        Resource *replacement =
            new Resource(makeString((const char *)0x81cb78));
        if (replacement != current && current)
            delete current;
        current = replacement;
    }
}
