// from server: 98% by EspClaude
// from server: 72% by colin
// roc 2007-08 005bfab0  unit: RBX::Lua::LuaArguments  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bfab0
//
// 005bfab0  83ec08               sub esp, 8
// 005bfab3  53                   push ebx
// 005bfab4  55                   push ebp
// 005bfab5  56                   push esi
// 005bfab6  57                   push edi
// 005bfab7  8bf9                 mov edi, ecx
// 005bfab9  8b4704               mov eax, dword ptr [edi + 4]
// 005bfabc  33ed                 xor ebp, ebp
// 005bfabe  85c0                 test eax, eax
// 005bfac0  745b                 je 0x5bfb1d
// 005bfac2  8b5f08               mov ebx, dword ptr [edi + 8]
// 005bfac5  2bd8                 sub ebx, eax
// 005bfac7  c1fb02               sar ebx, 2
// 005bfaca  7451                 je 0x5bfb1d
// 005bfacc  8b442420             mov eax, dword ptr [esp + 0x20]
// 005bfad0  83c004               add eax, 4
// 005bfad3  89442420             mov dword ptr [esp + 0x20], eax
// 005bfad7  8b4f04               mov ecx, dword ptr [edi + 4]
// 005bfada  8d342b               lea esi, [ebx + ebp]
// 005bfadd  d1ee                 shr esi, 1
// 005bfadf  85c9                 test ecx, ecx
// 005bfae1  740c                 je 0x5bfaef
// 005bfae3  8b4708               mov eax, dword ptr [edi + 8]
// 005bfae6  2bc1                 sub eax, ecx
// 005bfae8  c1f802               sar eax, 2
// 005bfaeb  3bf0                 cmp esi, eax
// 005bfaed  7206                 jb 0x5bfaf5
// 005bfaef  ff15d8e67700         call dword ptr [0x77e6d8]
// 005bfaf5  8b4f04               mov ecx, dword ptr [edi + 4]
// 005bfaf8  8b14b1               mov edx, dword ptr [ecx + esi*4]
// 005bfafb  8b4204               mov eax, dword ptr [edx + 4]
// 005bfafe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bfb02  83c004               add eax, 4
// 005bfb05  50                   push eax
// 005bfb06  ff1570e67700         call dword ptr [0x77e670]
// 005bfb0c  85c0                 test eax, eax
// 005bfb0e  7d04                 jge 0x5bfb14
// 005bfb10  8bde                 mov ebx, esi
// 005bfb12  eb05                 jmp 0x5bfb19
// 005bfb14  7e30                 jle 0x5bfb46
// 005bfb16  8d6e01               lea ebp, [esi + 1]
// 005bfb19  3beb                 cmp ebp, ebx
// 005bfb1b  72ba                 jb 0x5bfad7
// 005bfb1d  8b5f08               mov ebx, dword ptr [edi + 8]
// 005bfb20  395f04               cmp dword ptr [edi + 4], ebx
// 005bfb23  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005bfb27  c70600000000         mov dword ptr [esi], 0
// 005bfb2d  7606                 jbe 0x5bfb35
// 005bfb2f  ff15d8e67700         call dword ptr [0x77e6d8]
// 005bfb35  893e                 mov dword ptr [esi], edi
// 005bfb37  5f                   pop edi
// 005bfb38  895e04               mov dword ptr [esi + 4], ebx
// 005bfb3b  8bc6                 mov eax, esi
// 005bfb3d  5e                   pop esi
// 005bfb3e  5d                   pop ebp
// 005bfb3f  5b                   pop ebx
// 005bfb40  83c408               add esp, 8
// 005bfb43  c20800               ret 8
// 005bfb46  8b5f04               mov ebx, dword ptr [edi + 4]
// 005bfb49  3b5f08               cmp ebx, dword ptr [edi + 8]
// 005bfb4c  7606                 jbe 0x5bfb54
// 005bfb4e  ff15d8e67700         call dword ptr [0x77e6d8]
// 005bfb54  8d34b3               lea esi, [ebx + esi*4]
// 005bfb57  3b7708               cmp esi, dword ptr [edi + 8]
// 005bfb5a  895c2414             mov dword ptr [esp + 0x14], ebx
// 005bfb5e  7705                 ja 0x5bfb65
// 005bfb60  3b7704               cmp esi, dword ptr [edi + 4]
// 005bfb63  7306                 jae 0x5bfb6b
// 005bfb65  ff15d8e67700         call dword ptr [0x77e6d8]
// 005bfb6b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005bfb6f  8938                 mov dword ptr [eax], edi
// 005bfb71  5f                   pop edi
// 005bfb72  897004               mov dword ptr [eax + 4], esi
// 005bfb75  5e                   pop esi
// 005bfb76  5d                   pop ebp
// 005bfb77  5b                   pop ebx
// 005bfb78  83c408               add esp, 8
// 005bfb7b  c20800               ret 8

struct LuaArguments {
    char pad0[4];
    int* begin;
    int* end;
    int find(int* out, const char* key) const;
};

struct String {
    __declspec(dllimport) int compare(const String&) const;
};
extern "C" __declspec(dllimport) void __cdecl invalid_parameter_noinfo();

int LuaArguments::find(int* out, const char* key) const {
    unsigned lo = 0;
    unsigned hi;
    if (begin != 0) {
        hi = (unsigned)(end - begin);
        if (hi != 0) {
            const char* k = key + 4;
            do {
                unsigned mid = (lo + hi) >> 1;
                unsigned sz = begin == 0 ? 0 : (unsigned)(end - begin);
                if (mid >= sz)
                    invalid_parameter_noinfo();
                int* elem = begin + mid;
                int* s = (int*)elem[0];
                const char* p = (const char*)(s[1] + 4);
                int r = ((const String*)k)->compare(*(const String*)p);
                if (r < 0)
                    hi = mid;
                else if (r > 0)
                    lo = mid + 1;
                else {
                    int* b = begin;
                    if (b > end)
                        invalid_parameter_noinfo();
                    int* it = b + mid;
                    struct { const void* cont; int* volatile ptr; } tmp;
                    tmp.ptr = b;
                    if (it > end || it < begin)
                        invalid_parameter_noinfo();
                    out[0] = (int)this;
                    out[1] = (int)it;
                    return (int)out;
                }
            } while (lo < hi);
        }
    }
    int* e = end;
    out[0] = 0;
    if (begin > e)
        invalid_parameter_noinfo();
    out[0] = (int)this;
    out[1] = (int)e;
    return (int)out;
}
