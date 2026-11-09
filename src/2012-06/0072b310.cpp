// roc 2012-06 0072b310  unit: RBX::Workspace  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072b310
//
// 0072b310  6aff                 push -1
// 0072b312  684961ab00           push 0xab6149
// 0072b317  64a100000000         mov eax, dword ptr fs:[0]
// 0072b31d  50                   push eax
// 0072b31e  64892500000000       mov dword ptr fs:[0], esp
// 0072b325  83ec1c               sub esp, 0x1c
// 0072b328  56                   push esi
// 0072b329  8b742430             mov esi, dword ptr [esp + 0x30]
// 0072b32d  56                   push esi
// 0072b32e  e86dffffff           call 0x72b2a0
// 0072b333  56                   push esi
// 0072b334  8d44240c             lea eax, [esp + 0xc]
// 0072b338  68845aba00           push 0xba5a84
// 0072b33d  50                   push eax
// 0072b33e  ff157027b200         call dword ptr [0xb22770]
// 0072b344  83c410               add esp, 0x10
// 0072b347  50                   push eax
// 0072b348  8bce                 mov ecx, esi
// 0072b34a  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0072b352  ff155826b200         call dword ptr [0xb22658]
// 0072b358  8d4c2404             lea ecx, [esp + 4]
// 0072b35c  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0072b364  ff153c26b200         call dword ptr [0xb2263c]
// 0072b36a  6a01                 push 1
// 0072b36c  6a28                 push 0x28
// 0072b36e  8bce                 mov ecx, esi
// 0072b370  ff15f426b200         call dword ptr [0xb226f4]
// 0072b376  6a01                 push 1
// 0072b378  6a1b                 push 0x1b
// 0072b37a  8bce                 mov ecx, esi
// 0072b37c  ff15f426b200         call dword ptr [0xb226f4]
// 0072b382  6a01                 push 1
// 0072b384  6a16                 push 0x16
// 0072b386  8bce                 mov ecx, esi
// 0072b388  ff15f426b200         call dword ptr [0xb226f4]
// 0072b38e  6a01                 push 1
// 0072b390  6a11                 push 0x11
// 0072b392  8bce                 mov ecx, esi
// 0072b394  ff15f426b200         call dword ptr [0xb226f4]
// 0072b39a  6a01                 push 1
// 0072b39c  6a0c                 push 0xc
// 0072b39e  8bce                 mov ecx, esi
// 0072b3a0  ff15f426b200         call dword ptr [0xb226f4]
// 0072b3a6  6a01                 push 1
// 0072b3a8  6a03                 push 3
// 0072b3aa  8bce                 mov ecx, esi
// 0072b3ac  ff15f426b200         call dword ptr [0xb226f4]
// 0072b3b2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0072b3b6  5e                   pop esi
// 0072b3b7  64890d00000000       mov dword ptr fs:[0], ecx
// 0072b3be  83c428               add esp, 0x28
// 0072b3c1  c3                   ret 
// copied from an identical function in another client (function ?sub_5a8140@@YAXPAUString@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    char storage[28];
    ~String();
};

extern void __cdecl sub_5a80d0(String*);
extern const char prefix[];

extern String (__cdecl *addPrefix)(const char*, const String&);
extern String& (__thiscall *assignString)(String*, const String&);
extern String& (__thiscall *eraseString)(String*, unsigned int, unsigned int);
extern void (__thiscall *destroyString)(String*);

inline String::~String()
{
    destroyString(this);
}

void __cdecl sub_5a8140(String* value)
{
    sub_5a80d0(value);
    assignString(value, addPrefix(prefix, *value));
    eraseString(value, 40, 1);
    eraseString(value, 27, 1);
    eraseString(value, 22, 1);
    eraseString(value, 17, 1);
    eraseString(value, 12, 1);
    eraseString(value, 3, 1);
}