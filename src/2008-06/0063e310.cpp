// from server: 100% by colin
// from server: 88% by king_originala
// roc 2008-06 0063e310  unit: RBX::AnchorTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063e310
//
// 0063e310  51                   push ecx
// 0063e311  56                   push esi
// 0063e312  8bf1                 mov esi, ecx
// 0063e314  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0063e317  85c0                 test eax, eax
// 0063e319  7445                 je 0x63e360
// 0063e31b  50                   push eax
// 0063e31c  e81fbdf5ff           call 0x59a040
// 0063e321  83c404               add esp, 4
// 0063e324  84c0                 test al, al
// 0063e326  7538                 jne 0x63e360
// 0063e328  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0063e32b  50                   push eax
// 0063e32c  e8affcffff           call 0x63dfe0
// 0063e331  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0063e334  8d4c240b             lea ecx, [esp + 0xb]
// 0063e338  85c0                 test eax, eax
// 0063e33a  51                   push ecx
// 0063e33b  0f95c0               setne al
// 0063e33e  52                   push edx
// 0063e33f  88442413             mov byte ptr [esp + 0x13], al
// 0063e343  e808faffff           call 0x63dd50
// 0063e348  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063e34b  83c40c               add esp, 0xc
// 0063e34e  6a08                 push 8
// 0063e350  50                   push eax
// 0063e351  e85a24f4ff           call 0x5807b0
// 0063e356  83c404               add esp, 4
// 0063e359  8bc8                 mov ecx, eax
// 0063e35b  e8c0f4f7ff           call 0x5bd820
// 0063e360  8bc6                 mov eax, esi
// 0063e362  5e                   pop esi
// 0063e363  59                   pop ecx
// 0063e364  c20400               ret 4

struct Instance;

struct ServiceProvider {
    void action(int);
};

extern bool __cdecl check(Instance*);
extern int __cdecl state(Instance*);
extern void __cdecl update(Instance*, const bool*);
extern ServiceProvider* __cdecl func_005807b0(Instance*);

struct AnchorTool {
    char padding[24];
    Instance* provider;
    Instance* object;

    AnchorTool* apply(int);
};

AnchorTool* AnchorTool::apply(int)
{
    if (object && !check(object)) {
        Instance* objectCopy = object;
        bool enabled = state(objectCopy) != 0;
        update(object, &enabled);
        func_005807b0(provider)->action(8);
    }
    return this;
}
