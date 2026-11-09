// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 006bb840  unit: RBX::Lua::LuaArguments  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb840
//
// 006bb840  83ec08               sub esp, 8
// 006bb843  53                   push ebx
// 006bb844  55                   push ebp
// 006bb845  56                   push esi
// 006bb846  8bf1                 mov esi, ecx
// 006bb848  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006bb84b  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 006bb84e  33ed                 xor ebp, ebp
// 006bb850  c1fb02               sar ebx, 2
// 006bb853  57                   push edi
// 006bb854  85db                 test ebx, ebx
// 006bb856  7649                 jbe 0x6bb8a1
// 006bb858  eb06                 jmp 0x6bb860
// 006bb85a  8d9b00000000         lea ebx, [ebx]
// 006bb860  8b4610               mov eax, dword ptr [esi + 0x10]
// 006bb863  2b460c               sub eax, dword ptr [esi + 0xc]
// 006bb866  8d3c2b               lea edi, [ebx + ebp]
// 006bb869  d1ef                 shr edi, 1
// 006bb86b  c1f802               sar eax, 2
// 006bb86e  3bf8                 cmp edi, eax
// 006bb870  7206                 jb 0x6bb878
// 006bb872  ff15ace98900         call dword ptr [0x89e9ac]
// 006bb878  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006bb87b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 006bb87e  8b4204               mov eax, dword ptr [edx + 4]
// 006bb881  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006bb885  3bc8                 cmp ecx, eax
// 006bb887  7443                 je 0x6bb8cc
// 006bb889  50                   push eax
// 006bb88a  ff155ce48900         call dword ptr [0x89e45c]
// 006bb890  85c0                 test eax, eax
// 006bb892  7d04                 jge 0x6bb898
// 006bb894  8bdf                 mov ebx, edi
// 006bb896  eb05                 jmp 0x6bb89d
// 006bb898  7e32                 jle 0x6bb8cc
// 006bb89a  8d6f01               lea ebp, [edi + 1]
// 006bb89d  3beb                 cmp ebp, ebx
// 006bb89f  72bf                 jb 0x6bb860
// 006bb8a1  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006bb8a4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006bb8a8  c70700000000         mov dword ptr [edi], 0
// 006bb8ae  395e0c               cmp dword ptr [esi + 0xc], ebx
// 006bb8b1  7606                 jbe 0x6bb8b9
// 006bb8b3  ff15ace98900         call dword ptr [0x89e9ac]
// 006bb8b9  8b06                 mov eax, dword ptr [esi]
// 006bb8bb  8907                 mov dword ptr [edi], eax
// 006bb8bd  895f04               mov dword ptr [edi + 4], ebx
// 006bb8c0  8bc7                 mov eax, edi
// 006bb8c2  5f                   pop edi
// 006bb8c3  5e                   pop esi
// 006bb8c4  5d                   pop ebp
// 006bb8c5  5b                   pop ebx
// 006bb8c6  83c408               add esp, 8
// 006bb8c9  c20800               ret 8
// 006bb8cc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006bb8cf  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006bb8d2  7606                 jbe 0x6bb8da
// 006bb8d4  ff15ace98900         call dword ptr [0x89e9ac]
// 006bb8da  8b36                 mov esi, dword ptr [esi]
// 006bb8dc  8bee                 mov ebp, esi
// 006bb8de  895c2414             mov dword ptr [esp + 0x14], ebx
// 006bb8e2  85f6                 test esi, esi
// 006bb8e4  7518                 jne 0x6bb8fe
// 006bb8e6  ff15ace98900         call dword ptr [0x89e9ac]
// 006bb8ec  33c0                 xor eax, eax
// 006bb8ee  8d3cbb               lea edi, [ebx + edi*4]
// 006bb8f1  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006bb8f4  7713                 ja 0x6bb909
// 006bb8f6  85f6                 test esi, esi
// 006bb8f8  7408                 je 0x6bb902
// 006bb8fa  8b36                 mov esi, dword ptr [esi]
// 006bb8fc  eb06                 jmp 0x6bb904
// 006bb8fe  8b06                 mov eax, dword ptr [esi]
// 006bb900  ebec                 jmp 0x6bb8ee
// 006bb902  33f6                 xor esi, esi
// 006bb904  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006bb907  7306                 jae 0x6bb90f
// 006bb909  ff15ace98900         call dword ptr [0x89e9ac]
// 006bb90f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006bb913  897804               mov dword ptr [eax + 4], edi
// 006bb916  5f                   pop edi
// 006bb917  5e                   pop esi
// 006bb918  8928                 mov dword ptr [eax], ebp
// 006bb91a  5d                   pop ebp
// 006bb91b  5b                   pop ebx
// 006bb91c  83c408               add esp, 8
// 006bb91f  c20800               ret 8

// from server: 100% by Espeon
// roc 2008-06 0061ba10  unit: RBX::Lua::LuaArguments  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061ba10
//
// 0061ba10  83ec08               sub esp, 8
// 0061ba13  53                   push ebx
// 0061ba14  55                   push ebp
// 0061ba15  56                   push esi
// 0061ba16  8bf1                 mov esi, ecx
// 0061ba18  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0061ba1b  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 0061ba1e  33ed                 xor ebp, ebp
// 0061ba20  c1fb02               sar ebx, 2
// 0061ba23  57                   push edi
// 0061ba24  85db                 test ebx, ebx
// 0061ba26  764f                 jbe 0x61ba77
// 0061ba28  eb06                 jmp 0x61ba30
// 0061ba2a  8d9b00000000         lea ebx, [ebx]
// 0061ba30  8b4610               mov eax, dword ptr [esi + 0x10]
// 0061ba33  2b460c               sub eax, dword ptr [esi + 0xc]
// 0061ba36  8d3c2b               lea edi, [ebx + ebp]
// 0061ba39  d1ef                 shr edi, 1
// 0061ba3b  c1f802               sar eax, 2
// 0061ba3e  3bf8                 cmp edi, eax
// 0061ba40  7206                 jb 0x61ba48
// 0061ba42  ff1590288000         call dword ptr [0x802890]
// 0061ba48  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0061ba4b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0061ba4e  8b4204               mov eax, dword ptr [edx + 4]
// 0061ba51  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061ba55  3bc8                 cmp ecx, eax
// 0061ba57  7449                 je 0x61baa2
// 0061ba59  83c004               add eax, 4
// 0061ba5c  50                   push eax
// 0061ba5d  83c104               add ecx, 4
// 0061ba60  ff1524248000         call dword ptr [0x802424]
// 0061ba66  85c0                 test eax, eax
// 0061ba68  7d04                 jge 0x61ba6e
// 0061ba6a  8bdf                 mov ebx, edi
// 0061ba6c  eb05                 jmp 0x61ba73
// 0061ba6e  7e32                 jle 0x61baa2
// 0061ba70  8d6f01               lea ebp, [edi + 1]
// 0061ba73  3beb                 cmp ebp, ebx
// 0061ba75  72b9                 jb 0x61ba30
// 0061ba77  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0061ba7a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0061ba7e  c70700000000         mov dword ptr [edi], 0
// 0061ba84  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0061ba87  7606                 jbe 0x61ba8f
// 0061ba89  ff1590288000         call dword ptr [0x802890]
// 0061ba8f  8b06                 mov eax, dword ptr [esi]
// 0061ba91  8907                 mov dword ptr [edi], eax
// 0061ba93  895f04               mov dword ptr [edi + 4], ebx
// 0061ba96  8bc7                 mov eax, edi
// 0061ba98  5f                   pop edi
// 0061ba99  5e                   pop esi
// 0061ba9a  5d                   pop ebp
// 0061ba9b  5b                   pop ebx
// 0061ba9c  83c408               add esp, 8
// 0061ba9f  c20800               ret 8
// 0061baa2  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0061baa5  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0061baa8  7606                 jbe 0x61bab0
// 0061baaa  ff1590288000         call dword ptr [0x802890]
// 0061bab0  8b36                 mov esi, dword ptr [esi]
// 0061bab2  8bee                 mov ebp, esi
// 0061bab4  895c2414             mov dword ptr [esp + 0x14], ebx
// 0061bab8  85f6                 test esi, esi
// 0061baba  7518                 jne 0x61bad4
// 0061babc  ff1590288000         call dword ptr [0x802890]
// 0061bac2  33c0                 xor eax, eax
// 0061bac4  8d3cbb               lea edi, [ebx + edi*4]
// 0061bac7  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0061baca  7713                 ja 0x61badf
// 0061bacc  85f6                 test esi, esi
// 0061bace  7408                 je 0x61bad8
// 0061bad0  8b36                 mov esi, dword ptr [esi]
// 0061bad2  eb06                 jmp 0x61bada
// 0061bad4  8b06                 mov eax, dword ptr [esi]
// 0061bad6  ebec                 jmp 0x61bac4
// 0061bad8  33f6                 xor esi, esi
// 0061bada  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0061badd  7306                 jae 0x61bae5
// 0061badf  ff1590288000         call dword ptr [0x802890]
// 0061bae5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061bae9  897804               mov dword ptr [eax + 4], edi
// 0061baec  5f                   pop edi
// 0061baed  5e                   pop esi
// 0061baee  8928                 mov dword ptr [eax], ebp
// 0061baf0  5d                   pop ebp
// 0061baf1  5b                   pop ebx
// 0061baf2  83c408               add esp, 8
// 0061baf5  c20800               ret 8

// from server: 95% by king_originala
// roc 2008-06 0061ba10  unit: RBX::Lua::LuaArguments  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061ba10
//
// 0061ba10  83ec08               sub esp, 8
// 0061ba13  53                   push ebx
// 0061ba14  55                   push ebp
// 0061ba15  56                   push esi
// 0061ba16  8bf1                 mov esi, ecx
// 0061ba18  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0061ba1b  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 0061ba1e  33ed                 xor ebp, ebp
// 0061ba20  c1fb02               sar ebx, 2
// 0061ba23  57                   push edi
// 0061ba24  85db                 test ebx, ebx
// 0061ba26  764f                 jbe 0x61ba77
// 0061ba28  eb06                 jmp 0x61ba30
// 0061ba2a  8d9b00000000         lea ebx, [ebx]
// 0061ba30  8b4610               mov eax, dword ptr [esi + 0x10]
// 0061ba33  2b460c               sub eax, dword ptr [esi + 0xc]
// 0061ba36  8d3c2b               lea edi, [ebx + ebp]
// 0061ba39  d1ef                 shr edi, 1
// 0061ba3b  c1f802               sar eax, 2
// 0061ba3e  3bf8                 cmp edi, eax
// 0061ba40  7206                 jb 0x61ba48
// 0061ba42  ff1590288000         call dword ptr [0x802890]
// 0061ba48  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0061ba4b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0061ba4e  8b4204               mov eax, dword ptr [edx + 4]
// 0061ba51  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061ba55  3bc8                 cmp ecx, eax
// 0061ba57  7449                 je 0x61baa2
// 0061ba59  83c004               add eax, 4
// 0061ba5c  50                   push eax
// 0061ba5d  83c104               add ecx, 4
// 0061ba60  ff1524248000         call dword ptr [0x802424]
// 0061ba66  85c0                 test eax, eax
// 0061ba68  7d04                 jge 0x61ba6e
// 0061ba6a  8bdf                 mov ebx, edi
// 0061ba6c  eb05                 jmp 0x61ba73
// 0061ba6e  7e32                 jle 0x61baa2
// 0061ba70  8d6f01               lea ebp, [edi + 1]
// 0061ba73  3beb                 cmp ebp, ebx
// 0061ba75  72b9                 jb 0x61ba30
// 0061ba77  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0061ba7a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0061ba7e  c70700000000         mov dword ptr [edi], 0
// 0061ba84  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0061ba87  7606                 jbe 0x61ba8f
// 0061ba89  ff1590288000         call dword ptr [0x802890]
// 0061ba8f  8b06                 mov eax, dword ptr [esi]
// 0061ba91  8907                 mov dword ptr [edi], eax
// 0061ba93  895f04               mov dword ptr [edi + 4], ebx
// 0061ba96  8bc7                 mov eax, edi
// 0061ba98  5f                   pop edi
// 0061ba99  5e                   pop esi
// 0061ba9a  5d                   pop ebp
// 0061ba9b  5b                   pop ebx
// 0061ba9c  83c408               add esp, 8
// 0061ba9f  c20800               ret 8
// 0061baa2  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0061baa5  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0061baa8  7606                 jbe 0x61bab0
// 0061baaa  ff1590288000         call dword ptr [0x802890]
// 0061bab0  8b36                 mov esi, dword ptr [esi]
// 0061bab2  8bee                 mov ebp, esi
// 0061bab4  895c2414             mov dword ptr [esp + 0x14], ebx
// 0061bab8  85f6                 test esi, esi
// 0061baba  7518                 jne 0x61bad4
// 0061babc  ff1590288000         call dword ptr [0x802890]
// 0061bac2  33c0                 xor eax, eax
// 0061bac4  8d3cbb               lea edi, [ebx + edi*4]
// 0061bac7  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0061baca  7713                 ja 0x61badf
// 0061bacc  85f6                 test esi, esi
// 0061bace  7408                 je 0x61bad8
// 0061bad0  8b36                 mov esi, dword ptr [esi]
// 0061bad2  eb06                 jmp 0x61bada
// 0061bad4  8b06                 mov eax, dword ptr [esi]
// 0061bad6  ebec                 jmp 0x61bac4
// 0061bad8  33f6                 xor esi, esi
// 0061bada  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0061badd  7306                 jae 0x61bae5
// 0061badf  ff1590288000         call dword ptr [0x802890]
// 0061bae5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061bae9  897804               mov dword ptr [eax + 4], edi
// 0061baec  5f                   pop edi
// 0061baed  5e                   pop esi
// 0061baee  8928                 mov dword ptr [eax], ebp
// 0061baf0  5d                   pop ebp
// 0061baf1  5b                   pop ebx
// 0061baf2  83c408               add esp, 8
// 0061baf5  c20800               ret 8

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct String {
    unsigned char data[28];
};

extern int (__thiscall *string_compare)(const String *, const String &);

struct Key {
    String text;
};

struct Entry {
    unsigned int tag;
    Key *key;
};

struct S;

struct Proxy {
    S *container;
};

struct Iterator {
    Proxy *owner;
    Entry **position;

    Iterator(Entry **p, S *s);
    Iterator &operator+=(unsigned int n);
    Iterator operator+(unsigned int n) const;
};

struct S {
    Proxy *owner;
    unsigned int reserved[2];
    Entry **first;
    Entry **last;

    Iterator find(const Key *key);
};

inline Iterator::Iterator(Entry **p, S *s) : owner(0)
{
    if (s->first > p || p > s->last)
        _invalid_parameter_noinfo();
    owner = s->owner;
    position = p;
}

inline Iterator &Iterator::operator+=(unsigned int n)
{
    S *cursor = reinterpret_cast<S *>(owner);

    if (!cursor)
        _invalid_parameter_noinfo();

    S *container = cursor
        ? reinterpret_cast<Proxy *>(cursor)->container
        : 0;

    Entry **p = position + n;
    if (p > container->last)
        _invalid_parameter_noinfo();
    else {
        if (cursor)
            cursor = reinterpret_cast<Proxy *>(cursor)->container;
        else
            cursor = 0;

        if (p < cursor->first)
            _invalid_parameter_noinfo();
    }

    position = p;
    return *this;
}

inline Iterator Iterator::operator+(unsigned int n) const
{
    Iterator result(*this);
    return result += n;
}

Iterator S::find(const Key *key)
{
    unsigned int low = 0;
    unsigned int high = last - first;
    unsigned int middle;

    while (low < high) {
        middle = (high + low) >> 1;

        if (middle >= static_cast<unsigned int>(last - first))
            _invalid_parameter_noinfo();

        Key *candidate = first[middle]->key;
        if (key == candidate)
            goto found;

        int comparison = string_compare(&key->text, candidate->text);
        if (comparison < 0)
            high = middle;
        else if (comparison > 0)
            low = middle + 1;
        else
            goto found;
    }

    return Iterator(last, this);

found:
    return Iterator(first, this) + middle;
}
