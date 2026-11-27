// from server: 100% by Xemicl
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
typedef struct z_stream_s {
    unsigned char *next_in; unsigned int avail_in; unsigned long total_in;
    unsigned char *next_out; unsigned int avail_out; unsigned long total_out;
    char *msg; void *state; void *zalloc; void *zfree; void *opaque;
    int data_type; unsigned long adler; unsigned long reserved;
} z_stream;
int __stdcall deflateReset(z_stream *strm);
#define Z_BINARY 0
typedef unsigned char *png_bytep;
typedef unsigned int png_size_t;
typedef unsigned long png_uint_32;
typedef char *png_charp;
typedef char **png_charpp;
typedef struct png_struct_def {
    char pad0[0x74];
    z_stream zstream;
    png_bytep zbuf;
    png_size_t zbuf_size;
} png_struct;
typedef png_struct *png_structp;
typedef struct
{
    char *input;   /* the uncompressed input data */
    int input_len;   /* its length */
    int num_output_ptr; /* number of output pointers used */
    int max_output_ptr; /* size of output_ptr */
    png_charpp output_ptr; /* array of pointers to output */
} compression_state;
void png_free(png_structp png_ptr, void *ptr);
void png_write_data(png_structp png_ptr, png_bytep data, png_size_t length);
void png_calculate_crc(png_structp png_ptr, png_bytep ptr, png_size_t length);
void png_write_chunk_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
   if (png_ptr == 0) return;
   if (data != 0 && length > 0)
   {
      png_write_data(png_ptr, data, length);
      png_calculate_crc(png_ptr, data, length);
   }
}
int png_text_compress(png_structp png_ptr, png_charp text, png_size_t text_len, int compression, compression_state *comp);
void png_write_chunk_end(png_structp png_ptr);

static void /* PRIVATE */
png_write_compressed_data_out(png_structp png_ptr, compression_state *comp)
{
   int i;

   /* handle the no-compression case */
   if (comp->input)
   {
       png_write_chunk_data(png_ptr, (png_bytep)comp->input,
                            (png_size_t)comp->input_len);
       return;
   }

   /* write saved output buffers, if any */
   for (i = 0; i < comp->num_output_ptr; i++)
   {
      png_write_chunk_data(png_ptr, (png_bytep)comp->output_ptr[i],
         (png_size_t)png_ptr->zbuf_size);
      png_free(png_ptr, comp->output_ptr[i]);
       comp->output_ptr[i]=0;
   }
   if (comp->max_output_ptr != 0)
      png_free(png_ptr, comp->output_ptr);
       comp->output_ptr=0;
   /* write anything left in zbuf */
   if (png_ptr->zstream.avail_out < (png_uint_32)png_ptr->zbuf_size)
      png_write_chunk_data(png_ptr, png_ptr->zbuf,
         (png_size_t)(png_ptr->zbuf_size - png_ptr->zstream.avail_out));

   /* reset zlib for another zTXt/iTXt or image data */
   deflateReset(&png_ptr->zstream);
   png_ptr->zstream.data_type = Z_BINARY;
}

void png_write_zTXt(png_structp png_ptr, png_charp text, png_size_t text_len, int compression)
{
   compression_state comp;
   comp.num_output_ptr = 0;
   comp.max_output_ptr = 0;
   comp.output_ptr = 0;
   comp.input = 0;
   comp.input_len = 0;
   text_len = png_text_compress(png_ptr, text, text_len, compression, &comp);
   png_write_compressed_data_out(png_ptr, &comp);
   png_write_chunk_end(png_ptr);
}
void png_write_iTXt(png_structp png_ptr, png_charp text, png_size_t text_len, int compression)
{
   compression_state comp;
   comp.num_output_ptr = 0;
   comp.max_output_ptr = 0;
   comp.output_ptr = 0;
   comp.input = 0;
   text_len = png_text_compress(png_ptr, text, text_len, compression - 2, &comp);
   png_write_chunk_data(png_ptr, (png_bytep)text, text_len);
   png_write_compressed_data_out(png_ptr, &comp);
   png_write_chunk_end(png_ptr);
}