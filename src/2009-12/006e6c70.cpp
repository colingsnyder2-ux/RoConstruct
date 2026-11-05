// from server: 100% by nuck16
// roc 2009-12 006e6c70  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e6c70
//
// 006e6c70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006e6c74  83f804               cmp eax, 4
// 006e6c77  7409                 je 0x6e6c82
// 006e6c79  8944240c             mov dword ptr [esp + 0xc], eax
// 006e6c7d  e93efeffff           jmp 0x6e6ac0
// 006e6c82  8b442408             mov eax, dword ptr [esp + 8]
// 006e6c86  32c9                 xor cl, cl
// 006e6c88  c7009038b400         mov dword ptr [eax], 0xb43890
// 006e6c8e  884804               mov byte ptr [eax + 4], cl
// 006e6c91  884805               mov byte ptr [eax + 5], cl
// 006e6c94  c3                   ret 

// 0xb43890 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b43890[];
extern "C" void func_6e6ac0(int, int, int);

void func_006e6c70(int a, int b, int c)
{
    if (c != 4)
    {
        func_6e6ac0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b43890;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
