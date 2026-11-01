// from server: 100% by colin
struct CXTPPropertyGridNativeXPTheme {
    CXTPPropertyGridNativeXPTheme* construct(int);
    char pad[0x40];
};

extern "C" void __stdcall sub_006f91b0(int);

CXTPPropertyGridNativeXPTheme* CXTPPropertyGridNativeXPTheme::construct(int arg)
{
    sub_006f91b0(arg);
    *(void**)this = (void*)0x7dc964;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 4) = 1;
    return this;
}
