// from server: 100% by nuck16
// roc 2009-12 004ff680  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ff680
//
// 004ff680  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ff684  83f804               cmp eax, 4
// 004ff687  7409                 je 0x4ff692
// 004ff689  8944240c             mov dword ptr [esp + 0xc], eax
// 004ff68d  e9cecdffff           jmp 0x4fc460
// 004ff692  8b442408             mov eax, dword ptr [esp + 8]
// 004ff696  32c9                 xor cl, cl
// 004ff698  c7006035b100         mov dword ptr [eax], 0xb13560
// 004ff69e  884804               mov byte ptr [eax + 4], cl
// 004ff6a1  884805               mov byte ptr [eax + 5], cl
// 004ff6a4  c3                   ret 

// 0xb13560 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b13560[];
extern "C" void func_4fc460(int, int, int);

void func_004ff680(int a, int b, int c)
{
    if (c != 4)
    {
        func_4fc460(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b13560;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
