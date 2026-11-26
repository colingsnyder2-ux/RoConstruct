// from server: 100% by Xemicl
// roc 2012-06 00435470  unit: CPatchedControlComboBox  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435470
//
// 00435470  53                   push ebx
// 00435471  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00435475  56                   push esi
// 00435476  53                   push ebx
// 00435477  8bf1                 mov esi, ecx
// 00435479  e862955500           call 0x98e9e0
// 0043547e  85c0                 test eax, eax
// 00435480  7505                 jne 0x435487
// 00435482  5e                   pop esi
// 00435483  5b                   pop ebx
// 00435484  c20400               ret 4
// 00435487  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 0043548d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00435490  8b35043cb200         mov esi, dword ptr [0xb23c04]
// 00435496  57                   push edi
// 00435497  6a00                 push 0
// 00435499  6a00                 push 0
// 0043549b  688b010000           push 0x18b
// 004354a0  50                   push eax
// 004354a1  ffd6                 call esi
// 004354a3  6a00                 push 0
// 004354a5  8bf8                 mov edi, eax
// 004354a7  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 004354ad  8b4820               mov ecx, dword ptr [eax + 0x20]
// 004354b0  6a00                 push 0
// 004354b2  688b010000           push 0x18b
// 004354b7  51                   push ecx
// 004354b8  ffd6                 call esi
// 004354ba  33d2                 xor edx, edx
// 004354bc  3bf8                 cmp edi, eax
// 004354be  0f94c2               sete dl
// 004354c1  5f                   pop edi
// 004354c2  5e                   pop esi
// 004354c3  5b                   pop ebx
// 004354c4  8bc2                 mov eax, edx
// 004354c6  c20400               ret 4
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