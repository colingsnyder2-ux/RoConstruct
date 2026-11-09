// from server: 49% by king_originala
// roc 2008-06 004da34d  unit: RBX::ViewNew::ViewRbxGfx  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004da34d
//
// 004da34d  a168248000           mov eax, dword ptr [0x802468]
// 004da352  8b0d60248000         mov ecx, dword ptr [0x802460]
// 004da358  50                   push eax
// 004da359  51                   push ecx
// 004da35a  6a06                 push 6
// 004da35c  6a1c                 push 0x1c
// 004da35e  8d95d4fcffff         lea edx, [ebp - 0x32c]
// 004da364  52                   push edx
// 004da365  e82e721c00           call 0x6a1598
// 004da36a  8d8de8feffff         lea ecx, [ebp - 0x118]
// 004da370  c645fc27             mov byte ptr [ebp - 4], 0x27
// 004da374  ff1560248000         call dword ptr [0x802460]
// 004da37a  8d8d7cfdffff         lea ecx, [ebp - 0x284]
// 004da380  c645fc28             mov byte ptr [ebp - 4], 0x28
// 004da384  ff1560248000         call dword ptr [0x802460]
// 004da38a  8d857cfdffff         lea eax, [ebp - 0x284]
// 004da390  50                   push eax
// 004da391  8d8de8feffff         lea ecx, [ebp - 0x118]
// 004da397  51                   push ecx
// 004da398  8d9540feffff         lea edx, [ebp - 0x1c0]
// 004da39e  52                   push edx
// 004da39f  c645fc29             mov byte ptr [ebp - 4], 0x29
// 004da3a3  ff15584e8000         call dword ptr [0x804e58]
// 004da3a9  83c40c               add esp, 0xc
// 004da3ac  6a01                 push 1
// 004da3ae  6a00                 push 0
// 004da3b0  688cca8100           push 0x81ca8c
// 004da3b5  8d8de8feffff         lea ecx, [ebp - 0x118]
// 004da3bb  ff1598248000         call dword ptr [0x802498]
// 004da3c1  8b0de8238000         mov ecx, dword ptr [0x8023e8]
// 004da3c7  3b01                 cmp eax, dword ptr [ecx]
// 004da3c9  0f8557020000         jne 0x4da626
// 004da3cf  8d9540feffff         lea edx, [ebp - 0x1c0]
// 004da3d5  52                   push edx
// 004da3d6  e8d5490300           call 0x50edb0
// 004da3db  83c404               add esp, 4
// 004da3de  8d4d54               lea ecx, [ebp + 0x54]
// 004da3e1  8bf0                 mov esi, eax
// 004da3e3  ff1560248000         call dword ptr [0x802460]
// 004da3e9  c645fc2a             mov byte ptr [ebp - 4], 0x2a
// 004da3ed  85f6                 test esi, esi
// 004da3ef  0f8c87010000         jl 0x4da57c
// 004da3f5  83fe08               cmp esi, 8
// 004da3f8  0f837e010000         jae 0x4da57c
// 004da3fe  688cca8100           push 0x81ca8c
// 004da403  8d4d2c               lea ecx, [ebp + 0x2c]
// 004da406  ff1558248000         call dword ptr [0x802458]
// 004da40c  8b0cb518079400       mov ecx, dword ptr [esi*4 + 0x940718]
// 004da413  51                   push ecx
// 004da414  50                   push eax
// 004da415  8d9510ffffff         lea edx, [ebp - 0xf0]
// 004da41b  b32b                 mov bl, 0x2b
// 004da41d  52                   push edx
// 004da41e  885dfc               mov byte ptr [ebp - 4], bl
// 004da421  ff15e4238000         call dword ptr [0x8023e4]
// 004da427  83c40c               add esp, 0xc
// 004da42a  50                   push eax
// 004da42b  8d4d54               lea ecx, [ebp + 0x54]
// 004da42e  c645fc2c             mov byte ptr [ebp - 4], 0x2c
// 004da432  ff150c248000         call dword ptr [0x80240c]
// 004da438  8d8d10ffffff         lea ecx, [ebp - 0xf0]
// 004da43e  885dfc               mov byte ptr [ebp - 4], bl
// 004da441  ff1568248000         call dword ptr [0x802468]
// 004da447  8d4d2c               lea ecx, [ebp + 0x2c]
// 004da44a  c645fc2a             mov byte ptr [ebp - 4], 0x2a
// 004da44e  ff1568248000         call dword ptr [0x802468]
// 004da454  e931010000           jmp 0x4da58a

struct String;

typedef void (__thiscall *StringRoutine)(String *);

extern StringRoutine stringConstruct;
extern StringRoutine stringDestroy;
extern String *(__thiscall *stringConstructText)(String *, const char *);
extern String &(__thiscall *stringAssign)(String *, const String &);
extern unsigned (__thiscall *stringFind)(const String *, const char *, unsigned, unsigned);
extern String (__cdecl *stringAppend)(const String &, const char *);
extern void (__cdecl *splitFilename)(const String &, String &, String &);
extern const unsigned *stringNpos;
extern const char emptyText[];
extern const char *suffixes[8];

extern void __stdcall constructArray(void *, unsigned, unsigned,
                                    StringRoutine, StringRoutine);
extern int __cdecl parseIndex(const String &);

struct String {
    unsigned char storage[28];
    String();
    ~String();
    String &operator=(const String &);
    unsigned find(const char *, unsigned, unsigned) const;
};

inline String::String()
{
    stringConstruct(this);
}

inline String::~String()
{
    stringDestroy(this);
}

inline String &String::operator=(const String &s)
{
    return stringAssign(this, s);
}

inline unsigned String::find(const char *s, unsigned p, unsigned n) const
{
    return stringFind(this, s, p, n);
}

struct TextString {
    unsigned char storage[28];
    TextString();
    ~TextString();
    String &initialize(const char *);
};

inline TextString::TextString()
{
}

inline TextString::~TextString()
{
    stringDestroy(reinterpret_cast<String *>(this));
}

inline String &TextString::initialize(const char *s)
{
    return *stringConstructText(reinterpret_cast<String *>(this), s);
}

struct StringArray {
    unsigned char storage[168];
    StringArray();
    ~StringArray();
};

inline StringArray::StringArray()
{
    constructArray(storage, 28, 6, stringConstruct, stringDestroy);
}

inline StringArray::~StringArray()
{
    for (unsigned i = 6; i != 0; --i)
        stringDestroy(reinterpret_cast<String *>(storage + (i - 1) * 28));
}

#pragma optimize("y", off)

void reconstruct(String base)
{
    StringArray entries;
    String filename;
    String path;

    splitFilename(base, filename, path);
    if (filename.find(emptyText, 0, 1) == *stringNpos) {
        int index = parseIndex(base);
        String result;
        if (index >= 0 && static_cast<unsigned>(index) < 8) {
            TextString prefix;
            result = stringAppend(prefix.initialize(emptyText), suffixes[index]);
        }
    }
}
