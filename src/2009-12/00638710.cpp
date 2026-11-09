// from server: 100% by nuck16
// roc 2009-12 00638710  unit: RBX::VSelection::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00638710
//
// 00638710  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00638714  83f804               cmp eax, 4
// 00638717  7409                 je 0x638722
// 00638719  8944240c             mov dword ptr [esp + 0xc], eax
// 0063871d  e9defcffff           jmp 0x638400
// 00638722  8b442408             mov eax, dword ptr [esp + 8]
// 00638726  32c9                 xor cl, cl
// 00638728  c70078a4b200         mov dword ptr [eax], 0xb2a478
// 0063872e  884804               mov byte ptr [eax + 4], cl
// 00638731  884805               mov byte ptr [eax + 5], cl
// 00638734  c3                   ret 

// 0xb2a478 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b2a478[];
extern "C" void func_638400(int, int, int);

void func_00638710(int a, int b, int c)
{
    if (c != 4)
    {
        func_638400(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b2a478;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
