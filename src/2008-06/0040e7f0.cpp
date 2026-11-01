// from server: 100% by colin
// from server: 95% by colin
// roc 2008-06 0040e7f0  unit: CBrowserView  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e7f0
//
// 0040e7f0  6aff                 push -1
// 0040e7f2  68c9107c00           push 0x7c10c9
// 0040e7f7  64a100000000         mov eax, dword ptr fs:[0]
// 0040e7fd  50                   push eax
// 0040e7fe  64892500000000       mov dword ptr fs:[0], esp
// 0040e805  51                   push ecx
// 0040e806  56                   push esi
// 0040e807  57                   push edi
// 0040e808  8bf1                 mov esi, ecx
// 0040e80a  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e810  8d442408             lea eax, [esp + 8]
// 0040e814  50                   push eax
// 0040e815  e826ae2900           call 0x6a9640
// 0040e81a  8d4c2408             lea ecx, [esp + 8]
// 0040e81e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040e826  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e82c  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e832  8bf8                 mov edi, eax
// 0040e834  e8a7992900           call 0x6a81e0
// 0040e839  8b10                 mov edx, dword ptr [eax]
// 0040e83b  57                   push edi
// 0040e83c  8bc8                 mov ecx, eax
// 0040e83e  8b8214020000         mov eax, dword ptr [edx + 0x214]
// 0040e844  6aff                 push -1
// 0040e846  ffd0                 call eax
// 0040e848  8b3d142e8000         mov edi, dword ptr [0x802e14]
// 0040e84e  83f8ff               cmp eax, -1
// 0040e851  756c                 jne 0x40e8bf
// 0040e853  8d4c2408             lea ecx, [esp + 8]
// 0040e857  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e85d  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e863  8b9178010000         mov edx, dword ptr [ecx + 0x178]
// 0040e869  50                   push eax
// 0040e86a  8b4220               mov eax, dword ptr [edx + 0x20]
// 0040e86d  6a00                 push 0
// 0040e86f  6881010000           push 0x181
// 0040e874  50                   push eax
// 0040e875  ffd7                 call edi
// 0040e877  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e87d  8b8178010000         mov eax, dword ptr [ecx + 0x178]
// 0040e883  8b5020               mov edx, dword ptr [eax + 0x20]
// 0040e886  6a00                 push 0
// 0040e888  6a00                 push 0
// 0040e88a  688b010000           push 0x18b
// 0040e88f  52                   push edx
// 0040e890  ffd7                 call edi
// 0040e892  83f80a               cmp eax, 0xa
// 0040e895  7e28                 jle 0x40e8bf
// 0040e897  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0040e89d  8b8078010000         mov eax, dword ptr [eax + 0x178]
// 0040e8a3  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0040e8a6  6a00                 push 0
// 0040e8a8  6a00                 push 0
// 0040e8aa  688b010000           push 0x18b
// 0040e8af  51                   push ecx
// 0040e8b0  ffd7                 call edi
// 0040e8b2  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e8b8  48                   dec eax
// 0040e8b9  50                   push eax
// 0040e8ba  e8b1fbffff           call 0x40e470
// 0040e8bf  6a00                 push 0
// 0040e8c1  6a00                 push 0
// 0040e8c3  6a00                 push 0
// 0040e8c5  6a00                 push 0
// 0040e8c7  6a00                 push 0
// 0040e8c9  8d4c241c             lea ecx, [esp + 0x1c]
// 0040e8cd  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e8d3  50                   push eax
// 0040e8d4  8bce                 mov ecx, esi
// 0040e8d6  e89f202900           call 0x6a097a
// 0040e8db  8b9618010000         mov edx, dword ptr [esi + 0x118]
// 0040e8e1  8bb284010000         mov esi, dword ptr [edx + 0x184]
// 0040e8e7  8b4620               mov eax, dword ptr [esi + 0x20]
// 0040e8ea  6aff                 push -1
// 0040e8ec  6a00                 push 0
// 0040e8ee  68b1000000           push 0xb1
// 0040e8f3  50                   push eax
// 0040e8f4  ffd7                 call edi
// 0040e8f6  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0040e8f9  6a00                 push 0
// 0040e8fb  6a00                 push 0
// 0040e8fd  68b7000000           push 0xb7
// 0040e902  51                   push ecx
// 0040e903  ffd7                 call edi
// 0040e905  8d4c2408             lea ecx, [esp + 8]
// 0040e909  ff15143f8000         call dword ptr [0x803f14]
// 0040e90f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040e913  5f                   pop edi
// 0040e914  5e                   pop esi
// 0040e915  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e91c  83c410               add esp, 0x10
// 0040e91f  c3                   ret 

// from server: 93% by king_originala
// roc 2008-06 0040e7f0  unit: CBrowserView  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e7f0
//
// 0040e7f0  6aff                 push -1
// 0040e7f2  68c9107c00           push 0x7c10c9
// 0040e7f7  64a100000000         mov eax, dword ptr fs:[0]
// 0040e7fd  50                   push eax
// 0040e7fe  64892500000000       mov dword ptr fs:[0], esp
// 0040e805  51                   push ecx
// 0040e806  56                   push esi
// 0040e807  57                   push edi
// 0040e808  8bf1                 mov esi, ecx
// 0040e80a  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e810  8d442408             lea eax, [esp + 8]
// 0040e814  50                   push eax
// 0040e815  e826ae2900           call 0x6a9640
// 0040e81a  8d4c2408             lea ecx, [esp + 8]
// 0040e81e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040e826  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e82c  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e832  8bf8                 mov edi, eax
// 0040e834  e8a7992900           call 0x6a81e0
// 0040e839  8b10                 mov edx, dword ptr [eax]
// 0040e83b  57                   push edi
// 0040e83c  8bc8                 mov ecx, eax
// 0040e83e  8b8214020000         mov eax, dword ptr [edx + 0x214]
// 0040e844  6aff                 push -1
// 0040e846  ffd0                 call eax
// 0040e848  8b3d142e8000         mov edi, dword ptr [0x802e14]
// 0040e84e  83f8ff               cmp eax, -1
// 0040e851  756c                 jne 0x40e8bf
// 0040e853  8d4c2408             lea ecx, [esp + 8]
// 0040e857  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e85d  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e863  8b9178010000         mov edx, dword ptr [ecx + 0x178]
// 0040e869  50                   push eax
// 0040e86a  8b4220               mov eax, dword ptr [edx + 0x20]
// 0040e86d  6a00                 push 0
// 0040e86f  6881010000           push 0x181
// 0040e874  50                   push eax
// 0040e875  ffd7                 call edi
// 0040e877  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e87d  8b8178010000         mov eax, dword ptr [ecx + 0x178]
// 0040e883  8b5020               mov edx, dword ptr [eax + 0x20]
// 0040e886  6a00                 push 0
// 0040e888  6a00                 push 0
// 0040e88a  688b010000           push 0x18b
// 0040e88f  52                   push edx
// 0040e890  ffd7                 call edi
// 0040e892  83f80a               cmp eax, 0xa
// 0040e895  7e28                 jle 0x40e8bf
// 0040e897  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0040e89d  8b8078010000         mov eax, dword ptr [eax + 0x178]
// 0040e8a3  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0040e8a6  6a00                 push 0
// 0040e8a8  6a00                 push 0
// 0040e8aa  688b010000           push 0x18b
// 0040e8af  51                   push ecx
// 0040e8b0  ffd7                 call edi
// 0040e8b2  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e8b8  48                   dec eax
// 0040e8b9  50                   push eax
// 0040e8ba  e8b1fbffff           call 0x40e470
// 0040e8bf  6a00                 push 0
// 0040e8c1  6a00                 push 0
// 0040e8c3  6a00                 push 0
// 0040e8c5  6a00                 push 0
// 0040e8c7  6a00                 push 0
// 0040e8c9  8d4c241c             lea ecx, [esp + 0x1c]
// 0040e8cd  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e8d3  50                   push eax
// 0040e8d4  8bce                 mov ecx, esi
// 0040e8d6  e89f202900           call 0x6a097a
// 0040e8db  8b9618010000         mov edx, dword ptr [esi + 0x118]
// 0040e8e1  8bb284010000         mov esi, dword ptr [edx + 0x184]
// 0040e8e7  8b4620               mov eax, dword ptr [esi + 0x20]
// 0040e8ea  6aff                 push -1
// 0040e8ec  6a00                 push 0
// 0040e8ee  68b1000000           push 0xb1
// 0040e8f3  50                   push eax
// 0040e8f4  ffd7                 call edi
// 0040e8f6  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0040e8f9  6a00                 push 0
// 0040e8fb  6a00                 push 0
// 0040e8fd  68b7000000           push 0xb7
// 0040e902  51                   push ecx
// 0040e903  ffd7                 call edi
// 0040e905  8d4c2408             lea ecx, [esp + 8]
// 0040e909  ff15143f8000         call dword ptr [0x803f14]
// 0040e90f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040e913  5f                   pop edi
// 0040e914  5e                   pop esi
// 0040e915  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e91c  83c410               add esp, 0x10
// 0040e91f  c3                   ret 

struct Text;
typedef const char* (__thiscall *TextAccess)(const Text*);
typedef void (__thiscall *TextDestroy)(Text*);

extern TextAccess textAccess;
extern TextDestroy textDestroy;

struct Text {
    char* data;
    __declspec(dllimport) ~Text() throw();
    operator const char*() const;
};

inline Text::operator const char*() const
{
    return textAccess(this);
}

typedef int (__thiscall *FindEntry)(void*, int, const char*);

struct SearchObject {
    FindEntry* table;
};

struct Window {
    char pad[0x20];
    void* handle;
};

struct Combo {
    char pad[0x178];
    Window* list;
    char gap[8];
    Window* edit;

    Text getText();
    int getSomething();
    void finalize(int);
};

typedef long (__stdcall *MessageFunction)(void*, unsigned int,
                                         unsigned int, long);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int,
                                                             unsigned int, long);

struct CBrowserView {
    char pad[0x118];
    Combo* combo;

    void navigate(const char*, unsigned long, const char*, const char*,
                  void*, unsigned long);
    void func_0040e7f0();
};

void CBrowserView::func_0040e7f0()
{
    Text text = combo->getText();
    const char* value = text;
    SearchObject* object = (SearchObject*)combo->getSomething();
    int result = object->table[133](object, -1, value);


    if (result == -1) {
        SendMessageA(combo->list->handle, 0x181, 0, (long)(const char*)text);
        Window* list = combo->list;
        if (SendMessageA(list->handle, 0x18b, 0, 0) > 10) {
            Window* finalList = combo->list;
            combo->finalize(SendMessageA(finalList->handle, 0x18b, 0, 0) - 1);
        }
    }

    navigate(text, 0, 0, 0, 0, 0);

    Window* edit = combo->edit;
    SendMessageA(edit->handle, 0xb1, 0, -1);
    SendMessageA(edit->handle, 0xb7, 0, 0);
}
