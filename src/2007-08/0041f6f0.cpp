// from server: 100% by Intel
// from server: 94% by EspClaude
// roc 2007-08 0041f6f0  unit: CSettingsExplorer  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041f6f0
//
// 0041f6f0  56                   push esi
// 0041f6f1  8bf1                 mov esi, ecx
// 0041f6f3  8b8608010000         mov eax, dword ptr [esi + 0x108]
// 0041f6f9  85c0                 test eax, eax
// 0041f6fb  7552                 jne 0x41f74f
// 0041f6fd  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0041f703  6a00                 push 0
// 0041f705  68544e8800           push 0x884e54
// 0041f70a  684c1f8800           push 0x881f4c
// 0041f70f  6a00                 push 0
// 0041f711  50                   push eax
// 0041f712  e81f162100           call 0x630d36
// 0041f717  83c414               add esp, 0x14
// 0041f71a  85c0                 test eax, eax
// 0041f71c  742f                 je 0x41f74d
// 0041f71e  8bb6bc000000         mov esi, dword ptr [esi + 0xbc]
// 0041f724  6a00                 push 0
// 0041f726  68544e8800           push 0x884e54
// 0041f72b  684c1f8800           push 0x881f4c
// 0041f730  6a00                 push 0
// 0041f732  56                   push esi
// 0041f733  e8fe152100           call 0x630d36
// 0041f738  83c414               add esp, 0x14
// 0041f73b  8bc8                 mov ecx, eax
// 0041f73d  e8aeffffff           call 0x41f6f0
// 0041f742  85c0                 test eax, eax
// 0041f744  7407                 je 0x41f74d
// 0041f746  b801000000           mov eax, 1
// 0041f74b  5e                   pop esi
// 0041f74c  c3                   ret 
// 0041f74d  33c0                 xor eax, eax
// 0041f74f  5e                   pop esi
// 0041f750  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 004225b0  unit: CSettingsExplorer  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004225b0
//
// 004225b0  56                   push esi
// 004225b1  8bf1                 mov esi, ecx
// 004225b3  8b8650010000         mov eax, dword ptr [esi + 0x150]
// 004225b9  85c0                 test eax, eax
// 004225bb  7552                 jne 0x42260f
// 004225bd  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 004225c3  6a00                 push 0
// 004225c5  684cac9200           push 0x92ac4c
// 004225ca  687c909200           push 0x92907c
// 004225cf  6a00                 push 0
// 004225d1  50                   push eax
// 004225d2  e8eff12700           call 0x6a17c6
// 004225d7  83c414               add esp, 0x14
// 004225da  85c0                 test eax, eax
// 004225dc  742f                 je 0x42260d
// 004225de  8bb604010000         mov esi, dword ptr [esi + 0x104]
// 004225e4  6a00                 push 0
// 004225e6  684cac9200           push 0x92ac4c
// 004225eb  687c909200           push 0x92907c
// 004225f0  6a00                 push 0
// 004225f2  56                   push esi
// 004225f3  e8cef12700           call 0x6a17c6
// 004225f8  83c414               add esp, 0x14
// 004225fb  8bc8                 mov ecx, eax
// 004225fd  e8aeffffff           call 0x4225b0
// 00422602  85c0                 test eax, eax
// 00422604  7407                 je 0x42260d
// 00422606  b801000000           mov eax, 1
// 0042260b  5e                   pop esi
// 0042260c  c3                   ret 
// 0042260d  33c0                 xor eax, eax
// 0042260f  5e                   pop esi
// 00422610  c3                   ret 

#include <intrin.h>
// from server: 89% by colin
// from server: 86% by colin
extern char sourceType;
extern char targetType;

struct S {
    char padding0[0xbc];
    void* parent;
    char padding1[0x48];
    int value;

    int f();
};

extern "C" S* __cdecl runtimeCast(void*, int, void*, void*, int);

int S::f()
{
    int state=value;
    _ReadWriteBarrier();
    if (state)
        return state;

    void* current=parent;
    _ReadWriteBarrier();
    S* cast = runtimeCast(current, 0, &sourceType, &targetType, 0);
    if (cast) {
        void* p = parent;
        if (runtimeCast(p, 0, &sourceType, &targetType, 0)->f())
            return 1;
    }

    return 0;
}
