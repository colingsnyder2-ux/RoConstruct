// roc 2009-12 0046b190  unit: Scintilla::CScintillaView  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046b190
//
// 0046b190  8b442404             mov eax, dword ptr [esp + 4]
// 0046b194  53                   push ebx
// 0046b195  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0046b199  56                   push esi
// 0046b19a  57                   push edi
// 0046b19b  6a01                 push 1
// 0046b19d  8d7958               lea edi, [ecx + 0x58]
// 0046b1a0  53                   push ebx
// 0046b1a1  50                   push eax
// 0046b1a2  8bcf                 mov ecx, edi
// 0046b1a4  e857f0ffff           call 0x46a200
// 0046b1a9  8bf0                 mov esi, eax
// 0046b1ab  83feff               cmp esi, -1
// 0046b1ae  7413                 je 0x46b1c3
// 0046b1b0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0046b1b3  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0046b1b6  6a01                 push 1
// 0046b1b8  51                   push ecx
// 0046b1b9  52                   push edx
// 0046b1ba  8bcf                 mov ecx, edi
// 0046b1bc  e80ff1ffff           call 0x46a2d0
// 0046b1c1  8bc6                 mov eax, esi
// 0046b1c3  5f                   pop edi
// 0046b1c4  5e                   pop esi
// 0046b1c5  5b                   pop ebx
// 0046b1c6  c20800               ret 8
// copied from an identical function in another client (function ?SomeMethod@CScintillaView@ns_ROCX00002c@@QAEHHH@Z)

namespace ns_ROCX00002c {
struct CScintillaView {
    char pad[0x58];
    int field_58;
    int InsertText(int pos, int length, const char* text);
    int ReplaceSel(int pos, int length, const char* text);
    int SomeMethod(int a, int b);
};

int CScintillaView::SomeMethod(int a, int b) {
    int* self = (int*)((char*)this + 0x58);
    int result = ((CScintillaView*)self)->InsertText(a, b, (const char*)1);
    if (result != -1) {
        ((CScintillaView*)self)->ReplaceSel(*(int*)(b + 0xc), *(int*)(b + 0x10), (const char*)1);
    }
    return result;
}
}
