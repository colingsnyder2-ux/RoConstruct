// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0048c3e0  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048c3e0
//
// 0048c3e0  64a100000000         mov eax, dword ptr fs:[0]
// 0048c3e6  6aff                 push -1
// 0048c3e8  68b9fe7c00           push 0x7cfeb9
// 0048c3ed  50                   push eax
// 0048c3ee  64892500000000       mov dword ptr fs:[0], esp
// 0048c3f5  83ec44               sub esp, 0x44
// 0048c3f8  56                   push esi
// 0048c3f9  8bf1                 mov esi, ecx
// 0048c3fb  6a01                 push 1
// 0048c3fd  56                   push esi
// 0048c3fe  e8ad9a0000           call 0x495eb0
// 0048c403  83c408               add esp, 8
// 0048c406  84c0                 test al, al
// 0048c408  7534                 jne 0x48c43e
// 0048c40a  68d0168200           push 0x8216d0
// 0048c40f  8d4c2408             lea ecx, [esp + 8]
// 0048c413  ff1558248000         call dword ptr [0x802458]
// 0048c419  8d442404             lea eax, [esp + 4]
// 0048c41d  50                   push eax
// 0048c41e  8d4c2424             lea ecx, [esp + 0x24]
// 0048c422  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0048c42a  e821d9f7ff           call 0x409d50
// 0048c42f  68c81b8d00           push 0x8d1bc8
// 0048c434  8d4c2424             lea ecx, [esp + 0x24]
// 0048c438  51                   push ecx
// 0048c439  e84e512100           call 0x6a158c
// 0048c43e  8b8e70010000         mov ecx, dword ptr [esi + 0x170]
// 0048c444  85c9                 test ecx, ecx
// 0048c446  740a                 je 0x48c452
// 0048c448  68b0994800           push 0x4899b0
// 0048c44d  e81e00fdff           call 0x45c470
// 0048c452  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0048c456  5e                   pop esi
// 0048c457  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c45e  83c450               add esp, 0x50
// 0048c461  c3                   ret 

extern void (__thiscall *constructString)(void*, const char*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string
    {
        unsigned int allocatorState;
        union
        {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception
    {
        char* message;
        bool ownsMessage;

    public:
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception
    {
        string message;

    public:
        explicit runtime_error(const string&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct Appearance
{
    void remove(void (__cdecl*)());
};

struct Object
{
    unsigned char padding[0x170];
    Appearance* appearance;

    void removeCharacterAppearance();
};

extern bool __cdecl checkBackend(int, int);
extern void __cdecl removeAppearance();

void Object::removeCharacterAppearance()
{
    if (!checkBackend(reinterpret_cast<int>(this), 1))
    {
        std::string text(
            "RemoveCharacterAppearance can only be called by the backend server");
        throw std::runtime_error(text);
    }

    if (appearance)
        appearance->remove(removeAppearance);
}
