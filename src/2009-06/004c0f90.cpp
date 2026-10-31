// from server: 100% by EspClaude
// roc 2009-06 004c0f90  unit: RBX::Network::Player  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c0f90
//
// 004c0f90  64a100000000         mov eax, dword ptr fs:[0]
// 004c0f96  6aff                 push -1
// 004c0f98  6849b88500           push 0x85b849
// 004c0f9d  50                   push eax
// 004c0f9e  64892500000000       mov dword ptr fs:[0], esp
// 004c0fa5  83ec44               sub esp, 0x44
// 004c0fa8  56                   push esi
// 004c0fa9  8bf1                 mov esi, ecx
// 004c0fab  6a01                 push 1
// 004c0fad  56                   push esi
// 004c0fae  e8cd2f0000           call 0x4c3f80
// 004c0fb3  83c408               add esp, 8
// 004c0fb6  84c0                 test al, al
// 004c0fb8  7534                 jne 0x4c0fee
// 004c0fba  688c4a8c00           push 0x8c4a8c
// 004c0fbf  8d4c2408             lea ecx, [esp + 8]
// 004c0fc3  ff15b4e48900         call dword ptr [0x89e4b4]
// 004c0fc9  8d442404             lea eax, [esp + 4]
// 004c0fcd  50                   push eax
// 004c0fce  8d4c2424             lea ecx, [esp + 0x24]
// 004c0fd2  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004c0fda  e83184f4ff           call 0x409410
// 004c0fdf  6850a79700           push 0x97a750
// 004c0fe4  8d4c2424             lea ecx, [esp + 0x24]
// 004c0fe8  51                   push ecx
// 004c0fe9  e85c8a2500           call 0x719a4a
// 004c0fee  6a00                 push 0
// 004c0ff0  8bce                 mov ecx, esi
// 004c0ff2  e8e9fbffff           call 0x4c0be0
// 004c0ff7  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004c0ffb  5e                   pop esi
// 004c0ffc  64890d00000000       mov dword ptr fs:[0], ecx
// 004c1003  83c450               add esp, 0x50
// 004c1006  c3                   ret 
// copied from an identical function in another client (function ?removeCharacter@Player@ns_ROCX000017@@QAEXXZ)

namespace ns_ROCX000017 {
extern void (__thiscall *stringConstruct)(void*, const char*);

namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class T, class Traits, class Alloc>
class basic_string {
    unsigned char allocator_storage[4];
    union {
        T buffer[16];
        T* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
public:
    basic_string(const T*);
    basic_string(const basic_string&);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
inline basic_string<T, Traits, Alloc>::basic_string(const T* s)
{
    stringConstruct(this, s);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;

class exception {
    const char* message;
    bool owns_message;
public:
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;
};

class runtime_error : public exception {
    string text;
public:
    runtime_error(const string&);
    runtime_error(const runtime_error&);
    virtual ~runtime_error();
};
}

struct Player {
    void removeCharacter();
    void setCharacter(int);
};

extern bool __cdecl checkBackend(Player*, int);

void Player::removeCharacter()
{
    if (!checkBackend(this, 1))
        throw std::runtime_error(
            std::string("RemoveCharacter can only be called by the backend server"));
    setCharacter(0);
}
}
