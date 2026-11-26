// from server: 100% by Xemicl
// roc 2012-06 0064de10  unit: seg_00640000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064de10
//
// 0064de10  57                   push edi
// 0064de11  8b7c2408             mov edi, dword ptr [esp + 8]
// 0064de15  85ff                 test edi, edi
// 0064de17  742d                 je 0x64de46
// 0064de19  8b4754               mov eax, dword ptr [edi + 0x54]
// 0064de1c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064de20  56                   push esi
// 0064de21  8b742414             mov esi, dword ptr [esp + 0x14]
// 0064de25  50                   push eax
// 0064de26  56                   push esi
// 0064de27  6a01                 push 1
// 0064de29  51                   push ecx
// 0064de2a  ff153029b200         call dword ptr [0xb22930]
// 0064de30  83c410               add esp, 0x10
// 0064de33  3bc6                 cmp eax, esi
// 0064de35  5e                   pop esi
// 0064de36  740e                 je 0x64de46
// 0064de38  68f06ab800           push 0xb86af0
// 0064de3d  57                   push edi
// 0064de3e  e86d030000           call 0x64e1b0
// 0064de43  83c408               add esp, 8
// 0064de46  5f                   pop edi
// 0064de47  c3                   ret 
// copied from an identical function in another client (function _png_default_read_data)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>
extern "C" {
struct png_struct_def { char pad[0x54]; void* io_ptr; };
typedef png_struct_def* png_structp;
void png_error(png_structp, const char*);
void png_default_read_data(png_structp png_ptr, unsigned char* data, size_t length)
{
   size_t check;
   if (png_ptr == NULL) return;
   check = fread(data, 1, length, (FILE*)(png_ptr->io_ptr));
   if (check != length)
      png_error(png_ptr, "Read Error");
}
}