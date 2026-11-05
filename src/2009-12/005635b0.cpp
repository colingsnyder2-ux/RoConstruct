// from server: 100% by nuck16
// roc 2009-12 005635b0  unit: RBX::Network::InterpolatingPhysicsReceiver::Nugget::UHistory::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005635b0
//
// 005635b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005635b4  83f804               cmp eax, 4
// 005635b7  7409                 je 0x5635c2
// 005635b9  8944240c             mov dword ptr [esp + 0xc], eax
// 005635bd  e96ef8ffff           jmp 0x562e30
// 005635c2  8b442408             mov eax, dword ptr [esp + 8]
// 005635c6  32c9                 xor cl, cl
// 005635c8  c7004007b200         mov dword ptr [eax], 0xb20740
// 005635ce  884804               mov byte ptr [eax + 4], cl
// 005635d1  884805               mov byte ptr [eax + 5], cl
// 005635d4  c3                   ret 

// 0xb20740 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b20740[];
extern "C" void func_562e30(int, int, int);

void func_005635b0(int a, int b, int c)
{
    if (c != 4)
    {
        func_562e30(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b20740;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
