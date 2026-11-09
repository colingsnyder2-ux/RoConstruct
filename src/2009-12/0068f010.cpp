// from server: 100% by nuck16
// roc 2009-12 0068f010  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068f010
//
// 0068f010  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068f014  83f804               cmp eax, 4
// 0068f017  7409                 je 0x68f022
// 0068f019  8944240c             mov dword ptr [esp + 0xc], eax
// 0068f01d  e90ef2ffff           jmp 0x68e230
// 0068f022  8b442408             mov eax, dword ptr [esp + 8]
// 0068f026  32c9                 xor cl, cl
// 0068f028  c700586ab300         mov dword ptr [eax], 0xb36a58
// 0068f02e  884804               mov byte ptr [eax + 4], cl
// 0068f031  884805               mov byte ptr [eax + 5], cl
// 0068f034  c3                   ret 

// 0xb36a58 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b36a58[];
extern "C" void func_68e230(int, int, int);

void func_0068f010(int a, int b, int c)
{
    if (c != 4)
    {
        func_68e230(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b36a58;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
