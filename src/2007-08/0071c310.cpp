// from server: 65% by colin
// roc 2007-08 0071c310  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0071c310
//
// 0071c310  f4                   hlt 
// 0071c311  ff6a0f               jmp ptr [edx + 0xf]
// 0071c314  8bc8                 mov ecx, eax
// 0071c316  e855c4f4ff           call 0x668770
// 0071c31b  50                   push eax
// 0071c31c  8bcb                 mov ecx, ebx
// 0071c31e  e89dcbf4ff           call 0x668ec0
// 0071c323  e848ccf4ff           call 0x668f70
// 0071c328  6a0f                 push 0xf
// 0071c32a  8bc8                 mov ecx, eax
// 0071c32c  e83fc4f4ff           call 0x668770
// 0071c331  50                   push eax
// 0071c332  8bcf                 mov ecx, edi
// 0071c334  e887cbf4ff           call 0x668ec0
// 0071c339  5f                   pop edi
// 0071c33a  5e                   pop esi
// 0071c33b  5d                   pop ebp
// 0071c33c  5b                   pop ebx
// 0071c33d  83c408               add esp, 8
// 0071c340  c3                   ret 

struct CXTPTabPaintManagerColorSetOffice2003 {
    void method_71C310();
};

extern "C" void* __cdecl sub_668770(int);
extern "C" void __cdecl sub_668EC0(void*, void*);
extern "C" void* __cdecl sub_668F70();

void CXTPTabPaintManagerColorSetOffice2003::method_71C310() {
    void* a = sub_668770(0);
    sub_668EC0(this, a);
    void* b = sub_668F70();
    void* c = sub_668770(0xf);
    sub_668EC0(b, c);
}
