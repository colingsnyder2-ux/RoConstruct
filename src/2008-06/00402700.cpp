// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 00402700  unit: VCWorkspace::?$CComObject  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402700
//
// 00402700  8b442404             mov eax, dword ptr [esp + 4]
// 00402704  834020ff             add dword ptr [eax + 0x20], -1
// 00402708  56                   push esi
// 00402709  8b7020               mov esi, dword ptr [eax + 0x20]
// 0040270c  7510                 jne 0x40271e
// 0040270e  85c0                 test eax, eax
// 00402710  740c                 je 0x40271e
// 00402712  8d4810               lea ecx, [eax + 0x10]
// 00402715  8b01                 mov eax, dword ptr [ecx]
// 00402717  8b5014               mov edx, dword ptr [eax + 0x14]
// 0040271a  6a01                 push 1
// 0040271c  ffd2                 call edx
// 0040271e  8bc6                 mov eax, esi
// 00402720  5e                   pop esi
// 00402721  c20400               ret 4

struct Interface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void destroy(unsigned int);
    unsigned char padding[12];
};

struct Object
{
    unsigned char padding[16];
    Interface interfacePart;
    unsigned long references;
};

unsigned long __stdcall release(Object* object)
{
    unsigned long& count = object->references;
    unsigned long result = --count;
    if (result == 0 && object != 0)
        object->interfacePart.destroy(1);
    return result;
}
