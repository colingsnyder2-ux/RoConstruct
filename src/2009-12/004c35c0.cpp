// from server: 100% by nuck16
// roc 2009-12 004c35c0  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c35c0
//
// 004c35c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c35c4  83f804               cmp eax, 4
// 004c35c7  7409                 je 0x4c35d2
// 004c35c9  8944240c             mov dword ptr [esp + 0xc], eax
// 004c35cd  e98eedffff           jmp 0x4c2360
// 004c35d2  8b442408             mov eax, dword ptr [esp + 8]
// 004c35d6  32c9                 xor cl, cl
// 004c35d8  c700080cb100         mov dword ptr [eax], 0xb10c08
// 004c35de  884804               mov byte ptr [eax + 4], cl
// 004c35e1  884805               mov byte ptr [eax + 5], cl
// 004c35e4  c3                   ret 

// 0xb10c08 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b10c08[];
extern "C" void func_4c2360(int, int, int);

void func_004c35c0(int a, int b, int c)
{
    if (c != 4)
    {
        func_4c2360(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b10c08;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
