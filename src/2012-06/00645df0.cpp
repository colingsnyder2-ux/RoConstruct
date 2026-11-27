// from server: 100% by Xemicl
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
#include <string.h>
#include <setjmp.h>
typedef struct z_stream_s {
    unsigned char *next_in; unsigned int avail_in; unsigned long total_in;
    unsigned char *next_out; unsigned int avail_out; unsigned long total_out;
    char *msg; void *state; void *zalloc; void *zfree; void *opaque;
    int data_type; unsigned long adler; unsigned long reserved;
} z_stream;
int __stdcall deflateEnd(z_stream *strm);
typedef struct png_struct_def png_struct;
typedef png_struct *png_structp;
typedef void (*png_error_ptr)(png_structp, const char *);
typedef void (*png_free_ptr)(png_structp, void *);
struct png_struct_def {
    jmp_buf jmpbuf;
    png_error_ptr error_fn;
    png_error_ptr warning_fn;
    void *error_ptr;
    char pad4c[0x28];
    z_stream zstream;
    unsigned char *zbuf;
    char padb0[0x38];
    unsigned char *prev_row;
    unsigned char *row_buf;
    unsigned char *sub_row;
    unsigned char *up_row;
    unsigned char *avg_row;
    unsigned char *paeth_row;
    char pad100[0xfc];
    unsigned char *prev_filters;
    unsigned short *filter_weights;
    unsigned short *inv_filter_weights;
    unsigned short *filter_costs;
    unsigned short *inv_filter_costs;
    char *time_buffer;
    char pad214[0x38];
    png_free_ptr free_fn;
    char pad250[0x3c];
};
void png_free(png_structp png_ptr, void *ptr);
void png_write_destroy(png_structp png_ptr)
{
   jmp_buf tmp_jmp; /* save jump buffer */
   png_error_ptr error_fn;
   png_error_ptr warning_fn;
   void *error_ptr;
   png_free_ptr free_fn;

   /* free any memory zlib uses */
   deflateEnd(&png_ptr->zstream);

   /* free our memory.  png_free checks NULL for us. */
   png_free(png_ptr, png_ptr->zbuf);
   png_free(png_ptr, png_ptr->row_buf);
   png_free(png_ptr, png_ptr->prev_row);
   png_free(png_ptr, png_ptr->sub_row);
   png_free(png_ptr, png_ptr->up_row);
   png_free(png_ptr, png_ptr->avg_row);
   png_free(png_ptr, png_ptr->paeth_row);

   png_free(png_ptr, png_ptr->time_buffer);

   png_free(png_ptr, png_ptr->prev_filters);
   png_free(png_ptr, png_ptr->filter_weights);
   png_free(png_ptr, png_ptr->inv_filter_weights);
   png_free(png_ptr, png_ptr->filter_costs);
   png_free(png_ptr, png_ptr->inv_filter_costs);

   /* reset structure */
   memcpy(tmp_jmp, png_ptr->jmpbuf, sizeof(jmp_buf));

   error_fn = png_ptr->error_fn;
   warning_fn = png_ptr->warning_fn;
   error_ptr = png_ptr->error_ptr;
   free_fn = png_ptr->free_fn;

   memset(png_ptr, 0, sizeof(png_struct));

   png_ptr->error_fn = error_fn;
   png_ptr->warning_fn = warning_fn;
   png_ptr->error_ptr = error_ptr;
   png_ptr->free_fn = free_fn;

   memcpy(png_ptr->jmpbuf, tmp_jmp, sizeof(jmp_buf));
}