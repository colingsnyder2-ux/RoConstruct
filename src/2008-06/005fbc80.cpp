// from server: 100% by colin
// from server: 0% by king_originala
// roc 2008-06 005fbc80  unit: RBX::LocalBackpackItem  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fbc80
//
// 005fbc80  53                   push ebx
// 005fbc81  55                   push ebp
// 005fbc82  56                   push esi
// 005fbc83  57                   push edi
// 005fbc84  8bd9                 mov ebx, ecx
// 005fbc86  33f6                 xor esi, esi
// 005fbc88  e893f1e8ff           call 0x48ae20
// 005fbc8d  85c0                 test eax, eax
// 005fbc8f  7669                 jbe 0x5fbcfa
// 005fbc91  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005fbc95  eb09                 jmp 0x5fbca0
// 005fbc97  8da42400000000       lea esp, [esp]
// 005fbc9e  8bff                 mov edi, edi
// 005fbca0  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 005fbca6  8b4710               mov eax, dword ptr [edi + 0x10]
// 005fbca9  2b470c               sub eax, dword ptr [edi + 0xc]
// 005fbcac  c1f803               sar eax, 3
// 005fbcaf  3bf0                 cmp esi, eax
// 005fbcb1  7206                 jb 0x5fbcb9
// 005fbcb3  ff1590288000         call dword ptr [0x802890]
// 005fbcb9  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 005fbcbc  8b0cf1               mov ecx, dword ptr [ecx + esi*8]
// 005fbcbf  39a948010000         cmp dword ptr [ecx + 0x148], ebp
// 005fbcc5  7413                 je 0x5fbcda
// 005fbcc7  8bcb                 mov ecx, ebx
// 005fbcc9  46                   inc esi
// 005fbcca  e851f1e8ff           call 0x48ae20
// 005fbccf  3bf0                 cmp esi, eax
// 005fbcd1  72cd                 jb 0x5fbca0
// 005fbcd3  5f                   pop edi
// 005fbcd4  5e                   pop esi
// 005fbcd5  5d                   pop ebp
// 005fbcd6  5b                   pop ebx
// 005fbcd7  c20400               ret 4
// 005fbcda  6a00                 push 0
// 005fbcdc  89b3a8010000         mov dword ptr [ebx + 0x1a8], esi
// 005fbce2  e809ecf5ff           call 0x55a8f0
// 005fbce7  3baba0010000         cmp ebp, dword ptr [ebx + 0x1a0]
// 005fbced  8d8ba0010000         lea ecx, [ebx + 0x1a0]
// 005fbcf3  7505                 jne 0x5fbcfa
// 005fbcf5  e886b1e5ff           call 0x456e80
// 005fbcfa  5f                   pop edi
// 005fbcfb  5e                   pop esi
// 005fbcfc  5d                   pop ebp
// 005fbcfd  5b                   pop ebx
// 005fbcfe  c20400               ret 4

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Item {
    char padding[0x148];
    void* key;
    void update(int);
};

struct Entry {
    Item* item;
    void* owner;
};

struct Items {
    char padding[0x0C];
    Entry* first;
    Entry* last;
};

struct Reference {
    void* object;
    void* owner;
    void clear();
};

struct S {
    char padding0[0x108];
    Items* items;
    char padding1[0x94];
    Reference selected;
    unsigned index;

    unsigned count();
    void f(void* key);
};

void S::f(void* key)
{
    do {
    for (unsigned i = 0; i < count(); ++i) {
        Items* list = items;
        if (i >= static_cast<unsigned>(list->last - list->first))
            invalid_parameter_noinfo();

        Item* item = list->first[i].item;
        if (item->key == key) {
            index = i;
            item->update(0);
            if (key == selected.object)
                selected.clear();
            return;
        }
    }
    } while (0);
}

