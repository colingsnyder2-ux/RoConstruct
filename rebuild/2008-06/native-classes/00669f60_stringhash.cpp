// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// Function at 00669f60: ?stringHash@RBX@@YAIABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// Template instantiation with conditional pointer logic from the binary.
// The binary checks [ptr + 0x18] >= 0x10 and conditionally selects data pointer.
// Calls sub_669f10 with (out, data, len) and returns the result.

// Evidence: from context pack 00669f60, assembly shows:
//   mov eax, dword ptr [esp + 4]       ; load parameter
//   cmp dword ptr [eax + 0x18], 0x10   ; check [ptr+0x18] >= 0x10
//   mov ecx, dword ptr [eax + 0x14]   ; load [ptr+0x14]
//   jb 0x669f72                        ; if [ptr+0x18] < 0x10, jump
//   mov eax, dword ptr [eax + 4]      ; else [ptr+4]
//   add eax, 4
//   jmp 0x669f75
// 0x669f72: add eax, 4
// 0x669f75: push ecx; push eax; call sub_669f10; ret

// RBX::stringHash - template instantiation with binary-observed control flow
extern "C" int __cdecl sub_669f10(int* out, const char* data, int len);

int __cdecl stringHash(const char* p)
{
    // Evidence: binary at 00669f60 checks [p + 0x18] >= 0x10
    if (*(unsigned int*)(p + 0x18) >= 0x10) {
        // Take dereferenced pointer at [p + 4]
        int len = *(int*)(p + 0x14);
        const char* data = *(const char**)(p + 4);
        int result = 0;
        sub_669f10(&result, data, len);
        return result;
    } else {
        // Use p + 4 as data pointer
        int len = *(int*)(p + 0x14);
        const char* data = p + 4;
        int result = 0;
        sub_669f10(&result, data, len);
        return result;
    }
}
