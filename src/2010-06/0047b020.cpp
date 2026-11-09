// from server: 100% by Yeetserama
// roc 2010-06 0047b020  unit: DxUserInput  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047b020
//
// 0047b020  6aff                 push -1
// 0047b022  68a9fe9700           push 0x97fea9
// 0047b027  64a100000000         mov eax, dword ptr fs:[0]
// 0047b02d  50                   push eax
// 0047b02e  64892500000000       mov dword ptr fs:[0], esp
// 0047b035  51                   push ecx
// 0047b036  56                   push esi
// 0047b037  57                   push edi
// 0047b038  8bf1                 mov esi, ecx
// 0047b03a  33ff                 xor edi, edi
// 0047b03c  681828a100           push 0xa12818
// 0047b041  8d4c240c             lea ecx, [esp + 0xc]
// 0047b045  897c240c             mov dword ptr [esp + 0xc], edi
// 0047b049  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 0047b04f  8d442408             lea eax, [esp + 8]
// 0047b053  897c2414             mov dword ptr [esp + 0x14], edi
// 0047b057  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0047b05b  50                   push eax
// 0047b05c  57                   push edi
// 0047b05d  8bce                 mov ecx, esi
// 0047b05f  e81cfeffff           call 0x47ae80
// 0047b064  8d4c2408             lea ecx, [esp + 8]
// 0047b068  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047b06e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047b072  8bc7                 mov eax, edi
// 0047b074  5f                   pop edi
// 0047b075  5e                   pop esi
// 0047b076  64890d00000000       mov dword ptr fs:[0], ecx
// 0047b07d  83c410               add esp, 0x10
// 0047b080  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000015_0046a440@DxUserInput@ns_ROCX000015@@QAEHH@Z)

namespace ns_ROCX000015 {
struct Text;

extern void (__thiscall *constructText)(Text *, const char *);
extern void (__thiscall *destroyText)(Text *);

struct Text {
    void *data;
    Text(const char *);
    __declspec(dllimport) ~Text() throw();
};

inline Text::Text(const char *value) : data(0)
{
    constructText(this, value);
}

struct DxUserInput {
    void helper(int, const Text *);
    int fn_ROCX000015_0046a440(int);
};

int DxUserInput::fn_ROCX000015_0046a440(int value)
{
    Text name("FileVersion");
    helper(value, &name);
    return value;
}
}
