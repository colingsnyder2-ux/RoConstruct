// from server: 100% by Xemicl
// roc 2012-06 0049e090  unit: Scintilla::CScintillaView  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049e090
//
// 0049e090  8b442404             mov eax, dword ptr [esp + 4]
// 0049e094  53                   push ebx
// 0049e095  55                   push ebp
// 0049e096  56                   push esi
// 0049e097  57                   push edi
// 0049e098  8bf1                 mov esi, ecx
// 0049e09a  50                   push eax
// 0049e09b  b90417d700           mov ecx, 0xd71704
// 0049e0a0  ff157847b200         call dword ptr [0xb24778]
// 0049e0a6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0049e0aa  51                   push ecx
// 0049e0ab  b90817d700           mov ecx, 0xd71708
// 0049e0b0  ff157847b200         call dword ptr [0xb24778]
// 0049e0b6  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0049e0ba  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0049e0be  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0049e0c2  8b542418             mov edx, dword ptr [esp + 0x18]
// 0049e0c6  55                   push ebp
// 0049e0c7  893d0c17d700         mov dword ptr [0xd7170c], edi
// 0049e0cd  891d1417d700         mov dword ptr [0xd71714], ebx
// 0049e0d3  89151017d700         mov dword ptr [0xd71710], edx
// 0049e0d9  892d1817d700         mov dword ptr [0xd71718], ebp
// 0049e0df  8b06                 mov eax, dword ptr [esi]
// 0049e0e1  53                   push ebx
// 0049e0e2  57                   push edi
// 0049e0e3  b90417d700           mov ecx, 0xd71704
// 0049e0e8  89442420             mov dword ptr [esp + 0x20], eax
// 0049e0ec  ff159847b200         call dword ptr [0xb24798]
// 0049e0f2  8b542420             mov edx, dword ptr [esp + 0x20]
// 0049e0f6  50                   push eax
// 0049e0f7  8b82c0010000         mov eax, dword ptr [edx + 0x1c0]
// 0049e0fd  8bce                 mov ecx, esi
// 0049e0ff  ffd0                 call eax
// 0049e101  85c0                 test eax, eax
// 0049e103  7561                 jne 0x49e166
// 0049e105  8b0e                 mov ecx, dword ptr [esi]
// 0049e107  8b542418             mov edx, dword ptr [esp + 0x18]
// 0049e10b  55                   push ebp
// 0049e10c  53                   push ebx
// 0049e10d  57                   push edi
// 0049e10e  894c2420             mov dword ptr [esp + 0x20], ecx
// 0049e112  52                   push edx
// 0049e113  b90417d700           mov ecx, 0xd71704
// 0049e118  ff159847b200         call dword ptr [0xb24798]
// 0049e11e  50                   push eax
// 0049e11f  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049e123  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 0049e129  8bce                 mov ecx, esi
// 0049e12b  ffd2                 call edx
// 0049e12d  85c0                 test eax, eax
// 0049e12f  0f85a4000000         jne 0x49e1d9
// 0049e135  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0049e139  8b06                 mov eax, dword ptr [esi]
// 0049e13b  6a01                 push 1
// 0049e13d  55                   push ebp
// 0049e13e  53                   push ebx
// 0049e13f  57                   push edi
// 0049e140  51                   push ecx
// 0049e141  b90417d700           mov ecx, 0xd71704
// 0049e146  89442428             mov dword ptr [esp + 0x28], eax
// 0049e14a  ff159847b200         call dword ptr [0xb24798]
// 0049e150  8b542428             mov edx, dword ptr [esp + 0x28]
// 0049e154  50                   push eax
// 0049e155  8b82a8010000         mov eax, dword ptr [edx + 0x1a8]
// 0049e15b  8bce                 mov ecx, esi
// 0049e15d  ffd0                 call eax
// 0049e15f  5f                   pop edi
// 0049e160  5e                   pop esi
// 0049e161  5d                   pop ebp
// 0049e162  5b                   pop ebx
// 0049e163  c21800               ret 0x18
// 0049e166  6a01                 push 1
// 0049e168  b90817d700           mov ecx, 0xd71708
// 0049e16d  ff159847b200         call dword ptr [0xb24798]
// 0049e173  50                   push eax
// 0049e174  8d4e58               lea ecx, [esi + 0x58]
// 0049e177  e824f4ffff           call 0x49d5a0
// 0049e17c  8b0e                 mov ecx, dword ptr [esi]
// 0049e17e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0049e182  55                   push ebp
// 0049e183  53                   push ebx
// 0049e184  57                   push edi
// 0049e185  894c2420             mov dword ptr [esp + 0x20], ecx
// 0049e189  52                   push edx
// 0049e18a  b90417d700           mov ecx, 0xd71704
// 0049e18f  ff159847b200         call dword ptr [0xb24798]
// 0049e195  50                   push eax
// 0049e196  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049e19a  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 0049e1a0  8bce                 mov ecx, esi
// 0049e1a2  ffd2                 call edx
// 0049e1a4  85c0                 test eax, eax
// 0049e1a6  7531                 jne 0x49e1d9
// 0049e1a8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0049e1ac  8b06                 mov eax, dword ptr [esi]
// 0049e1ae  6a01                 push 1
// 0049e1b0  55                   push ebp
// 0049e1b1  53                   push ebx
// 0049e1b2  57                   push edi
// 0049e1b3  51                   push ecx
// 0049e1b4  b90417d700           mov ecx, 0xd71704
// 0049e1b9  89442428             mov dword ptr [esp + 0x28], eax
// 0049e1bd  ff159847b200         call dword ptr [0xb24798]
// 0049e1c3  8b542428             mov edx, dword ptr [esp + 0x28]
// 0049e1c7  50                   push eax
// 0049e1c8  8b82a8010000         mov eax, dword ptr [edx + 0x1a8]
// 0049e1ce  8bce                 mov ecx, esi
// 0049e1d0  ffd0                 call eax
// 0049e1d2  5f                   pop edi
// 0049e1d3  5e                   pop esi
// 0049e1d4  5d                   pop ebp
// 0049e1d5  5b                   pop ebx
// 0049e1d6  c21800               ret 0x18
// 0049e1d9  8b16                 mov edx, dword ptr [esi]
// 0049e1db  8b82c8010000         mov eax, dword ptr [edx + 0x1c8]
// 0049e1e1  8bce                 mov ecx, esi
// 0049e1e3  ffd0                 call eax
// 0049e1e5  5f                   pop edi
// 0049e1e6  5e                   pop esi
// 0049e1e7  5d                   pop ebp
// 0049e1e8  5b                   pop ebx
// 0049e1e9  c21800               ret 0x18
// copied from an identical function in another client (function ?update@View@ns_ROCX00000e@@QAEHPBDHHHH0@Z)

namespace ns_ROCX00000e {
typedef void (__thiscall *AssignText)(void *, const char *);
typedef const char *(__thiscall *GetText)(void *);

extern AssignText assignText;
extern GetText getText;
extern char textStorage[4];
extern char otherStorage[4];
extern int savedB;
extern int savedA;
extern int savedC;
extern int savedD;

struct Control {
    void setText(const char *, int);
};

#define SLOT(n) virtual void unused##n();
#define TEN(n) SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
               SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct View {
    TEN(0)
    TEN(1)
    TEN(2)
    TEN(3)
    TEN(4)
    TEN(5)
    TEN(6)
    TEN(7)
    TEN(8)
    TEN(9)
    SLOT(100)
    SLOT(101)
    SLOT(102)
    SLOT(103)
    SLOT(104)
    SLOT(105)
    virtual int apply(const char *, int, int, int, int, int);
    virtual int check(const char *, int, int, int, int);
    SLOT(108)
    SLOT(109)
    SLOT(110)
    SLOT(111)
    virtual int prepare(const char *, int, int, int);
    SLOT(113)
    virtual int finish();

    char padding[0x54];
    Control control;

    int update(const char *, int, int, int, int, const char *);
};

#undef TEN
#undef SLOT

int View::update(const char *text, int a, int b, int c, int d,
                 const char *other)
{
    assignText(textStorage, text);
    assignText(otherStorage, other);

    savedB = b;
    savedC = c;
    savedA = a;
    savedD = d;

    if (!prepare(getText(textStorage), b, c, d)) {
        if (!check(getText(textStorage), a, b, c, d))
            return apply(getText(textStorage), a, b, c, d, 1);
    } else {
        control.setText(getText(otherStorage), 1);
        if (!check(getText(textStorage), a, b, c, d))
            return apply(getText(textStorage), a, b, c, d, 1);
    }
    return finish();
}
}
