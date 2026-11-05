// from server: 100% by colin
// from server: 96% by colin
// roc 2008-06 0040f050  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f050
//
// 0040f050  6aff                 push -1
// 0040f052  6883d47b00           push 0x7bd483
// 0040f057  64a100000000         mov eax, dword ptr fs:[0]
// 0040f05d  50                   push eax
// 0040f05e  64892500000000       mov dword ptr fs:[0], esp
// 0040f065  83ec14               sub esp, 0x14
// 0040f068  53                   push ebx
// 0040f069  55                   push ebp
// 0040f06a  56                   push esi
// 0040f06b  57                   push edi
// 0040f06c  33db                 xor ebx, ebx
// 0040f06e  68e8000000           push 0xe8
// 0040f073  895c2430             mov dword ptr [esp + 0x30], ebx
// 0040f077  e8a4182900           call 0x6a0920
// 0040f07c  83c404               add esp, 4
// 0040f07f  89442410             mov dword ptr [esp + 0x10], eax
// 0040f083  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040f088  3bc3                 cmp eax, ebx
// 0040f08a  740b                 je 0x40f097
// 0040f08c  8bc8                 mov ecx, eax
// 0040f08e  e8ab1b2900           call 0x6a0c3e
// 0040f093  8bf8                 mov edi, eax
// 0040f095  eb02                 jmp 0x40f099
// 0040f097  33ff                 xor edi, edi
// 0040f099  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f09d  8b07                 mov eax, dword ptr [edi]
// 0040f09f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 0040f0a5  53                   push ebx
// 0040f0a6  53                   push ebx
// 0040f0a7  53                   push ebx
// 0040f0a8  51                   push ecx
// 0040f0a9  8d542424             lea edx, [esp + 0x24]
// 0040f0ad  52                   push edx
// 0040f0ae  680000cf00           push 0xcf0000
// 0040f0b3  53                   push ebx
// 0040f0b4  53                   push ebx
// 0040f0b5  8bcf                 mov ecx, edi
// 0040f0b7  885c244c             mov byte ptr [esp + 0x4c], bl
// 0040f0bb  895c2434             mov dword ptr [esp + 0x34], ebx
// 0040f0bf  895c2438             mov dword ptr [esp + 0x38], ebx
// 0040f0c3  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040f0c7  895c2440             mov dword ptr [esp + 0x40], ebx
// 0040f0cb  ffd0                 call eax
// 0040f0cd  53                   push ebx
// 0040f0ce  6880000000           push 0x80
// 0040f0d3  6800020000           push 0x200
// 0040f0d8  8bcf                 mov ecx, edi
// 0040f0da  e8591b2900           call 0x6a0c38
// 0040f0df  53                   push ebx
// 0040f0e0  6828af9200           push 0x92af28
// 0040f0e5  687c809200           push 0x92807c
// 0040f0ea  53                   push ebx
// 0040f0eb  6800e90000           push 0xe900
// 0040f0f0  53                   push ebx
// 0040f0f1  6800008050           push 0x50800000
// 0040f0f6  53                   push ebx
// 0040f0f7  53                   push ebx
// 0040f0f8  6858cf8000           push 0x80cf58
// 0040f0fd  57                   push edi
// 0040f0fe  e85d5a2b00           call 0x6c4b60
// 0040f103  50                   push eax
// 0040f104  e8bd262900           call 0x6a17c6
// 0040f109  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0040f10d  8bf0                 mov esi, eax
// 0040f10f  83c414               add esp, 0x14
// 0040f112  39aec4020000         cmp dword ptr [esi + 0x2c4], ebp
// 0040f118  7425                 je 0x40f13f
// 0040f11a  3beb                 cmp ebp, ebx
// 0040f11c  7409                 je 0x40f127
// 0040f11e  8b4d00               mov ecx, dword ptr [ebp]
// 0040f121  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f124  55                   push ebp
// 0040f125  ffd2                 call edx
// 0040f127  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0040f12d  3bc3                 cmp eax, ebx
// 0040f12f  7408                 je 0x40f139
// 0040f131  8b08                 mov ecx, dword ptr [eax]
// 0040f133  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f136  50                   push eax
// 0040f137  ffd2                 call edx
// 0040f139  89aec4020000         mov dword ptr [esi + 0x2c4], ebp
// 0040f13f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f143  ff15e03e8000         call dword ptr [0x803ee0]
// 0040f149  8be8                 mov ebp, eax
// 0040f14b  55                   push ebp
// 0040f14c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 0040f152  ff15b83e8000         call dword ptr [0x803eb8]
// 0040f158  53                   push ebx
// 0040f159  53                   push ebx
// 0040f15a  53                   push ebx
// 0040f15b  53                   push ebx
// 0040f15c  53                   push ebx
// 0040f15d  55                   push ebp
// 0040f15e  8bce                 mov ecx, esi
// 0040f160  e815182900           call 0x6a097a
// 0040f165  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f169  8d442434             lea eax, [esp + 0x34]
// 0040f16d  50                   push eax
// 0040f16e  e8bf1a2900           call 0x6a0c32
// 0040f173  8b442438             mov eax, dword ptr [esp + 0x38]
// 0040f177  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0040f17b  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040f17f  6a04                 push 4
// 0040f181  2bc8                 sub ecx, eax
// 0040f183  51                   push ecx
// 0040f184  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0040f188  2bd1                 sub edx, ecx
// 0040f18a  52                   push edx
// 0040f18b  50                   push eax
// 0040f18c  51                   push ecx
// 0040f18d  53                   push ebx
// 0040f18e  8bcf                 mov ecx, edi
// 0040f190  e8b1182900           call 0x6a0a46
// 0040f195  6a01                 push 1
// 0040f197  53                   push ebx
// 0040f198  8bcf                 mov ecx, edi
// 0040f19a  e88d1a2900           call 0x6a0c2c
// 0040f19f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f1a3  ff15143f8000         call dword ptr [0x803f14]
// 0040f1a9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040f1ad  5f                   pop edi
// 0040f1ae  8bc6                 mov eax, esi
// 0040f1b0  5e                   pop esi
// 0040f1b1  5d                   pop ebp
// 0040f1b2  5b                   pop ebx
// 0040f1b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f1ba  83c420               add esp, 0x20
// 0040f1bd  c3                   ret 

// from server: 94% by king_originala
// roc 2008-06 0040f050  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f050
//
// 0040f050  6aff                 push -1
// 0040f052  6883d47b00           push 0x7bd483
// 0040f057  64a100000000         mov eax, dword ptr fs:[0]
// 0040f05d  50                   push eax
// 0040f05e  64892500000000       mov dword ptr fs:[0], esp
// 0040f065  83ec14               sub esp, 0x14
// 0040f068  53                   push ebx
// 0040f069  55                   push ebp
// 0040f06a  56                   push esi
// 0040f06b  57                   push edi
// 0040f06c  33db                 xor ebx, ebx
// 0040f06e  68e8000000           push 0xe8
// 0040f073  895c2430             mov dword ptr [esp + 0x30], ebx
// 0040f077  e8a4182900           call 0x6a0920
// 0040f07c  83c404               add esp, 4
// 0040f07f  89442410             mov dword ptr [esp + 0x10], eax
// 0040f083  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040f088  3bc3                 cmp eax, ebx
// 0040f08a  740b                 je 0x40f097
// 0040f08c  8bc8                 mov ecx, eax
// 0040f08e  e8ab1b2900           call 0x6a0c3e
// 0040f093  8bf8                 mov edi, eax
// 0040f095  eb02                 jmp 0x40f099
// 0040f097  33ff                 xor edi, edi
// 0040f099  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f09d  8b07                 mov eax, dword ptr [edi]
// 0040f09f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 0040f0a5  53                   push ebx
// 0040f0a6  53                   push ebx
// 0040f0a7  53                   push ebx
// 0040f0a8  51                   push ecx
// 0040f0a9  8d542424             lea edx, [esp + 0x24]
// 0040f0ad  52                   push edx
// 0040f0ae  680000cf00           push 0xcf0000
// 0040f0b3  53                   push ebx
// 0040f0b4  53                   push ebx
// 0040f0b5  8bcf                 mov ecx, edi
// 0040f0b7  885c244c             mov byte ptr [esp + 0x4c], bl
// 0040f0bb  895c2434             mov dword ptr [esp + 0x34], ebx
// 0040f0bf  895c2438             mov dword ptr [esp + 0x38], ebx
// 0040f0c3  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040f0c7  895c2440             mov dword ptr [esp + 0x40], ebx
// 0040f0cb  ffd0                 call eax
// 0040f0cd  53                   push ebx
// 0040f0ce  6880000000           push 0x80
// 0040f0d3  6800020000           push 0x200
// 0040f0d8  8bcf                 mov ecx, edi
// 0040f0da  e8591b2900           call 0x6a0c38
// 0040f0df  53                   push ebx
// 0040f0e0  6828af9200           push 0x92af28
// 0040f0e5  687c809200           push 0x92807c
// 0040f0ea  53                   push ebx
// 0040f0eb  6800e90000           push 0xe900
// 0040f0f0  53                   push ebx
// 0040f0f1  6800008050           push 0x50800000
// 0040f0f6  53                   push ebx
// 0040f0f7  53                   push ebx
// 0040f0f8  6858cf8000           push 0x80cf58
// 0040f0fd  57                   push edi
// 0040f0fe  e85d5a2b00           call 0x6c4b60
// 0040f103  50                   push eax
// 0040f104  e8bd262900           call 0x6a17c6
// 0040f109  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0040f10d  8bf0                 mov esi, eax
// 0040f10f  83c414               add esp, 0x14
// 0040f112  39aec4020000         cmp dword ptr [esi + 0x2c4], ebp
// 0040f118  7425                 je 0x40f13f
// 0040f11a  3beb                 cmp ebp, ebx
// 0040f11c  7409                 je 0x40f127
// 0040f11e  8b4d00               mov ecx, dword ptr [ebp]
// 0040f121  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f124  55                   push ebp
// 0040f125  ffd2                 call edx
// 0040f127  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0040f12d  3bc3                 cmp eax, ebx
// 0040f12f  7408                 je 0x40f139
// 0040f131  8b08                 mov ecx, dword ptr [eax]
// 0040f133  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f136  50                   push eax
// 0040f137  ffd2                 call edx
// 0040f139  89aec4020000         mov dword ptr [esi + 0x2c4], ebp
// 0040f13f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f143  ff15e03e8000         call dword ptr [0x803ee0]
// 0040f149  8be8                 mov ebp, eax
// 0040f14b  55                   push ebp
// 0040f14c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 0040f152  ff15b83e8000         call dword ptr [0x803eb8]
// 0040f158  53                   push ebx
// 0040f159  53                   push ebx
// 0040f15a  53                   push ebx
// 0040f15b  53                   push ebx
// 0040f15c  53                   push ebx
// 0040f15d  55                   push ebp
// 0040f15e  8bce                 mov ecx, esi
// 0040f160  e815182900           call 0x6a097a
// 0040f165  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f169  8d442434             lea eax, [esp + 0x34]
// 0040f16d  50                   push eax
// 0040f16e  e8bf1a2900           call 0x6a0c32
// 0040f173  8b442438             mov eax, dword ptr [esp + 0x38]
// 0040f177  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0040f17b  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040f17f  6a04                 push 4
// 0040f181  2bc8                 sub ecx, eax
// 0040f183  51                   push ecx
// 0040f184  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0040f188  2bd1                 sub edx, ecx
// 0040f18a  52                   push edx
// 0040f18b  50                   push eax
// 0040f18c  51                   push ecx
// 0040f18d  53                   push ebx
// 0040f18e  8bcf                 mov ecx, edi
// 0040f190  e8b1182900           call 0x6a0a46
// 0040f195  6a01                 push 1
// 0040f197  53                   push ebx
// 0040f198  8bcf                 mov ecx, edi
// 0040f19a  e88d1a2900           call 0x6a0c2c
// 0040f19f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f1a3  ff15143f8000         call dword ptr [0x803f14]
// 0040f1a9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040f1ad  5f                   pop edi
// 0040f1ae  8bc6                 mov eax, esi
// 0040f1b0  5e                   pop esi
// 0040f1b1  5d                   pop ebp
// 0040f1b2  5b                   pop ebx
// 0040f1b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f1ba  83c420               add esp, 0x20
// 0040f1bd  c3                   ret 

typedef unsigned long DWORD;

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Rect {
    int left, top, right, bottom;
    Rect(int, int, int, int);
};

inline Rect::Rect(int l, int t, int r, int b)
    : left(l), top(t), right(r), bottom(b)
{
}

struct Window;
struct View;
struct Unknown;
struct String;

extern const char windowClass[];
extern const char windowType[];
extern const char viewType[];

extern const char *(__thiscall *stringData)(const String *);
extern void (__thiscall *stringAssign)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *) throw();

struct String {
    void *data;
    __declspec(dllimport) ~String() throw();
};

struct UnknownTable {
    long (__stdcall *query)(Unknown *, const void *, void **);
    unsigned long (__stdcall *addRef)(Unknown *);
    unsigned long (__stdcall *release)(Unknown *);
};

struct Unknown {
    UnknownTable *table;
};

struct WindowTable {
    void *unused[81];
    int (__thiscall *create)(Window *, const char *, const char *,
                            DWORD, const Rect &, Window *, unsigned int,
                            void *, void *);
};

struct Window {
    WindowTable *table;
    unsigned char storage[228];

    Window();
    void modifyStyle(DWORD, DWORD, unsigned int);
    void getClientRect(Rect *);
    void setWindowPos(Window *, int, int, int, int, unsigned int);
    void showWindow(int, int);
};

struct View {
    unsigned char storage[708];
    Unknown *object;
    unsigned long reserved;
    String text;

    void navigate(const char *, DWORD, const char *, const char *,
                  void *, DWORD);
};

extern Window *__stdcall createView(Window *, const char *, const char *,
                                     void *, DWORD, unsigned int,
                                     unsigned int);
extern View *__cdecl castView(Window *, int, const void *, const void *, int);

View *__cdecl makeView(Rect rect, Window *parent, String text, Unknown *object)
{
    Window *window = new Window;

    int (__thiscall *createProc)(Window *, const char *, const char *,
                                 DWORD, const Rect &, Window *, unsigned int,
                                 void *, void *) = window->table->create;
    createProc(window, 0, 0, 0x00cf0000, Rect(0, 0, 0, 0),
               parent, 0, 0, 0);
    window->modifyStyle(0x200, 0x80, 0);

    View *view = castView(
        createView(window, windowClass, 0, 0, 0x50800000, 0, 0xe900),
        0, windowType, viewType, 0);

    if (view->object != object) {
        if (object)
            object->table->addRef(object);
        if (view->object)
            view->object->table->release(view->object);
        view->object = object;
    }

    const char *value = stringData(&text);
    stringAssign(&view->text, value);
    view->navigate(value, 0, 0, 0, 0, 0);

    parent->getClientRect(&rect);
    window->setWindowPos(0, rect.left, rect.top,
                         rect.right - rect.left,
                         rect.bottom - rect.top, 4);
    window->showWindow(0, 1);
    return view;
}
