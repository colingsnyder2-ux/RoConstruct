// from server: 100% by Yeetserama
// roc 2007-08 00434ad0  unit: CObjectBrowser  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434ad0
//
// 00434ad0  6aff                 push -1
// 00434ad2  6849d87300           push 0x73d849
// 00434ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00434add  50                   push eax
// 00434ade  51                   push ecx
// 00434adf  56                   push esi
// 00434ae0  57                   push edi
// 00434ae1  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434ae6  33c4                 xor eax, esp
// 00434ae8  50                   push eax
// 00434ae9  8d442410             lea eax, [esp + 0x10]
// 00434aed  64a300000000         mov dword ptr fs:[0], eax
// 00434af3  8bf1                 mov esi, ecx
// 00434af5  8d4c240c             lea ecx, [esp + 0xc]
// 00434af9  ff15acdd7700         call dword ptr [0x77ddac]
// 00434aff  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00434b03  8b4704               mov eax, dword ptr [edi + 4]
// 00434b06  8d4804               lea ecx, [eax + 4]
// 00434b09  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00434b11  ff15a8e67700         call dword ptr [0x77e6a8]
// 00434b17  50                   push eax
// 00434b18  8d442410             lea eax, [esp + 0x10]
// 00434b1c  685ca07800           push 0x78a05c
// 00434b21  50                   push eax
// 00434b22  ff1594dd7700         call dword ptr [0x77dd94]
// 00434b28  83c40c               add esp, 0xc
// 00434b2b  8d4c240c             lea ecx, [esp + 0xc]
// 00434b2f  ff1598dd7700         call dword ptr [0x77dd98]
// 00434b35  680200ffff           push 0xffff0002
// 00434b3a  680000ffff           push 0xffff0000
// 00434b3f  6a00                 push 0
// 00434b41  6a00                 push 0
// 00434b43  6a00                 push 0
// 00434b45  6a09                 push 9
// 00434b47  6a09                 push 9
// 00434b49  50                   push eax
// 00434b4a  6a23                 push 0x23
// 00434b4c  8bce                 mov ecx, esi
// 00434b4e  e8e1ba1f00           call 0x630634
// 00434b53  57                   push edi
// 00434b54  6a00                 push 0
// 00434b56  6a00                 push 0
// 00434b58  6a00                 push 0
// 00434b5a  6a00                 push 0
// 00434b5c  6a00                 push 0
// 00434b5e  6a04                 push 4
// 00434b60  50                   push eax
// 00434b61  8bce                 mov ecx, esi
// 00434b63  e8d2ba1f00           call 0x63063a
// 00434b68  8d4c240c             lea ecx, [esp + 0xc]
// 00434b6c  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00434b72  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00434b76  64890d00000000       mov dword ptr fs:[0], ecx
// 00434b7d  59                   pop ecx
// 00434b7e  5f                   pop edi
// 00434b7f  5e                   pop esi
// 00434b80  83c410               add esp, 0x10
// 00434b83  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000d_00433d00@CObjectBrowser@ns_ROCX00000d@@QAEXPAUItem@2@@Z)

namespace ns_ROCX00000d {
struct Text
{
    unsigned int value;
    Text();
    __declspec(dllimport) ~Text() throw();
    const char* data() const;
};

extern void (__thiscall* text_construct)(Text*);
extern void (__thiscall* text_destroy)(Text*);
extern const char* (__thiscall* text_data)(const Text*);
extern const char* (__thiscall* string_data)(const void*);
extern void (__cdecl* text_format)(Text*, const char*, ...);
extern const char format_string[];

inline Text::Text()
{
    text_construct(this);
}

inline const char* Text::data() const
{
    return text_data(this);
}

struct Item
{
    unsigned int reserved;
    char* object;
};

struct CObjectBrowser
{
    void* create(int, const char*, int, int, int, int, int,
                 unsigned int, unsigned int);
    void attach(void*, int, int, int, int, int, int, Item*);
    void fn_ROCX00000d_00433d00(Item*);
};

void CObjectBrowser::fn_ROCX00000d_00433d00(Item* item)
{
    Text text;
    char* obj = item->object;
    text_format(&text, format_string, string_data(obj + 4));
    void* control = create(35, text.data(), 9, 9, 0, 0, 0,
                           0xffff0000U, 0xffff0002U);
    attach(control, 4, 0, 0, 0, 0, 0, item);
}
}
