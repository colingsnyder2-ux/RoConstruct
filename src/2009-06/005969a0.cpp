// from server: 100% by EspClaude
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
/* libpng 1.2.31 pngrutil.c png_handle_sCAL (self-contained: exe png_struct offsets) */
#include <stdlib.h>
typedef unsigned long png_uint_32;
typedef unsigned int png_size_t;
typedef unsigned char png_byte;
typedef png_byte* png_bytep;
typedef char* png_charp;
typedef const char* png_const_charp;
typedef struct png_struct_def {
   char pad0[0x68];
   png_uint_32 mode;
   char pad1[0x288 - 0x6c];
   png_charp chunkdata;
} png_struct;
typedef png_struct* png_structp;
typedef struct png_info_struct {
   png_uint_32 width;
   png_uint_32 height;
   png_uint_32 valid;
} png_info;
typedef png_info* png_infop;
#define PNG_HAVE_IHDR 0x01
#define PNG_HAVE_IDAT 0x04
#define PNG_INFO_sCAL 0x4000

void png_error(png_structp png_ptr, png_const_charp error_message);
void png_warning(png_structp png_ptr, png_const_charp warning_message);
void* png_malloc_warn(png_structp png_ptr, png_uint_32 size);
void png_free(png_structp png_ptr, void* ptr);
void png_read_data(png_structp png_ptr, png_bytep data, png_size_t length);
void png_calculate_crc(png_structp png_ptr, png_bytep ptr, png_size_t length);
int png_crc_finish(png_structp png_ptr, png_uint_32 skip);
void png_set_sCAL(png_structp png_ptr, png_infop info_ptr, int unit, double width, double height);
#define png_strtod(p,a,b) strtod(a,b)

void /* PRIVATE */
png_crc_read(png_structp png_ptr, png_bytep buf, png_size_t length)
{
   if(png_ptr == NULL) return;
   png_read_data(png_ptr, buf, length);
   png_calculate_crc(png_ptr, buf, length);
}

void /* PRIVATE */
png_handle_sCAL(png_structp png_ptr, png_infop info_ptr, png_uint_32 length)
{
   png_charp ep;
   double width, height;
   png_charp vp;
   png_size_t slength;

   if (!(png_ptr->mode & PNG_HAVE_IHDR))
      png_error(png_ptr, "Missing IHDR before sCAL");
   else if (png_ptr->mode & PNG_HAVE_IDAT)
   {
      png_warning(png_ptr, "Invalid sCAL after IDAT");
      png_crc_finish(png_ptr, length);
      return;
   }
   else if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_sCAL))
   {
      png_warning(png_ptr, "Duplicate sCAL chunk");
      png_crc_finish(png_ptr, length);
      return;
   }

   png_ptr->chunkdata = (png_charp)png_malloc_warn(png_ptr, length + 1);
   if (png_ptr->chunkdata == NULL)
   {
      png_warning(png_ptr, "Out of memory while processing sCAL chunk");
      return;
   }
   slength = (png_size_t)length;
   png_crc_read(png_ptr, (png_bytep)png_ptr->chunkdata, slength);

   if (png_crc_finish(png_ptr, 0))
   {
      png_free(png_ptr, png_ptr->chunkdata);
      png_ptr->chunkdata = NULL;
      return;
   }

   png_ptr->chunkdata[slength] = 0x00; /* null terminate the last string */

   ep = png_ptr->chunkdata + 1;        /* skip unit byte */

   width = png_strtod(png_ptr, ep, &vp);
   if (*vp)
   {
      png_warning(png_ptr, "malformed width string in sCAL chunk");
      return;
   }

   for (ep = png_ptr->chunkdata; *ep; ep++)
      /* empty loop */ ;
   ep++;

   if (png_ptr->chunkdata + slength < ep)
   {
      png_warning(png_ptr, "Truncated sCAL chunk");
      png_free(png_ptr, png_ptr->chunkdata);
      png_ptr->chunkdata = NULL;
      return;
   }

   height = png_strtod(png_ptr, ep, &vp);
   if (*vp)
   {
      png_warning(png_ptr, "malformed height string in sCAL chunk");
      return;
   }

   if (png_ptr->chunkdata + slength < ep
      || width <= 0. || height <= 0.
      )
   {
      png_warning(png_ptr, "Invalid sCAL data");
      png_free(png_ptr, png_ptr->chunkdata);
      png_ptr->chunkdata = NULL;
      return;
   }

   png_set_sCAL(png_ptr, info_ptr, png_ptr->chunkdata[0], width, height);

   png_free(png_ptr, png_ptr->chunkdata);
   png_ptr->chunkdata = NULL;
}
