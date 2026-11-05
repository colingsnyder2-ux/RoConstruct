// from server: 100% by EspClaude
// from server: 85% by king_originala
// roc 2008-06 005aae90  unit: RBX::VScriptContext::?$FactoryProduct  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005aae90
//
// 005aae90  8b15e46b9700         mov edx, dword ptr [0x976be4]
// 005aae96  56                   push esi
// 005aae97  8bf1                 mov esi, ecx
// 005aae99  8b4610               mov eax, dword ptr [esi + 0x10]
// 005aae9c  2b460c               sub eax, dword ptr [esi + 0xc]
// 005aae9f  57                   push edi
// 005aaea0  c1f802               sar eax, 2
// 005aaea3  f6c201               test dl, 1
// 005aaea6  7520                 jne 0x5aaec8
// 005aaea8  8b3d801a9700         mov edi, dword ptr [0x971a80]
// 005aaeae  83ca01               or edx, 1
// 005aaeb1  8bcf                 mov ecx, edi
// 005aaeb3  47                   inc edi
// 005aaeb4  8915e46b9700         mov dword ptr [0x976be4], edx
// 005aaeba  890de06b9700         mov dword ptr [0x976be0], ecx
// 005aaec0  893d801a9700         mov dword ptr [0x971a80], edi
// 005aaec6  eb06                 jmp 0x5aaece
// 005aaec8  8b0de06b9700         mov ecx, dword ptr [0x976be0]
// 005aaece  3bc1                 cmp eax, ecx
// 005aaed0  7647                 jbe 0x5aaf19
// 005aaed2  f6c201               test dl, 1
// 005aaed5  751c                 jne 0x5aaef3
// 005aaed7  a1801a9700           mov eax, dword ptr [0x971a80]
// 005aaedc  83ca01               or edx, 1
// 005aaedf  8bc8                 mov ecx, eax
// 005aaee1  40                   inc eax
// 005aaee2  8915e46b9700         mov dword ptr [0x976be4], edx
// 005aaee8  890de06b9700         mov dword ptr [0x976be0], ecx
// 005aaeee  a3801a9700           mov dword ptr [0x971a80], eax
// 005aaef3  8b4610               mov eax, dword ptr [esi + 0x10]
// 005aaef6  2b460c               sub eax, dword ptr [esi + 0xc]
// 005aaef9  8bf9                 mov edi, ecx
// 005aaefb  c1f802               sar eax, 2
// 005aaefe  3bc8                 cmp ecx, eax
// 005aaf00  7206                 jb 0x5aaf08
// 005aaf02  ff1590288000         call dword ptr [0x802890]
// 005aaf08  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005aaf0b  833cb900             cmp dword ptr [ecx + edi*4], 0
// 005aaf0f  7408                 je 0x5aaf19
// 005aaf11  5f                   pop edi
// 005aaf12  b801000000           mov eax, 1
// 005aaf17  5e                   pop esi
// 005aaf18  c3                   ret 
// 005aaf19  5f                   pop edi
// 005aaf1a  33c0                 xor eax, eax
// 005aaf1c  5e                   pop esi
// 005aaf1d  c3                   ret 

extern unsigned int counter;
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Key
{
    static unsigned int index();
};

inline unsigned int Key::index()
{
    static unsigned int value = counter++;
    return value;
}

struct S
{
    unsigned int padding[3];
    void** begin;
    void** end;

    int f();
    unsigned int size() const { return static_cast<unsigned int>(end - begin); }
    void* const& at(unsigned int i) const { if (i >= size()) invalid_parameter_noinfo(); return begin[i]; }
};

int S::f()
{
    if (size() > Key::index())
    {
        if (at(Key::index()) != 0)
            return 1;
    }
    return 0;
}
