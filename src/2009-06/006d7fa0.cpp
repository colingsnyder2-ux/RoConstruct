// from server: 100% by EspClaude
// from server: 96% by EspClaude
// roc 2009-06 006d7fa0  unit: RBX::MultiJoint  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d7fa0
//
// 006d7fa0  55                   push ebp
// 006d7fa1  57                   push edi
// 006d7fa2  8bf9                 mov edi, ecx
// 006d7fa4  33ed                 xor ebp, ebp
// 006d7fa6  39af98000000         cmp dword ptr [edi + 0x98], ebp
// 006d7fac  7e78                 jle 0x6d8026
// 006d7fae  53                   push ebx
// 006d7faf  56                   push esi
// 006d7fb0  8d9fbc000000         lea ebx, [edi + 0xbc]
// 006d7fb6  8db7a0000000         lea esi, [edi + 0xa0]
// 006d7fbc  8d642400             lea esp, [esp]
// 006d7fc0  8b03                 mov eax, dword ptr [ebx]
// 006d7fc2  50                   push eax
// 006d7fc3  8bcf                 mov ecx, edi
// 006d7fc5  e896dcffff           call 0x6d5c60
// 006d7fca  8bc8                 mov ecx, eax
// 006d7fcc  e8cf06fdff           call 0x6a86a0
// 006d7fd1  8b0b                 mov ecx, dword ptr [ebx]
// 006d7fd3  85c9                 test ecx, ecx
// 006d7fd5  7408                 je 0x6d7fdf
// 006d7fd7  8b11                 mov edx, dword ptr [ecx]
// 006d7fd9  8b02                 mov eax, dword ptr [edx]
// 006d7fdb  6a01                 push 1
// 006d7fdd  ffd0                 call eax
// 006d7fdf  8b4efc               mov ecx, dword ptr [esi - 4]
// 006d7fe2  51                   push ecx
// 006d7fe3  8bcf                 mov ecx, edi
// 006d7fe5  e876dcffff           call 0x6d5c60
// 006d7fea  8bc8                 mov ecx, eax
// 006d7fec  e81f08fdff           call 0x6a8810
// 006d7ff1  8b16                 mov edx, dword ptr [esi]
// 006d7ff3  52                   push edx
// 006d7ff4  8bcf                 mov ecx, edi
// 006d7ff6  e865dcffff           call 0x6d5c60
// 006d7ffb  8bc8                 mov ecx, eax
// 006d7ffd  e80e08fdff           call 0x6a8810
// 006d8002  c746fc00000000       mov dword ptr [esi - 4], 0
// 006d8009  c70600000000         mov dword ptr [esi], 0
// 006d800f  c70300000000         mov dword ptr [ebx], 0
// 006d8015  45                   inc ebp
// 006d8016  83c304               add ebx, 4
// 006d8019  83c608               add esi, 8
// 006d801c  3baf98000000         cmp ebp, dword ptr [edi + 0x98]
// 006d8022  7c9c                 jl 0x6d7fc0
// 006d8024  5e                   pop esi
// 006d8025  5b                   pop ebx
// 006d8026  c7879800000000000000 mov dword ptr [edi + 0x98], 0
// 006d8030  8bcf                 mov ecx, edi
// 006d8032  5f                   pop edi
// 006d8033  5d                   pop ebp
// 006d8034  e947dcffff           jmp 0x6d5c80

// from server: 100% by king_originala
// roc 2008-06 006469e0  unit: RBX::MultiJoint  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006469e0
//
// 006469e0  55                   push ebp
// 006469e1  57                   push edi
// 006469e2  8bf9                 mov edi, ecx
// 006469e4  33ed                 xor ebp, ebp
// 006469e6  39af88000000         cmp dword ptr [edi + 0x88], ebp
// 006469ec  7e78                 jle 0x646a66
// 006469ee  53                   push ebx
// 006469ef  56                   push esi
// 006469f0  8d9fac000000         lea ebx, [edi + 0xac]
// 006469f6  8db790000000         lea esi, [edi + 0x90]
// 006469fc  8d642400             lea esp, [esp]
// 00646a00  8b03                 mov eax, dword ptr [ebx]
// 00646a02  50                   push eax
// 00646a03  8bcf                 mov ecx, edi
// 00646a05  e846eeffff           call 0x645850
// 00646a0a  8bc8                 mov ecx, eax
// 00646a0c  e8df47fbff           call 0x5fb1f0
// 00646a11  8b0b                 mov ecx, dword ptr [ebx]
// 00646a13  85c9                 test ecx, ecx
// 00646a15  7408                 je 0x646a1f
// 00646a17  8b11                 mov edx, dword ptr [ecx]
// 00646a19  8b02                 mov eax, dword ptr [edx]
// 00646a1b  6a01                 push 1
// 00646a1d  ffd0                 call eax
// 00646a1f  8b4efc               mov ecx, dword ptr [esi - 4]
// 00646a22  51                   push ecx
// 00646a23  8bcf                 mov ecx, edi
// 00646a25  e826eeffff           call 0x645850
// 00646a2a  8bc8                 mov ecx, eax
// 00646a2c  e88f49fbff           call 0x5fb3c0
// 00646a31  8b16                 mov edx, dword ptr [esi]
// 00646a33  52                   push edx
// 00646a34  8bcf                 mov ecx, edi
// 00646a36  e815eeffff           call 0x645850
// 00646a3b  8bc8                 mov ecx, eax
// 00646a3d  e87e49fbff           call 0x5fb3c0
// 00646a42  c746fc00000000       mov dword ptr [esi - 4], 0
// 00646a49  c70600000000         mov dword ptr [esi], 0
// 00646a4f  c70300000000         mov dword ptr [ebx], 0
// 00646a55  45                   inc ebp
// 00646a56  83c304               add ebx, 4
// 00646a59  83c608               add esi, 8
// 00646a5c  3baf88000000         cmp ebp, dword ptr [edi + 0x88]
// 00646a62  7c9c                 jl 0x646a00
// 00646a64  5e                   pop esi
// 00646a65  5b                   pop ebx
// 00646a66  c7878800000000000000 mov dword ptr [edi + 0x88], 0
// 00646a70  8bcf                 mov ecx, edi
// 00646a72  5f                   pop edi
// 00646a73  5d                   pop ebp
// 00646a74  e9e7edffff           jmp 0x645860

struct Kernel {
    void removeJoint();
    void release();
};

struct Joint {
    virtual ~Joint();
};

struct Pair {
    void* first;
    void* second;
};

struct MultiJoint {
    unsigned char padding[0x98];
    int count;
    Pair pairs[4];
    Joint* joints[4];

    Kernel* lookup(void*);
    void finish();
    void clear();
};

void MultiJoint::clear()
{
    for (int i = 0; i < count; ++i) {
        lookup(joints[i])->removeJoint();
        delete joints[i];
        lookup(pairs[i].first)->release();
        lookup(pairs[i].second)->release();
        pairs[i].first = 0;
        pairs[i].second = 0;
        joints[i] = 0;
    }
    count = 0;
    finish();
}
