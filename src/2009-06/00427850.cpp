// from server: 100% by EspClaude
// roc 2009-06 00427850  unit: CPatchedControlComboBox  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427850
//
// 00427850  53                   push ebx
// 00427851  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00427855  56                   push esi
// 00427856  53                   push ebx
// 00427857  8bf1                 mov esi, ecx
// 00427859  e8723b2f00           call 0x71b3d0
// 0042785e  85c0                 test eax, eax
// 00427860  7505                 jne 0x427867
// 00427862  5e                   pop esi
// 00427863  5b                   pop ebx
// 00427864  c20400               ret 4
// 00427867  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 0042786d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00427870  8b3590ee8900         mov esi, dword ptr [0x89ee90]
// 00427876  57                   push edi
// 00427877  6a00                 push 0
// 00427879  6a00                 push 0
// 0042787b  688b010000           push 0x18b
// 00427880  50                   push eax
// 00427881  ffd6                 call esi
// 00427883  6a00                 push 0
// 00427885  8bf8                 mov edi, eax
// 00427887  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 0042788d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00427890  6a00                 push 0
// 00427892  688b010000           push 0x18b
// 00427897  51                   push ecx
// 00427898  ffd6                 call esi
// 0042789a  33d2                 xor edx, edx
// 0042789c  3bf8                 cmp edi, eax
// 0042789e  0f94c2               sete dl
// 004278a1  5f                   pop edi
// 004278a2  5e                   pop esi
// 004278a3  5b                   pop ebx
// 004278a4  8bc2                 mov eax, edx
// 004278a6  c20400               ret 4
// copied from an identical function in another client (function ?equal@S@@QAEHPAU1@@Z)

// from server: 91% by colin
// from server: 89% by king_originala
// roc 2008-06 0042eac0  unit: CPatchedControlComboBox  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042eac0
//
// 0042eac0  53                   push ebx
// 0042eac1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0042eac5  56                   push esi
// 0042eac6  53                   push ebx
// 0042eac7  8bf1                 mov esi, ecx
// 0042eac9  e872832700           call 0x6a6e40
// 0042eace  85c0                 test eax, eax
// 0042ead0  7505                 jne 0x42ead7
// 0042ead2  5e                   pop esi
// 0042ead3  5b                   pop ebx
// 0042ead4  c20400               ret 4
// 0042ead7  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 0042eadd  8b4020               mov eax, dword ptr [eax + 0x20]
// 0042eae0  8b35142e8000         mov esi, dword ptr [0x802e14]
// 0042eae6  57                   push edi
// 0042eae7  6a00                 push 0
// 0042eae9  6a00                 push 0
// 0042eaeb  688b010000           push 0x18b
// 0042eaf0  50                   push eax
// 0042eaf1  ffd6                 call esi
// 0042eaf3  6a00                 push 0
// 0042eaf5  8bf8                 mov edi, eax
// 0042eaf7  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 0042eafd  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0042eb00  6a00                 push 0
// 0042eb02  688b010000           push 0x18b
// 0042eb07  51                   push ecx
// 0042eb08  ffd6                 call esi
// 0042eb0a  33d2                 xor edx, edx
// 0042eb0c  3bf8                 cmp edi, eax
// 0042eb0e  0f94c2               sete dl
// 0042eb11  5f                   pop edi
// 0042eb12  5e                   pop esi
// 0042eb13  5b                   pop ebx
// 0042eb14  8bc2                 mov eax, edx
// 0042eb16  c20400               ret 4
#include <intrin.h>

struct WindowData
{
    char padding[0x20];
    void* handle;
};

typedef long (__stdcall *MessageFunction)(void*, unsigned int, unsigned int, long);
extern "C" MessageFunction SendMessageA;

struct S
{
    char padding[0x178];
    WindowData* window;

    int baseEqual(S* other);
    int equal(S* other);
};

int S::equal(S* other)
{
    if (!baseEqual(other))
        return 0;

    void* handle = window->handle;
    MessageFunction send = SendMessageA;
    long count = send(handle, 0x18B, 0, 0);
    WindowData* otherWindow = other->window;
    return count == send(otherWindow->handle, 0x18B, 0, 0);
}