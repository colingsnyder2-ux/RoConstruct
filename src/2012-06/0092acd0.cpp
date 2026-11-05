// from server: 96% by colin
struct PolyPair {
    char pad[0x20];
};

struct FaceFacePair : PolyPair {
    void* allocateClone();
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* FaceFacePair::allocateClone()
{
    FaceFacePair* p = (FaceFacePair*)operator_new(0x20);
    if (p != 0)
    {
        *(void**)p = (void*)0xbfdb74;
        *(int*)((char*)p + 4) = *(int*)((char*)this + 4);
        *(int*)((char*)p + 8) = *(int*)((char*)this + 8);
        *(int*)((char*)p + 0xc) = *(int*)((char*)this + 0xc);
        *(int*)((char*)p + 0x10) = *(int*)((char*)this + 0x10);
        *(int*)((char*)p + 0x14) = *(int*)((char*)this + 0x14);
        *(void**)p = (void*)0xbfdc44;
        *(int*)((char*)p + 0x18) = *(int*)((char*)this + 0x18);
        *(int*)((char*)p + 0x1c) = *(int*)((char*)this + 0x1c);
    }
    return p;
}
