// from server: 100% by nuck16
// roc 2009-12 004c0bd0  unit: RBX::RbxParticleEmitter  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0bd0
//
// 004c0bd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c0bd4  83f804               cmp eax, 4
// 004c0bd7  7409                 je 0x4c0be2
// 004c0bd9  8944240c             mov dword ptr [esp + 0xc], eax
// 004c0bdd  e96ef5ffff           jmp 0x4c0150
// 004c0be2  8b442408             mov eax, dword ptr [esp + 8]
// 004c0be6  32c9                 xor cl, cl
// 004c0be8  c7000006b100         mov dword ptr [eax], 0xb10600
// 004c0bee  884804               mov byte ptr [eax + 4], cl
// 004c0bf1  884805               mov byte ptr [eax + 5], cl
// 004c0bf4  c3                   ret 

// 0xb10600 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b10600[];
extern "C" void func_4c0150(int, int, int);

void func_004c0bd0(int a, int b, int c)
{
    if (c != 4)
    {
        func_4c0150(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b10600;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
