// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0067d3d0  unit: Ogre::RbxEntity  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d3d0
//
// 0067d3d0  83ec08               sub esp, 8
// 0067d3d3  53                   push ebx
// 0067d3d4  8b99e8000000         mov ebx, dword ptr [ecx + 0xe8]
// 0067d3da  55                   push ebp
// 0067d3db  56                   push esi
// 0067d3dc  8db1d8000000         lea esi, [ecx + 0xd8]
// 0067d3e2  57                   push edi
// 0067d3e3  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0067d3e6  7606                 jbe 0x67d3ee
// 0067d3e8  ff1590288000         call dword ptr [0x802890]
// 0067d3ee  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0067d3f1  8b2e                 mov ebp, dword ptr [esi]
// 0067d3f3  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0067d3f6  7606                 jbe 0x67d3fe
// 0067d3f8  ff1590288000         call dword ptr [0x802890]
// 0067d3fe  8b06                 mov eax, dword ptr [esi]
// 0067d400  53                   push ebx
// 0067d401  55                   push ebp
// 0067d402  57                   push edi
// 0067d403  50                   push eax
// 0067d404  8d442420             lea eax, [esp + 0x20]
// 0067d408  50                   push eax
// 0067d409  8bce                 mov ecx, esi
// 0067d40b  e8b089dcff           call 0x445dc0
// 0067d410  5f                   pop edi
// 0067d411  5e                   pop esi
// 0067d412  5d                   pop ebp
// 0067d413  5b                   pop ebx
// 0067d414  83c408               add esp, 8
// 0067d417  c3                   ret 

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Iterator {
    void* owner;
    unsigned int position;
};

struct Range {
    void* owner;
    unsigned int reserved[2];
    unsigned int first;
    unsigned int last;

    Iterator erase(Iterator first, Iterator last);
};

struct S {
    unsigned char reserved[0xe8];
    unsigned int last;

    void f();
};

void S::f()
{
    Iterator finish;
    finish.position = last;

    Range* range = reinterpret_cast<Range*>(reserved + 0xd8);
    if (range->first > finish.position)
        _invalid_parameter_noinfo();

    Iterator start;
    start.position = range->first;
    finish.owner = range->owner;

    if (start.position > range->last)
        _invalid_parameter_noinfo();

    start.owner = range->owner;
    range->erase(start, finish);
}
