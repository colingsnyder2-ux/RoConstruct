// from server: 100% by EspClaude
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
/* libpng 1.2.31 pngrutil.c png_decompress_chunk (self-contained: exe png_struct offsets) */
#include <stdio.h>
#include <string.h>
typedef unsigned long png_uint_32;
typedef unsigned int png_size_t;
typedef unsigned char png_byte;
typedef png_byte* png_bytep;
typedef char* png_charp;
typedef const char* png_const_charp;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef struct z_stream_s {
    png_bytep next_in;
    uInt avail_in;
    uLong total_in;
    png_bytep next_out;
    uInt avail_out;
    uLong total_out;
    char* msg;
    void* state;
    void* zalloc;
    void* zfree;
    void* opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;
typedef struct png_struct_def {
   char pad0[0x74];
   z_stream zstream;
   png_bytep zbuf;
   png_size_t zbuf_size;
   char pad1[0x11c - 0xb4];
   png_byte chunk_name[5];
   char pad2[0x288 - 0x121];
   png_charp chunkdata;
} png_struct;
typedef png_struct* png_structp;
#define PNG_CONST const
#define PNG_COMPRESSION_TYPE_BASE 0
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_PARTIAL_FLUSH 1
#define Z_BUF_ERROR (-5)
#define Z_DATA_ERROR (-3)
#define png_sizeof(x) sizeof(x)
#define png_memcpy memcpy
#define png_snprintf _snprintf
int inflate(z_stream* strm, int flush);
int inflateReset(z_stream* strm);
void png_error(png_structp png_ptr, png_const_charp error_message);
void png_warning(png_structp png_ptr, png_const_charp warning_message);
void* png_malloc_warn(png_structp png_ptr, png_uint_32 size);
void png_free(png_structp png_ptr, void* ptr);

void /* PRIVATE */
png_decompress_chunk(png_structp png_ptr, int comp_type,
                              png_size_t chunklength,
                              png_size_t prefix_size, png_size_t *newlength)
{
   static PNG_CONST char msg[] = "Error decoding compressed text";
   png_charp text;
   png_size_t text_size;

   if (comp_type == PNG_COMPRESSION_TYPE_BASE)
   {
      int ret = Z_OK;
      png_ptr->zstream.next_in = (png_bytep)(png_ptr->chunkdata + prefix_size);
      png_ptr->zstream.avail_in = (uInt)(chunklength - prefix_size);
      png_ptr->zstream.next_out = png_ptr->zbuf;
      png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;

      text_size = 0;
      text = NULL;

      while (png_ptr->zstream.avail_in)
      {
         ret = inflate(&png_ptr->zstream, Z_PARTIAL_FLUSH);
         if (ret != Z_OK && ret != Z_STREAM_END)
         {
            if (png_ptr->zstream.msg != NULL)
               png_warning(png_ptr, png_ptr->zstream.msg);
            else
               png_warning(png_ptr, msg);
            inflateReset(&png_ptr->zstream);
            png_ptr->zstream.avail_in = 0;

            if (text ==  NULL)
            {
               text_size = prefix_size + png_sizeof(msg) + 1;
               text = (png_charp)png_malloc_warn(png_ptr, text_size);
               if (text ==  NULL)
                 {
                    png_free(png_ptr, png_ptr->chunkdata);
                    png_ptr->chunkdata = NULL;
                    png_error(png_ptr, "Not enough memory to decompress chunk");
                 }
               png_memcpy(text, png_ptr->chunkdata, prefix_size);
            }

            text[text_size - 1] = 0x00;

            /* Copy what we can of the error message into the text chunk */
            text_size = (png_size_t)(chunklength -
              (text - png_ptr->chunkdata) - 1);
            if (text_size > png_sizeof(msg))
               text_size = png_sizeof(msg);
            png_memcpy(text + prefix_size, msg, text_size);
            break;
         }
         if (!png_ptr->zstream.avail_out || ret == Z_STREAM_END)
         {
            if (text == NULL)
            {
               text_size = prefix_size +
                   png_ptr->zbuf_size - png_ptr->zstream.avail_out;
               text = (png_charp)png_malloc_warn(png_ptr, text_size + 1);
               if (text ==  NULL)
               {
                  png_free(png_ptr, png_ptr->chunkdata);
                  png_ptr->chunkdata = NULL;
                  png_error(png_ptr,
                    "Not enough memory to decompress chunk.");
               }
               png_memcpy(text + prefix_size, png_ptr->zbuf,
                    text_size - prefix_size);
               png_memcpy(text, png_ptr->chunkdata, prefix_size);
               *(text + text_size) = 0x00;
            }
            else
            {
               png_charp tmp;

               tmp = text;
               text = (png_charp)png_malloc_warn(png_ptr,
                  (png_uint_32)(text_size +
                  png_ptr->zbuf_size - png_ptr->zstream.avail_out + 1));
               if (text == NULL)
               {
                  png_free(png_ptr, tmp);
                  png_free(png_ptr, png_ptr->chunkdata);
                  png_ptr->chunkdata = NULL;
                  png_error(png_ptr,
                    "Not enough memory to decompress chunk..");
               }
               png_memcpy(text, tmp, text_size);
               png_free(png_ptr, tmp);
               png_memcpy(text + text_size, png_ptr->zbuf,
                  (png_ptr->zbuf_size - png_ptr->zstream.avail_out));
               text_size += png_ptr->zbuf_size - png_ptr->zstream.avail_out;
               *(text + text_size) = 0x00;
            }
            if (ret == Z_STREAM_END)
               break;
            else
            {
               png_ptr->zstream.next_out = png_ptr->zbuf;
               png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
            }
         }
      }
      if (ret != Z_STREAM_END)
      {
#if !defined(PNG_NO_STDIO) && !defined(_WIN32_WCE)
         char umsg[52];

         if (ret == Z_BUF_ERROR)
            png_snprintf(umsg, 52,
                "Buffer error in compressed datastream in %s chunk",
                png_ptr->chunk_name);

         else if (ret == Z_DATA_ERROR)
            png_snprintf(umsg, 52,
                "Data error in compressed datastream in %s chunk",
                png_ptr->chunk_name);

         else
            png_snprintf(umsg, 52,
                "Incomplete compressed datastream in %s chunk",
                png_ptr->chunk_name);

         png_warning(png_ptr, umsg);
#else
         png_warning(png_ptr,
            "Incomplete compressed datastream in chunk other than IDAT");
#endif
         text_size = prefix_size;
         if (text ==  NULL)
         {
            text = (png_charp)png_malloc_warn(png_ptr, text_size+1);
            if (text == NULL)
              {
                png_free(png_ptr, png_ptr->chunkdata);
                png_ptr->chunkdata = NULL;
                png_error(png_ptr, "Not enough memory for text.");
              }
            png_memcpy(text, png_ptr->chunkdata, prefix_size);
         }
         *(text + text_size) = 0x00;
      }

      inflateReset(&png_ptr->zstream);
      png_ptr->zstream.avail_in = 0;

      png_free(png_ptr, png_ptr->chunkdata);
      png_ptr->chunkdata = text;
      *newlength=text_size;
   }
   else /* if (comp_type != PNG_COMPRESSION_TYPE_BASE) */
   {
#if !defined(PNG_NO_STDIO) && !defined(_WIN32_WCE)
      char umsg[50];

      png_snprintf(umsg, 50, "Unknown zTXt compression type %d", comp_type);
      png_warning(png_ptr, umsg);
#else
      png_warning(png_ptr, "Unknown zTXt compression type");
#endif

      *(png_ptr->chunkdata + prefix_size) = 0x00;
      *newlength = prefix_size;
   }
}
