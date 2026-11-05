// from server: 100% by nuck16
// roc 2009-12 00464320  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00464320
//
// 00464320  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00464324  83f804               cmp eax, 4
// 00464327  7409                 je 0x464332
// 00464329  8944240c             mov dword ptr [esp + 0xc], eax
// 0046432d  e9eeddffff           jmp 0x462120
// 00464332  8b442408             mov eax, dword ptr [esp + 8]
// 00464336  32c9                 xor cl, cl
// 00464338  c70018aab000         mov dword ptr [eax], 0xb0aa18
// 0046433e  884804               mov byte ptr [eax + 4], cl
// 00464341  884805               mov byte ptr [eax + 5], cl
// 00464344  c3                   ret 

// 0xb0aa18 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b0aa18[];
extern "C" void func_462120(int, int, int);

void func_00464320(int a, int b, int c)
{
    if (c != 4)
    {
        func_462120(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b0aa18;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
