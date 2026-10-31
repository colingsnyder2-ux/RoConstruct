// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0067da50  unit: Ogre::RbxEntity  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067da50
//
// 0067da50  8b442404             mov eax, dword ptr [esp + 4]
// 0067da54  8d542404             lea edx, [esp + 4]
// 0067da58  52                   push edx
// 0067da59  81c1d8000000         add ecx, 0xd8
// 0067da5f  89442408             mov dword ptr [esp + 8], eax
// 0067da63  e83839daff           call 0x4213a0
// 0067da68  c20400               ret 4

struct Listener {
    void invoke(void* const& value);
};

struct S {
    char padding[0xD8];
    Listener listener;
    void f(void* value);
};

void S::f(void* value)
{
    void* copy = value;
    listener.invoke(copy);
}
