// from server: 100% by Xemicl
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
__declspec(dllimport) struct _iobuf* __cdecl __iob_func(void); __declspec(dllimport) int __cdecl fprintf(struct _iobuf*, const char*, ...);
typedef unsigned char  Byte;
typedef unsigned int   uInt;
typedef unsigned long  uLong;
 typedef Byte   Bytef;
typedef char   charf;
typedef int    intf;
typedef uInt   uIntf;
typedef uLong  uLongf;
 typedef void const *voidpc;
 typedef void    *voidpf;
 typedef void       *voidp;
typedef voidpf (*alloc_func) (voidpf opaque, uInt items, uInt size);
typedef void   (*free_func)  (voidpf opaque, voidpf address);
struct internal_state;
typedef struct z_stream_s {
 Bytef    *next_in;
 uInt     avail_in;
 uLong    total_in;
 Bytef    *next_out;
 uInt     avail_out;
 uLong    total_out;
 char     *msg;
 struct internal_state  *state;
 alloc_func zalloc;
 free_func  zfree;
 voidpf     opaque;
 int     data_type;
 uLong   adler;
 uLong   reserved;
} z_stream;
typedef z_stream  *z_streamp;
typedef struct gz_header_s {
 int     text;
 uLong   time;
 int     xflags;
 int     os;
 Bytef   *extra;
 uInt    extra_len;
 uInt    extra_max;
 Bytef   *name;
 uInt    name_max;
 Bytef   *comment;
 uInt    comm_max;
 int     hcrc;
 int     done;
} gz_header;
typedef gz_header  *gz_headerp;
extern const char *  zlibVersion (void);
extern int __stdcall deflate (z_streamp strm, int flush);
extern int __stdcall deflateEnd (z_streamp strm);
extern int __stdcall inflate (z_streamp strm, int flush);
extern int __stdcall inflateEnd (z_streamp strm);
extern int __stdcall deflateSetDictionary (z_streamp strm, const Bytef *dictionary, uInt dictLength);
extern int __stdcall deflateCopy (z_streamp dest, z_streamp source);
extern int __stdcall deflateReset (z_streamp strm);
extern int __stdcall deflateParams (z_streamp strm, int level, int strategy);
extern int __stdcall deflateTune (z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain);
extern uLong __stdcall deflateBound (z_streamp strm, uLong sourceLen);
extern int __stdcall deflatePrime (z_streamp strm, int bits, int value);
extern int __stdcall deflateSetHeader (z_streamp strm, gz_headerp head);
extern int __stdcall inflateSetDictionary (z_streamp strm, const Bytef *dictionary, uInt dictLength);
extern int __stdcall inflateSync (z_streamp strm);
extern int __stdcall inflateCopy (z_streamp dest, z_streamp source);
extern int __stdcall inflateReset (z_streamp strm);
extern int __stdcall inflatePrime (z_streamp strm, int bits, int value);
extern int __stdcall inflateGetHeader (z_streamp strm, gz_headerp head);
typedef unsigned (*in_func) (void  *, unsigned char  *  *);
typedef int (*out_func) (void  *, unsigned char  *, unsigned);
extern int __stdcall inflateBack (z_streamp strm, in_func in, void  *in_desc, out_func out, void  *out_desc);
extern int __stdcall inflateBackEnd (z_streamp strm);
extern uLong  zlibCompileFlags (void);
extern int  compress (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen);
extern int  compress2 (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen, int level);
extern uLong  compressBound (uLong sourceLen);
extern int  uncompress (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen);
typedef voidp gzFile;
extern gzFile  gzopen  (const char *path, const char *mode);
extern gzFile  gzdopen  (int fd, const char *mode);
extern int  gzsetparams (gzFile file, int level, int strategy);
extern int     gzread  (gzFile file, voidp buf, unsigned len);
extern int     gzwrite (gzFile file, voidpc buf, unsigned len);
extern int    gzprintf (gzFile file, const char *format, ...);
extern int  gzputs (gzFile file, const char *s);
extern char *  gzgets (gzFile file, char *buf, int len);
extern int     gzputc (gzFile file, int c);
extern int     gzgetc (gzFile file);
extern int     gzungetc (int c, gzFile file);
extern int     gzflush (gzFile file, int flush);
extern long     gzseek (gzFile file, long offset, int whence);
extern int     gzrewind (gzFile file);
extern long     gztell (gzFile file);
extern int  gzeof (gzFile file);
extern int  gzdirect (gzFile file);
extern int     gzclose (gzFile file);
extern const char *  gzerror (gzFile file, int *errnum);
extern void  gzclearerr (gzFile file);
extern uLong  adler32 (uLong adler, const Bytef *buf, uInt len);
extern uLong  adler32_combine (uLong adler1, uLong adler2, long len2);
extern uLong  crc32   (uLong crc, const Bytef *buf, uInt len);
extern uLong  crc32_combine (uLong crc1, uLong crc2, long len2);
extern int __stdcall deflateInit_ (z_streamp strm, int level, const char *version, int stream_size);
extern int __stdcall inflateInit_ (z_streamp strm, const char *version, int stream_size);
extern int __stdcall deflateInit2_ (z_streamp strm, int level, int method, int windowBits, int memLevel, int strategy, const char *version, int stream_size);
extern int __stdcall inflateInit2_ (z_streamp strm, int windowBits, const char *version, int stream_size);
extern int __stdcall inflateBackInit_ (z_streamp strm, int windowBits, unsigned char  *window, const char *version, int stream_size);
 struct internal_state {int dummy;};
extern const char   *  zError           (int);
extern int __stdcall inflateSyncPoint (z_streamp z);
extern const uLongf *  get_crc_table    (void);
typedef unsigned int size_t; typedef __int64 time_t; typedef int jmp_buf[16];
struct _iobuf {
 char *_ptr;
 int   _cnt;
 char *_base;
 int   _flag;
 int   _file;
 int   _charbuf;
 int   _bufsiz;
 char *_tmpfname;
 };
typedef struct _iobuf FILE;
struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 };
__declspec(dllimport) int __cdecl _snprintf(char*, size_t, const char*, ...);
void* __cdecl memcpy(void*, const void*, size_t); void* __cdecl memset(void*, int, size_t); size_t __cdecl strlen(const char*); int __cdecl memcmp(const void*, const void*, size_t); int __cdecl abs(int); double __cdecl fabs(double);
#pragma intrinsic(memcpy, memset, strlen, memcmp, abs, fabs)
typedef unsigned long png_uint_32;
typedef long png_int_32;
typedef unsigned short png_uint_16;
typedef short png_int_16;
typedef unsigned char png_byte;
 typedef size_t png_size_t;
typedef png_int_32 png_fixed_point;
typedef void             * png_voidp;
typedef png_byte         * png_bytep;
typedef png_uint_32      * png_uint_32p;
typedef png_int_32       * png_int_32p;
typedef png_uint_16      * png_uint_16p;
typedef png_int_16       * png_int_16p;
typedef const char   * png_const_charp;
typedef char             * png_charp;
typedef png_fixed_point  * png_fixed_point_p;
typedef FILE                * png_FILE_p;
typedef double           * png_doublep;
typedef png_byte         *  * png_bytepp;
typedef png_uint_32      *  * png_uint_32pp;
typedef png_int_32       *  * png_int_32pp;
typedef png_uint_16      *  * png_uint_16pp;
typedef png_int_16       *  * png_int_16pp;
typedef const char   *  * png_const_charpp;
typedef char             *  * png_charpp;
typedef png_fixed_point  *  * png_fixed_point_pp;
typedef double           *  * png_doublepp;
typedef char             *  *  * png_charppp;
typedef charf *         png_zcharp;
typedef charf *  *   png_zcharpp;
typedef z_stream  *  png_zstreamp;
typedef struct png_color_struct
{
 png_byte red;
 png_byte green;
 png_byte blue;
} png_color;
typedef png_color  * png_colorp;
typedef png_color  *  * png_colorpp;
typedef struct png_color_16_struct
{
 png_byte index;
 png_uint_16 red;
 png_uint_16 green;
 png_uint_16 blue;
 png_uint_16 gray;
} png_color_16;
typedef png_color_16  * png_color_16p;
typedef png_color_16  *  * png_color_16pp;
typedef struct png_color_8_struct
{
 png_byte red;
 png_byte green;
 png_byte blue;
 png_byte gray;
 png_byte alpha;
} png_color_8;
typedef png_color_8  * png_color_8p;
typedef png_color_8  *  * png_color_8pp;
typedef struct png_sPLT_entry_struct
{
 png_uint_16 red;
 png_uint_16 green;
 png_uint_16 blue;
 png_uint_16 alpha;
 png_uint_16 frequency;
} png_sPLT_entry;
typedef png_sPLT_entry  * png_sPLT_entryp;
typedef png_sPLT_entry  *  * png_sPLT_entrypp;
typedef struct png_sPLT_struct
{
 png_charp name;
 png_byte depth;
 png_sPLT_entryp entries;
 png_int_32 nentries;
} png_sPLT_t;
typedef png_sPLT_t  * png_sPLT_tp;
typedef png_sPLT_t  *  * png_sPLT_tpp;
typedef struct png_text_struct
{
 int  compression;
 png_charp key;
 png_charp text;
 png_size_t text_length;
} png_text;
typedef png_text  * png_textp;
typedef png_text  *  * png_textpp;
typedef struct png_time_struct
{
 png_uint_16 year;
 png_byte month;
 png_byte day;
 png_byte hour;
 png_byte minute;
 png_byte second;
} png_time;
typedef png_time  * png_timep;
typedef png_time  *  * png_timepp;
typedef struct png_unknown_chunk_t
{
 png_byte name[5];
 png_byte *data;
 png_size_t size;
 png_byte location;
}
png_unknown_chunk;
typedef png_unknown_chunk  * png_unknown_chunkp;
typedef png_unknown_chunk  *  * png_unknown_chunkpp;
typedef struct png_info_struct
{
 png_uint_32 width;
 png_uint_32 height;
 png_uint_32 valid;
 png_uint_32 rowbytes;
 png_colorp palette;
 png_uint_16 num_palette;
 png_uint_16 num_trans;
 png_byte bit_depth;
 png_byte color_type;
 png_byte compression_type;
 png_byte filter_type;
 png_byte interlace_type;
 png_byte channels;
 png_byte pixel_depth;
 png_byte spare_byte;
 png_byte signature[8];
 float gamma;
 png_byte srgb_intent;
 int num_text;
 int max_text;
 png_textp text;
 png_time mod_time;
 png_color_8 sig_bit;
 png_bytep trans;
 png_color_16 trans_values;
 png_color_16 background;
 png_int_32 x_offset;
 png_int_32 y_offset;
 png_byte offset_unit_type;
 png_uint_32 x_pixels_per_unit;
 png_uint_32 y_pixels_per_unit;
 png_byte phys_unit_type;
 png_uint_16p hist;
 float x_white;
 float y_white;
 float x_red;
 float y_red;
 float x_green;
 float y_green;
 float x_blue;
 float y_blue;
 png_charp pcal_purpose;
 png_int_32 pcal_X0;
 png_int_32 pcal_X1;
 png_charp pcal_units;
 png_charpp pcal_params;
 png_byte pcal_type;
 png_byte pcal_nparams;
 png_uint_32 free_me;
 png_unknown_chunkp unknown_chunks;
 png_size_t unknown_chunks_num;
 png_charp iccp_name;
 png_charp iccp_profile;
 png_uint_32 iccp_proflen;
 png_byte iccp_compression;
 png_sPLT_tp splt_palettes;
 png_uint_32 splt_palettes_num;
 png_byte scal_unit;
 double scal_pixel_width;
 double scal_pixel_height;
 png_charp scal_s_width;
 png_charp scal_s_height;
 png_bytepp row_pointers;
 png_fixed_point int_gamma;
 png_fixed_point int_x_white;
 png_fixed_point int_y_white;
 png_fixed_point int_x_red;
 png_fixed_point int_y_red;
 png_fixed_point int_x_green;
 png_fixed_point int_y_green;
 png_fixed_point int_x_blue;
 png_fixed_point int_y_blue;
} png_info;
typedef png_info  * png_infop;
typedef png_info  *  * png_infopp;
typedef struct png_row_info_struct
{
 png_uint_32 width;
 png_uint_32 rowbytes;
 png_byte color_type;
 png_byte bit_depth;
 png_byte channels;
 png_byte pixel_depth;
} png_row_info;
typedef png_row_info  * png_row_infop;
typedef png_row_info  *  * png_row_infopp;
typedef struct png_struct_def png_struct;
typedef png_struct  * png_structp;
typedef void (__cdecl *png_error_ptr) (png_structp, png_const_charp);
typedef void (__cdecl *png_rw_ptr) (png_structp, png_bytep, png_size_t);
typedef void (__cdecl *png_flush_ptr) (png_structp);
typedef void (__cdecl *png_read_status_ptr) (png_structp, png_uint_32, int);
typedef void (__cdecl *png_write_status_ptr) (png_structp, png_uint_32, int);
typedef void (__cdecl *png_progressive_info_ptr) (png_structp, png_infop);
typedef void (__cdecl *png_progressive_end_ptr) (png_structp, png_infop);
typedef void (__cdecl *png_progressive_row_ptr) (png_structp, png_bytep, png_uint_32, int);
typedef void (__cdecl *png_user_transform_ptr) (png_structp, png_row_infop, png_bytep);
typedef int (__cdecl *png_user_chunk_ptr) (png_structp, png_unknown_chunkp);
typedef void (__cdecl *png_unknown_chunk_ptr) (png_structp);
typedef png_voidp (*png_malloc_ptr) (png_structp, png_size_t);
typedef void (*png_free_ptr) (png_structp, png_voidp);
struct png_struct_def
{
 jmp_buf jmpbuf;
 png_error_ptr error_fn;
 png_error_ptr warning_fn;
 png_voidp error_ptr;
 png_rw_ptr write_data_fn;
 png_rw_ptr read_data_fn;
 png_voidp io_ptr;
 png_user_transform_ptr read_user_transform_fn;
 png_user_transform_ptr write_user_transform_fn;
 png_voidp user_transform_ptr;
 png_byte user_transform_depth;
 png_byte user_transform_channels;
 png_uint_32 mode;
 png_uint_32 flags;
 png_uint_32 transformations;
 z_stream zstream;
 png_bytep zbuf;
 png_size_t zbuf_size;
 int zlib_level;
 int zlib_method;
 int zlib_window_bits;
 int zlib_mem_level;
 int zlib_strategy;
 png_uint_32 width;
 png_uint_32 height;
 png_uint_32 num_rows;
 png_uint_32 usr_width;
 png_uint_32 rowbytes;
 png_uint_32 irowbytes;
 png_uint_32 iwidth;
 png_uint_32 row_number;
 png_bytep prev_row;
 png_bytep row_buf;
 png_bytep sub_row;
 png_bytep up_row;
 png_bytep avg_row;
 png_bytep paeth_row;
 png_row_info row_info;
 png_uint_32 idat_size;
 png_uint_32 crc;
 png_colorp palette;
 png_uint_16 num_palette;
 png_uint_16 num_trans;
 png_byte chunk_name[5];
 png_byte compression;
 png_byte filter;
 png_byte interlaced;
 png_byte pass;
 png_byte do_filter;
 png_byte color_type;
 png_byte bit_depth;
 png_byte usr_bit_depth;
 png_byte pixel_depth;
 png_byte channels;
 png_byte usr_channels;
 png_byte sig_bytes;
 png_uint_16 filler;
 png_byte background_gamma_type;
 float background_gamma;
 png_color_16 background;
 png_color_16 background_1;
 png_flush_ptr output_flush_fn;
 png_uint_32 flush_dist;
 png_uint_32 flush_rows;
 int gamma_shift;
 float gamma;
 float screen_gamma;
 png_bytep gamma_table;
 png_bytep gamma_from_1;
 png_bytep gamma_to_1;
 png_uint_16pp gamma_16_table;
 png_uint_16pp gamma_16_from_1;
 png_uint_16pp gamma_16_to_1;
 png_color_8 sig_bit;
 png_color_8 shift;
 png_bytep trans;
 png_color_16 trans_values;
 png_read_status_ptr read_row_fn;
 png_write_status_ptr write_row_fn;
 png_progressive_info_ptr info_fn;
 png_progressive_row_ptr row_fn;
 png_progressive_end_ptr end_fn;
 png_bytep save_buffer_ptr;
 png_bytep save_buffer;
 png_bytep current_buffer_ptr;
 png_bytep current_buffer;
 png_uint_32 push_length;
 png_uint_32 skip_length;
 png_size_t save_buffer_size;
 png_size_t save_buffer_max;
 png_size_t buffer_size;
 png_size_t current_buffer_size;
 int process_mode;
 int cur_palette;
 png_size_t current_text_size;
 png_size_t current_text_left;
 png_charp current_text;
 png_charp current_text_ptr;
 png_bytep palette_lookup;
 png_bytep dither_index;
 png_uint_16p hist;
 png_byte heuristic_method;
 png_byte num_prev_filters;
 png_bytep prev_filters;
 png_uint_16p filter_weights;
 png_uint_16p inv_filter_weights;
 png_uint_16p filter_costs;
 png_uint_16p inv_filter_costs;
 png_charp time_buffer;
 png_uint_32 free_me;
 png_voidp user_chunk_ptr;
 png_user_chunk_ptr read_user_chunk_fn;
 int num_chunk_list;
 png_bytep chunk_list;
 png_byte rgb_to_gray_status;
 png_uint_16 rgb_to_gray_red_coeff;
 png_uint_16 rgb_to_gray_green_coeff;
 png_uint_16 rgb_to_gray_blue_coeff;
 png_uint_32 mng_features_permitted;
 png_fixed_point int_gamma;
 png_byte filter_type;
 png_byte     mmx_bitdepth_threshold;
 png_uint_32  mmx_rowbytes_threshold;
 png_uint_32  asm_flags;
 png_voidp mem_ptr;
 png_malloc_ptr malloc_fn;
 png_free_ptr free_fn;
 png_bytep big_row_buf;
 png_bytep dither_sort;
 png_bytep index_to_palette;
 png_bytep palette_to_index;
 png_byte compression_type;
 png_uint_32 user_width_max;
 png_uint_32 user_height_max;
 png_unknown_chunk unknown_chunk;
};
typedef png_structp version_1_2_22;
typedef png_struct  *  * png_structpp;
extern  png_uint_32 __cdecl png_access_version_number (void);
extern  void __cdecl png_set_sig_bytes (png_structp png_ptr, int num_bytes);
extern  int __cdecl png_sig_cmp (png_bytep sig, png_size_t start, png_size_t num_to_check);
extern  int __cdecl png_check_sig (png_bytep sig, int num);
extern  png_structp __cdecl png_create_read_struct
 (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
extern  png_structp __cdecl png_create_write_struct
 (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
extern  png_uint_32 __cdecl png_get_compression_buffer_size
 (png_structp png_ptr);
extern  void __cdecl png_set_compression_buffer_size
 (png_structp png_ptr, png_uint_32 size);
extern  int __cdecl png_reset_zstream (png_structp png_ptr);
extern  png_structp __cdecl png_create_read_struct_2
 (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
extern  png_structp __cdecl png_create_write_struct_2
 (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
extern  void __cdecl png_write_chunk (png_structp png_ptr, png_bytep chunk_name, png_bytep data, png_size_t length);
extern  void __cdecl png_write_chunk_start (png_structp png_ptr, png_bytep chunk_name, png_uint_32 length);
extern  void __cdecl png_write_chunk_data (png_structp png_ptr, png_bytep data, png_size_t length);
extern  void __cdecl png_write_chunk_end (png_structp png_ptr);
extern  png_infop __cdecl png_create_info_struct
 (png_structp png_ptr);
extern  void __cdecl png_info_init (png_infop info_ptr);
extern  void __cdecl png_info_init_3 (png_infopp info_ptr, png_size_t png_info_struct_size);
extern  void __cdecl png_write_info_before_PLTE (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_write_info (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_read_info (png_structp png_ptr, png_infop info_ptr);
extern  png_charp __cdecl png_convert_to_rfc1123
 (png_structp png_ptr, png_timep ptime);
extern  void __cdecl png_convert_from_struct_tm (png_timep ptime, struct tm * ttime);
extern  void __cdecl png_convert_from_time_t (png_timep ptime, time_t ttime);
extern  void __cdecl png_set_expand (png_structp png_ptr);
extern  void __cdecl png_set_expand_gray_1_2_4_to_8 (png_structp png_ptr);
extern  void __cdecl png_set_palette_to_rgb (png_structp png_ptr);
extern  void __cdecl png_set_tRNS_to_alpha (png_structp png_ptr);
extern  void __cdecl png_set_gray_1_2_4_to_8 (png_structp png_ptr);
extern  void __cdecl png_set_bgr (png_structp png_ptr);
extern  void __cdecl png_set_gray_to_rgb (png_structp png_ptr);
extern  void __cdecl png_set_rgb_to_gray (png_structp png_ptr, int error_action, double red, double green );
extern  void __cdecl png_set_rgb_to_gray_fixed (png_structp png_ptr, int error_action, png_fixed_point red, png_fixed_point green );
extern  png_byte __cdecl png_get_rgb_to_gray_status (png_structp png_ptr);
extern  void __cdecl png_build_grayscale_palette (int bit_depth, png_colorp palette);
extern  void __cdecl png_set_strip_alpha (png_structp png_ptr);
extern  void __cdecl png_set_swap_alpha (png_structp png_ptr);
extern  void __cdecl png_set_invert_alpha (png_structp png_ptr);
extern  void __cdecl png_set_filler (png_structp png_ptr, png_uint_32 filler, int flags);
extern  void __cdecl png_set_add_alpha (png_structp png_ptr, png_uint_32 filler, int flags);
extern  void __cdecl png_set_swap (png_structp png_ptr);
extern  void __cdecl png_set_packing (png_structp png_ptr);
extern  void __cdecl png_set_packswap (png_structp png_ptr);
extern  void __cdecl png_set_shift (png_structp png_ptr, png_color_8p true_bits);
extern  int __cdecl png_set_interlace_handling (png_structp png_ptr);
extern  void __cdecl png_set_invert_mono (png_structp png_ptr);
extern  void __cdecl png_set_background (png_structp png_ptr, png_color_16p background_color, int background_gamma_code, int need_expand, double background_gamma);
extern  void __cdecl png_set_strip_16 (png_structp png_ptr);
extern  void __cdecl png_set_dither (png_structp png_ptr, png_colorp palette, int num_palette, int maximum_colors, png_uint_16p histogram, int full_dither);
extern  void __cdecl png_set_gamma (png_structp png_ptr, double screen_gamma, double default_file_gamma);
extern  void __cdecl png_permit_empty_plte (png_structp png_ptr, int empty_plte_permitted);
extern  void __cdecl png_set_flush (png_structp png_ptr, int nrows);
extern  void __cdecl png_write_flush (png_structp png_ptr);
extern  void __cdecl png_start_read_image (png_structp png_ptr);
extern  void __cdecl png_read_update_info (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_read_rows (png_structp png_ptr, png_bytepp row, png_bytepp display_row, png_uint_32 num_rows);
extern  void __cdecl png_read_row (png_structp png_ptr, png_bytep row, png_bytep display_row);
extern  void __cdecl png_read_image (png_structp png_ptr, png_bytepp image);
extern  void __cdecl png_write_row (png_structp png_ptr, png_bytep row);
extern  void __cdecl png_write_rows (png_structp png_ptr, png_bytepp row, png_uint_32 num_rows);
extern  void __cdecl png_write_image (png_structp png_ptr, png_bytepp image);
extern  void __cdecl png_write_end (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_read_end (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_destroy_info_struct (png_structp png_ptr, png_infopp info_ptr_ptr);
extern  void __cdecl png_destroy_read_struct (png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr);
extern void png_read_destroy (png_structp png_ptr, png_infop info_ptr, png_infop end_info_ptr);
extern  void __cdecl png_destroy_write_struct
 (png_structpp png_ptr_ptr, png_infopp info_ptr_ptr);
extern void png_write_destroy (png_structp png_ptr);
extern  void __cdecl png_set_crc_action (png_structp png_ptr, int crit_action, int ancil_action);
extern  void __cdecl png_set_filter (png_structp png_ptr, int method, int filters);
extern  void __cdecl png_set_filter_heuristics (png_structp png_ptr, int heuristic_method, int num_weights, png_doublep filter_weights, png_doublep filter_costs);
extern  void __cdecl png_set_compression_level (png_structp png_ptr, int level);
extern  void __cdecl png_set_compression_mem_level
 (png_structp png_ptr, int mem_level);
extern  void __cdecl png_set_compression_strategy
 (png_structp png_ptr, int strategy);
extern  void __cdecl png_set_compression_window_bits
 (png_structp png_ptr, int window_bits);
extern  void __cdecl png_set_compression_method (png_structp png_ptr, int method);
extern  void __cdecl png_init_io (png_structp png_ptr, png_FILE_p fp);
extern  void __cdecl png_set_error_fn (png_structp png_ptr, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn);
extern  png_voidp __cdecl png_get_error_ptr (png_structp png_ptr);
extern  void __cdecl png_set_write_fn (png_structp png_ptr, png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn);
extern  void __cdecl png_set_read_fn (png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);
extern  png_voidp __cdecl png_get_io_ptr (png_structp png_ptr);
extern  void __cdecl png_set_read_status_fn (png_structp png_ptr, png_read_status_ptr read_row_fn);
extern  void __cdecl png_set_write_status_fn (png_structp png_ptr, png_write_status_ptr write_row_fn);
extern  void __cdecl png_set_mem_fn (png_structp png_ptr, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
extern  png_voidp __cdecl png_get_mem_ptr (png_structp png_ptr);
extern  void __cdecl png_set_read_user_transform_fn (png_structp png_ptr, png_user_transform_ptr read_user_transform_fn);
extern  void __cdecl png_set_write_user_transform_fn (png_structp png_ptr, png_user_transform_ptr write_user_transform_fn);
extern  void __cdecl png_set_user_transform_info (png_structp png_ptr, png_voidp user_transform_ptr, int user_transform_depth, int user_transform_channels);
extern  png_voidp __cdecl png_get_user_transform_ptr
 (png_structp png_ptr);
extern  void __cdecl png_set_read_user_chunk_fn (png_structp png_ptr, png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn);
extern  png_voidp __cdecl png_get_user_chunk_ptr (png_structp png_ptr);
extern  void __cdecl png_set_progressive_read_fn (png_structp png_ptr, png_voidp progressive_ptr, png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn);
extern  png_voidp __cdecl png_get_progressive_ptr
 (png_structp png_ptr);
extern  void __cdecl png_process_data (png_structp png_ptr, png_infop info_ptr, png_bytep buffer, png_size_t buffer_size);
extern  void __cdecl png_progressive_combine_row (png_structp png_ptr, png_bytep old_row, png_bytep new_row);
extern  png_voidp __cdecl png_malloc (png_structp png_ptr, png_uint_32 size);
extern  png_voidp __cdecl png_malloc_warn (png_structp png_ptr, png_uint_32 size);
extern  void __cdecl png_free (png_structp png_ptr, png_voidp ptr);
extern  void __cdecl png_free_data (png_structp png_ptr, png_infop info_ptr, png_uint_32 free_me, int num);
extern  void __cdecl png_data_freer (png_structp png_ptr, png_infop info_ptr, int freer, png_uint_32 mask);
extern  png_voidp __cdecl png_malloc_default (png_structp png_ptr, png_uint_32 size);
extern  void __cdecl png_free_default (png_structp png_ptr, png_voidp ptr);
extern  png_voidp __cdecl png_memcpy_check (png_structp png_ptr, png_voidp s1, png_voidp s2, png_uint_32 size);
extern  png_voidp __cdecl png_memset_check (png_structp png_ptr, png_voidp s1, int value, png_uint_32 size);
extern  void __cdecl png_error (png_structp png_ptr, png_const_charp error_message);
extern  void __cdecl png_chunk_error (png_structp png_ptr, png_const_charp error_message);
extern  void __cdecl png_warning (png_structp png_ptr, png_const_charp warning_message);
extern  void __cdecl png_chunk_warning (png_structp png_ptr, png_const_charp warning_message);
extern  png_uint_32 __cdecl png_get_valid (png_structp png_ptr, png_infop info_ptr, png_uint_32 flag);
extern  png_uint_32 __cdecl png_get_rowbytes (png_structp png_ptr, png_infop info_ptr);
extern  png_bytepp __cdecl png_get_rows (png_structp png_ptr, png_infop info_ptr);
extern  void __cdecl png_set_rows (png_structp png_ptr, png_infop info_ptr, png_bytepp row_pointers);
extern  png_byte __cdecl png_get_channels (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_image_width (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_image_height (png_structp png_ptr, png_infop info_ptr);
extern  png_byte __cdecl png_get_bit_depth (png_structp png_ptr, png_infop info_ptr);
extern  png_byte __cdecl png_get_color_type (png_structp png_ptr, png_infop info_ptr);
extern  png_byte __cdecl png_get_filter_type (png_structp png_ptr, png_infop info_ptr);
extern  png_byte __cdecl png_get_interlace_type (png_structp png_ptr, png_infop info_ptr);
extern  png_byte __cdecl png_get_compression_type (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_pixels_per_meter (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_x_pixels_per_meter (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_y_pixels_per_meter (png_structp png_ptr, png_infop info_ptr);
extern  float __cdecl png_get_pixel_aspect_ratio (png_structp png_ptr, png_infop info_ptr);
extern  png_int_32 __cdecl png_get_x_offset_pixels (png_structp png_ptr, png_infop info_ptr);
extern  png_int_32 __cdecl png_get_y_offset_pixels (png_structp png_ptr, png_infop info_ptr);
extern  png_int_32 __cdecl png_get_x_offset_microns (png_structp png_ptr, png_infop info_ptr);
extern  png_int_32 __cdecl png_get_y_offset_microns (png_structp png_ptr, png_infop info_ptr);
extern  png_bytep __cdecl png_get_signature (png_structp png_ptr, png_infop info_ptr);
extern  png_uint_32 __cdecl png_get_bKGD (png_structp png_ptr, png_infop info_ptr, png_color_16p *background);
extern  void __cdecl png_set_bKGD (png_structp png_ptr, png_infop info_ptr, png_color_16p background);
extern  png_uint_32 __cdecl png_get_cHRM (png_structp png_ptr, png_infop info_ptr, double *white_x, double *white_y, double *red_x, double *red_y, double *green_x, double *green_y, double *blue_x, double *blue_y);
extern  png_uint_32 __cdecl png_get_cHRM_fixed (png_structp png_ptr, png_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y, png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point *int_blue_x, png_fixed_point *int_blue_y);
extern  void __cdecl png_set_cHRM (png_structp png_ptr, png_infop info_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y);
extern  void __cdecl png_set_cHRM_fixed (png_structp png_ptr, png_infop info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y);
extern  png_uint_32 __cdecl png_get_gAMA (png_structp png_ptr, png_infop info_ptr, double *file_gamma);
extern  png_uint_32 __cdecl png_get_gAMA_fixed (png_structp png_ptr, png_infop info_ptr, png_fixed_point *int_file_gamma);
extern  void __cdecl png_set_gAMA (png_structp png_ptr, png_infop info_ptr, double file_gamma);
extern  void __cdecl png_set_gAMA_fixed (png_structp png_ptr, png_infop info_ptr, png_fixed_point int_file_gamma);
extern  png_uint_32 __cdecl png_get_hIST (png_structp png_ptr, png_infop info_ptr, png_uint_16p *hist);
extern  void __cdecl png_set_hIST (png_structp png_ptr, png_infop info_ptr, png_uint_16p hist);
extern  png_uint_32 __cdecl png_get_IHDR (png_structp png_ptr, png_infop info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);
extern  void __cdecl png_set_IHDR (png_structp png_ptr, png_infop info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth, int color_type, int interlace_method, int compression_method, int filter_method);
extern  png_uint_32 __cdecl png_get_oFFs (png_structp png_ptr, png_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y, int *unit_type);
extern  void __cdecl png_set_oFFs (png_structp png_ptr, png_infop info_ptr, png_int_32 offset_x, png_int_32 offset_y, int unit_type);
extern  png_uint_32 __cdecl png_get_pCAL (png_structp png_ptr, png_infop info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1, int *type, int *nparams, png_charp *units, png_charpp *params);
extern  void __cdecl png_set_pCAL (png_structp png_ptr, png_infop info_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1, int type, int nparams, png_charp units, png_charpp params);
extern  png_uint_32 __cdecl png_get_pHYs (png_structp png_ptr, png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);
extern  void __cdecl png_set_pHYs (png_structp png_ptr, png_infop info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type);
extern  png_uint_32 __cdecl png_get_PLTE (png_structp png_ptr, png_infop info_ptr, png_colorp *palette, int *num_palette);
extern  void __cdecl png_set_PLTE (png_structp png_ptr, png_infop info_ptr, png_colorp palette, int num_palette);
extern  png_uint_32 __cdecl png_get_sBIT (png_structp png_ptr, png_infop info_ptr, png_color_8p *sig_bit);
extern  void __cdecl png_set_sBIT (png_structp png_ptr, png_infop info_ptr, png_color_8p sig_bit);
extern  png_uint_32 __cdecl png_get_sRGB (png_structp png_ptr, png_infop info_ptr, int *intent);
extern  void __cdecl png_set_sRGB (png_structp png_ptr, png_infop info_ptr, int intent);
extern  void __cdecl png_set_sRGB_gAMA_and_cHRM (png_structp png_ptr, png_infop info_ptr, int intent);
extern  png_uint_32 __cdecl png_get_iCCP (png_structp png_ptr, png_infop info_ptr, png_charpp name, int *compression_type, png_charpp profile, png_uint_32 *proflen);
extern  void __cdecl png_set_iCCP (png_structp png_ptr, png_infop info_ptr, png_charp name, int compression_type, png_charp profile, png_uint_32 proflen);
extern  png_uint_32 __cdecl png_get_sPLT (png_structp png_ptr, png_infop info_ptr, png_sPLT_tpp entries);
extern  void __cdecl png_set_sPLT (png_structp png_ptr, png_infop info_ptr, png_sPLT_tp entries, int nentries);
extern  png_uint_32 __cdecl png_get_text (png_structp png_ptr, png_infop info_ptr, png_textp *text_ptr, int *num_text);
extern  void __cdecl png_set_text (png_structp png_ptr, png_infop info_ptr, png_textp text_ptr, int num_text);
extern  png_uint_32 __cdecl png_get_tIME (png_structp png_ptr, png_infop info_ptr, png_timep *mod_time);
extern  void __cdecl png_set_tIME (png_structp png_ptr, png_infop info_ptr, png_timep mod_time);
extern  png_uint_32 __cdecl png_get_tRNS (png_structp png_ptr, png_infop info_ptr, png_bytep *trans, int *num_trans, png_color_16p *trans_values);
extern  void __cdecl png_set_tRNS (png_structp png_ptr, png_infop info_ptr, png_bytep trans, int num_trans, png_color_16p trans_values);
extern  png_uint_32 __cdecl png_get_sCAL (png_structp png_ptr, png_infop info_ptr, int *unit, double *width, double *height);
extern  void __cdecl png_set_sCAL (png_structp png_ptr, png_infop info_ptr, int unit, double width, double height);
extern  void __cdecl png_set_keep_unknown_chunks (png_structp png_ptr, int keep, png_bytep chunk_list, int num_chunks);
extern  void __cdecl png_set_unknown_chunks (png_structp png_ptr, png_infop info_ptr, png_unknown_chunkp unknowns, int num_unknowns);
extern  void __cdecl png_set_unknown_chunk_location
 (png_structp png_ptr, png_infop info_ptr, int chunk, int location);
extern  png_uint_32 __cdecl png_get_unknown_chunks (png_structp png_ptr, png_infop info_ptr, png_unknown_chunkpp entries);
 int __cdecl png_handle_as_unknown (png_structp png_ptr, png_bytep chunk_name);
extern  void __cdecl png_set_invalid (png_structp png_ptr, png_infop info_ptr, int mask);
extern  void __cdecl png_read_png (png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);
extern  void __cdecl png_write_png (png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);
extern  png_charp __cdecl png_get_copyright (png_structp png_ptr);
extern  png_charp __cdecl png_get_header_ver (png_structp png_ptr);
extern  png_charp __cdecl png_get_header_version (png_structp png_ptr);
extern  png_charp __cdecl png_get_libpng_ver (png_structp png_ptr);
extern  png_uint_32 __cdecl png_permit_mng_features (png_structp png_ptr, png_uint_32 mng_features_permitted);
extern  png_uint_32 __cdecl png_get_mmx_flagmask
 (int flag_select, int *compilerID);
extern  png_uint_32 __cdecl png_get_asm_flagmask
 (int flag_select);
extern  png_uint_32 __cdecl png_get_asm_flags
 (png_structp png_ptr);
extern  png_byte __cdecl png_get_mmx_bitdepth_threshold
 (png_structp png_ptr);
extern  png_uint_32 __cdecl png_get_mmx_rowbytes_threshold
 (png_structp png_ptr);
extern  void __cdecl png_set_asm_flags
 (png_structp png_ptr, png_uint_32 asm_flags);
extern  void __cdecl png_set_mmx_thresholds
 (png_structp png_ptr, png_byte mmx_bitdepth_threshold, png_uint_32 mmx_rowbytes_threshold);
extern  int __cdecl png_mmx_support (void);
extern  void __cdecl png_set_strip_error_numbers (png_structp png_ptr, png_uint_32 strip_mode);
extern  void __cdecl png_set_user_limits (png_structp png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max);
extern  png_uint_32 __cdecl png_get_user_width_max (png_structp png_ptr);
extern  png_uint_32 __cdecl png_get_user_height_max (png_structp png_ptr);
extern  png_uint_32 __cdecl png_get_uint_32 (png_bytep buf);
extern  png_uint_16 __cdecl png_get_uint_16 (png_bytep buf);
extern  png_int_32 __cdecl png_get_int_32 (png_bytep buf);
extern  png_uint_32 __cdecl png_get_uint_31
 (png_structp png_ptr, png_bytep buf);
extern  void __cdecl png_save_uint_32
 (png_bytep buf, png_uint_32 i);
extern  void __cdecl png_save_int_32
 (png_bytep buf, png_int_32 i);
extern  void __cdecl png_save_uint_16
 (png_bytep buf, unsigned int i);
extern  void __cdecl png_read_init (png_structp png_ptr);
extern  void __cdecl png_read_init_3 (png_structpp ptr_ptr, png_const_charp user_png_ver, png_size_t png_struct_size);
extern  void __cdecl png_read_init_2 (png_structp png_ptr, png_const_charp user_png_ver, png_size_t png_struct_size, png_size_t png_info_size);
extern  void __cdecl png_write_init (png_structp png_ptr);
extern  void __cdecl png_write_init_3 (png_structpp ptr_ptr, png_const_charp user_png_ver, png_size_t png_struct_size);
extern  void __cdecl png_write_init_2 (png_structp png_ptr, png_const_charp user_png_ver, png_size_t png_struct_size, png_size_t png_info_size);
 png_voidp png_create_struct (int type);
 void png_destroy_struct (png_voidp struct_ptr);
 png_voidp png_create_struct_2 (int type, png_malloc_ptr malloc_fn, png_voidp mem_ptr);
 void png_destroy_struct_2 (png_voidp struct_ptr, png_free_ptr free_fn, png_voidp mem_ptr);
 void png_info_destroy (png_structp png_ptr, png_infop info_ptr);
 voidpf png_zalloc (voidpf png_ptr, uInt items, uInt size);
 void png_zfree (voidpf png_ptr, voidpf ptr);
 void __cdecl png_default_read_data (png_structp png_ptr, png_bytep data, png_size_t length);
 void __cdecl png_push_fill_buffer (png_structp png_ptr, png_bytep buffer, png_size_t length);
 void __cdecl png_default_write_data (png_structp png_ptr, png_bytep data, png_size_t length);
 void __cdecl png_default_flush (png_structp png_ptr);
 void png_reset_crc (png_structp png_ptr);
 void png_write_data (png_structp png_ptr, png_bytep data, png_size_t length);
 void png_read_data (png_structp png_ptr, png_bytep data, png_size_t length);
 void png_crc_read (png_structp png_ptr, png_bytep buf, png_size_t length);
 png_charp png_decompress_chunk (png_structp png_ptr, int comp_type, png_charp chunkdata, png_size_t chunklength, png_size_t prefix_length, png_size_t *data_length);
 int png_crc_finish (png_structp png_ptr, png_uint_32 skip);
 int png_crc_error (png_structp png_ptr);
 void png_calculate_crc (png_structp png_ptr, png_bytep ptr, png_size_t length);
 void png_flush (png_structp png_ptr);
 void png_write_sig (png_structp png_ptr);
 void png_write_IHDR (png_structp png_ptr, png_uint_32 width, png_uint_32 height, int bit_depth, int color_type, int compression_method, int filter_method, int interlace_method);
 void png_write_PLTE (png_structp png_ptr, png_colorp palette, png_uint_32 num_pal);
 void png_write_IDAT (png_structp png_ptr, png_bytep data, png_size_t length);
 void png_write_IEND (png_structp png_ptr);
 void png_write_gAMA (png_structp png_ptr, double file_gamma);
 void png_write_gAMA_fixed (png_structp png_ptr, png_fixed_point file_gamma);
 void png_write_sBIT (png_structp png_ptr, png_color_8p sbit, int color_type);
 void png_write_cHRM (png_structp png_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y);
 void png_write_cHRM_fixed (png_structp png_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y);
 void png_write_sRGB (png_structp png_ptr, int intent);
 void png_write_iCCP (png_structp png_ptr, png_charp name, int compression_type, png_charp profile, int proflen);
 void png_write_sPLT (png_structp png_ptr, png_sPLT_tp palette);
 void png_write_tRNS (png_structp png_ptr, png_bytep trans, png_color_16p values, int number, int color_type);
 void png_write_bKGD (png_structp png_ptr, png_color_16p values, int color_type);
 void png_write_hIST (png_structp png_ptr, png_uint_16p hist, int num_hist);
 png_size_t png_check_keyword (png_structp png_ptr, png_charp key, png_charpp new_key);
 void png_write_tEXt (png_structp png_ptr, png_charp key, png_charp text, png_size_t text_len);
 void png_write_zTXt (png_structp png_ptr, png_charp key, png_charp text, png_size_t text_len, int compression);
 int png_set_text_2 (png_structp png_ptr, png_infop info_ptr, png_textp text_ptr, int num_text);
 void png_write_oFFs (png_structp png_ptr, png_int_32 x_offset, png_int_32 y_offset, int unit_type);
 void png_write_pCAL (png_structp png_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1, int type, int nparams, png_charp units, png_charpp params);
 void png_write_pHYs (png_structp png_ptr, png_uint_32 x_pixels_per_unit, png_uint_32 y_pixels_per_unit, int unit_type);
 void png_write_tIME (png_structp png_ptr, png_timep mod_time);
 void png_write_sCAL (png_structp png_ptr, int unit, double width, double height);
 void png_write_finish_row (png_structp png_ptr);
 void png_write_start_row (png_structp png_ptr);
 void png_build_gamma_table (png_structp png_ptr);
 void png_combine_row (png_structp png_ptr, png_bytep row, int mask);
 void png_do_read_interlace (png_structp png_ptr);
 void png_do_write_interlace (png_row_infop row_info, png_bytep row, int pass);
 void png_read_filter_row (png_structp png_ptr, png_row_infop row_info, png_bytep row, png_bytep prev_row, int filter);
 void png_write_find_filter (png_structp png_ptr, png_row_infop row_info);
 void png_write_filtered_row (png_structp png_ptr, png_bytep filtered_row);
 void png_read_finish_row (png_structp png_ptr);
 void png_read_start_row (png_structp png_ptr);
 void png_read_transform_info (png_structp png_ptr, png_infop info_ptr);
 void png_do_read_filler (png_row_infop row_info, png_bytep row, png_uint_32 filler, png_uint_32 flags);
 void png_do_read_swap_alpha (png_row_infop row_info, png_bytep row);
 void png_do_write_swap_alpha (png_row_infop row_info, png_bytep row);
 void png_do_read_invert_alpha (png_row_infop row_info, png_bytep row);
 void png_do_write_invert_alpha (png_row_infop row_info, png_bytep row);
 void png_do_strip_filler (png_row_infop row_info, png_bytep row, png_uint_32 flags);
 void png_do_swap (png_row_infop row_info, png_bytep row);
 void png_do_packswap (png_row_infop row_info, png_bytep row);
 int png_do_rgb_to_gray (png_structp png_ptr, png_row_infop row_info, png_bytep row);
 void png_do_gray_to_rgb (png_row_infop row_info, png_bytep row);
 void png_do_unpack (png_row_infop row_info, png_bytep row);
 void png_do_unshift (png_row_infop row_info, png_bytep row, png_color_8p sig_bits);
 void png_do_invert (png_row_infop row_info, png_bytep row);
 void png_do_chop (png_row_infop row_info, png_bytep row);
 void png_do_dither (png_row_infop row_info, png_bytep row, png_bytep palette_lookup, png_bytep dither_lookup);
 void png_do_bgr (png_row_infop row_info, png_bytep row);
 void png_do_pack (png_row_infop row_info, png_bytep row, png_uint_32 bit_depth);
 void png_do_shift (png_row_infop row_info, png_bytep row, png_color_8p bit_depth);
 void png_do_background (png_row_infop row_info, png_bytep row, png_color_16p trans_values, png_color_16p background, png_color_16p background_1, png_bytep gamma_table, png_bytep gamma_from_1, png_bytep gamma_to_1, png_uint_16pp gamma_16, png_uint_16pp gamma_16_from_1, png_uint_16pp gamma_16_to_1, int gamma_shift);
 void png_do_gamma (png_row_infop row_info, png_bytep row, png_bytep gamma_table, png_uint_16pp gamma_16_table, int gamma_shift);
 void png_do_expand_palette (png_row_infop row_info, png_bytep row, png_colorp palette, png_bytep trans, int num_trans);
 void png_do_expand (png_row_infop row_info, png_bytep row, png_color_16p trans_value);
 void png_handle_IHDR (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_PLTE (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_IEND (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_bKGD (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_cHRM (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_gAMA (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_hIST (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
extern void png_handle_iCCP (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_oFFs (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_pCAL (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_pHYs (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_sBIT (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_sCAL (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
extern void png_handle_sPLT (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_sRGB (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_tEXt (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_tIME (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_tRNS (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_zTXt (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_handle_unknown (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_check_chunk_name (png_structp png_ptr, png_bytep chunk_name);
 void png_do_read_transformations (png_structp png_ptr);
 void png_do_write_transformations (png_structp png_ptr);
 void png_init_read_transformations (png_structp png_ptr);
 void png_push_read_chunk (png_structp png_ptr, png_infop info_ptr);
 void png_push_read_sig (png_structp png_ptr, png_infop info_ptr);
 void png_push_check_crc (png_structp png_ptr);
 void png_push_crc_skip (png_structp png_ptr, png_uint_32 length);
 void png_push_crc_finish (png_structp png_ptr);
 void png_push_save_buffer (png_structp png_ptr);
 void png_push_restore_buffer (png_structp png_ptr, png_bytep buffer, png_size_t buffer_length);
 void png_push_read_IDAT (png_structp png_ptr);
 void png_process_IDAT_data (png_structp png_ptr, png_bytep buffer, png_size_t buffer_length);
 void png_push_process_row (png_structp png_ptr);
 void png_push_handle_unknown (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_push_have_info (png_structp png_ptr, png_infop info_ptr);
 void png_push_have_end (png_structp png_ptr, png_infop info_ptr);
 void png_push_have_row (png_structp png_ptr, png_bytep row);
 void png_push_read_end (png_structp png_ptr, png_infop info_ptr);
 void png_process_some_data (png_structp png_ptr, png_infop info_ptr);
 void png_read_push_finish_row (png_structp png_ptr);
 void png_push_handle_tEXt (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_push_read_tEXt (png_structp png_ptr, png_infop info_ptr);
 void png_push_handle_zTXt (png_structp png_ptr, png_infop info_ptr, png_uint_32 length);
 void png_push_read_zTXt (png_structp png_ptr, png_infop info_ptr);
 void png_do_read_intrapixel (png_row_infop row_info, png_bytep row);
 void png_do_write_intrapixel (png_row_infop row_info, png_bytep row);
 void png_init_mmx_flags (png_structp png_ptr);
void __cdecl
png_save_uint_32(png_bytep buf, png_uint_32 i)
{
 buf[0] = (png_byte)((i >> 24) & 0xff);
 buf[1] = (png_byte)((i >> 16) & 0xff);
 buf[2] = (png_byte)((i >> 8) & 0xff);
 buf[3] = (png_byte)(i & 0xff);
}
void __cdecl
png_save_int_32(png_bytep buf, png_int_32 i)
{
 buf[0] = (png_byte)((i >> 24) & 0xff);
 buf[1] = (png_byte)((i >> 16) & 0xff);
 buf[2] = (png_byte)((i >> 8) & 0xff);
 buf[3] = (png_byte)(i & 0xff);
}
void __cdecl
png_save_uint_16(png_bytep buf, unsigned int i)
{
 buf[0] = (png_byte)((i >> 8) & 0xff);
 buf[1] = (png_byte)(i & 0xff);
}
void __cdecl
png_write_chunk(png_structp png_ptr, png_bytep chunk_name,
 png_bytep data, png_size_t length)
{
 if(png_ptr == ((void *)0)) return;
 png_write_chunk_start(png_ptr, chunk_name, (png_uint_32)length);
 png_write_chunk_data(png_ptr, data, length);
 png_write_chunk_end(png_ptr);
}
void __cdecl
png_write_chunk_start(png_structp png_ptr, png_bytep chunk_name,
 png_uint_32 length)
{
 png_byte buf[4];
 ;
 if(png_ptr == ((void *)0)) return;
 png_save_uint_32(buf, length);
 png_write_data(png_ptr, buf, (png_size_t)4);
 png_write_data(png_ptr, chunk_name, (png_size_t)4);
 png_reset_crc(png_ptr);
 png_calculate_crc(png_ptr, chunk_name, (png_size_t)4);
}
void __cdecl
png_write_chunk_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
 if(png_ptr == ((void *)0)) return;
 if (data != ((void *)0) && length > 0)
 {
 png_calculate_crc(png_ptr, data, length);
 png_write_data(png_ptr, data, length);
 }
}
void __cdecl
png_write_chunk_end(png_structp png_ptr)
{
 png_byte buf[4];
 if(png_ptr == ((void *)0)) return;
 png_save_uint_32(buf, png_ptr->crc);
 png_write_data(png_ptr, buf, (png_size_t)4);
}
void
png_write_sig(png_structp png_ptr)
{
 png_byte png_signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};
 png_write_data(png_ptr, &png_signature[png_ptr->sig_bytes],
 (png_size_t)8 - png_ptr->sig_bytes);
 if(png_ptr->sig_bytes < 3)
 png_ptr->mode |= 0x1000;
}
typedef struct
{
 char *input;
 int input_len;
 int num_output_ptr;
 int max_output_ptr;
 png_charpp output_ptr;
} compression_state;
static int
png_text_compress(png_structp png_ptr,
 png_charp text, png_size_t text_len, int compression,
 compression_state *comp)
{
 int ret;
 comp->num_output_ptr = 0;
 comp->max_output_ptr = 0;
 comp->output_ptr = ((void *)0);
 comp->input = ((void *)0);
 comp->input_len = 0;
 if (compression == -1)
 {
 comp->input = text;
 comp->input_len = text_len;
 return((int)text_len);
 }
 if (compression >= 3)
 {
 char msg[50];
 _snprintf(msg, 50, "Unknown compression type %d", compression);
 png_warning(png_ptr, msg);
 }
 png_ptr->zstream.avail_in = (uInt)text_len;
 png_ptr->zstream.next_in = (Bytef *)text;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.next_out = (Bytef *)png_ptr->zbuf;
 do
 {
 ret = deflate(&png_ptr->zstream, 0);
 if (ret != 0)
 {
 if (png_ptr->zstream.msg != ((void *)0))
 png_error(png_ptr, png_ptr->zstream.msg);
 else
 png_error(png_ptr, "zlib error");
 }
 if (!(png_ptr->zstream.avail_out))
 {
 if (comp->num_output_ptr >= comp->max_output_ptr)
 {
 int old_max;
 old_max = comp->max_output_ptr;
 comp->max_output_ptr = comp->num_output_ptr + 4;
 if (comp->output_ptr != ((void *)0))
 {
 png_charpp old_ptr;
 old_ptr = comp->output_ptr;
 comp->output_ptr = (png_charpp)png_malloc(png_ptr,
 (png_uint_32)(comp->max_output_ptr *
 sizeof (png_charpp)));
 memcpy(comp->output_ptr, old_ptr, old_max
 * sizeof (png_charp));
 png_free(png_ptr, old_ptr);
 }
 else
 comp->output_ptr = (png_charpp)png_malloc(png_ptr,
 (png_uint_32)(comp->max_output_ptr *
 sizeof (png_charp)));
 }
 comp->output_ptr[comp->num_output_ptr] = (png_charp)png_malloc(png_ptr,
 (png_uint_32)png_ptr->zbuf_size);
 memcpy(comp->output_ptr[comp->num_output_ptr], png_ptr->zbuf,
 png_ptr->zbuf_size);
 comp->num_output_ptr++;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.next_out = png_ptr->zbuf;
 }
 } while (png_ptr->zstream.avail_in);
 do
 {
 ret = deflate(&png_ptr->zstream, 4);
 if (ret == 0)
 {
 if (!(png_ptr->zstream.avail_out))
 {
 if (comp->num_output_ptr >= comp->max_output_ptr)
 {
 int old_max;
 old_max = comp->max_output_ptr;
 comp->max_output_ptr = comp->num_output_ptr + 4;
 if (comp->output_ptr != ((void *)0))
 {
 png_charpp old_ptr;
 old_ptr = comp->output_ptr;
 comp->output_ptr = (png_charpp)png_malloc(png_ptr,
 (png_uint_32)(comp->max_output_ptr *
 sizeof (png_charpp)));
 memcpy(comp->output_ptr, old_ptr,
 old_max * sizeof (png_charp));
 png_free(png_ptr, old_ptr);
 }
 else
 comp->output_ptr = (png_charpp)png_malloc(png_ptr,
 (png_uint_32)(comp->max_output_ptr *
 sizeof (png_charp)));
 }
 comp->output_ptr[comp->num_output_ptr] =
 (png_charp)png_malloc(png_ptr, (png_uint_32)png_ptr->zbuf_size);
 memcpy(comp->output_ptr[comp->num_output_ptr], png_ptr->zbuf,
 png_ptr->zbuf_size);
 comp->num_output_ptr++;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.next_out = png_ptr->zbuf;
 }
 }
 else if (ret != 1)
 {
 if (png_ptr->zstream.msg != ((void *)0))
 png_error(png_ptr, png_ptr->zstream.msg);
 else
 png_error(png_ptr, "zlib error");
 }
 } while (ret != 1);
 text_len = png_ptr->zbuf_size * comp->num_output_ptr;
 if (png_ptr->zstream.avail_out < png_ptr->zbuf_size)
 text_len += png_ptr->zbuf_size - (png_size_t)png_ptr->zstream.avail_out;
 return((int)text_len);
}
static void
png_write_compressed_data_out(png_structp png_ptr, compression_state *comp)
{
 int i;
 if (comp->input)
 {
 png_write_chunk_data(png_ptr, (png_bytep)comp->input,
 (png_size_t)comp->input_len);
 return;
 }
 for (i = 0; i < comp->num_output_ptr; i++)
 {
 png_write_chunk_data(png_ptr,(png_bytep)comp->output_ptr[i],
 png_ptr->zbuf_size);
 png_free(png_ptr, comp->output_ptr[i]);
 comp->output_ptr[i]=((void *)0);
 }
 if (comp->max_output_ptr != 0)
 png_free(png_ptr, comp->output_ptr);
 comp->output_ptr=((void *)0);
 if (png_ptr->zstream.avail_out < (png_uint_32)png_ptr->zbuf_size)
 png_write_chunk_data(png_ptr, png_ptr->zbuf,
 png_ptr->zbuf_size - png_ptr->zstream.avail_out);
 deflateReset(&png_ptr->zstream);
 png_ptr->zstream.data_type = 0;
}
void
png_write_IHDR(png_structp png_ptr, png_uint_32 width, png_uint_32 height,
 int bit_depth, int color_type, int compression_type, int filter_type,
 int interlace_type)
{
 png_byte png_IHDR[5] = { 73, 72, 68, 82, '\0'};
 png_byte buf[13];
 ;
 switch (color_type)
 {
 case 0:
 switch (bit_depth)
 {
 case 1:
 case 2:
 case 4:
 case 8:
 case 16: png_ptr->channels = 1; break;
 default: png_error(png_ptr,"Invalid bit depth for grayscale image");
 }
 break;
 case (2):
 if (bit_depth != 8 && bit_depth != 16)
 png_error(png_ptr, "Invalid bit depth for RGB image");
 png_ptr->channels = 3;
 break;
 case (2 | 1):
 switch (bit_depth)
 {
 case 1:
 case 2:
 case 4:
 case 8: png_ptr->channels = 1; break;
 default: png_error(png_ptr, "Invalid bit depth for paletted image");
 }
 break;
 case (4):
 if (bit_depth != 8 && bit_depth != 16)
 png_error(png_ptr, "Invalid bit depth for grayscale+alpha image");
 png_ptr->channels = 2;
 break;
 case (2 | 4):
 if (bit_depth != 8 && bit_depth != 16)
 png_error(png_ptr, "Invalid bit depth for RGBA image");
 png_ptr->channels = 4;
 break;
 default:
 png_error(png_ptr, "Invalid image color type specified");
 }
 if (compression_type != 0)
 {
 png_warning(png_ptr, "Invalid compression type specified");
 compression_type = 0;
 }
 if (
 !((png_ptr->mng_features_permitted & 0x04) &&
 ((png_ptr->mode&0x1000) == 0) &&
 (color_type == (2) ||
 color_type == (2 | 4)) &&
 (filter_type == 64)) &&
 filter_type != 0)
 {
 png_warning(png_ptr, "Invalid filter type specified");
 filter_type = 0;
 }
 if (interlace_type != 0 &&
 interlace_type != 1)
 {
 png_warning(png_ptr, "Invalid interlace type specified");
 interlace_type = 1;
 }
 png_ptr->bit_depth = (png_byte)bit_depth;
 png_ptr->color_type = (png_byte)color_type;
 png_ptr->interlaced = (png_byte)interlace_type;
 png_ptr->filter_type = (png_byte)filter_type;
 png_ptr->compression_type = (png_byte)compression_type;
 png_ptr->width = width;
 png_ptr->height = height;
 png_ptr->pixel_depth = (png_byte)(bit_depth * png_ptr->channels);
 png_ptr->rowbytes = ((png_ptr->pixel_depth) >= 8 ? ((width) * (((png_uint_32)(png_ptr->pixel_depth)) >> 3)) : (( ((width) * ((png_uint_32)(png_ptr->pixel_depth))) + 7) >> 3) );
 png_ptr->usr_width = png_ptr->width;
 png_ptr->usr_bit_depth = png_ptr->bit_depth;
 png_ptr->usr_channels = png_ptr->channels;
 png_save_uint_32(buf, width);
 png_save_uint_32(buf + 4, height);
 buf[8] = (png_byte)bit_depth;
 buf[9] = (png_byte)color_type;
 buf[10] = (png_byte)compression_type;
 buf[11] = (png_byte)filter_type;
 buf[12] = (png_byte)interlace_type;
 png_write_chunk(png_ptr, png_IHDR, buf, (png_size_t)13);
 png_ptr->zstream.zalloc = png_zalloc;
 png_ptr->zstream.zfree = png_zfree;
 png_ptr->zstream.opaque = (voidpf)png_ptr;
 if (!(png_ptr->do_filter))
 {
 if (png_ptr->color_type == (2 | 1) ||
 png_ptr->bit_depth < 8)
 png_ptr->do_filter = 0x08;
 else
 png_ptr->do_filter = (0x08 | 0x10 | 0x20 | 0x40 | 0x80);
 }
 if (!(png_ptr->flags & 0x0001))
 {
 if (png_ptr->do_filter != 0x08)
 png_ptr->zlib_strategy = 1;
 else
 png_ptr->zlib_strategy = 0;
 }
 if (!(png_ptr->flags & 0x0002))
 png_ptr->zlib_level = (-1);
 if (!(png_ptr->flags & 0x0004))
 png_ptr->zlib_mem_level = 8;
 if (!(png_ptr->flags & 0x0008))
 png_ptr->zlib_window_bits = 15;
 if (!(png_ptr->flags & 0x0010))
 png_ptr->zlib_method = 8;
 if (deflateInit2_((&png_ptr->zstream),(png_ptr->zlib_level),(png_ptr->zlib_method),(png_ptr->zlib_window_bits),(png_ptr->zlib_mem_level), (png_ptr->zlib_strategy), "1.2.3", sizeof(z_stream)) != 0)
 png_error(png_ptr, "zlib failed to initialize compressor");
 png_ptr->zstream.next_out = png_ptr->zbuf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.data_type = 0;
 png_ptr->mode = 0x01;
}
void
png_write_PLTE(png_structp png_ptr, png_colorp palette, png_uint_32 num_pal)
{
 png_byte png_PLTE[5] = { 80, 76, 84, 69, '\0'};
 png_uint_32 i;
 png_colorp pal_ptr;
 png_byte buf[3];
 ;
 if ((
 !(png_ptr->mng_features_permitted & 0x01) &&
 num_pal == 0) || num_pal > 256)
 {
 if (png_ptr->color_type == (2 | 1))
 {
 png_error(png_ptr, "Invalid number of colors in palette");
 }
 else
 {
 png_warning(png_ptr, "Invalid number of colors in palette");
 return;
 }
 }
 if (!(png_ptr->color_type&2))
 {
 png_warning(png_ptr,
 "Ignoring request to write a PLTE chunk in grayscale PNG");
 return;
 }
 png_ptr->num_palette = (png_uint_16)num_pal;
 ;
 png_write_chunk_start(png_ptr, png_PLTE, num_pal * 3);
 for (i = 0, pal_ptr = palette; i < num_pal; i++, pal_ptr++)
 {
 buf[0] = pal_ptr->red;
 buf[1] = pal_ptr->green;
 buf[2] = pal_ptr->blue;
 png_write_chunk_data(png_ptr, buf, (png_size_t)3);
 }
 png_write_chunk_end(png_ptr);
 png_ptr->mode |= 0x02;
}
void
png_write_IDAT(png_structp png_ptr, png_bytep data, png_size_t length)
{
 png_byte png_IDAT[5] = { 73, 68, 65, 84, '\0'};
 ;
 if (!(png_ptr->mode & 0x04) &&
 png_ptr->compression_type == 0)
 {
 unsigned int z_cmf = data[0];
 if ((z_cmf & 0x0f) == 8 && (z_cmf & 0xf0) <= 0x70)
 {
 if (length >= 2 &&
 png_ptr->height < 16384 && png_ptr->width < 16384)
 {
 png_uint_32 uncompressed_idat_size = png_ptr->height *
 ((png_ptr->width *
 png_ptr->channels * png_ptr->bit_depth + 15) >> 3);
 unsigned int z_cinfo = z_cmf >> 4;
 unsigned int half_z_window_size = 1 << (z_cinfo + 7);
 while (uncompressed_idat_size <= half_z_window_size &&
 half_z_window_size >= 256)
 {
 z_cinfo--;
 half_z_window_size >>= 1;
 }
 z_cmf = (z_cmf & 0x0f) | (z_cinfo << 4);
 if (data[0] != (png_byte)z_cmf)
 {
 data[0] = (png_byte)z_cmf;
 data[1] &= 0xe0;
 data[1] += (png_byte)(0x1f - ((z_cmf << 8) + data[1]) % 0x1f);
 }
 }
 }
 else
 png_error(png_ptr,
 "Invalid zlib compression method or flags in IDAT");
 }
 png_write_chunk(png_ptr, png_IDAT, data, length);
 png_ptr->mode |= 0x04;
}
void
png_write_IEND(png_structp png_ptr)
{
 png_byte png_IEND[5] = { 73, 69, 78, 68, '\0'};
 ;
 png_write_chunk(png_ptr, png_IEND, (png_bytep)((void *)0),
 (png_size_t)0);
 png_ptr->mode |= 0x10;
}
void
png_write_gAMA(png_structp png_ptr, double file_gamma)
{
 png_byte png_gAMA[5] = {103, 65, 77, 65, '\0'};
 png_uint_32 igamma;
 png_byte buf[4];
 ;
 igamma = (png_uint_32)(file_gamma * 100000.0 + 0.5);
 png_save_uint_32(buf, igamma);
 png_write_chunk(png_ptr, png_gAMA, buf, (png_size_t)4);
}
void
png_write_gAMA_fixed(png_structp png_ptr, png_fixed_point file_gamma)
{
 png_byte png_gAMA[5] = {103, 65, 77, 65, '\0'};
 png_byte buf[4];
 ;
 png_save_uint_32(buf, (png_uint_32)file_gamma);
 png_write_chunk(png_ptr, png_gAMA, buf, (png_size_t)4);
}
void
png_write_sRGB(png_structp png_ptr, int srgb_intent)
{
 png_byte png_sRGB[5] = {115, 82, 71, 66, '\0'};
 png_byte buf[1];
 ;
 if(srgb_intent >= 4)
 png_warning(png_ptr,
 "Invalid sRGB rendering intent specified");
 buf[0]=(png_byte)srgb_intent;
 png_write_chunk(png_ptr, png_sRGB, buf, (png_size_t)1);
}
void
png_write_iCCP(png_structp png_ptr, png_charp name, int compression_type,
 png_charp profile, int profile_len)
{
 png_byte png_iCCP[5] = {105, 67, 67, 80, '\0'};
 png_size_t name_len;
 png_charp new_name;
 compression_state comp;
 int embedded_profile_len = 0;
 ;
 comp.num_output_ptr = 0;
 comp.max_output_ptr = 0;
 comp.output_ptr = ((void *)0);
 comp.input = ((void *)0);
 comp.input_len = 0;
 if (name == ((void *)0) || (name_len = png_check_keyword(png_ptr, name,
 &new_name)) == 0)
 {
 png_warning(png_ptr, "Empty keyword in iCCP chunk");
 return;
 }
 if (compression_type != 0)
 png_warning(png_ptr, "Unknown compression type in iCCP chunk");
 if (profile == ((void *)0))
 profile_len = 0;
 if (profile_len > 3)
 embedded_profile_len =
 ((*( (png_bytep)profile  ))<<24) |
 ((*( (png_bytep)profile+1))<<16) |
 ((*( (png_bytep)profile+2))<< 8) |
 ((*( (png_bytep)profile+3))    );
 if (profile_len < embedded_profile_len)
 {
 png_warning(png_ptr,
 "Embedded profile length too large in iCCP chunk");
 return;
 }
 if (profile_len > embedded_profile_len)
 {
 png_warning(png_ptr,
 "Truncating profile to actual length in iCCP chunk");
 profile_len = embedded_profile_len;
 }
 if (profile_len)
 profile_len = png_text_compress(png_ptr, profile, (png_size_t)profile_len,
 0, &comp);
 png_write_chunk_start(png_ptr, png_iCCP,
 (png_uint_32)name_len+profile_len+2);
 new_name[name_len+1]=0x00;
 png_write_chunk_data(png_ptr, (png_bytep)new_name, name_len + 2);
 if (profile_len)
 png_write_compressed_data_out(png_ptr, &comp);
 png_write_chunk_end(png_ptr);
 png_free(png_ptr, new_name);
}
void
png_write_sPLT(png_structp png_ptr, png_sPLT_tp spalette)
{
 png_byte png_sPLT[5] = {115, 80, 76, 84, '\0'};
 png_size_t name_len;
 png_charp new_name;
 png_byte entrybuf[10];
 int entry_size = (spalette->depth == 8 ? 6 : 10);
 int palette_size = entry_size * spalette->nentries;
 png_sPLT_entryp ep;
 ;
 if (spalette->name == ((void *)0) || (name_len = png_check_keyword(png_ptr,
 spalette->name, &new_name))==0)
 {
 png_warning(png_ptr, "Empty keyword in sPLT chunk");
 return;
 }
 png_write_chunk_start(png_ptr, png_sPLT,
 (png_uint_32)(name_len + 2 + palette_size));
 png_write_chunk_data(png_ptr, (png_bytep)new_name, name_len + 1);
 png_write_chunk_data(png_ptr, (png_bytep)&spalette->depth, 1);
 for (ep = spalette->entries; ep<spalette->entries+spalette->nentries; ep++)
 {
 if (spalette->depth == 8)
 {
 entrybuf[0] = (png_byte)ep->red;
 entrybuf[1] = (png_byte)ep->green;
 entrybuf[2] = (png_byte)ep->blue;
 entrybuf[3] = (png_byte)ep->alpha;
 png_save_uint_16(entrybuf + 4, ep->frequency);
 }
 else
 {
 png_save_uint_16(entrybuf + 0, ep->red);
 png_save_uint_16(entrybuf + 2, ep->green);
 png_save_uint_16(entrybuf + 4, ep->blue);
 png_save_uint_16(entrybuf + 6, ep->alpha);
 png_save_uint_16(entrybuf + 8, ep->frequency);
 }
 png_write_chunk_data(png_ptr, entrybuf, (png_size_t)entry_size);
 }
 png_write_chunk_end(png_ptr);
 png_free(png_ptr, new_name);
}
void
png_write_sBIT(png_structp png_ptr, png_color_8p sbit, int color_type)
{
 png_byte png_sBIT[5] = {115, 66, 73, 84, '\0'};
 png_byte buf[4];
 png_size_t size;
 ;
 if (color_type & 2)
 {
 png_byte maxbits;
 maxbits = (png_byte)(color_type==(2 | 1) ? 8 :
 png_ptr->usr_bit_depth);
 if (sbit->red == 0 || sbit->red > maxbits ||
 sbit->green == 0 || sbit->green > maxbits ||
 sbit->blue == 0 || sbit->blue > maxbits)
 {
 png_warning(png_ptr, "Invalid sBIT depth specified");
 return;
 }
 buf[0] = sbit->red;
 buf[1] = sbit->green;
 buf[2] = sbit->blue;
 size = 3;
 }
 else
 {
 if (sbit->gray == 0 || sbit->gray > png_ptr->usr_bit_depth)
 {
 png_warning(png_ptr, "Invalid sBIT depth specified");
 return;
 }
 buf[0] = sbit->gray;
 size = 1;
 }
 if (color_type & 4)
 {
 if (sbit->alpha == 0 || sbit->alpha > png_ptr->usr_bit_depth)
 {
 png_warning(png_ptr, "Invalid sBIT depth specified");
 return;
 }
 buf[size++] = sbit->alpha;
 }
 png_write_chunk(png_ptr, png_sBIT, buf, size);
}
void
png_write_cHRM(png_structp png_ptr, double white_x, double white_y,
 double red_x, double red_y, double green_x, double green_y,
 double blue_x, double blue_y)
{
 png_byte png_cHRM[5] = { 99, 72, 82, 77, '\0'};
 png_byte buf[32];
 png_uint_32 itemp;
 ;
 if (white_x < 0 || white_x > 0.8 || white_y < 0 || white_y > 0.8 ||
 white_x + white_y > 1.0)
 {
 png_warning(png_ptr, "Invalid cHRM white point specified");
 fprintf((&__iob_func()[2]),"white_x=%f, white_y=%f\n",white_x, white_y);
 return;
 }
 itemp = (png_uint_32)(white_x * 100000.0 + 0.5);
 png_save_uint_32(buf, itemp);
 itemp = (png_uint_32)(white_y * 100000.0 + 0.5);
 png_save_uint_32(buf + 4, itemp);
 if (red_x < 0 ||  red_y < 0 || red_x + red_y > 1.0)
 {
 png_warning(png_ptr, "Invalid cHRM red point specified");
 return;
 }
 itemp = (png_uint_32)(red_x * 100000.0 + 0.5);
 png_save_uint_32(buf + 8, itemp);
 itemp = (png_uint_32)(red_y * 100000.0 + 0.5);
 png_save_uint_32(buf + 12, itemp);
 if (green_x < 0 || green_y < 0 || green_x + green_y > 1.0)
 {
 png_warning(png_ptr, "Invalid cHRM green point specified");
 return;
 }
 itemp = (png_uint_32)(green_x * 100000.0 + 0.5);
 png_save_uint_32(buf + 16, itemp);
 itemp = (png_uint_32)(green_y * 100000.0 + 0.5);
 png_save_uint_32(buf + 20, itemp);
 if (blue_x < 0 || blue_y < 0 || blue_x + blue_y > 1.0)
 {
 png_warning(png_ptr, "Invalid cHRM blue point specified");
 return;
 }
 itemp = (png_uint_32)(blue_x * 100000.0 + 0.5);
 png_save_uint_32(buf + 24, itemp);
 itemp = (png_uint_32)(blue_y * 100000.0 + 0.5);
 png_save_uint_32(buf + 28, itemp);
 png_write_chunk(png_ptr, png_cHRM, buf, (png_size_t)32);
}
void
png_write_cHRM_fixed(png_structp png_ptr, png_fixed_point white_x,
 png_fixed_point white_y, png_fixed_point red_x, png_fixed_point red_y,
 png_fixed_point green_x, png_fixed_point green_y, png_fixed_point blue_x,
 png_fixed_point blue_y)
{
 png_byte png_cHRM[5] = { 99, 72, 82, 77, '\0'};
 png_byte buf[32];
 ;
 if (white_x > 80000L || white_y > 80000L || white_x + white_y > 100000L)
 {
 png_warning(png_ptr, "Invalid fixed cHRM white point specified");
 fprintf((&__iob_func()[2]),"white_x=%ld, white_y=%ld\n",white_x, white_y);
 return;
 }
 png_save_uint_32(buf, (png_uint_32)white_x);
 png_save_uint_32(buf + 4, (png_uint_32)white_y);
 if (red_x + red_y > 100000L)
 {
 png_warning(png_ptr, "Invalid cHRM fixed red point specified");
 return;
 }
 png_save_uint_32(buf + 8, (png_uint_32)red_x);
 png_save_uint_32(buf + 12, (png_uint_32)red_y);
 if (green_x + green_y > 100000L)
 {
 png_warning(png_ptr, "Invalid fixed cHRM green point specified");
 return;
 }
 png_save_uint_32(buf + 16, (png_uint_32)green_x);
 png_save_uint_32(buf + 20, (png_uint_32)green_y);
 if (blue_x + blue_y > 100000L)
 {
 png_warning(png_ptr, "Invalid fixed cHRM blue point specified");
 return;
 }
 png_save_uint_32(buf + 24, (png_uint_32)blue_x);
 png_save_uint_32(buf + 28, (png_uint_32)blue_y);
 png_write_chunk(png_ptr, png_cHRM, buf, (png_size_t)32);
}
void
png_write_tRNS(png_structp png_ptr, png_bytep trans, png_color_16p tran,
 int num_trans, int color_type)
{
 png_byte png_tRNS[5] = {116, 82, 78, 83, '\0'};
 png_byte buf[6];
 ;
 if (color_type == (2 | 1))
 {
 if (num_trans <= 0 || num_trans > (int)png_ptr->num_palette)
 {
 png_warning(png_ptr,"Invalid number of transparent colors specified");
 return;
 }
 png_write_chunk(png_ptr, png_tRNS, trans, (png_size_t)num_trans);
 }
 else if (color_type == 0)
 {
 if(tran->gray >= (1 << png_ptr->bit_depth))
 {
 png_warning(png_ptr,
 "Ignoring attempt to write tRNS chunk out-of-range for bit_depth");
 return;
 }
 png_save_uint_16(buf, tran->gray);
 png_write_chunk(png_ptr, png_tRNS, buf, (png_size_t)2);
 }
 else if (color_type == (2))
 {
 png_save_uint_16(buf, tran->red);
 png_save_uint_16(buf + 2, tran->green);
 png_save_uint_16(buf + 4, tran->blue);
 if(png_ptr->bit_depth == 8 && (buf[0] | buf[2] | buf[4]))
 {
 png_warning(png_ptr,
 "Ignoring attempt to write 16-bit tRNS chunk when bit_depth is 8");
 return;
 }
 png_write_chunk(png_ptr, png_tRNS, buf, (png_size_t)6);
 }
 else
 {
 png_warning(png_ptr, "Can't write tRNS with an alpha channel");
 }
}
void
png_write_bKGD(png_structp png_ptr, png_color_16p back, int color_type)
{
 png_byte png_bKGD[5] = { 98, 75, 71, 68, '\0'};
 png_byte buf[6];
 ;
 if (color_type == (2 | 1))
 {
 if (
 (png_ptr->num_palette ||
 (!(png_ptr->mng_features_permitted & 0x01))) &&
 back->index > png_ptr->num_palette)
 {
 png_warning(png_ptr, "Invalid background palette index");
 return;
 }
 buf[0] = back->index;
 png_write_chunk(png_ptr, png_bKGD, buf, (png_size_t)1);
 }
 else if (color_type & 2)
 {
 png_save_uint_16(buf, back->red);
 png_save_uint_16(buf + 2, back->green);
 png_save_uint_16(buf + 4, back->blue);
 if(png_ptr->bit_depth == 8 && (buf[0] | buf[2] | buf[4]))
 {
 png_warning(png_ptr,
 "Ignoring attempt to write 16-bit bKGD chunk when bit_depth is 8");
 return;
 }
 png_write_chunk(png_ptr, png_bKGD, buf, (png_size_t)6);
 }
 else
 {
 if(back->gray >= (1 << png_ptr->bit_depth))
 {
 png_warning(png_ptr,
 "Ignoring attempt to write bKGD chunk out-of-range for bit_depth");
 return;
 }
 png_save_uint_16(buf, back->gray);
 png_write_chunk(png_ptr, png_bKGD, buf, (png_size_t)2);
 }
}
void
png_write_hIST(png_structp png_ptr, png_uint_16p hist, int num_hist)
{
 png_byte png_hIST[5] = {104, 73, 83, 84, '\0'};
 int i;
 png_byte buf[3];
 ;
 if (num_hist > (int)png_ptr->num_palette)
 {
 ;
 png_warning(png_ptr, "Invalid number of histogram entries specified");
 return;
 }
 png_write_chunk_start(png_ptr, png_hIST, (png_uint_32)(num_hist * 2));
 for (i = 0; i < num_hist; i++)
 {
 png_save_uint_16(buf, hist[i]);
 png_write_chunk_data(png_ptr, buf, (png_size_t)2);
 }
 png_write_chunk_end(png_ptr);
}
png_size_t
png_check_keyword(png_structp png_ptr, png_charp key, png_charpp new_key)
{
 png_size_t key_len;
 png_charp kp, dp;
 int kflag;
 int kwarn=0;
 ;
 *new_key = ((void *)0);
 if (key == ((void *)0) || (key_len = strlen(key)) == 0)
 {
 png_warning(png_ptr, "zero length keyword");
 return ((png_size_t)0);
 }
 ;
 *new_key = (png_charp)png_malloc_warn(png_ptr, (png_uint_32)(key_len + 2));
 if (*new_key == ((void *)0))
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
 ;
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
 *new_key=((void *)0);
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
void
png_write_tEXt(png_structp png_ptr, png_charp key, png_charp text,
 png_size_t text_len)
{
 png_byte png_tEXt[5] = {116, 69, 88, 116, '\0'};
 png_size_t key_len;
 png_charp new_key;
 ;
 if (key == ((void *)0) || (key_len = png_check_keyword(png_ptr, key, &new_key))==0)
 {
 png_warning(png_ptr, "Empty keyword in tEXt chunk");
 return;
 }
 if (text == ((void *)0) || *text == '\0')
 text_len = 0;
 else
 text_len = strlen(text);
 png_write_chunk_start(png_ptr, png_tEXt, (png_uint_32)key_len+text_len+1);
 png_write_chunk_data(png_ptr, (png_bytep)new_key, key_len + 1);
 if (text_len)
 png_write_chunk_data(png_ptr, (png_bytep)text, text_len);
 png_write_chunk_end(png_ptr);
 png_free(png_ptr, new_key);
}
void
png_write_zTXt(png_structp png_ptr, png_charp key, png_charp text,
 png_size_t text_len, int compression)
{
 png_byte png_zTXt[5] = {122, 84, 88, 116, '\0'};
 png_size_t key_len;
 char buf[1];
 png_charp new_key;
 compression_state comp;
 ;
 comp.num_output_ptr = 0;
 comp.max_output_ptr = 0;
 comp.output_ptr = ((void *)0);
 comp.input = ((void *)0);
 comp.input_len = 0;
 if (key == ((void *)0) || (key_len = png_check_keyword(png_ptr, key, &new_key))==0)
 {
 png_warning(png_ptr, "Empty keyword in zTXt chunk");
 return;
 }
 if (text == ((void *)0) || *text == '\0' || compression==-1)
 {
 png_write_tEXt(png_ptr, new_key, text, (png_size_t)0);
 png_free(png_ptr, new_key);
 return;
 }
 text_len = strlen(text);
 text_len = png_text_compress(png_ptr, text, text_len, compression,
 &comp);
 png_write_chunk_start(png_ptr, png_zTXt, (png_uint_32)
 (key_len+text_len+2));
 png_write_chunk_data(png_ptr, (png_bytep)new_key, key_len + 1);
 png_free(png_ptr, new_key);
 buf[0] = (png_byte)compression;
 png_write_chunk_data(png_ptr, (png_bytep)buf, (png_size_t)1);
 png_write_compressed_data_out(png_ptr, &comp);
 png_write_chunk_end(png_ptr);
}
void
png_write_oFFs(png_structp png_ptr, png_int_32 x_offset, png_int_32 y_offset,
 int unit_type)
{
 png_byte png_oFFs[5] = {111, 70, 70, 115, '\0'};
 png_byte buf[9];
 ;
 if (unit_type >= 2)
 png_warning(png_ptr, "Unrecognized unit type for oFFs chunk");
 png_save_int_32(buf, x_offset);
 png_save_int_32(buf + 4, y_offset);
 buf[8] = (png_byte)unit_type;
 png_write_chunk(png_ptr, png_oFFs, buf, (png_size_t)9);
}
void
png_write_pCAL(png_structp png_ptr, png_charp purpose, png_int_32 X0,
 png_int_32 X1, int type, int nparams, png_charp units, png_charpp params)
{
 png_byte png_pCAL[5] = {112, 67, 65, 76, '\0'};
 png_size_t purpose_len, units_len, total_len;
 png_uint_32p params_len;
 png_byte buf[10];
 png_charp new_purpose;
 int i;
 ;
 if (type >= 4)
 png_warning(png_ptr, "Unrecognized equation type for pCAL chunk");
 purpose_len = png_check_keyword(png_ptr, purpose, &new_purpose) + 1;
 ;
 units_len = strlen(units) + (nparams == 0 ? 0 : 1);
 ;
 total_len = purpose_len + units_len + 10;
 params_len = (png_uint_32p)png_malloc(png_ptr, (png_uint_32)(nparams
 *sizeof (png_uint_32)));
 for (i = 0; i < nparams; i++)
 {
 params_len[i] = strlen(params[i]) + (i == nparams - 1 ? 0 : 1);
 ;
 total_len += (png_size_t)params_len[i];
 }
 ;
 png_write_chunk_start(png_ptr, png_pCAL, (png_uint_32)total_len);
 png_write_chunk_data(png_ptr, (png_bytep)new_purpose, purpose_len);
 png_save_int_32(buf, X0);
 png_save_int_32(buf + 4, X1);
 buf[8] = (png_byte)type;
 buf[9] = (png_byte)nparams;
 png_write_chunk_data(png_ptr, buf, (png_size_t)10);
 png_write_chunk_data(png_ptr, (png_bytep)units, (png_size_t)units_len);
 png_free(png_ptr, new_purpose);
 for (i = 0; i < nparams; i++)
 {
 png_write_chunk_data(png_ptr, (png_bytep)params[i],
 (png_size_t)params_len[i]);
 }
 png_free(png_ptr, params_len);
 png_write_chunk_end(png_ptr);
}
void
png_write_sCAL(png_structp png_ptr, int unit, double width, double height)
{
 png_byte png_sCAL[5] = {115, 67, 65, 76, '\0'};
 char buf[64];
 png_size_t total_len;
 ;
 buf[0] = (char)unit;
 _snprintf(buf + 1, 63, "%12.12e", width);
 total_len = 1 + strlen(buf + 1) + 1;
 _snprintf(buf + total_len, 64-total_len, "%12.12e", height);
 total_len += strlen(buf + total_len);
 ;
 png_write_chunk(png_ptr, png_sCAL, (png_bytep)buf, total_len);
}
void
png_write_pHYs(png_structp png_ptr, png_uint_32 x_pixels_per_unit,
 png_uint_32 y_pixels_per_unit,
 int unit_type)
{
 png_byte png_pHYs[5] = {112, 72, 89, 115, '\0'};
 png_byte buf[9];
 ;
 if (unit_type >= 2)
 png_warning(png_ptr, "Unrecognized unit type for pHYs chunk");
 png_save_uint_32(buf, x_pixels_per_unit);
 png_save_uint_32(buf + 4, y_pixels_per_unit);
 buf[8] = (png_byte)unit_type;
 png_write_chunk(png_ptr, png_pHYs, buf, (png_size_t)9);
}
void
png_write_tIME(png_structp png_ptr, png_timep mod_time)
{
 png_byte png_tIME[5] = {116, 73, 77, 69, '\0'};
 png_byte buf[7];
 ;
 if (mod_time->month  > 12 || mod_time->month  < 1 ||
 mod_time->day    > 31 || mod_time->day    < 1 ||
 mod_time->hour   > 23 || mod_time->second > 60)
 {
 png_warning(png_ptr, "Invalid time specified for tIME chunk");
 return;
 }
 png_save_uint_16(buf, mod_time->year);
 buf[2] = mod_time->month;
 buf[3] = mod_time->day;
 buf[4] = mod_time->hour;
 buf[5] = mod_time->minute;
 buf[6] = mod_time->second;
 png_write_chunk(png_ptr, png_tIME, buf, (png_size_t)7);
}
void
png_write_start_row(png_structp png_ptr)
{
 int png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
 int png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};
 int png_pass_ystart[7] = {0, 0, 4, 0, 2, 0, 1};
 int png_pass_yinc[7] = {8, 8, 8, 4, 4, 2, 2};
 png_size_t buf_size;
 ;
 buf_size = (png_size_t)(((png_ptr->usr_channels*png_ptr->usr_bit_depth) >= 8 ? ((png_ptr->width) * (((png_uint_32)(png_ptr->usr_channels*png_ptr->usr_bit_depth)) >> 3)) : (( ((png_ptr->width) * ((png_uint_32)(png_ptr->usr_channels*png_ptr->usr_bit_depth))) + 7) >> 3) )+1);
 png_ptr->row_buf = (png_bytep)png_malloc(png_ptr, (png_uint_32)buf_size);
 png_ptr->row_buf[0] = 0;
 if (png_ptr->do_filter & 0x10)
 {
 png_ptr->sub_row = (png_bytep)png_malloc(png_ptr,
 (png_ptr->rowbytes + 1));
 png_ptr->sub_row[0] = 1;
 }
 if (png_ptr->do_filter & (0x40 | 0x20 | 0x80))
 {
 png_ptr->prev_row = (png_bytep)png_malloc(png_ptr, (png_uint_32)buf_size);
 memset(png_ptr->prev_row, 0, buf_size);
 if (png_ptr->do_filter & 0x20)
 {
 png_ptr->up_row = (png_bytep)png_malloc(png_ptr,
 (png_ptr->rowbytes + 1));
 png_ptr->up_row[0] = 2;
 }
 if (png_ptr->do_filter & 0x40)
 {
 png_ptr->avg_row = (png_bytep)png_malloc(png_ptr,
 (png_ptr->rowbytes + 1));
 png_ptr->avg_row[0] = 3;
 }
 if (png_ptr->do_filter & 0x80)
 {
 png_ptr->paeth_row = (png_bytep)png_malloc(png_ptr,
 (png_ptr->rowbytes + 1));
 png_ptr->paeth_row[0] = 4;
 }
 }
 if (png_ptr->interlaced)
 {
 if (!(png_ptr->transformations & 0x0002))
 {
 png_ptr->num_rows = (png_ptr->height + png_pass_yinc[0] - 1 -
 png_pass_ystart[0]) / png_pass_yinc[0];
 png_ptr->usr_width = (png_ptr->width + png_pass_inc[0] - 1 -
 png_pass_start[0]) / png_pass_inc[0];
 }
 else
 {
 png_ptr->num_rows = png_ptr->height;
 png_ptr->usr_width = png_ptr->width;
 }
 }
 else
 {
 png_ptr->num_rows = png_ptr->height;
 png_ptr->usr_width = png_ptr->width;
 }
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.next_out = png_ptr->zbuf;
}
void
png_write_finish_row(png_structp png_ptr)
{
 int png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
 int png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};
 int png_pass_ystart[7] = {0, 0, 4, 0, 2, 0, 1};
 int png_pass_yinc[7] = {8, 8, 8, 4, 4, 2, 2};
 int ret;
 ;
 png_ptr->row_number++;
 if (png_ptr->row_number < png_ptr->num_rows)
 return;
 if (png_ptr->interlaced)
 {
 png_ptr->row_number = 0;
 if (png_ptr->transformations & 0x0002)
 {
 png_ptr->pass++;
 }
 else
 {
 do
 {
 png_ptr->pass++;
 if (png_ptr->pass >= 7)
 break;
 png_ptr->usr_width = (png_ptr->width +
 png_pass_inc[png_ptr->pass] - 1 -
 png_pass_start[png_ptr->pass]) /
 png_pass_inc[png_ptr->pass];
 png_ptr->num_rows = (png_ptr->height +
 png_pass_yinc[png_ptr->pass] - 1 -
 png_pass_ystart[png_ptr->pass]) /
 png_pass_yinc[png_ptr->pass];
 if (png_ptr->transformations & 0x0002)
 break;
 } while (png_ptr->usr_width == 0 || png_ptr->num_rows == 0);
 }
 if (png_ptr->pass < 7)
 {
 if (png_ptr->prev_row != ((void *)0))
 memset(png_ptr->prev_row, 0,
 (png_size_t)(((png_ptr->usr_channels* png_ptr->usr_bit_depth) >= 8 ? ((png_ptr->width) * (((png_uint_32)(png_ptr->usr_channels* png_ptr->usr_bit_depth)) >> 3)) : (( ((png_ptr->width) * ((png_uint_32)(png_ptr->usr_channels* png_ptr->usr_bit_depth))) + 7) >> 3) ))+1);
 return;
 }
 }
 do
 {
 ret = deflate(&png_ptr->zstream, 4);
 if (ret == 0)
 {
 if (!(png_ptr->zstream.avail_out))
 {
 png_write_IDAT(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
 png_ptr->zstream.next_out = png_ptr->zbuf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 }
 }
 else if (ret != 1)
 {
 if (png_ptr->zstream.msg != ((void *)0))
 png_error(png_ptr, png_ptr->zstream.msg);
 else
 png_error(png_ptr, "zlib error");
 }
 } while (ret != 1);
 if (png_ptr->zstream.avail_out < png_ptr->zbuf_size)
 {
 png_write_IDAT(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size -
 png_ptr->zstream.avail_out);
 }
 deflateReset(&png_ptr->zstream);
 png_ptr->zstream.data_type = 0;
}
void
png_do_write_interlace(png_row_infop row_info, png_bytep row, int pass)
{
 int png_pass_start[7] = {0, 4, 0, 2, 0, 1, 0};
 int png_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};
 ;
 if (pass < 6)
 {
 switch (row_info->pixel_depth)
 {
 case 1:
 {
 png_bytep sp;
 png_bytep dp;
 int shift;
 int d;
 int value;
 png_uint_32 i;
 png_uint_32 row_width = row_info->width;
 dp = row;
 d = 0;
 shift = 7;
 for (i = png_pass_start[pass]; i < row_width;
 i += png_pass_inc[pass])
 {
 sp = row + (png_size_t)(i >> 3);
 value = (int)(*sp >> (7 - (int)(i & 0x07))) & 0x01;
 d |= (value << shift);
 if (shift == 0)
 {
 shift = 7;
 *dp++ = (png_byte)d;
 d = 0;
 }
 else
 shift--;
 }
 if (shift != 7)
 *dp = (png_byte)d;
 break;
 }
 case 2:
 {
 png_bytep sp;
 png_bytep dp;
 int shift;
 int d;
 int value;
 png_uint_32 i;
 png_uint_32 row_width = row_info->width;
 dp = row;
 shift = 6;
 d = 0;
 for (i = png_pass_start[pass]; i < row_width;
 i += png_pass_inc[pass])
 {
 sp = row + (png_size_t)(i >> 2);
 value = (*sp >> ((3 - (int)(i & 0x03)) << 1)) & 0x03;
 d |= (value << shift);
 if (shift == 0)
 {
 shift = 6;
 *dp++ = (png_byte)d;
 d = 0;
 }
 else
 shift -= 2;
 }
 if (shift != 6)
 *dp = (png_byte)d;
 break;
 }
 case 4:
 {
 png_bytep sp;
 png_bytep dp;
 int shift;
 int d;
 int value;
 png_uint_32 i;
 png_uint_32 row_width = row_info->width;
 dp = row;
 shift = 4;
 d = 0;
 for (i = png_pass_start[pass]; i < row_width;
 i += png_pass_inc[pass])
 {
 sp = row + (png_size_t)(i >> 1);
 value = (*sp >> ((1 - (int)(i & 0x01)) << 2)) & 0x0f;
 d |= (value << shift);
 if (shift == 0)
 {
 shift = 4;
 *dp++ = (png_byte)d;
 d = 0;
 }
 else
 shift -= 4;
 }
 if (shift != 4)
 *dp = (png_byte)d;
 break;
 }
 default:
 {
 png_bytep sp;
 png_bytep dp;
 png_uint_32 i;
 png_uint_32 row_width = row_info->width;
 png_size_t pixel_bytes;
 dp = row;
 pixel_bytes = (row_info->pixel_depth >> 3);
 for (i = png_pass_start[pass]; i < row_width;
 i += png_pass_inc[pass])
 {
 sp = row + (png_size_t)i * pixel_bytes;
 if (dp != sp)
 memcpy(dp, sp, pixel_bytes);
 dp += pixel_bytes;
 }
 break;
 }
 }
 row_info->width = (row_info->width +
 png_pass_inc[pass] - 1 -
 png_pass_start[pass]) /
 png_pass_inc[pass];
 row_info->rowbytes = ((row_info->pixel_depth) >= 8 ? ((row_info->width) * (((png_uint_32)(row_info->pixel_depth)) >> 3)) : (( ((row_info->width) * ((png_uint_32)(row_info->pixel_depth))) + 7) >> 3) );
 }
}
void
png_write_find_filter(png_structp png_ptr, png_row_infop row_info)
{
 png_bytep best_row;
 png_bytep prev_row, row_buf;
 png_uint_32 mins, bpp;
 png_byte filter_to_do = png_ptr->do_filter;
 png_uint_32 row_bytes = row_info->rowbytes;
 int num_p_filters = (int)png_ptr->num_prev_filters;
 ;
 bpp = (row_info->pixel_depth + 7) >> 3;
 prev_row = png_ptr->prev_row;
 best_row = png_ptr->row_buf;
 row_buf = best_row;
 mins = (((png_uint_32)(-1)) >> 1);
 if ((filter_to_do & 0x08) &&
 filter_to_do != 0x08)
 {
 png_bytep rp;
 png_uint_32 sum = 0;
 png_uint_32 i;
 int v;
 for (i = 0, rp = row_buf + 1; i < row_bytes; i++, rp++)
 {
 v = *rp;
 sum += (v < 128) ? v : 256 - v;
 }
 if (png_ptr->heuristic_method == 2)
 {
 png_uint_32 sumhi, sumlo;
 int j;
 sumlo = sum & ((png_uint_32)0xffffL);
 sumhi = (sum >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 0)
 {
 sumlo = (sumlo * png_ptr->filter_weights[j]) >>
 8;
 sumhi = (sumhi * png_ptr->filter_weights[j]) >>
 8;
 }
 }
 sumlo = (sumlo * png_ptr->filter_costs[0]) >>
 3;
 sumhi = (sumhi * png_ptr->filter_costs[0]) >>
 3;
 if (sumhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 sum = (((png_uint_32)(-1)) >> 1);
 else
 sum = (sumhi << 10) + sumlo;
 }
 mins = sum;
 }
 if (filter_to_do == 0x10)
 {
 png_bytep rp, lp, dp;
 png_uint_32 i;
 for (i = 0, rp = row_buf + 1, dp = png_ptr->sub_row + 1; i < bpp;
 i++, rp++, dp++)
 {
 *dp = *rp;
 }
 for (lp = row_buf + 1; i < row_bytes;
 i++, rp++, lp++, dp++)
 {
 *dp = (png_byte)(((int)*rp - (int)*lp) & 0xff);
 }
 best_row = png_ptr->sub_row;
 }
 else if (filter_to_do & 0x10)
 {
 png_bytep rp, dp, lp;
 png_uint_32 sum = 0, lmins = mins;
 png_uint_32 i;
 int v;
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 lmhi, lmlo;
 lmlo = lmins & ((png_uint_32)0xffffL);
 lmhi = (lmins >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 1)
 {
 lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
 8;
 lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
 8;
 }
 }
 lmlo = (lmlo * png_ptr->inv_filter_costs[1]) >>
 3;
 lmhi = (lmhi * png_ptr->inv_filter_costs[1]) >>
 3;
 if (lmhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 lmins = (((png_uint_32)(-1)) >> 1);
 else
 lmins = (lmhi << 10) + lmlo;
 }
 for (i = 0, rp = row_buf + 1, dp = png_ptr->sub_row + 1; i < bpp;
 i++, rp++, dp++)
 {
 v = *dp = *rp;
 sum += (v < 128) ? v : 256 - v;
 }
 for (lp = row_buf + 1; i < row_bytes;
 i++, rp++, lp++, dp++)
 {
 v = *dp = (png_byte)(((int)*rp - (int)*lp) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 if (sum > lmins)
 break;
 }
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 sumhi, sumlo;
 sumlo = sum & ((png_uint_32)0xffffL);
 sumhi = (sum >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 1)
 {
 sumlo = (sumlo * png_ptr->inv_filter_weights[j]) >>
 8;
 sumhi = (sumhi * png_ptr->inv_filter_weights[j]) >>
 8;
 }
 }
 sumlo = (sumlo * png_ptr->inv_filter_costs[1]) >>
 3;
 sumhi = (sumhi * png_ptr->inv_filter_costs[1]) >>
 3;
 if (sumhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 sum = (((png_uint_32)(-1)) >> 1);
 else
 sum = (sumhi << 10) + sumlo;
 }
 if (sum < mins)
 {
 mins = sum;
 best_row = png_ptr->sub_row;
 }
 }
 if (filter_to_do == 0x20)
 {
 png_bytep rp, dp, pp;
 png_uint_32 i;
 for (i = 0, rp = row_buf + 1, dp = png_ptr->up_row + 1,
 pp = prev_row + 1; i < row_bytes;
 i++, rp++, pp++, dp++)
 {
 *dp = (png_byte)(((int)*rp - (int)*pp) & 0xff);
 }
 best_row = png_ptr->up_row;
 }
 else if (filter_to_do & 0x20)
 {
 png_bytep rp, dp, pp;
 png_uint_32 sum = 0, lmins = mins;
 png_uint_32 i;
 int v;
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 lmhi, lmlo;
 lmlo = lmins & ((png_uint_32)0xffffL);
 lmhi = (lmins >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 2)
 {
 lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
 8;
 lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
 8;
 }
 }
 lmlo = (lmlo * png_ptr->inv_filter_costs[2]) >>
 3;
 lmhi = (lmhi * png_ptr->inv_filter_costs[2]) >>
 3;
 if (lmhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 lmins = (((png_uint_32)(-1)) >> 1);
 else
 lmins = (lmhi << 10) + lmlo;
 }
 for (i = 0, rp = row_buf + 1, dp = png_ptr->up_row + 1,
 pp = prev_row + 1; i < row_bytes; i++)
 {
 v = *dp++ = (png_byte)(((int)*rp++ - (int)*pp++) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 if (sum > lmins)
 break;
 }
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 sumhi, sumlo;
 sumlo = sum & ((png_uint_32)0xffffL);
 sumhi = (sum >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 2)
 {
 sumlo = (sumlo * png_ptr->filter_weights[j]) >>
 8;
 sumhi = (sumhi * png_ptr->filter_weights[j]) >>
 8;
 }
 }
 sumlo = (sumlo * png_ptr->filter_costs[2]) >>
 3;
 sumhi = (sumhi * png_ptr->filter_costs[2]) >>
 3;
 if (sumhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 sum = (((png_uint_32)(-1)) >> 1);
 else
 sum = (sumhi << 10) + sumlo;
 }
 if (sum < mins)
 {
 mins = sum;
 best_row = png_ptr->up_row;
 }
 }
 if (filter_to_do == 0x40)
 {
 png_bytep rp, dp, pp, lp;
 png_uint_32 i;
 for (i = 0, rp = row_buf + 1, dp = png_ptr->avg_row + 1,
 pp = prev_row + 1; i < bpp; i++)
 {
 *dp++ = (png_byte)(((int)*rp++ - ((int)*pp++ / 2)) & 0xff);
 }
 for (lp = row_buf + 1; i < row_bytes; i++)
 {
 *dp++ = (png_byte)(((int)*rp++ - (((int)*pp++ + (int)*lp++) / 2))
 & 0xff);
 }
 best_row = png_ptr->avg_row;
 }
 else if (filter_to_do & 0x40)
 {
 png_bytep rp, dp, pp, lp;
 png_uint_32 sum = 0, lmins = mins;
 png_uint_32 i;
 int v;
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 lmhi, lmlo;
 lmlo = lmins & ((png_uint_32)0xffffL);
 lmhi = (lmins >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 3)
 {
 lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
 8;
 lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
 8;
 }
 }
 lmlo = (lmlo * png_ptr->inv_filter_costs[3]) >>
 3;
 lmhi = (lmhi * png_ptr->inv_filter_costs[3]) >>
 3;
 if (lmhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 lmins = (((png_uint_32)(-1)) >> 1);
 else
 lmins = (lmhi << 10) + lmlo;
 }
 for (i = 0, rp = row_buf + 1, dp = png_ptr->avg_row + 1,
 pp = prev_row + 1; i < bpp; i++)
 {
 v = *dp++ = (png_byte)(((int)*rp++ - ((int)*pp++ / 2)) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 }
 for (lp = row_buf + 1; i < row_bytes; i++)
 {
 v = *dp++ =
 (png_byte)(((int)*rp++ - (((int)*pp++ + (int)*lp++) / 2)) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 if (sum > lmins)
 break;
 }
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 sumhi, sumlo;
 sumlo = sum & ((png_uint_32)0xffffL);
 sumhi = (sum >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 0)
 {
 sumlo = (sumlo * png_ptr->filter_weights[j]) >>
 8;
 sumhi = (sumhi * png_ptr->filter_weights[j]) >>
 8;
 }
 }
 sumlo = (sumlo * png_ptr->filter_costs[3]) >>
 3;
 sumhi = (sumhi * png_ptr->filter_costs[3]) >>
 3;
 if (sumhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 sum = (((png_uint_32)(-1)) >> 1);
 else
 sum = (sumhi << 10) + sumlo;
 }
 if (sum < mins)
 {
 mins = sum;
 best_row = png_ptr->avg_row;
 }
 }
 if (filter_to_do == 0x80)
 {
 png_bytep rp, dp, pp, cp, lp;
 png_uint_32 i;
 for (i = 0, rp = row_buf + 1, dp = png_ptr->paeth_row + 1,
 pp = prev_row + 1; i < bpp; i++)
 {
 *dp++ = (png_byte)(((int)*rp++ - (int)*pp++) & 0xff);
 }
 for (lp = row_buf + 1, cp = prev_row + 1; i < row_bytes; i++)
 {
 int a, b, c, pa, pb, pc, p;
 b = *pp++;
 c = *cp++;
 a = *lp++;
 p = b - c;
 pc = a - c;
 pa = p < 0 ? -p : p;
 pb = pc < 0 ? -pc : pc;
 pc = (p + pc) < 0 ? -(p + pc) : p + pc;
 p = (pa <= pb && pa <=pc) ? a : (pb <= pc) ? b : c;
 *dp++ = (png_byte)(((int)*rp++ - p) & 0xff);
 }
 best_row = png_ptr->paeth_row;
 }
 else if (filter_to_do & 0x80)
 {
 png_bytep rp, dp, pp, cp, lp;
 png_uint_32 sum = 0, lmins = mins;
 png_uint_32 i;
 int v;
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 lmhi, lmlo;
 lmlo = lmins & ((png_uint_32)0xffffL);
 lmhi = (lmins >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 4)
 {
 lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
 8;
 lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
 8;
 }
 }
 lmlo = (lmlo * png_ptr->inv_filter_costs[4]) >>
 3;
 lmhi = (lmhi * png_ptr->inv_filter_costs[4]) >>
 3;
 if (lmhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 lmins = (((png_uint_32)(-1)) >> 1);
 else
 lmins = (lmhi << 10) + lmlo;
 }
 for (i = 0, rp = row_buf + 1, dp = png_ptr->paeth_row + 1,
 pp = prev_row + 1; i < bpp; i++)
 {
 v = *dp++ = (png_byte)(((int)*rp++ - (int)*pp++) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 }
 for (lp = row_buf + 1, cp = prev_row + 1; i < row_bytes; i++)
 {
 int a, b, c, pa, pb, pc, p;
 b = *pp++;
 c = *cp++;
 a = *lp++;
 p = b - c;
 pc = a - c;
 pa = p < 0 ? -p : p;
 pb = pc < 0 ? -pc : pc;
 pc = (p + pc) < 0 ? -(p + pc) : p + pc;
 p = (pa <= pb && pa <=pc) ? a : (pb <= pc) ? b : c;
 v = *dp++ = (png_byte)(((int)*rp++ - p) & 0xff);
 sum += (v < 128) ? v : 256 - v;
 if (sum > lmins)
 break;
 }
 if (png_ptr->heuristic_method == 2)
 {
 int j;
 png_uint_32 sumhi, sumlo;
 sumlo = sum & ((png_uint_32)0xffffL);
 sumhi = (sum >> 10) & ((png_uint_32)(~((png_uint_32)0xffffL) >> 10));
 for (j = 0; j < num_p_filters; j++)
 {
 if (png_ptr->prev_filters[j] == 4)
 {
 sumlo = (sumlo * png_ptr->filter_weights[j]) >>
 8;
 sumhi = (sumhi * png_ptr->filter_weights[j]) >>
 8;
 }
 }
 sumlo = (sumlo * png_ptr->filter_costs[4]) >>
 3;
 sumhi = (sumhi * png_ptr->filter_costs[4]) >>
 3;
 if (sumhi > ((png_uint_32)(~((png_uint_32)0xffffL) >> 10)))
 sum = (((png_uint_32)(-1)) >> 1);
 else
 sum = (sumhi << 10) + sumlo;
 }
 if (sum < mins)
 {
 best_row = png_ptr->paeth_row;
 }
 }
 png_write_filtered_row(png_ptr, best_row);
 if (png_ptr->num_prev_filters > 0)
 {
 int j;
 for (j = 1; j < num_p_filters; j++)
 {
 png_ptr->prev_filters[j] = png_ptr->prev_filters[j - 1];
 }
 png_ptr->prev_filters[j] = best_row[0];
 }
}
void
png_write_filtered_row(png_structp png_ptr, png_bytep filtered_row)
{
 ;
 ;
 png_ptr->zstream.next_in = filtered_row;
 png_ptr->zstream.avail_in = (uInt)png_ptr->row_info.rowbytes + 1;
 do
 {
 int ret;
 ret = deflate(&png_ptr->zstream, 0);
 if (ret != 0)
 {
 if (png_ptr->zstream.msg != ((void *)0))
 png_error(png_ptr, png_ptr->zstream.msg);
 else
 png_error(png_ptr, "zlib error");
 }
 if (!(png_ptr->zstream.avail_out))
 {
 png_write_IDAT(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
 png_ptr->zstream.next_out = png_ptr->zbuf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 }
 } while (png_ptr->zstream.avail_in);
 if (png_ptr->prev_row != ((void *)0))
 {
 png_bytep tptr;
 tptr = png_ptr->prev_row;
 png_ptr->prev_row = png_ptr->row_buf;
 png_ptr->row_buf = tptr;
 }
 png_write_finish_row(png_ptr);
 png_ptr->flush_rows++;
 if (png_ptr->flush_dist > 0 &&
 png_ptr->flush_rows >= png_ptr->flush_dist)
 {
 png_write_flush(png_ptr);
 }
}
