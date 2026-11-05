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
#define PNG_INFO_cHRM 0x0004
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
png_uint_32 png_get_uint_32(png_byte* buf)
{
   png_uint_32 i = ((png_uint_32)(*buf) << 24) +
      ((png_uint_32)(*(buf + 1)) << 16) +
      ((png_uint_32)(*(buf + 2)) << 8) +
      (png_uint_32)(*(buf + 3));
   return (i);
}
void png_set_cHRM(png_structp png_ptr, png_infop info_ptr,
   double white_x, double white_y, double red_x, double red_y,
   double green_x, double green_y, double blue_x, double blue_y);
void png_set_cHRM_fixed(png_structp png_ptr, png_infop info_ptr,
   png_fixed_point int_white_x, png_fixed_point int_white_y,
   png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point
   int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x,
   png_fixed_point int_blue_y);
void
png_handle_cHRM(png_structp png_ptr, png_infop info_ptr, png_uint_32 length)
{
   png_byte buf[32];
   float white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y;
   png_fixed_point int_x_white, int_y_white, int_x_red, int_y_red, int_x_green,
      int_y_green, int_x_blue, int_y_blue;

   png_uint_32 uint_x, uint_y;

   if (!(png_ptr->mode & PNG_HAVE_IHDR))
      png_error(png_ptr, "Missing IHDR before cHRM");
   else if (png_ptr->mode & PNG_HAVE_IDAT)
   {
      png_warning(png_ptr, "Invalid cHRM after IDAT");
      png_crc_finish(png_ptr, length);
      return;
   }
   else if (png_ptr->mode & PNG_HAVE_PLTE)
      /* Should be an error, but we can cope with it */
      png_warning(png_ptr, "Missing PLTE before cHRM");

   if (info_ptr != NULL && (info_ptr->valid & PNG_INFO_cHRM)
      && !(info_ptr->valid & PNG_INFO_sRGB)
      )
   {
      png_warning(png_ptr, "Duplicate cHRM chunk");
      png_crc_finish(png_ptr, length);
      return;
   }

   if (length != 32)
   {
      png_warning(png_ptr, "Incorrect cHRM chunk length");
      png_crc_finish(png_ptr, length);
      return;
   }

   png_crc_read(png_ptr, buf, 32);
   if (png_crc_finish(png_ptr, 0))
      return;

   uint_x = png_get_uint_32(buf);
   uint_y = png_get_uint_32(buf + 4);
   if (uint_x > 80000L || uint_y > 80000L ||
      uint_x + uint_y > 100000L)
   {
      png_warning(png_ptr, "Invalid cHRM white point");
      return;
   }
   int_x_white = (png_fixed_point)uint_x;
   int_y_white = (png_fixed_point)uint_y;

   uint_x = png_get_uint_32(buf + 8);
   uint_y = png_get_uint_32(buf + 12);
   if (uint_x + uint_y > 100000L)
   {
      png_warning(png_ptr, "Invalid cHRM red point");
      return;
   }
   int_x_red = (png_fixed_point)uint_x;
   int_y_red = (png_fixed_point)uint_y;

   uint_x = png_get_uint_32(buf + 16);
   uint_y = png_get_uint_32(buf + 20);
   if (uint_x + uint_y > 100000L)
   {
      png_warning(png_ptr, "Invalid cHRM green point");
      return;
   }
   int_x_green = (png_fixed_point)uint_x;
   int_y_green = (png_fixed_point)uint_y;

   uint_x = png_get_uint_32(buf + 24);
   uint_y = png_get_uint_32(buf + 28);
   if (uint_x + uint_y > 100000L)
   {
      png_warning(png_ptr, "Invalid cHRM blue point");
      return;
   }
   int_x_blue = (png_fixed_point)uint_x;
   int_y_blue = (png_fixed_point)uint_y;

   white_x = (float)int_x_white / (float)100000.0;
   white_y = (float)int_y_white / (float)100000.0;
   red_x   = (float)int_x_red   / (float)100000.0;
   red_y   = (float)int_y_red   / (float)100000.0;
   green_x = (float)int_x_green / (float)100000.0;
   green_y = (float)int_y_green / (float)100000.0;
   blue_x  = (float)int_x_blue  / (float)100000.0;
   blue_y  = (float)int_y_blue  / (float)100000.0;

   if ((info_ptr != NULL) && (info_ptr->valid & PNG_INFO_sRGB))
      {
      if (PNG_OUT_OF_RANGE(int_x_white, 31270,  1000) ||
          PNG_OUT_OF_RANGE(int_y_white, 32900,  1000) ||
          PNG_OUT_OF_RANGE(int_x_red,   64000L, 1000) ||
          PNG_OUT_OF_RANGE(int_y_red,   33000,  1000) ||
          PNG_OUT_OF_RANGE(int_x_green, 30000,  1000) ||
          PNG_OUT_OF_RANGE(int_y_green, 60000L, 1000) ||
          PNG_OUT_OF_RANGE(int_x_blue,  15000,  1000) ||
          PNG_OUT_OF_RANGE(int_y_blue,   6000,  1000))
         {
            png_warning(png_ptr,
              "Ignoring incorrect cHRM value when sRGB is also present");
            fprintf(stderr, "wx=%f, wy=%f, rx=%f, ry=%f\n",
               white_x, white_y, red_x, red_y);
            fprintf(stderr, "gx=%f, gy=%f, bx=%f, by=%f\n",
               green_x, green_y, blue_x, blue_y);
         }
         return;
      }

   png_set_cHRM(png_ptr, info_ptr,
      white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y);
   png_set_cHRM_fixed(png_ptr, info_ptr,
      int_x_white, int_y_white, int_x_red, int_y_red, int_x_green,
      int_y_green, int_x_blue, int_y_blue);
}
