// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b9890  unit: RBX::Soundscape::SoundChannel  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b9890
//
// 005b9890  51                   push ecx
// 005b9891  56                   push esi
// 005b9892  8bf1                 mov esi, ecx
// 005b9894  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005b989a  85c0                 test eax, eax
// 005b989c  7479                 je 0x5b9917
// 005b989e  8d4c2404             lea ecx, [esp + 4]
// 005b98a2  51                   push ecx
// 005b98a3  50                   push eax
// 005b98a4  e85d630e00           call 0x69fc06
// 005b98a9  50                   push eax
// 005b98aa  e8f1eeffff           call 0x5b87a0
// 005b98af  8a8665010000         mov al, byte ptr [esi + 0x165]
// 005b98b5  83c404               add esp, 4
// 005b98b8  d0e8                 shr al, 1
// 005b98ba  2401                 and al, 1
// 005b98bc  ba00000000           mov edx, 0
// 005b98c1  0f95c2               setne dl
// 005b98c4  33c9                 xor ecx, ecx
// 005b98c6  42                   inc edx
// 005b98c7  0b542404             or edx, dword ptr [esp + 4]
// 005b98cb  84c0                 test al, al
// 005b98cd  0f95c1               setne cl
// 005b98d0  83c1fd               add ecx, -3
// 005b98d3  23d1                 and edx, ecx
// 005b98d5  8bc2                 mov eax, edx
// 005b98d7  8b963c010000         mov edx, dword ptr [esi + 0x13c]
// 005b98dd  50                   push eax
// 005b98de  52                   push edx
// 005b98df  8944240c             mov dword ptr [esp + 0xc], eax
// 005b98e3  e818630e00           call 0x69fc00
// 005b98e8  50                   push eax
// 005b98e9  e8b2eeffff           call 0x5b87a0
// 005b98ee  0fb68665010000       movzx eax, byte ptr [esi + 0x165]
// 005b98f5  8b963c010000         mov edx, dword ptr [esi + 0x13c]
// 005b98fb  2402                 and al, 2
// 005b98fd  0fb6c8               movzx ecx, al
// 005b9900  83c404               add esp, 4
// 005b9903  f7d9                 neg ecx
// 005b9905  1bc9                 sbb ecx, ecx
// 005b9907  51                   push ecx
// 005b9908  52                   push edx
// 005b9909  e8ec620e00           call 0x69fbfa
// 005b990e  50                   push eax
// 005b990f  e88ceeffff           call 0x5b87a0
// 005b9914  83c404               add esp, 4
// 005b9917  5e                   pop esi
// 005b9918  59                   pop ecx
// 005b9919  c3                   ret 

extern "C" int __stdcall getMode(void *, unsigned int *);
extern "C" int __stdcall setMode(void *, unsigned int);
extern "C" int __stdcall setLoopCount(void *, int);
void __cdecl checkResult(int);

struct SoundChannel {
    unsigned char padding0[0x13c];
    void *handle;
    unsigned char padding1[0x25];
    unsigned char unused : 1;
    unsigned char looping : 1;
    unsigned char remaining : 6;

    void updateLooping();
};

void SoundChannel::updateLooping()
{
    if (handle) {
        unsigned int mode;
        checkResult(getMode(handle, &mode));
        mode |= looping ? 2 : 1;
        mode &= looping ? -2 : -3;
        checkResult(setMode(handle, mode));
        checkResult(setLoopCount(handle, looping ? -1 : 0));
    }
}
