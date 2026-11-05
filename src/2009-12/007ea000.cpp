// from server: 100% by nuck16
// roc 2009-12 007ea000  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ea000
//
// 007ea000  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ea004  83f804               cmp eax, 4
// 007ea007  7409                 je 0x7ea012
// 007ea009  8944240c             mov dword ptr [esp + 0xc], eax
// 007ea00d  e92efeffff           jmp 0x7e9e40
// 007ea012  8b442408             mov eax, dword ptr [esp + 8]
// 007ea016  32c9                 xor cl, cl
// 007ea018  c7000050b600         mov dword ptr [eax], 0xb65000
// 007ea01e  884804               mov byte ptr [eax + 4], cl
// 007ea021  884805               mov byte ptr [eax + 5], cl
// 007ea024  c3                   ret 

// 0xb65000 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b65000[];
extern "C" void func_7e9e40(int, int, int);

void func_007ea000(int a, int b, int c)
{
    if (c != 4)
    {
        func_7e9e40(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b65000;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
