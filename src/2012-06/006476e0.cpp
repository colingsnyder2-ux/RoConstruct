// from server: 100% by Xemicl
// roc 2012-06 006476e0  unit: seg_00640000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006476e0
//
// 006476e0  57                   push edi
// 006476e1  8b7c2408             mov edi, dword ptr [esp + 8]
// 006476e5  85ff                 test edi, edi
// 006476e7  742d                 je 0x647716
// 006476e9  8b4754               mov eax, dword ptr [edi + 0x54]
// 006476ec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006476f0  56                   push esi
// 006476f1  8b742414             mov esi, dword ptr [esp + 0x14]
// 006476f5  50                   push eax
// 006476f6  56                   push esi
// 006476f7  6a01                 push 1
// 006476f9  51                   push ecx
// 006476fa  ff154429b200         call dword ptr [0xb22944]
// 00647700  83c410               add esp, 0x10
// 00647703  3bc6                 cmp eax, esi
// 00647705  5e                   pop esi
// 00647706  740e                 je 0x647716
// 00647708  685c64b800           push 0xb8645c
// 0064770d  57                   push edi
// 0064770e  e89d6a0000           call 0x64e1b0
// 00647713  83c408               add esp, 8
// 00647716  5f                   pop edi
// 00647717  c3                   ret 
// copied from an identical function in another client (function _png_default_write_data)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>
extern "C" {
struct png_struct_def { char pad[0x54]; void* io_ptr; };
typedef png_struct_def* png_structp;
void png_error(png_structp, const char*);
void png_default_write_data(png_structp png_ptr, unsigned char* data, size_t length)
{
   size_t check;
   if (png_ptr == NULL) return;
   check = fwrite(data, 1, length, (FILE*)(png_ptr->io_ptr));
   if (check != length)
      png_error(png_ptr, "Write Error");
}
}