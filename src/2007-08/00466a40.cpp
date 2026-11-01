// from server: 100% by Yeetserama
// from server: 94% by colin
// roc 2007-08 00466a40  unit: CWebToolbox  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466a40
//
// 00466a40  56                   push esi
// 00466a41  8bf1                 mov esi, ecx
// 00466a43  8b8ef4000000         mov ecx, dword ptr [esi + 0xf4]
// 00466a49  85c9                 test ecx, ecx
// 00466a4b  57                   push edi
// 00466a4c  7405                 je 0x466a53
// 00466a4e  e8b1951c00           call 0x630004
// 00466a53  8bb6f8000000         mov esi, dword ptr [esi + 0xf8]
// 00466a59  85f6                 test esi, esi
// 00466a5b  7408                 je 0x466a65
// 00466a5d  8b06                 mov eax, dword ptr [esi]
// 00466a5f  8b4804               mov ecx, dword ptr [eax + 4]
// 00466a62  56                   push esi
// 00466a63  ffd1                 call ecx
// 00466a65  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00466a69  85c0                 test eax, eax
// 00466a6b  7507                 jne 0x466a74
// 00466a6d  bf03400080           mov edi, 0x80004003
// 00466a72  eb10                 jmp 0x466a84
// 00466a74  85f6                 test esi, esi
// 00466a76  8930                 mov dword ptr [eax], esi
// 00466a78  7408                 je 0x466a82
// 00466a7a  8b16                 mov edx, dword ptr [esi]
// 00466a7c  8b4204               mov eax, dword ptr [edx + 4]
// 00466a7f  56                   push esi
// 00466a80  ffd0                 call eax
// 00466a82  33ff                 xor edi, edi
// 00466a84  85f6                 test esi, esi
// 00466a86  7408                 je 0x466a90
// 00466a88  8b0e                 mov ecx, dword ptr [esi]
// 00466a8a  8b5108               mov edx, dword ptr [ecx + 8]
// 00466a8d  56                   push esi
// 00466a8e  ffd2                 call edx
// 00466a90  8bc7                 mov eax, edi
// 00466a92  5f                   pop edi
// 00466a93  5e                   pop esi
// 00466a94  c20400               ret 4

struct CWebToolbox {
    char pad[0xf4];
    void* field_f4;
    void* field_f8;
    long method(void** out);
};

extern "C" void __fastcall sub_630004(void* p);

long CWebToolbox::method(void** out) {
    if (field_f4) {
        sub_630004(field_f4);
    }
    void* p = field_f8;
    if (p) {
        (*(void (__stdcall**)(void*))((*(int**)p) + 1))(p);
    }
    long hr;
    if (out == 0) {
        hr = (long)0x80004003;
    } else {
        *out = p;
        if (p) {
            (*(void (__stdcall**)(void*))((*(int**)p) + 1))(p);
        }
        hr = 0;
    }
    if (p) {
        (*(void (__stdcall**)(void*))((*(int**)p) + 2))(p);
    }
    return hr;
}
