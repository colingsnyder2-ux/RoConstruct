// from server: 100% by nuck16
// roc 2009-12 0053bd60  unit: G3D::VRay::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053bd60
//
// 0053bd60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0053bd64  83f804               cmp eax, 4
// 0053bd67  7409                 je 0x53bd72
// 0053bd69  8944240c             mov dword ptr [esp + 0xc], eax
// 0053bd6d  e9eebdffff           jmp 0x537b60
// 0053bd72  8b442408             mov eax, dword ptr [esp + 8]
// 0053bd76  32c9                 xor cl, cl
// 0053bd78  c70050d3b100         mov dword ptr [eax], 0xb1d350
// 0053bd7e  884804               mov byte ptr [eax + 4], cl
// 0053bd81  884805               mov byte ptr [eax + 5], cl
// 0053bd84  c3                   ret 

// 0xb1d350 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1d350[];
extern "C" void func_537b60(int, int, int);

void func_0053bd60(int a, int b, int c)
{
    if (c != 4)
    {
        func_537b60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1d350;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
