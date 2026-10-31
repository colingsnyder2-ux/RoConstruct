// from server: 91% by EspClaude
// from server: 100% by colin
// roc 2008-06 005833e0  unit: RBX::CameraZoomExtentsCommand  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005833e0
//
// 005833e0  64a100000000         mov eax, dword ptr fs:[0]
// 005833e6  6aff                 push -1
// 005833e8  68793f7c00           push 0x7c3f79
// 005833ed  50                   push eax
// 005833ee  64892500000000       mov dword ptr fs:[0], esp
// 005833f5  56                   push esi
// 005833f6  8bf1                 mov esi, ecx
// 005833f8  837c243010           cmp dword ptr [esp + 0x30], 0x10
// 005833fd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00583401  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00583409  7304                 jae 0x58340f
// 0058340b  8d44241c             lea eax, [esp + 0x1c]
// 0058340f  6aff                 push -1
// 00583411  50                   push eax
// 00583412  e8790bfdff           call 0x553f90
// 00583417  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058341b  894604               mov dword ptr [esi + 4], eax
// 0058341e  8944241c             mov dword ptr [esp + 0x1c], eax
// 00583422  83c408               add esp, 8
// 00583425  8d442414             lea eax, [esp + 0x14]
// 00583429  894e08               mov dword ptr [esi + 8], ecx
// 0058342c  50                   push eax
// 0058342d  83c104               add ecx, 4
// 00583430  e86b10feff           call 0x5644a0
// 00583435  8d4c2418             lea ecx, [esp + 0x18]
// 00583439  8930                 mov dword ptr [eax], esi
// 0058343b  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00583443  ff1568248000         call dword ptr [0x802468]
// 00583449  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058344d  8bc6                 mov eax, esi
// 0058344f  64890d00000000       mov dword ptr fs:[0], ecx
// 00583456  5e                   pop esi
// 00583457  83c40c               add esp, 0xc
// 0058345a  c22000               ret 0x20

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
    public:
        unsigned char allocator_storage;
        union {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned length;
        unsigned capacity;

        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Command;
struct Owner;

struct CommandMap {
    Command** lookup(Owner* const& key);
};

struct Owner {
    unsigned reserved;
    CommandMap commands;
};

extern "C" void* __cdecl intern_name(const char* name, int length);

struct Command {
    unsigned reserved;
    void* name;
    Owner* owner;

    Command(Owner* source, String text);
};

Command::Command(Owner* source, String text)
{
    const char* characters = text.storage.pointer;
    if (text.capacity < 16)
        characters = text.storage.buffer;

    void* interned = intern_name(characters, -1);
    name = interned;
    owner = source;
    *owner->commands.lookup((Owner*)interned) = this;
}
