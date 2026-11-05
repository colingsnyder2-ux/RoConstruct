// from server: 100% by nuck16
// roc 2009-12 006977d0  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006977d0
//
// 006977d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006977d4  83f804               cmp eax, 4
// 006977d7  7409                 je 0x6977e2
// 006977d9  8944240c             mov dword ptr [esp + 0xc], eax
// 006977dd  e9aeebffff           jmp 0x696390
// 006977e2  8b442408             mov eax, dword ptr [esp + 8]
// 006977e6  32c9                 xor cl, cl
// 006977e8  c700088ab300         mov dword ptr [eax], 0xb38a08
// 006977ee  884804               mov byte ptr [eax + 4], cl
// 006977f1  884805               mov byte ptr [eax + 5], cl
// 006977f4  c3                   ret 

// 0xb38a08 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38a08[];
extern "C" void func_696390(int, int, int);

void func_006977d0(int a, int b, int c)
{
    if (c != 4)
    {
        func_696390(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38a08;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
