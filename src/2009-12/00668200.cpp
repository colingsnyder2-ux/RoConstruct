// from server: 100% by nuck16
// roc 2009-12 00668200  unit: RBX::DataModel::LegacyLock::Implementation::UEvents::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00668200
//
// 00668200  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00668204  83f804               cmp eax, 4
// 00668207  7409                 je 0x668212
// 00668209  8944240c             mov dword ptr [esp + 0xc], eax
// 0066820d  e93edcffff           jmp 0x665e50
// 00668212  8b442408             mov eax, dword ptr [esp + 8]
// 00668216  32c9                 xor cl, cl
// 00668218  c7006c34b300         mov dword ptr [eax], 0xb3346c
// 0066821e  884804               mov byte ptr [eax + 4], cl
// 00668221  884805               mov byte ptr [eax + 5], cl
// 00668224  c3                   ret 

// 0xb3346c is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b3346c[];
extern "C" void func_665e50(int, int, int);

void func_00668200(int a, int b, int c)
{
    if (c != 4)
    {
        func_665e50(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b3346c;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
