// roc 2012-06 0091ec50  unit: RBX::MotorJoint  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091ec50
//
// 0091ec50  56                   push esi
// 0091ec51  8b742410             mov esi, dword ptr [esp + 0x10]
// 0091ec55  33c9                 xor ecx, ecx
// 0091ec57  b8c9f80000           mov eax, 0xf8c9
// 0091ec5c  85f6                 test esi, esi
// 0091ec5e  7633                 jbe 0x91ec93
// 0091ec60  8b542408             mov edx, dword ptr [esp + 8]
// 0091ec64  53                   push ebx
// 0091ec65  55                   push ebp
// 0091ec66  57                   push edi
// 0091ec67  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0091ec6b  eb03                 jmp 0x91ec70
// 0091ec6d  8d4900               lea ecx, [ecx]
// 0091ec70  8b2a                 mov ebp, dword ptr [edx]
// 0091ec72  0fb61c39             movzx ebx, byte ptr [ecx + edi]
// 0091ec76  0fafe8               imul ebp, eax
// 0091ec79  69c0b7c60500         imul eax, eax, 0x5c6b7
// 0091ec7f  03dd                 add ebx, ebp
// 0091ec81  41                   inc ecx
// 0091ec82  891a                 mov dword ptr [edx], ebx
// 0091ec84  3bce                 cmp ecx, esi
// 0091ec86  72e8                 jb 0x91ec70
// 0091ec88  8122ffffff7f         and dword ptr [edx], 0x7fffffff
// 0091ec8e  5f                   pop edi
// 0091ec8f  5d                   pop ebp
// 0091ec90  5b                   pop ebx
// 0091ec91  5e                   pop esi
// 0091ec92  c3                   ret 
// 0091ec93  8b442408             mov eax, dword ptr [esp + 8]
// 0091ec97  8120ffffff7f         and dword ptr [eax], 0x7fffffff
// 0091ec9d  5e                   pop esi
// 0091ec9e  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00669f10@@YAXPAIPBEI@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void func_00669f10(unsigned int* hash, const unsigned char* data, unsigned int length)
{
    unsigned int a = 63689;
    for (unsigned int i = 0; i < length; ++i)
    {
        *hash = *hash * a + data[i];
        a *= 378551;
    }
    *hash &= 0x7fffffff;
}