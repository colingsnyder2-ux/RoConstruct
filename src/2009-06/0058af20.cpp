// from server: 100% by EspClaude
// roc 2009-06 0058af20  libpng 1.2.31 png_check_keyword (self-contained)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
extern "C" {
typedef unsigned char png_byte;
typedef char* png_charp;
typedef char** png_charpp;
typedef unsigned int png_size_t;
typedef unsigned long png_uint_32;
typedef void* png_voidp;
typedef struct png_struct_def png_struct;
typedef png_struct* png_structp;
__declspec(dllimport) int __cdecl _snprintf(char*, size_t, const char*, ...);
void png_warning(png_structp png_ptr, const char* message);
png_voidp png_malloc_warn(png_structp png_ptr, png_uint_32 size);
void png_free(png_structp png_ptr, png_voidp ptr);

png_size_t
png_check_keyword(png_structp png_ptr, png_charp key, png_charpp new_key)
{
   png_size_t key_len;
   png_charp kp, dp;
   int kflag;
   int kwarn=0;

   *new_key = 0;

   if (key == 0 || (key_len = strlen(key)) == 0)
   {
      png_warning(png_ptr, "zero length keyword");
      return ((png_size_t)0);
   }

   *new_key = (png_charp)png_malloc_warn(png_ptr, (png_uint_32)(key_len + 2));
   if (*new_key == 0)
   {
      png_warning(png_ptr, "Out of memory while procesing keyword");
      return ((png_size_t)0);
   }

   for (kp = key, dp = *new_key; *kp != '\0'; kp++, dp++)
   {
      if ((png_byte)*kp < 0x20 ||
         ((png_byte)*kp > 0x7E && (png_byte)*kp < 0xA1))
      {
         char msg[40];
         _snprintf(msg, 40,
           "invalid keyword character 0x%02X", (png_byte)*kp);
         png_warning(png_ptr, msg);
         *dp = ' ';
      }
      else
      {
         *dp = *kp;
      }
   }
   *dp = '\0';

   kp = *new_key + key_len - 1;
   if (*kp == ' ')
   {
      png_warning(png_ptr, "trailing spaces removed from keyword");
      while (*kp == ' ')
      {
        *(kp--) = '\0';
        key_len--;
      }
   }

   kp = *new_key;
   if (*kp == ' ')
   {
      png_warning(png_ptr, "leading spaces removed from keyword");
      while (*kp == ' ')
      {
        kp++;
        key_len--;
      }
   }

   for (kflag = 0, dp = *new_key; *kp != '\0'; kp++)
   {
      if (*kp == ' ' && kflag == 0)
      {
         *(dp++) = *kp;
         kflag = 1;
      }
      else if (*kp == ' ')
      {
         key_len--;
         kwarn=1;
      }
      else
      {
         *(dp++) = *kp;
         kflag = 0;
      }
   }
   *dp = '\0';
   if(kwarn)
      png_warning(png_ptr, "extra interior spaces removed from keyword");

   if (key_len == 0)
   {
      png_free(png_ptr, *new_key);
      *new_key=0;
      png_warning(png_ptr, "Zero length keyword");
   }

   if (key_len > 79)
   {
      png_warning(png_ptr, "keyword length must be 1 - 79 characters");
      new_key[79] = '\0';
      key_len = 79;
   }

   return (key_len);
}
}
