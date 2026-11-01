// from server: 100% by tester
struct PartInstance {
    void setShouldRender(int);
};

extern void __fastcall shouldRenderSetDirty(void*);

void PartInstance::setShouldRender(int)
{
    *(char*)((char*)this + 0x398) = 1;
    *(char*)((char*)this + 0x141) = 1;
    *(char*)((char*)this + 0x3b1) = 1;
    shouldRenderSetDirty((char*)this + 0x1cc);
}
