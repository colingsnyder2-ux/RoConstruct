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
