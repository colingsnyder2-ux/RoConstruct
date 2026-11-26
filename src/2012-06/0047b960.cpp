// from server: 100% by Xemicl
// roc 2012-06 0047b960  unit: CPublishAsPlaceDialog  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047b960
//
// 0047b960  6aff                 push -1
// 0047b962  685211aa00           push 0xaa1152
// 0047b967  64a100000000         mov eax, dword ptr fs:[0]
// 0047b96d  50                   push eax
// 0047b96e  64892500000000       mov dword ptr fs:[0], esp
// 0047b975  83ec08               sub esp, 8
// 0047b978  56                   push esi
// 0047b979  8d442408             lea eax, [esp + 8]
// 0047b97d  50                   push eax
// 0047b97e  8bf1                 mov esi, ecx
// 0047b980  e84b99f9ff           call 0x4152d0
// 0047b985  68f0c0b500           push 0xb5c0f0
// 0047b98a  50                   push eax
// 0047b98b  8d4c2410             lea ecx, [esp + 0x10]
// 0047b98f  51                   push ecx
// 0047b990  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0047b998  e803a0f9ff           call 0x4159a0
// 0047b99d  83c410               add esp, 0x10
// 0047b9a0  8b542420             mov edx, dword ptr [esp + 0x20]
// 0047b9a4  52                   push edx
// 0047b9a5  8bc8                 mov ecx, eax
// 0047b9a7  c644241801           mov byte ptr [esp + 0x18], 1
// 0047b9ac  ff159847b200         call dword ptr [0xb24798]
// 0047b9b2  50                   push eax
// 0047b9b3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047b9b7  50                   push eax
// 0047b9b8  8bce                 mov ecx, esi
// 0047b9ba  e8110d0200           call 0x49c6d0
// 0047b9bf  8d4c2404             lea ecx, [esp + 4]
// 0047b9c3  ff15d047b200         call dword ptr [0xb247d0]
// 0047b9c9  8d4c2408             lea ecx, [esp + 8]
// 0047b9cd  ff15d047b200         call dword ptr [0xb247d0]
// 0047b9d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047b9d7  c70634bfb500         mov dword ptr [esi], 0xb5bf34
// 0047b9dd  c7467408bfb500       mov dword ptr [esi + 0x74], 0xb5bf08
// 0047b9e4  8bc6                 mov eax, esi
// 0047b9e6  5e                   pop esi
// 0047b9e7  64890d00000000       mov dword ptr fs:[0], ecx
// 0047b9ee  83c414               add esp, 0x14
// 0047b9f1  c20800               ret 8
// copied from an identical function in another client (function ??0CPublishAsPlaceDialog@ns_ROCX000012@@QAE@HH@Z)

namespace ns_ROCX000012 {
// from server: 100% by EspClaude
// from server: 88% by colin
// roc 2008-06 0044f5c0  unit: CPublishAsPlaceDialog  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f5c0
//
// 0044f5c0  6aff                 push -1
// 0044f5c2  68d2167c00           push 0x7c16d2
// 0044f5c7  64a100000000         mov eax, dword ptr fs:[0]
// 0044f5cd  50                   push eax
// 0044f5ce  64892500000000       mov dword ptr fs:[0], esp
// 0044f5d5  83ec08               sub esp, 8
// 0044f5d8  56                   push esi
// 0044f5d9  8d442408             lea eax, [esp + 8]
// 0044f5dd  50                   push eax
// 0044f5de  8bf1                 mov esi, ecx
// 0044f5e0  e8eb6afbff           call 0x4060d0
// 0044f5e5  6838778100           push 0x817738
// 0044f5ea  50                   push eax
// 0044f5eb  8d4c2410             lea ecx, [esp + 0x10]
// 0044f5ef  51                   push ecx
// 0044f5f0  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0044f5f8  e863ebfbff           call 0x40e160
// 0044f5fd  83c410               add esp, 0x10
// 0044f600  8b542420             mov edx, dword ptr [esp + 0x20]
// 0044f604  52                   push edx
// 0044f605  8bc8                 mov ecx, eax
// 0044f607  c644241801           mov byte ptr [esp + 0x18], 1
// 0044f60c  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f612  50                   push eax
// 0044f613  8b442424             mov eax, dword ptr [esp + 0x24]
// 0044f617  50                   push eax
// 0044f618  8bce                 mov ecx, esi
// 0044f61a  e861080100           call 0x45fe80
// 0044f61f  8d4c2404             lea ecx, [esp + 4]
// 0044f623  ff15143f8000         call dword ptr [0x803f14]
// 0044f629  8d4c2408             lea ecx, [esp + 8]
// 0044f62d  ff15143f8000         call dword ptr [0x803f14]
// 0044f633  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044f637  c7067c758100         mov dword ptr [esi], 0x81757c
// 0044f63d  c7467450758100       mov dword ptr [esi + 0x74], 0x817550
// 0044f644  8bc6                 mov eax, esi
// 0044f646  5e                   pop esi
// 0044f647  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f64e  83c414               add esp, 0x14
// 0044f651  c20800               ret 8

// from server: 87% by king_originala
// roc 2008-06 0044f5c0  unit: CPublishAsPlaceDialog  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f5c0
//
// 0044f5c0  6aff                 push -1
// 0044f5c2  68d2167c00           push 0x7c16d2
// 0044f5c7  64a100000000         mov eax, dword ptr fs:[0]
// 0044f5cd  50                   push eax
// 0044f5ce  64892500000000       mov dword ptr fs:[0], esp
// 0044f5d5  83ec08               sub esp, 8
// 0044f5d8  56                   push esi
// 0044f5d9  8d442408             lea eax, [esp + 8]
// 0044f5dd  50                   push eax
// 0044f5de  8bf1                 mov esi, ecx
// 0044f5e0  e8eb6afbff           call 0x4060d0
// 0044f5e5  6838778100           push 0x817738
// 0044f5ea  50                   push eax
// 0044f5eb  8d4c2410             lea ecx, [esp + 0x10]
// 0044f5ef  51                   push ecx
// 0044f5f0  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0044f5f8  e863ebfbff           call 0x40e160
// 0044f5fd  83c410               add esp, 0x10
// 0044f600  8b542420             mov edx, dword ptr [esp + 0x20]
// 0044f604  52                   push edx
// 0044f605  8bc8                 mov ecx, eax
// 0044f607  c644241801           mov byte ptr [esp + 0x18], 1
// 0044f60c  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f612  50                   push eax
// 0044f613  8b442424             mov eax, dword ptr [esp + 0x24]
// 0044f617  50                   push eax
// 0044f618  8bce                 mov ecx, esi
// 0044f61a  e861080100           call 0x45fe80
// 0044f61f  8d4c2404             lea ecx, [esp + 4]
// 0044f623  ff15143f8000         call dword ptr [0x803f14]
// 0044f629  8d4c2408             lea ecx, [esp + 8]
// 0044f62d  ff15143f8000         call dword ptr [0x803f14]
// 0044f633  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044f637  c7067c758100         mov dword ptr [esi], 0x81757c
// 0044f63d  c7467450758100       mov dword ptr [esi + 0x74], 0x817550
// 0044f644  8bc6                 mov eax, esi
// 0044f646  5e                   pop esi
// 0044f647  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f64e  83c414               add esp, 0x14
// 0044f651  c20800               ret 8

struct Text;
typedef void (__thiscall *TextDestructor)(Text *);
typedef int (__thiscall *TextValue)(const Text *);

extern TextDestructor destroy_text;
extern TextValue text_value;

struct Text
{
    void *data;
    __declspec(dllimport) ~Text() throw();
    int value() const;
};

inline int Text::value() const
{
    return text_value(this);
}

struct TextB
{
    void *data;
    __declspec(dllimport) ~TextB() throw();
    int value() const { return text_value((const Text*)this); }
};

extern Text __cdecl make_text();
extern TextB __cdecl append_text(const Text &, const char *);

struct Primary
{
    virtual void primary();
    char padding[112];
};

struct Secondary
{
    virtual void secondary();
};

struct Base : Primary, Secondary
{
    Base(int, int, int);
};

struct CPublishAsPlaceDialog : Base
{
    CPublishAsPlaceDialog(int, int);
    virtual void primary();
    virtual void secondary();
};

CPublishAsPlaceDialog::CPublishAsPlaceDialog(int first, int second)
    : Base(first, append_text(make_text(), "/UI/Save.aspx?type=Model").value(), second)
{
}
}