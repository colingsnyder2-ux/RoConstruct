// from server: 92% by atomic.potato
struct UnlockedPartByLocalCharacter
{
    UnlockedPartByLocalCharacter& f(int);
};

extern "C" void __stdcall sub_8f22f0(UnlockedPartByLocalCharacter*);
extern "C" void __stdcall sub_91f250(UnlockedPartByLocalCharacter*, int);

UnlockedPartByLocalCharacter& UnlockedPartByLocalCharacter::f(int arg)
{
    sub_8f22f0(this);
    *(int*)this = 0xbf6644;
    *(int*)((char*)this + 0x1c) = 0xbf6628;
    sub_91f250(this, arg);
    return *this;
}
