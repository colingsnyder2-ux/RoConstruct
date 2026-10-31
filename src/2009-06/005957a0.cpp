// from server: 100% by EspClaude
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
#include <stdio.h>
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef long png_fixed_point;
typedef struct png_struct_def {
    char pad[0x68];
    png_uint_32 mode;
    char pad2[0x15c - 0x6c];
    float gamma;
    char pad3[0x234 - 0x160];
    png_fixed_point int_gamma;
} png_struct;
typedef struct png_info_struct {
    png_uint_32 width, height, valid;
    char pad[0xfc - 0xc];
    png_fixed_point int_gamma;
    png_fixed_point int_x_white, int_y_white, int_x_red, int_y_red;
    png_fixed_point int_x_green, int_y_green, int_x_blue, int_y_blue;
} png_info;
typedef png_struct* png_structp;
typedef png_info* png_infop;
#define PNG_HAVE_IHDR 0x01
#define PNG_HAVE_PLTE 0x02
#define PNG_HAVE_IDAT 0x04
#define PNG_INFO_gAMA 0x0001
#define PNG_INFO_sRGB 0x0800
#define PNG_INFO_cHRM 0x0004
#define PNG_sRGB_INTENT_LAST 4
void png_set_sRGB_gAMA_and_cHRM(png_structp png_ptr, png_infop info_ptr, int intent);
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
void
png_handle_sRGB(png_structp png_ptr, png_infop info_ptr, png_uint_32 length)
{
   int intent;
   png_byte buf[1];

   if (!(png_ptr->mode & PNG_HAVE_IHDR))
      png_error(png_ptr, "Missing IHDR before sRGB");
   else if (png_ptr->mode & PNG_HAVE_IDAT)
   {
      png_warning(png_ptr, "Invalid sRGB after IDAT");
      png_crc_finish(png_ptr, length);
      return;
   }
   else if (png_ptr->mode & PNG_HAVE_PLTE)
      png_warning(png_ptr, "Out of place sRGB chunk");

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_sRGB))
   {
      png_warning(png_ptr, "Duplicate sRGB chunk");
      png_crc_finish(png_ptr, length);
      return;
   }

   if (length != 1)
   {
      png_warning(png_ptr, "Incorrect sRGB chunk length");
      png_crc_finish(png_ptr, length);
      return;
   }

   png_crc_read(png_ptr, buf, 1);
   if (png_crc_finish(png_ptr, 0))
      return;

   intent = buf[0];
   if (intent >= PNG_sRGB_INTENT_LAST)
   {
      png_warning(png_ptr, "Unknown sRGB intent");
      return;
   }

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_gAMA))
   {
   png_fixed_point igamma;
      igamma=info_ptr->int_gamma;
      if (PNG_OUT_OF_RANGE(igamma, 45500L, 500))
      {
         png_warning(png_ptr,
           "Ignoring incorrect gAMA value when sRGB is also present");
         fprintf(stderr,"incorrect gamma=(%d/100000)\n",(int)png_ptr->int_gamma);
      }
   }

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_cHRM))
      if (PNG_OUT_OF_RANGE(info_ptr->int_x_white, 31270,  1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_y_white, 32900,  1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_x_red,   64000L, 1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_y_red,   33000,  1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_x_green, 30000,  1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_y_green, 60000L, 1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_x_blue,  15000,  1000) ||
          PNG_OUT_OF_RANGE(info_ptr->int_y_blue,   6000,  1000))
         {
            png_warning(png_ptr,
              "Ignoring incorrect cHRM value when sRGB is also present");
         }

   png_set_sRGB_gAMA_and_cHRM(png_ptr, info_ptr, intent);
}
