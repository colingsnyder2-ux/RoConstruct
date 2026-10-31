// from server: 91% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bcd80  unit: SoundServiceStatsItem  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bcd80
//
// 005bcd80  64a100000000         mov eax, dword ptr fs:[0]
// 005bcd86  6aff                 push -1
// 005bcd88  6809e77c00           push 0x7ce709
// 005bcd8d  50                   push eax
// 005bcd8e  64892500000000       mov dword ptr fs:[0], esp
// 005bcd95  83ec24               sub esp, 0x24
// 005bcd98  56                   push esi
// 005bcd99  8bf1                 mov esi, ecx
// 005bcd9b  8b8658010000         mov eax, dword ptr [esi + 0x158]
// 005bcda1  83b83401000000       cmp dword ptr [eax + 0x134], 0
// 005bcda8  0f84a5000000         je 0x5bce53
// 005bcdae  8b8038010000         mov eax, dword ptr [eax + 0x138]
// 005bcdb4  50                   push eax
// 005bcdb5  8944240c             mov dword ptr [esp + 0xc], eax
// 005bcdb9  db44240c             fild dword ptr [esp + 0xc]
// 005bcdbd  68a4808300           push 0x8380a4
// 005bcdc2  85c0                 test eax, eax
// 005bcdc4  7d06                 jge 0x5bcdcc
// 005bcdc6  dc0540128100         fadd qword ptr [0x811240]
// 005bcdcc  83ec08               sub esp, 8
// 005bcdcf  dd1c24               fstp qword ptr [esp]
// 005bcdd2  56                   push esi
// 005bcdd3  e848c10000           call 0x5c8f20
// 005bcdd8  83c414               add esp, 0x14
// 005bcddb  8d442408             lea eax, [esp + 8]
// 005bcddf  50                   push eax
// 005bcde0  8d4c2408             lea ecx, [esp + 8]
// 005bcde4  51                   push ecx
// 005bcde5  e8702e0e00           call 0x69fc5a
// 005bcdea  85c0                 test eax, eax
// 005bcdec  7514                 jne 0x5bce02
// 005bcdee  8b542404             mov edx, dword ptr [esp + 4]
// 005bcdf2  8b442408             mov eax, dword ptr [esp + 8]
// 005bcdf6  89965c010000         mov dword ptr [esi + 0x15c], edx
// 005bcdfc  898660010000         mov dword ptr [esi + 0x160], eax
// 005bce02  53                   push ebx
// 005bce03  57                   push edi
// 005bce04  8dbe68010000         lea edi, [esi + 0x168]
// 005bce0a  8d9e64010000         lea ebx, [esi + 0x164]
// 005bce10  8bb658010000         mov esi, dword ptr [esi + 0x158]
// 005bce16  57                   push edi
// 005bce17  8d8e80010000         lea ecx, [esi + 0x180]
// 005bce1d  53                   push ebx
// 005bce1e  c70700000000         mov dword ptr [edi], 0
// 005bce24  51                   push ecx
// 005bce25  c70300000000         mov dword ptr [ebx], 0
// 005bce2b  e8a0b5ffff           call 0x5b83d0
// 005bce30  57                   push edi
// 005bce31  53                   push ebx
// 005bce32  81c6a0010000         add esi, 0x1a0
// 005bce38  56                   push esi
// 005bce39  e892b5ffff           call 0x5b83d0
// 005bce3e  83c418               add esp, 0x18
// 005bce41  5f                   pop edi
// 005bce42  5b                   pop ebx
// 005bce43  5e                   pop esi
// 005bce44  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005bce48  64890d00000000       mov dword ptr fs:[0], ecx
// 005bce4f  83c430               add esp, 0x30
// 005bce52  c3                   ret 
// 005bce53  6898808300           push 0x838098
// 005bce58  8d4c2410             lea ecx, [esp + 0x10]
// 005bce5c  ff1558248000         call dword ptr [0x802458]
// 005bce62  d9ee                 fldz 
// 005bce64  8d54240c             lea edx, [esp + 0xc]
// 005bce68  dd9e30010000         fstp qword ptr [esi + 0x130]
// 005bce6e  52                   push edx
// 005bce6f  8d8e38010000         lea ecx, [esi + 0x138]
// 005bce75  c744243400000000     mov dword ptr [esp + 0x34], 0
// 005bce7d  ff150c248000         call dword ptr [0x80240c]
// 005bce83  8d4c240c             lea ecx, [esp + 0xc]
// 005bce87  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 005bce8f  ff1568248000         call dword ptr [0x802468]
// 005bce95  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005bce99  5e                   pop esi
// 005bce9a  64890d00000000       mov dword ptr fs:[0], ecx
// 005bcea1  83c430               add esp, 0x30
// 005bcea4  c3                   ret 

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Allocator>
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
    basic_string& operator=(const basic_string&);
};
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>::basic_string(const T* s)
{
    stringConstruct(this, s);
}

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>::~basic_string()
{
    stringDestroy(this);
}

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>&
std::basic_string<T, Traits, Allocator>::operator=(const basic_string& s)
{
    return stringAssign(this, s);
}

struct Service {
    char padding[0x134];
    int enabled;
    unsigned int handle;
    char padding2[0x44];
    char collection1[0x20];
    char collection2[0x20];
};

struct SoundServiceStatsItem {
    char padding[0x130];
    double value;
    String text;
    char padding2[4];
    Service* service;
    int measurement1;
    int measurement2;
    unsigned int count1;
    unsigned int count2;

    void update();
};

extern void __cdecl setFormattedValue(
    SoundServiceStatsItem*, double, const char*, ...);
extern int __stdcall queryMeasurements(int*, int*);
extern void __cdecl accumulateCounts(
    void*, unsigned int*, unsigned int*);

void SoundServiceStatsItem::update()
{
    if (service->enabled) {
        unsigned int handle = service->handle;
        setFormattedValue(this, double(handle), "fmod %08x", handle);

        int first;
        int second;
        if (queryMeasurements(&first, &second) == 0) {
            measurement1 = first;
            measurement2 = second;
        }

        unsigned int* secondCount = &count2;
        unsigned int* firstCount = &count1;
        Service* current = service;
        *secondCount = 0;
        *firstCount = 0;
        accumulateCounts(current->collection1, firstCount, secondCount);
        accumulateCounts(current->collection2, firstCount, secondCount);
    } else {
        String disabled("-disabled-");
        value = 0.0;
        text = disabled;
    }
}
