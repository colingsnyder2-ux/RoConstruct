// roc 2012-06 0075b760  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0075b760
//
// 0075b760  8b442404             mov eax, dword ptr [esp + 4]
// 0075b764  56                   push esi
// 0075b765  8b30                 mov esi, dword ptr [eax]
// 0075b767  83ec1c               sub esp, 0x1c
// 0075b76a  8d560c               lea edx, [esi + 0xc]
// 0075b76d  8bcc                 mov ecx, esp
// 0075b76f  89642424             mov dword ptr [esp + 0x24], esp
// 0075b773  52                   push edx
// 0075b774  ff154426b200         call dword ptr [0xb22644]
// 0075b77a  8b4604               mov eax, dword ptr [esi + 4]
// 0075b77d  83ec08               sub esp, 8
// 0075b780  8bcc                 mov ecx, esp
// 0075b782  8901                 mov dword ptr [ecx], eax
// 0075b784  8b4608               mov eax, dword ptr [esi + 8]
// 0075b787  8964242c             mov dword ptr [esp + 0x2c], esp
// 0075b78b  894104               mov dword ptr [ecx + 4], eax
// 0075b78e  85c0                 test eax, eax
// 0075b790  740c                 je 0x75b79e
// 0075b792  83c004               add eax, 4
// 0075b795  b901000000           mov ecx, 1
// 0075b79a  f00fc108             lock xadd dword ptr [eax], ecx
// 0075b79e  8b16                 mov edx, dword ptr [esi]
// 0075b7a0  ffd2                 call edx
// 0075b7a2  83c424               add esp, 0x24
// 0075b7a5  5e                   pop esi
// 0075b7a6  c3                   ret 
// copied from an identical function in another client (function ?invoke@@YAXPAPAUEntry@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

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
typedef std::string String;

struct Control
{
    long reserved;
    volatile long references;
};

struct Shared
{
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Entry
{
    void (__cdecl *callback)(Shared, String);
    Shared value;
    String text;
};

void __cdecl invoke(Entry** argument)
{
    Entry* entry = *argument;
    entry->callback(entry->value, entry->text);
}