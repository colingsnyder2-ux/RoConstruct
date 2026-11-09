// from server: 100% by nuck16
// roc 2009-12 004c0c30  unit: RBX::RbxParticleEmitter  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0c30
//
// 004c0c30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c0c34  83f804               cmp eax, 4
// 004c0c37  7409                 je 0x4c0c42
// 004c0c39  8944240c             mov dword ptr [esp + 0xc], eax
// 004c0c3d  e9eef5ffff           jmp 0x4c0230
// 004c0c42  8b442408             mov eax, dword ptr [esp + 8]
// 004c0c46  32c9                 xor cl, cl
// 004c0c48  c7006007b100         mov dword ptr [eax], 0xb10760
// 004c0c4e  884804               mov byte ptr [eax + 4], cl
// 004c0c51  884805               mov byte ptr [eax + 5], cl
// 004c0c54  c3                   ret 

// 0xb10760 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b10760[];
extern "C" void func_4c0230(int, int, int);

void func_004c0c30(int a, int b, int c)
{
    if (c != 4)
    {
        func_4c0230(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b10760;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
