// from server: 100% by nuck16
// roc 2009-12 0074ba90  unit: RBX::GroundStage  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074ba90
//
// 0074ba90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074ba94  83f804               cmp eax, 4
// 0074ba97  7409                 je 0x74baa2
// 0074ba99  8944240c             mov dword ptr [esp + 0xc], eax
// 0074ba9d  e95efdffff           jmp 0x74b800
// 0074baa2  8b442408             mov eax, dword ptr [esp + 8]
// 0074baa6  32c9                 xor cl, cl
// 0074baa8  c7005086b500         mov dword ptr [eax], 0xb58650
// 0074baae  884804               mov byte ptr [eax + 4], cl
// 0074bab1  884805               mov byte ptr [eax + 5], cl
// 0074bab4  c3                   ret 

// 0xb58650 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b58650[];
extern "C" void func_74b800(int, int, int);

void func_0074ba90(int a, int b, int c)
{
    if (c != 4)
    {
        func_74b800(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b58650;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
