// from server: 100% by EspClaude
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
#include <stdio.h>
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef long png_fixed_point;
typedef struct png_struct_def {
    char pad[0x68];
    png_uint_32 mode;
    char pad2[0x15c - 0x6c];
    float gamma;
} png_struct;
typedef struct png_info_struct {
    png_uint_32 width, height, valid;
} png_info;
typedef png_struct* png_structp;
typedef png_info* png_infop;
#define PNG_HAVE_IHDR 0x01
#define PNG_HAVE_PLTE 0x02
#define PNG_HAVE_IDAT 0x04
#define PNG_INFO_gAMA 0x0001
#define PNG_INFO_sRGB 0x0800
#define PNG_OUT_OF_RANGE(value, ideal, delta) \
        ( (value) < (ideal)-(delta) || (value) > (ideal)+(delta) )
void png_error(png_structp png_ptr, const char* msg);
void png_warning(png_structp png_ptr, const char* msg);
int png_crc_finish(png_structp png_ptr, png_uint_32 skip);
void png_read_data(png_structp png_ptr, png_byte* data, png_uint_32 length);
void png_calculate_crc(png_structp png_ptr, png_byte* ptr, png_uint_32 length);
void png_crc_read(png_structp png_ptr, png_byte* buf, png_uint_32 length)
{
   png_read_data(png_ptr, buf, length);
   png_calculate_crc(png_ptr, buf, length);
}
void png_set_gAMA(png_structp png_ptr, png_infop info_ptr, double file_gamma);
void png_set_gAMA_fixed(png_structp png_ptr, png_infop info_ptr, png_fixed_point int_gamma);
png_uint_32 png_get_uint_32(png_byte* buf)
{
   png_uint_32 i = ((png_uint_32)(*buf) << 24) +
      ((png_uint_32)(*(buf + 1)) << 16) +
      ((png_uint_32)(*(buf + 2)) << 8) +
      (png_uint_32)(*(buf + 3));
   return (i);
}
void
png_handle_gAMA(png_structp png_ptr, png_infop info_ptr, png_uint_32 length)
{
   png_fixed_point igamma;
   float file_gamma;
   png_byte buf[4];

   if (!(png_ptr->mode & PNG_HAVE_IHDR))
      png_error(png_ptr, "Missing IHDR before gAMA");
   else if (png_ptr->mode & PNG_HAVE_IDAT)
   {
      png_warning(png_ptr, "Invalid gAMA after IDAT");
      png_crc_finish(png_ptr, length);
      return;
   }
   else if (png_ptr->mode & PNG_HAVE_PLTE)
      png_warning(png_ptr, "Out of place gAMA chunk");

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_gAMA)
      && !(info_ptr->valid & PNG_INFO_sRGB)
      )
   {
      png_warning(png_ptr, "Duplicate gAMA chunk");
      png_crc_finish(png_ptr, length);
      return;
   }

   if (length != 4)
   {
      png_warning(png_ptr, "Incorrect gAMA chunk length");
      png_crc_finish(png_ptr, length);
      return;
   }

   png_crc_read(png_ptr, buf, 4);
   if (png_crc_finish(png_ptr, 0))
      return;

   igamma = (png_fixed_point)png_get_uint_32(buf);
   if (igamma == 0)
      {
         png_warning(png_ptr,
           "Ignoring gAMA chunk with gamma=0");
         return;
      }

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_sRGB))
      if (PNG_OUT_OF_RANGE(igamma, 45500L, 500))
      {
         png_warning(png_ptr,
           "Ignoring incorrect gAMA value when sRGB is also present");
         fprintf(stderr, "gamma = (%d/100000)\n", (int)igamma);
         return;
      }

   file_gamma = (float)igamma / (float)100000.0;
   png_ptr->gamma = file_gamma;
   png_set_gAMA(png_ptr, info_ptr, file_gamma);
   png_set_gAMA_fixed(png_ptr, info_ptr, igamma);
}
