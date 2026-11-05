// roc 2012-06 009f3230  unit: CXTPPropertyGridItemConstraints  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f3230
//
// 009f3230  53                   push ebx
// 009f3231  56                   push esi
// 009f3232  57                   push edi
// 009f3233  8bf9                 mov edi, ecx
// 009f3235  33f6                 xor esi, esi
// 009f3237  397728               cmp dword ptr [edi + 0x28], esi
// 009f323a  7e17                 jle 0x9f3253
// 009f323c  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 009f3240  56                   push esi
// 009f3241  8bcf                 mov ecx, edi
// 009f3243  e838d60300           call 0xa30880
// 009f3248  3b5824               cmp ebx, dword ptr [eax + 0x24]
// 009f324b  740f                 je 0x9f325c
// 009f324d  46                   inc esi
// 009f324e  3b7728               cmp esi, dword ptr [edi + 0x28]
// 009f3251  7ced                 jl 0x9f3240
// 009f3253  5f                   pop edi
// 009f3254  5e                   pop esi
// 009f3255  83c8ff               or eax, 0xffffffff
// 009f3258  5b                   pop ebx
// 009f3259  c20400               ret 4
// 009f325c  5f                   pop edi
// 009f325d  8bc6                 mov eax, esi
// 009f325f  5e                   pop esi
// 009f3260  5b                   pop ebx
// 009f3261  c20400               ret 4
// copied from an identical function in another client (function ?FindItem@CXTPPropertyGridItemConstraints@ns_ROCX000008@@QAEHH@Z)

namespace ns_ROCX000008 {
struct CXTPPropertyGridItemConstraints {
    char pad0[0x28];
    int m_count;
    int GetItemIndex(int index);
    int FindItem(int value);
};

int CXTPPropertyGridItemConstraints::FindItem(int value)
{
    int i = 0;
    if (m_count > 0) {
        do {
            int item = GetItemIndex(i);
            if (value == *(int*)((char*)item + 0x24))
                return i;
            ++i;
        } while (i < m_count);
    }
    return -1;
}
}
