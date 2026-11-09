// from server: 100% by nuck16
// roc 2009-12 006e6f10  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e6f10
//
// 006e6f10  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006e6f14  83f804               cmp eax, 4
// 006e6f17  7409                 je 0x6e6f22
// 006e6f19  8944240c             mov dword ptr [esp + 0xc], eax
// 006e6f1d  e93efeffff           jmp 0x6e6d60
// 006e6f22  8b442408             mov eax, dword ptr [esp + 8]
// 006e6f26  32c9                 xor cl, cl
// 006e6f28  c700303ab400         mov dword ptr [eax], 0xb43a30
// 006e6f2e  884804               mov byte ptr [eax + 4], cl
// 006e6f31  884805               mov byte ptr [eax + 5], cl
// 006e6f34  c3                   ret 

// 0xb43a30 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b43a30[];
extern "C" void func_6e6d60(int, int, int);

void func_006e6f10(int a, int b, int c)
{
    if (c != 4)
    {
        func_6e6d60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b43a30;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
