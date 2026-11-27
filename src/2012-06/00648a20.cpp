// from server: 100% by Xemicl
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
#define ZEXPORT __stdcall
#define ZEXPORTVA __cdecl
#define PNG_INTERNAL
#ifndef ZCONF_H
#define ZCONF_H
#ifdef Z_PREFIX
#  define deflateInit_          z_deflateInit_
#  define deflate               z_deflate
#  define deflateEnd            z_deflateEnd
#  define inflateInit_          z_inflateInit_
#  define inflate               z_inflate
#  define inflateEnd            z_inflateEnd
#  define deflateInit2_         z_deflateInit2_
#  define deflateSetDictionary  z_deflateSetDictionary
#  define deflateCopy           z_deflateCopy
#  define deflateReset          z_deflateReset
#  define deflateParams         z_deflateParams
#  define deflateBound          z_deflateBound
#  define deflatePrime          z_deflatePrime
#  define inflateInit2_         z_inflateInit2_
#  define inflateSetDictionary  z_inflateSetDictionary
#  define inflateSync           z_inflateSync
#  define inflateSyncPoint      z_inflateSyncPoint
#  define inflateCopy           z_inflateCopy
#  define inflateReset          z_inflateReset
#  define inflateBack           z_inflateBack
#  define inflateBackEnd        z_inflateBackEnd
#  define compress              z_compress
#  define compress2             z_compress2
#  define compressBound         z_compressBound
#  define uncompress            z_uncompress
#  define adler32               z_adler32
#  define crc32                 z_crc32
#  define get_crc_table         z_get_crc_table
#  define zError                z_zError
#  define alloc_func            z_alloc_func
#  define free_func             z_free_func
#  define in_func               z_in_func
#  define out_func              z_out_func
#  define Byte                  z_Byte
#  define uInt                  z_uInt
#  define uLong                 z_uLong
#  define Bytef                 z_Bytef
#  define charf                 z_charf
#  define intf                  z_intf
#  define uIntf                 z_uIntf
#  define uLongf                z_uLongf
#  define voidpf                z_voidpf
#  define voidp                 z_voidp
#endif
#if defined(__MSDOS__) && !defined(MSDOS)
#  define MSDOS
#endif
#if (defined(OS_2) || defined(__OS2__)) && !defined(OS2)
#  define OS2
#endif
#if defined(_WINDOWS) && !defined(WINDOWS)
#  define WINDOWS
#endif
#if defined(_WIN32) || defined(_WIN32_WCE) || defined(__WIN32__)
#  ifndef WIN32
#    define WIN32
#  endif
#endif
#if (defined(MSDOS) || defined(OS2) || defined(WINDOWS)) && !defined(WIN32)
#  if !defined(__GNUC__) && !defined(__FLAT__) && !defined(__386__)
#    ifndef SYS16BIT
#      define SYS16BIT
#    endif
#  endif
#endif
#ifdef SYS16BIT
#  define MAXSEG_64K
#endif
#ifdef MSDOS
#  define UNALIGNED_OK
#endif
#ifdef __STDC_VERSION__
#  ifndef STDC
#    define STDC
#  endif
#  if __STDC_VERSION__ >= 199901L
#    ifndef STDC99
#      define STDC99
#    endif
#  endif
#endif
#if !defined(STDC) && (defined(__STDC__) || defined(__cplusplus))
#  define STDC
#endif
#if !defined(STDC) && (defined(__GNUC__) || defined(__BORLANDC__))
#  define STDC
#endif
#if !defined(STDC) && (defined(MSDOS) || defined(WINDOWS) || defined(WIN32))
#  define STDC
#endif
#if !defined(STDC) && (defined(OS2) || defined(__HOS_AIX__))
#  define STDC
#endif
#if defined(__OS400__) && !defined(STDC)
#  define STDC
#endif
#ifndef STDC
#  ifndef const
#    define const
#  endif
#endif
#if defined(__MWERKS__)||defined(applec)||defined(THINK_C)||defined(__SC__)
#  define NO_DUMMY_DECL
#endif
#ifndef MAX_MEM_LEVEL
#  ifdef MAXSEG_64K
#    define MAX_MEM_LEVEL 8
#  else
#    define MAX_MEM_LEVEL 9
#  endif
#endif
#ifndef MAX_WBITS
#  define MAX_WBITS   15
#endif
#ifndef OF
#  ifdef STDC
#    define OF(args)  args
#  else
#    define OF(args)  ()
#  endif
#endif
#ifdef SYS16BIT
#  if defined(M_I86SM) || defined(M_I86MM)
#    define SMALL_MEDIUM
#    ifdef _MSC_VER
#      define FAR _far
#    else
#      define FAR far
#    endif
#  endif
#  if (defined(__SMALL__) || defined(__MEDIUM__))
#    define SMALL_MEDIUM
#    ifdef __BORLANDC__
#      define FAR _far
#    else
#      define FAR far
#    endif
#  endif
#endif
#if defined(WINDOWS) || defined(WIN32)
#  ifdef ZLIB_DLL
#    if defined(WIN32) && (!defined(__BORLANDC__) || (__BORLANDC__ >= 0x500))
#      ifdef ZLIB_INTERNAL
#        define ZEXTERN extern __declspec(dllexport)
#      else
#        define ZEXTERN extern __declspec(dllimport)
#      endif
#    endif
#  endif
#  ifdef ZLIB_WINAPI
#    ifdef FAR
#      undef FAR
#    endif
#    include <windows.h>
#    define ZEXPORT WINAPI
#    ifdef WIN32
#      define ZEXPORTVA WINAPIV
#    else
#      define ZEXPORTVA FAR CDECL
#    endif
#  endif
#endif
#if defined (__BEOS__)
#  ifdef ZLIB_DLL
#    ifdef ZLIB_INTERNAL
#      define ZEXPORT   __declspec(dllexport)
#      define ZEXPORTVA __declspec(dllexport)
#    else
#      define ZEXPORT   __declspec(dllimport)
#      define ZEXPORTVA __declspec(dllimport)
#    endif
#  endif
#endif
#ifndef ZEXTERN
#  define ZEXTERN extern
#endif
#ifndef ZEXPORT
#  define ZEXPORT
#endif
#ifndef ZEXPORTVA
#  define ZEXPORTVA
#endif
#ifndef FAR
#  define FAR
#endif
#if !defined(__MACTYPES__)
typedef unsigned char  Byte;
#endif
typedef unsigned int   uInt;
typedef unsigned long  uLong;
#ifdef SMALL_MEDIUM
#  define Bytef Byte FAR
#else
 typedef Byte  FAR Bytef;
#endif
typedef char  FAR charf;
typedef int   FAR intf;
typedef uInt  FAR uIntf;
typedef uLong FAR uLongf;
#ifdef STDC
 typedef void const *voidpc;
 typedef void FAR   *voidpf;
 typedef void       *voidp;
#else
 typedef Byte const *voidpc;
 typedef Byte FAR   *voidpf;
 typedef Byte       *voidp;
#endif
#if 0
#  include <sys/types.h>
#  include <unistd.h>
#  ifdef VMS
#    include <unixio.h>
#  endif
#  define z_off_t off_t
#endif
#ifndef SEEK_SET
#  define SEEK_SET        0
#  define SEEK_CUR        1
#  define SEEK_END        2
#endif
#ifndef z_off_t
#  define z_off_t long
#endif
#if defined(__OS400__)
#  define NO_vsnprintf
#endif
#if defined(__MVS__)
#  define NO_vsnprintf
#  ifdef FAR
#    undef FAR
#  endif
#endif
#if defined(__MVS__)
#   pragma map(deflateInit_,"DEIN")
#   pragma map(deflateInit2_,"DEIN2")
#   pragma map(deflateEnd,"DEEND")
#   pragma map(deflateBound,"DEBND")
#   pragma map(inflateInit_,"ININ")
#   pragma map(inflateInit2_,"ININ2")
#   pragma map(inflateEnd,"INEND")
#   pragma map(inflateSync,"INSY")
#   pragma map(inflateSetDictionary,"INSEDI")
#   pragma map(compressBound,"CMBND")
#   pragma map(inflate_table,"INTABL")
#   pragma map(inflate_fast,"INFA")
#   pragma map(inflate_copyright,"INCOPY")
#endif
#endif
#ifndef ZLIB_H
#define ZLIB_H
#ifdef __cplusplus
extern "C" {
#endif
#define ZLIB_VERSION "1.2.3"
#define ZLIB_VERNUM 0x1230
typedef voidpf (*alloc_func) OF((voidpf opaque, uInt items, uInt size));
typedef void   (*free_func)  OF((voidpf opaque, voidpf address));
struct internal_state;
typedef struct z_stream_s {
 Bytef    *next_in;
 uInt     avail_in;
 uLong    total_in;
 Bytef    *next_out;
 uInt     avail_out;
 uLong    total_out;
 char     *msg;
 struct internal_state FAR *state;
 alloc_func zalloc;
 free_func  zfree;
 voidpf     opaque;
 int     data_type;
 uLong   adler;
 uLong   reserved;
} z_stream;
typedef z_stream FAR *z_streamp;
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
typedef gz_header FAR *gz_headerp;
#define Z_NO_FLUSH      0
#define Z_PARTIAL_FLUSH 1
#define Z_SYNC_FLUSH    2
#define Z_FULL_FLUSH    3
#define Z_FINISH        4
#define Z_BLOCK         5
#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_VERSION_ERROR (-6)
#define Z_NO_COMPRESSION         0
#define Z_BEST_SPEED             1
#define Z_BEST_COMPRESSION       9
#define Z_DEFAULT_COMPRESSION  (-1)
#define Z_FILTERED            1
#define Z_HUFFMAN_ONLY        2
#define Z_RLE                 3
#define Z_FIXED               4
#define Z_DEFAULT_STRATEGY    0
#define Z_BINARY   0
#define Z_TEXT     1
#define Z_ASCII    Z_TEXT
#define Z_UNKNOWN  2
#define Z_DEFLATED   8
#define Z_NULL  0
#define zlib_version zlibVersion()
ZEXTERN const char * ZEXPORT zlibVersion OF((void));
ZEXTERN int ZEXPORT deflate OF((z_streamp strm, int flush));
ZEXTERN int ZEXPORT deflateEnd OF((z_streamp strm));
ZEXTERN int ZEXPORT inflate OF((z_streamp strm, int flush));
ZEXTERN int ZEXPORT inflateEnd OF((z_streamp strm));
ZEXTERN int ZEXPORT deflateSetDictionary OF((z_streamp strm,
 const Bytef *dictionary,
 uInt  dictLength));
ZEXTERN int ZEXPORT deflateCopy OF((z_streamp dest,
 z_streamp source));
ZEXTERN int ZEXPORT deflateReset OF((z_streamp strm));
ZEXTERN int ZEXPORT deflateParams OF((z_streamp strm,
 int level,
 int strategy));
ZEXTERN int ZEXPORT deflateTune OF((z_streamp strm,
 int good_length,
 int max_lazy,
 int nice_length,
 int max_chain));
ZEXTERN uLong ZEXPORT deflateBound OF((z_streamp strm,
 uLong sourceLen));
ZEXTERN int ZEXPORT deflatePrime OF((z_streamp strm,
 int bits,
 int value));
ZEXTERN int ZEXPORT deflateSetHeader OF((z_streamp strm,
 gz_headerp head));
ZEXTERN int ZEXPORT inflateSetDictionary OF((z_streamp strm,
 const Bytef *dictionary,
 uInt  dictLength));
ZEXTERN int ZEXPORT inflateSync OF((z_streamp strm));
ZEXTERN int ZEXPORT inflateCopy OF((z_streamp dest,
 z_streamp source));
ZEXTERN int ZEXPORT inflateReset OF((z_streamp strm));
ZEXTERN int ZEXPORT inflatePrime OF((z_streamp strm,
 int bits,
 int value));
ZEXTERN int ZEXPORT inflateGetHeader OF((z_streamp strm,
 gz_headerp head));
typedef unsigned (*in_func) OF((void FAR *, unsigned char FAR * FAR *));
typedef int (*out_func) OF((void FAR *, unsigned char FAR *, unsigned));
ZEXTERN int ZEXPORT inflateBack OF((z_streamp strm,
 in_func in, void FAR *in_desc,
 out_func out, void FAR *out_desc));
ZEXTERN int ZEXPORT inflateBackEnd OF((z_streamp strm));
ZEXTERN uLong ZEXPORT zlibCompileFlags OF((void));
ZEXTERN int ZEXPORT compress OF((Bytef *dest,   uLongf *destLen,
 const Bytef *source, uLong sourceLen));
ZEXTERN int ZEXPORT compress2 OF((Bytef *dest,   uLongf *destLen,
 const Bytef *source, uLong sourceLen,
 int level));
ZEXTERN uLong ZEXPORT compressBound OF((uLong sourceLen));
ZEXTERN int ZEXPORT uncompress OF((Bytef *dest,   uLongf *destLen,
 const Bytef *source, uLong sourceLen));
typedef voidp gzFile;
ZEXTERN gzFile ZEXPORT gzopen  OF((const char *path, const char *mode));
ZEXTERN gzFile ZEXPORT gzdopen  OF((int fd, const char *mode));
ZEXTERN int ZEXPORT gzsetparams OF((gzFile file, int level, int strategy));
ZEXTERN int ZEXPORT    gzread  OF((gzFile file, voidp buf, unsigned len));
ZEXTERN int ZEXPORT    gzwrite OF((gzFile file,
 voidpc buf, unsigned len));
ZEXTERN int ZEXPORTVA   gzprintf OF((gzFile file, const char *format, ...));
ZEXTERN int ZEXPORT gzputs OF((gzFile file, const char *s));
ZEXTERN char * ZEXPORT gzgets OF((gzFile file, char *buf, int len));
ZEXTERN int ZEXPORT    gzputc OF((gzFile file, int c));
ZEXTERN int ZEXPORT    gzgetc OF((gzFile file));
ZEXTERN int ZEXPORT    gzungetc OF((int c, gzFile file));
ZEXTERN int ZEXPORT    gzflush OF((gzFile file, int flush));
ZEXTERN z_off_t ZEXPORT    gzseek OF((gzFile file,
 z_off_t offset, int whence));
ZEXTERN int ZEXPORT    gzrewind OF((gzFile file));
ZEXTERN z_off_t ZEXPORT    gztell OF((gzFile file));
ZEXTERN int ZEXPORT gzeof OF((gzFile file));
ZEXTERN int ZEXPORT gzdirect OF((gzFile file));
ZEXTERN int ZEXPORT    gzclose OF((gzFile file));
ZEXTERN const char * ZEXPORT gzerror OF((gzFile file, int *errnum));
ZEXTERN void ZEXPORT gzclearerr OF((gzFile file));
ZEXTERN uLong ZEXPORT adler32 OF((uLong adler, const Bytef *buf, uInt len));
ZEXTERN uLong ZEXPORT adler32_combine OF((uLong adler1, uLong adler2,
 z_off_t len2));
ZEXTERN uLong ZEXPORT crc32   OF((uLong crc, const Bytef *buf, uInt len));
ZEXTERN uLong ZEXPORT crc32_combine OF((uLong crc1, uLong crc2, z_off_t len2));
ZEXTERN int ZEXPORT deflateInit_ OF((z_streamp strm, int level,
 const char *version, int stream_size));
ZEXTERN int ZEXPORT inflateInit_ OF((z_streamp strm,
 const char *version, int stream_size));
ZEXTERN int ZEXPORT deflateInit2_ OF((z_streamp strm, int  level, int  method,
 int windowBits, int memLevel,
 int strategy, const char *version,
 int stream_size));
ZEXTERN int ZEXPORT inflateInit2_ OF((z_streamp strm, int  windowBits,
 const char *version, int stream_size));
ZEXTERN int ZEXPORT inflateBackInit_ OF((z_streamp strm, int windowBits,
 unsigned char FAR *window,
 const char *version,
 int stream_size));
#define deflateInit(strm, level) \
 deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
 inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))
#define deflateInit2(strm, level, method, windowBits, memLevel, strategy) \
 deflateInit2_((strm),(level),(method),(windowBits),(memLevel),\
 (strategy),           ZLIB_VERSION, sizeof(z_stream))
#define inflateInit2(strm, windowBits) \
 inflateInit2_((strm), (windowBits), ZLIB_VERSION, sizeof(z_stream))
#define inflateBackInit(strm, windowBits, window) \
 inflateBackInit_((strm), (windowBits), (window), \
 ZLIB_VERSION, sizeof(z_stream))
#if !defined(ZUTIL_H) && !defined(NO_DUMMY_DECL)
 struct internal_state {int dummy;};
#endif
ZEXTERN const char   * ZEXPORT zError           OF((int));
ZEXTERN int            ZEXPORT inflateSyncPoint OF((z_streamp z));
ZEXTERN const uLongf * ZEXPORT get_crc_table    OF((void));
#ifdef __cplusplus
}
#endif
#endif
#ifndef PNGCONF_H
#define PNGCONF_H
#define PNG_1_2_X
#ifdef PNG_USER_CONFIG
#  ifndef PNG_USER_PRIVATEBUILD
#    define PNG_USER_PRIVATEBUILD
#  endif
#endif
#ifdef PNG_CONFIGURE_LIBPNG
#ifdef HAVE_CONFIG_H
#endif
#endif
#ifdef __STDC__
#ifdef SPECIALBUILD
#  pragma message("PNG_LIBPNG_SPECIALBUILD (and deprecated SPECIALBUILD)\
 are now LIBPNG reserved macros. Use PNG_USER_PRIVATEBUILD instead.")
#endif
#ifdef PRIVATEBUILD
# pragma message("PRIVATEBUILD is deprecated.\
 Use PNG_USER_PRIVATEBUILD instead.")
# define PNG_USER_PRIVATEBUILD PRIVATEBUILD
#endif
#endif
#ifndef PNG_VERSION_INFO_ONLY
#if !defined(PNG_NO_WARN_UNINITIALIZED_ROW) && \
 !defined(PNG_WARN_UNINITIALIZED_ROW)
#  define PNG_WARN_UNINITIALIZED_ROW 1
#endif
#ifndef PNG_ZBUF_SIZE
#  define PNG_ZBUF_SIZE 8192
#endif
#ifndef PNG_NO_READ_SUPPORTED
#  define PNG_READ_SUPPORTED
#endif
#ifndef PNG_NO_WRITE_SUPPORTED
#  define PNG_WRITE_SUPPORTED
#endif
#if !defined(PNG_1_0_X) && !defined(PNG_NO_MNG_FEATURES)
#  ifndef PNG_MNG_FEATURES_SUPPORTED
#    define PNG_MNG_FEATURES_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_FLOATING_POINT_SUPPORTED
#  ifndef PNG_FLOATING_POINT_SUPPORTED
#    define PNG_FLOATING_POINT_SUPPORTED
#  endif
#endif
#if defined(MAXSEG_64K) && !defined(PNG_MAX_MALLOC_64K)
#  define PNG_MAX_MALLOC_64K
#endif
#if defined(__CYGWIN__)
#  if defined(ALL_STATIC)
#    if defined(PNG_BUILD_DLL)
#      undef PNG_BUILD_DLL
#    endif
#    if defined(PNG_USE_DLL)
#      undef PNG_USE_DLL
#    endif
#    if defined(PNG_DLL)
#      undef PNG_DLL
#    endif
#    if !defined(PNG_STATIC)
#      define PNG_STATIC
#    endif
#  else
#    if defined (PNG_BUILD_DLL)
#      if defined(PNG_STATIC)
#        undef PNG_STATIC
#      endif
#      if defined(PNG_USE_DLL)
#        undef PNG_USE_DLL
#      endif
#      if !defined(PNG_DLL)
#        define PNG_DLL
#      endif
#    else
#      if defined(PNG_STATIC)
#        if defined(PNG_USE_DLL)
#          undef PNG_USE_DLL
#        endif
#        if defined(PNG_DLL)
#          undef PNG_DLL
#        endif
#      else
#        if !defined(PNG_USE_DLL)
#          define PNG_USE_DLL
#        endif
#        if !defined(PNG_DLL)
#          define PNG_DLL
#        endif
#      endif
#    endif
#  endif
#endif
#if defined(_WIN32_WCE)
#  include <windows.h>
#  define PNG_NO_CONSOLE_IO
#  ifdef PNG_DEBUG
#    undef PNG_DEBUG
#  endif
#endif
#ifdef PNG_BUILD_DLL
#  ifndef PNG_CONSOLE_IO_SUPPORTED
#    ifndef PNG_NO_CONSOLE_IO
#      define PNG_NO_CONSOLE_IO
#    endif
#  endif
#endif
#  ifdef PNG_NO_STDIO
#    ifndef PNG_NO_CONSOLE_IO
#      define PNG_NO_CONSOLE_IO
#    endif
#    ifdef PNG_DEBUG
#      if (PNG_DEBUG > 0)
#        include <stdio.h>
#      endif
#    endif
#  else
#    if !defined(_WIN32_WCE)
#      include <stdio.h>
#    endif
#  endif
#ifndef PNGARG
#ifdef OF
#  define PNGARG(arglist) OF(arglist)
#else
#ifdef _NO_PROTO
#  define PNGARG(arglist) ()
#  ifndef PNG_TYPECAST_NULL
#     define PNG_TYPECAST_NULL
#  endif
#else
#  define PNGARG(arglist) arglist
#endif
#endif
#endif
#ifndef MACOS
#  if (defined(__MWERKS__) && defined(macintosh)) || defined(applec) || \
 defined(THINK_C) || defined(__SC__) || defined(TARGET_OS_MAC)
#    define MACOS
#  endif
#endif
#if !defined(MACOS) && !defined(RISCOS) && !defined(_WIN32_WCE)
#  include <sys/types.h>
#endif
#if !defined(PNG_SETJMP_NOT_SUPPORTED) && !defined(PNG_NO_SETJMP_SUPPORTED)
#  define PNG_SETJMP_SUPPORTED
#endif
#ifdef PNG_SETJMP_SUPPORTED
#  ifdef __linux__
#    ifdef _BSD_SOURCE
#      define PNG_SAVE_BSD_SOURCE
#      undef _BSD_SOURCE
#    endif
#    ifdef _SETJMP_H
 __pngconf.h__ already includes setjmp.h;
 __dont__ include it again.;
#    endif
#  endif
#  include <setjmp.h>
#  ifdef __linux__
#    ifdef PNG_SAVE_BSD_SOURCE
#      ifndef _BSD_SOURCE
#        define _BSD_SOURCE
#      endif
#      undef PNG_SAVE_BSD_SOURCE
#    endif
#  endif
#endif
#ifdef BSD
#  include <strings.h>
#else
#  include <string.h>
#endif
#ifdef PNG_INTERNAL
#include <stdlib.h>
#define PNG_EXTERN
#if defined(PNG_FLOATING_POINT_SUPPORTED)
#  if defined(MACOS)
#    if !defined(__MATH_H__) && !defined(__MATH_H) && !defined(__cmath__)
#      include <fp.h>
#    endif
#  else
#    include <math.h>
#  endif
#  if defined(_AMIGA) && defined(__SASC) && defined(_M68881)
#    include <m68881.h>
#  endif
#endif
#if (defined(__MWERKS__) && defined(WIN32)) || defined(__STDC__)
#  define PNG_ALWAYS_EXTERN
#endif
#if defined(__TURBOC__) && defined(__MSDOS__)
#  include <mem.h>
#  include <alloc.h>
#endif
#if defined(_MSC_VER) && (defined(WIN32) || defined(_Windows) || \
 defined(_WINDOWS) || defined(_WIN32) || defined(__WIN32__))
#  include <malloc.h>
#endif
#ifndef PNG_DITHER_RED_BITS
#  define PNG_DITHER_RED_BITS 5
#endif
#ifndef PNG_DITHER_GREEN_BITS
#  define PNG_DITHER_GREEN_BITS 5
#endif
#ifndef PNG_DITHER_BLUE_BITS
#  define PNG_DITHER_BLUE_BITS 5
#endif
#ifndef PNG_MAX_GAMMA_8
#  define PNG_MAX_GAMMA_8 11
#endif
#ifndef PNG_GAMMA_THRESHOLD
#  define PNG_GAMMA_THRESHOLD 0.05
#endif
#endif
#ifndef PNG_NO_CONST
#  define PNG_CONST const
#else
#  define PNG_CONST
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
#  ifndef PNG_NO_iTXt_SUPPORTED
#    define PNG_NO_iTXt_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_iTXt
#    define PNG_NO_READ_iTXt
#  endif
#  ifndef PNG_NO_WRITE_iTXt
#    define PNG_NO_WRITE_iTXt
#  endif
#endif
#if !defined(PNG_NO_iTXt_SUPPORTED)
#  if !defined(PNG_READ_iTXt_SUPPORTED) && !defined(PNG_NO_READ_iTXt)
#    define PNG_READ_iTXt
#  endif
#  if !defined(PNG_WRITE_iTXt_SUPPORTED) && !defined(PNG_NO_WRITE_iTXt)
#    define PNG_WRITE_iTXt
#  endif
#endif
#ifdef PNG_LEGACY_SUPPORTED
#  define PNG_NO_FREE_ME
#  define PNG_NO_READ_UNKNOWN_CHUNKS
#  define PNG_NO_WRITE_UNKNOWN_CHUNKS
#  define PNG_NO_READ_USER_CHUNKS
#  define PNG_NO_READ_iCCP
#  define PNG_NO_WRITE_iCCP
#  define PNG_NO_READ_iTXt
#  define PNG_NO_WRITE_iTXt
#  define PNG_NO_READ_sCAL
#  define PNG_NO_WRITE_sCAL
#  define PNG_NO_READ_sPLT
#  define PNG_NO_WRITE_sPLT
#  define PNG_NO_INFO_IMAGE
#  define PNG_NO_READ_RGB_TO_GRAY
#  define PNG_NO_READ_USER_TRANSFORM
#  define PNG_NO_WRITE_USER_TRANSFORM
#  define PNG_NO_USER_MEM
#  define PNG_NO_READ_EMPTY_PLTE
#  define PNG_NO_MNG_FEATURES
#  define PNG_NO_FIXED_POINT_SUPPORTED
#endif
#if !defined(PNG_FLOATING_POINT_SUPPORTED) || \
 !defined(PNG_NO_FIXED_POINT_SUPPORTED)
#  define PNG_FIXED_POINT_SUPPORTED
#endif
#ifndef PNG_NO_FREE_ME
#  define PNG_FREE_ME_SUPPORTED
#endif
#if defined(PNG_READ_SUPPORTED)
#if !defined(PNG_READ_TRANSFORMS_NOT_SUPPORTED) && \
 !defined(PNG_NO_READ_TRANSFORMS)
#  define PNG_READ_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_READ_TRANSFORMS_SUPPORTED
#  ifndef PNG_NO_READ_EXPAND
#    define PNG_READ_EXPAND_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_SHIFT
#    define PNG_READ_SHIFT_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_PACK
#    define PNG_READ_PACK_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_BGR
#    define PNG_READ_BGR_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_SWAP
#    define PNG_READ_SWAP_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_PACKSWAP
#    define PNG_READ_PACKSWAP_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_INVERT
#    define PNG_READ_INVERT_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_DITHER
#    define PNG_READ_DITHER_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_BACKGROUND
#    define PNG_READ_BACKGROUND_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_16_TO_8
#    define PNG_READ_16_TO_8_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_FILLER
#    define PNG_READ_FILLER_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_GAMMA
#    define PNG_READ_GAMMA_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_GRAY_TO_RGB
#    define PNG_READ_GRAY_TO_RGB_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_SWAP_ALPHA
#    define PNG_READ_SWAP_ALPHA_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_INVERT_ALPHA
#    define PNG_READ_INVERT_ALPHA_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_STRIP_ALPHA
#    define PNG_READ_STRIP_ALPHA_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_USER_TRANSFORM
#    define PNG_READ_USER_TRANSFORM_SUPPORTED
#  endif
#  ifndef PNG_NO_READ_RGB_TO_GRAY
#    define PNG_READ_RGB_TO_GRAY_SUPPORTED
#  endif
#endif
#if !defined(PNG_NO_PROGRESSIVE_READ) && \
 !defined(PNG_PROGRESSIVE_READ_SUPPORTED)
#  define PNG_PROGRESSIVE_READ_SUPPORTED
#endif
#define PNG_READ_INTERLACING_SUPPORTED
#ifndef PNG_NO_READ_COMPOSITE_NODIV
#  ifndef PNG_NO_READ_COMPOSITED_NODIV
#    define PNG_READ_COMPOSITE_NODIV_SUPPORTED
#  endif
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
#ifndef PNG_NO_READ_EMPTY_PLTE
#  define PNG_READ_EMPTY_PLTE_SUPPORTED
#endif
#endif
#endif
#if defined(PNG_WRITE_SUPPORTED)
# if !defined(PNG_WRITE_TRANSFORMS_NOT_SUPPORTED) && \
 !defined(PNG_NO_WRITE_TRANSFORMS)
#  define PNG_WRITE_TRANSFORMS_SUPPORTED
#endif
#ifdef PNG_WRITE_TRANSFORMS_SUPPORTED
#  ifndef PNG_NO_WRITE_SHIFT
#    define PNG_WRITE_SHIFT_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_PACK
#    define PNG_WRITE_PACK_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_BGR
#    define PNG_WRITE_BGR_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_SWAP
#    define PNG_WRITE_SWAP_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_PACKSWAP
#    define PNG_WRITE_PACKSWAP_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_INVERT
#    define PNG_WRITE_INVERT_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_FILLER
#    define PNG_WRITE_FILLER_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_SWAP_ALPHA
#    define PNG_WRITE_SWAP_ALPHA_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_INVERT_ALPHA
#    define PNG_WRITE_INVERT_ALPHA_SUPPORTED
#  endif
#  ifndef PNG_NO_WRITE_USER_TRANSFORM
#    define PNG_WRITE_USER_TRANSFORM_SUPPORTED
#  endif
#endif
#if !defined(PNG_NO_WRITE_INTERLACING_SUPPORTED) && \
 !defined(PNG_WRITE_INTERLACING_SUPPORTED)
#define PNG_WRITE_INTERLACING_SUPPORTED
#endif
#if !defined(PNG_NO_WRITE_WEIGHTED_FILTER) && \
 !defined(PNG_WRITE_WEIGHTED_FILTER) && \
 defined(PNG_FLOATING_POINT_SUPPORTED)
#  define PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
#endif
#ifndef PNG_NO_WRITE_FLUSH
#  define PNG_WRITE_FLUSH_SUPPORTED
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
#ifndef PNG_NO_WRITE_EMPTY_PLTE
#  define PNG_WRITE_EMPTY_PLTE_SUPPORTED
#endif
#endif
#endif
#ifndef PNG_1_0_X
#  ifndef PNG_NO_ERROR_NUMBERS
#    define PNG_ERROR_NUMBERS_SUPPORTED
#  endif
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED)
#  ifndef PNG_NO_USER_TRANSFORM_PTR
#    define PNG_USER_TRANSFORM_PTR_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_STDIO
#  define PNG_TIME_RFC1123_SUPPORTED
#endif
#if !defined(PNG_NO_EASY_ACCESS) && !defined(PNG_EASY_ACCESS_SUPPORTED)
#  define PNG_EASY_ACCESS_SUPPORTED
#endif
#if defined(PNG_READ_SUPPORTED) && !defined(PNG_NO_OPTIMIZED_CODE)
#  ifndef PNG_OPTIMIZED_CODE_SUPPORTED
#    define PNG_OPTIMIZED_CODE_SUPPORTED
#  endif
#endif
#if defined(PNG_READ_SUPPORTED) && !defined(PNG_NO_ASSEMBLER_CODE)
#  ifndef PNG_ASSEMBLER_CODE_SUPPORTED
#    define PNG_ASSEMBLER_CODE_SUPPORTED
#  endif
#  if defined(__GNUC__) && defined(__x86_64__) && (__GNUC__ < 4)
#    if !defined(PNG_MMX_CODE_SUPPORTED) && !defined(PNG_NO_MMX_CODE)
#      define PNG_NO_MMX_CODE
#    endif
#  endif
#  if defined(__APPLE__)
#    if !defined(PNG_MMX_CODE_SUPPORTED) && !defined(PNG_NO_MMX_CODE)
#      define PNG_NO_MMX_CODE
#    endif
#  endif
#  if (defined(__MWERKS__) && ((__MWERKS__ < 0x0900) || macintosh))
#    if !defined(PNG_MMX_CODE_SUPPORTED) && !defined(PNG_NO_MMX_CODE)
#      define PNG_NO_MMX_CODE
#    endif
#  endif
#  if !defined(PNG_MMX_CODE_SUPPORTED) && !defined(PNG_NO_MMX_CODE)
#    define PNG_MMX_CODE_SUPPORTED
#  endif
#endif
#if !defined(PNG_1_0_X)
#if !defined(PNG_NO_USER_MEM) && !defined(PNG_USER_MEM_SUPPORTED)
#  define PNG_USER_MEM_SUPPORTED
#endif
#endif
#if !defined(PNG_1_0_X)
#ifndef PNG_SET_USER_LIMITS_SUPPORTED
#if !defined(PNG_NO_SET_USER_LIMITS) && !defined(PNG_SET_USER_LIMITS_SUPPORTED)
#  define PNG_SET_USER_LIMITS_SUPPORTED
#endif
#endif
#endif
#ifndef PNG_USER_WIDTH_MAX
#  define PNG_USER_WIDTH_MAX 1000000L
#endif
#ifndef PNG_USER_HEIGHT_MAX
#  define PNG_USER_HEIGHT_MAX 1000000L
#endif
#if defined(PNG_READ_SUPPORTED) && \
 !defined(PNG_READ_ANCILLARY_CHUNKS_NOT_SUPPORTED) && \
 !defined(PNG_NO_READ_ANCILLARY_CHUNKS)
#  define PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
#endif
#if defined(PNG_WRITE_SUPPORTED) && \
 !defined(PNG_WRITE_ANCILLARY_CHUNKS_NOT_SUPPORTED) && \
 !defined(PNG_NO_WRITE_ANCILLARY_CHUNKS)
#  define PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED
#endif
#ifdef PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
#ifdef PNG_NO_READ_TEXT
#  define PNG_NO_READ_iTXt
#  define PNG_NO_READ_tEXt
#  define PNG_NO_READ_zTXt
#endif
#ifndef PNG_NO_READ_bKGD
#  define PNG_READ_bKGD_SUPPORTED
#  define PNG_bKGD_SUPPORTED
#endif
#ifndef PNG_NO_READ_cHRM
#  define PNG_READ_cHRM_SUPPORTED
#  define PNG_cHRM_SUPPORTED
#endif
#ifndef PNG_NO_READ_gAMA
#  define PNG_READ_gAMA_SUPPORTED
#  define PNG_gAMA_SUPPORTED
#endif
#ifndef PNG_NO_READ_hIST
#  define PNG_READ_hIST_SUPPORTED
#  define PNG_hIST_SUPPORTED
#endif
#ifndef PNG_NO_READ_iCCP
#  define PNG_READ_iCCP_SUPPORTED
#  define PNG_iCCP_SUPPORTED
#endif
#ifndef PNG_NO_READ_iTXt
#  ifndef PNG_READ_iTXt_SUPPORTED
#    define PNG_READ_iTXt_SUPPORTED
#  endif
#  ifndef PNG_iTXt_SUPPORTED
#    define PNG_iTXt_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_READ_oFFs
#  define PNG_READ_oFFs_SUPPORTED
#  define PNG_oFFs_SUPPORTED
#endif
#ifndef PNG_NO_READ_pCAL
#  define PNG_READ_pCAL_SUPPORTED
#  define PNG_pCAL_SUPPORTED
#endif
#ifndef PNG_NO_READ_sCAL
#  define PNG_READ_sCAL_SUPPORTED
#  define PNG_sCAL_SUPPORTED
#endif
#ifndef PNG_NO_READ_pHYs
#  define PNG_READ_pHYs_SUPPORTED
#  define PNG_pHYs_SUPPORTED
#endif
#ifndef PNG_NO_READ_sBIT
#  define PNG_READ_sBIT_SUPPORTED
#  define PNG_sBIT_SUPPORTED
#endif
#ifndef PNG_NO_READ_sPLT
#  define PNG_READ_sPLT_SUPPORTED
#  define PNG_sPLT_SUPPORTED
#endif
#ifndef PNG_NO_READ_sRGB
#  define PNG_READ_sRGB_SUPPORTED
#  define PNG_sRGB_SUPPORTED
#endif
#ifndef PNG_NO_READ_tEXt
#  define PNG_READ_tEXt_SUPPORTED
#  define PNG_tEXt_SUPPORTED
#endif
#ifndef PNG_NO_READ_tIME
#  define PNG_READ_tIME_SUPPORTED
#  define PNG_tIME_SUPPORTED
#endif
#ifndef PNG_NO_READ_tRNS
#  define PNG_READ_tRNS_SUPPORTED
#  define PNG_tRNS_SUPPORTED
#endif
#ifndef PNG_NO_READ_zTXt
#  define PNG_READ_zTXt_SUPPORTED
#  define PNG_zTXt_SUPPORTED
#endif
#ifndef PNG_NO_READ_UNKNOWN_CHUNKS
#  define PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#  ifndef PNG_UNKNOWN_CHUNKS_SUPPORTED
#    define PNG_UNKNOWN_CHUNKS_SUPPORTED
#  endif
#  ifndef PNG_NO_HANDLE_AS_UNKNOWN
#    define PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#  endif
#endif
#if !defined(PNG_NO_READ_USER_CHUNKS) && \
 defined(PNG_READ_UNKNOWN_CHUNKS_SUPPORTED)
#  define PNG_READ_USER_CHUNKS_SUPPORTED
#  define PNG_USER_CHUNKS_SUPPORTED
#  ifdef PNG_NO_READ_UNKNOWN_CHUNKS
#    undef PNG_NO_READ_UNKNOWN_CHUNKS
#  endif
#  ifdef PNG_NO_HANDLE_AS_UNKNOWN
#    undef PNG_NO_HANDLE_AS_UNKNOWN
#  endif
#endif
#ifndef PNG_NO_READ_OPT_PLTE
#  define PNG_READ_OPT_PLTE_SUPPORTED
#endif
#if defined(PNG_READ_iTXt_SUPPORTED) || defined(PNG_READ_tEXt_SUPPORTED) || \
 defined(PNG_READ_zTXt_SUPPORTED)
#  define PNG_READ_TEXT_SUPPORTED
#  define PNG_TEXT_SUPPORTED
#endif
#endif
#ifdef PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED
#ifdef PNG_NO_WRITE_TEXT
#  define PNG_NO_WRITE_iTXt
#  define PNG_NO_WRITE_tEXt
#  define PNG_NO_WRITE_zTXt
#endif
#ifndef PNG_NO_WRITE_bKGD
#  define PNG_WRITE_bKGD_SUPPORTED
#  ifndef PNG_bKGD_SUPPORTED
#    define PNG_bKGD_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_cHRM
#  define PNG_WRITE_cHRM_SUPPORTED
#  ifndef PNG_cHRM_SUPPORTED
#    define PNG_cHRM_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_gAMA
#  define PNG_WRITE_gAMA_SUPPORTED
#  ifndef PNG_gAMA_SUPPORTED
#    define PNG_gAMA_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_hIST
#  define PNG_WRITE_hIST_SUPPORTED
#  ifndef PNG_hIST_SUPPORTED
#    define PNG_hIST_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_iCCP
#  define PNG_WRITE_iCCP_SUPPORTED
#  ifndef PNG_iCCP_SUPPORTED
#    define PNG_iCCP_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_iTXt
#  ifndef PNG_WRITE_iTXt_SUPPORTED
#    define PNG_WRITE_iTXt_SUPPORTED
#  endif
#  ifndef PNG_iTXt_SUPPORTED
#    define PNG_iTXt_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_oFFs
#  define PNG_WRITE_oFFs_SUPPORTED
#  ifndef PNG_oFFs_SUPPORTED
#    define PNG_oFFs_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_pCAL
#  define PNG_WRITE_pCAL_SUPPORTED
#  ifndef PNG_pCAL_SUPPORTED
#    define PNG_pCAL_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_sCAL
#  define PNG_WRITE_sCAL_SUPPORTED
#  ifndef PNG_sCAL_SUPPORTED
#    define PNG_sCAL_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_pHYs
#  define PNG_WRITE_pHYs_SUPPORTED
#  ifndef PNG_pHYs_SUPPORTED
#    define PNG_pHYs_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_sBIT
#  define PNG_WRITE_sBIT_SUPPORTED
#  ifndef PNG_sBIT_SUPPORTED
#    define PNG_sBIT_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_sPLT
#  define PNG_WRITE_sPLT_SUPPORTED
#  ifndef PNG_sPLT_SUPPORTED
#    define PNG_sPLT_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_sRGB
#  define PNG_WRITE_sRGB_SUPPORTED
#  ifndef PNG_sRGB_SUPPORTED
#    define PNG_sRGB_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_tEXt
#  define PNG_WRITE_tEXt_SUPPORTED
#  ifndef PNG_tEXt_SUPPORTED
#    define PNG_tEXt_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_tIME
#  define PNG_WRITE_tIME_SUPPORTED
#  ifndef PNG_tIME_SUPPORTED
#    define PNG_tIME_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_tRNS
#  define PNG_WRITE_tRNS_SUPPORTED
#  ifndef PNG_tRNS_SUPPORTED
#    define PNG_tRNS_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_zTXt
#  define PNG_WRITE_zTXt_SUPPORTED
#  ifndef PNG_zTXt_SUPPORTED
#    define PNG_zTXt_SUPPORTED
#  endif
#endif
#ifndef PNG_NO_WRITE_UNKNOWN_CHUNKS
#  define PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#  ifndef PNG_UNKNOWN_CHUNKS_SUPPORTED
#    define PNG_UNKNOWN_CHUNKS_SUPPORTED
#  endif
#  ifndef PNG_NO_HANDLE_AS_UNKNOWN
#     ifndef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#       define PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#     endif
#  endif
#endif
#if defined(PNG_WRITE_iTXt_SUPPORTED) || defined(PNG_WRITE_tEXt_SUPPORTED) || \
 defined(PNG_WRITE_zTXt_SUPPORTED)
#  define PNG_WRITE_TEXT_SUPPORTED
#  ifndef PNG_TEXT_SUPPORTED
#    define PNG_TEXT_SUPPORTED
#  endif
#endif
#endif
#ifndef PNG_NO_INFO_IMAGE
#  define PNG_INFO_IMAGE_SUPPORTED
#endif
#if defined(PNG_tIME_SUPPORTED)
#  if !defined(_WIN32_WCE)
#    include <time.h>
#  endif
#endif
typedef unsigned long png_uint_32;
typedef long png_int_32;
typedef unsigned short png_uint_16;
typedef short png_int_16;
typedef unsigned char png_byte;
#ifdef PNG_SIZE_T
 typedef PNG_SIZE_T png_size_t;
#  define png_sizeof(x) png_convert_size(sizeof(x))
#else
 typedef size_t png_size_t;
#  define png_sizeof(x) sizeof(x)
#endif
#ifdef __BORLANDC__
#  if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
#    define LDATA 1
#  else
#    define LDATA 0
#  endif
#  if !defined(__WIN32__) && !defined(__FLAT__) && !defined(__CYGWIN__)
#    define PNG_MAX_MALLOC_64K
#    if (LDATA != 1)
#      ifndef FAR
#        define FAR __far
#      endif
#      define USE_FAR_KEYWORD
#    endif
#  endif
#endif
#if defined(FAR)
#  if defined(M_I86MM)
#    define USE_FAR_KEYWORD
#    define FARDATA FAR
#    include <dos.h>
#  endif
#endif
#ifndef FAR
#  define FAR
#endif
#ifndef FARDATA
#  define FARDATA
#endif
typedef png_int_32 png_fixed_point;
typedef void            FAR * png_voidp;
typedef png_byte        FAR * png_bytep;
typedef png_uint_32     FAR * png_uint_32p;
typedef png_int_32      FAR * png_int_32p;
typedef png_uint_16     FAR * png_uint_16p;
typedef png_int_16      FAR * png_int_16p;
typedef PNG_CONST char  FAR * png_const_charp;
typedef char            FAR * png_charp;
typedef png_fixed_point FAR * png_fixed_point_p;
#ifndef PNG_NO_STDIO
#if defined(_WIN32_WCE)
typedef HANDLE                png_FILE_p;
#else
typedef FILE                * png_FILE_p;
#endif
#endif
#ifdef PNG_FLOATING_POINT_SUPPORTED
typedef double          FAR * png_doublep;
#endif
typedef png_byte        FAR * FAR * png_bytepp;
typedef png_uint_32     FAR * FAR * png_uint_32pp;
typedef png_int_32      FAR * FAR * png_int_32pp;
typedef png_uint_16     FAR * FAR * png_uint_16pp;
typedef png_int_16      FAR * FAR * png_int_16pp;
typedef PNG_CONST char  FAR * FAR * png_const_charpp;
typedef char            FAR * FAR * png_charpp;
typedef png_fixed_point FAR * FAR * png_fixed_point_pp;
#ifdef PNG_FLOATING_POINT_SUPPORTED
typedef double          FAR * FAR * png_doublepp;
#endif
typedef char            FAR * FAR * FAR * png_charppp;
#if defined(PNG_1_0_X) || defined(PNG_1_2_X)
typedef charf *         png_zcharp;
typedef charf * FAR *   png_zcharpp;
typedef z_stream FAR *  png_zstreamp;
#endif
#if !defined(PNG_DLL) && (defined(PNG_BUILD_DLL) || defined(PNG_USE_DLL))
#  define PNG_DLL
#endif
#if defined(__CYGWIN__)
#  if !defined(PNG_STATIC)
#    if defined(PNG_USE_GLOBAL_ARRAYS)
#      undef PNG_USE_GLOBAL_ARRAYS
#    endif
#    if !defined(PNG_USE_LOCAL_ARRAYS)
#      define PNG_USE_LOCAL_ARRAYS
#    endif
#  else
#    if defined(PNG_USE_LOCAL_ARRAYS) || defined(PNG_NO_GLOBAL_ARRAYS)
#      if defined(PNG_USE_GLOBAL_ARRAYS)
#        undef PNG_USE_GLOBAL_ARRAYS
#      endif
#    endif
#  endif
#  if !defined(PNG_USE_LOCAL_ARRAYS) && !defined(PNG_USE_GLOBAL_ARRAYS)
#    define PNG_USE_LOCAL_ARRAYS
#  endif
#endif
#if !defined(PNG_USE_LOCAL_ARRAYS) && !defined(PNG_USE_GLOBAL_ARRAYS)
#  if defined(PNG_NO_GLOBAL_ARRAYS) || \
 (defined(__GNUC__) && defined(PNG_DLL)) || defined(_MSC_VER)
#    define PNG_USE_LOCAL_ARRAYS
#  else
#    define PNG_USE_GLOBAL_ARRAYS
#  endif
#endif
#if defined(__CYGWIN__)
#  undef PNGAPI
#  define PNGAPI __cdecl
#  undef PNG_IMPEXP
#  define PNG_IMPEXP
#endif
#if defined(__MINGW32__) && !defined(PNG_MODULEDEF)
#  ifndef PNG_NO_MODULEDEF
#    define PNG_NO_MODULEDEF
#  endif
#endif
#if !defined(PNG_IMPEXP) && defined(PNG_BUILD_DLL) && !defined(PNG_NO_MODULEDEF)
#  define PNG_IMPEXP
#endif
#if defined(PNG_DLL) || defined(_DLL) || defined(__DLL__ ) || \
 (( defined(_Windows) || defined(_WINDOWS) || \
 defined(WIN32) || defined(_WIN32) || defined(__WIN32__) ))
#  ifndef PNGAPI
#     if defined(__GNUC__) || (defined (_MSC_VER) && (_MSC_VER >= 800))
#        define PNGAPI __cdecl
#     else
#        define PNGAPI _cdecl
#     endif
#  endif
#  if !defined(PNG_IMPEXP) && (!defined(PNG_DLL) || \
 0  )
#     define PNG_IMPEXP
#  endif
#  if !defined(PNG_IMPEXP)
#     define PNG_EXPORT_TYPE1(type,symbol)  PNG_IMPEXP type PNGAPI symbol
#     define PNG_EXPORT_TYPE2(type,symbol)  type PNG_IMPEXP PNGAPI symbol
#     if defined(_MSC_VER) || defined(__BORLANDC__)
#        if (_MSC_VER >= 800) || (__BORLANDC__ >= 0x500)
#           define PNG_EXPORT PNG_EXPORT_TYPE1
#        else
#           define PNG_EXPORT PNG_EXPORT_TYPE2
#           if defined(PNG_BUILD_DLL)
#              define PNG_IMPEXP __export
#           else
#              define PNG_IMPEXP
#           endif
#        endif
#     endif
#     if !defined(PNG_IMPEXP)
#        if defined(PNG_BUILD_DLL)
#           define PNG_IMPEXP __declspec(dllexport)
#        else
#           define PNG_IMPEXP __declspec(dllimport)
#        endif
#     endif
#  endif
#else
#   if (defined(__IBMC__) || defined(__IBMCPP__)) && defined(__OS2__)
#      ifndef PNGAPI
#         define PNGAPI _System
#      endif
#   else
#      if 0
#      endif
#   endif
#endif
#ifndef PNGAPI
#  define PNGAPI
#endif
#ifndef PNG_IMPEXP
#  define PNG_IMPEXP
#endif
#ifdef PNG_BUILDSYMS
#  ifndef PNG_EXPORT
#    define PNG_EXPORT(type,symbol) PNG_FUNCTION_EXPORT symbol END
#  endif
#  ifdef PNG_USE_GLOBAL_ARRAYS
#    ifndef PNG_EXPORT_VAR
#      define PNG_EXPORT_VAR(type) PNG_DATA_EXPORT
#    endif
#  endif
#endif
#ifndef PNG_EXPORT
#  define PNG_EXPORT(type,symbol) PNG_IMPEXP type PNGAPI symbol
#endif
#ifdef PNG_USE_GLOBAL_ARRAYS
#  ifndef PNG_EXPORT_VAR
#    define PNG_EXPORT_VAR(type) extern PNG_IMPEXP type
#  endif
#endif
#ifndef PNG_ABORT
#  define PNG_ABORT() abort()
#endif
#ifdef PNG_SETJMP_SUPPORTED
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#else
#  define png_jmpbuf(png_ptr) \
 (LIBPNG_WAS_COMPILED_WITH__PNG_SETJMP_NOT_SUPPORTED)
#endif
#if defined(USE_FAR_KEYWORD)
#  define CHECK   1
#  define NOCHECK 0
#  define CVT_PTR(ptr) (png_far_to_near(png_ptr,ptr,CHECK))
#  define CVT_PTR_NOCHECK(ptr) (png_far_to_near(png_ptr,ptr,NOCHECK))
#  define png_snprintf _fsnprintf
#  define png_strlen  _fstrlen
#  define png_memcmp  _fmemcmp
#  define png_memcpy  _fmemcpy
#  define png_memset  _fmemset
#else
#  define CVT_PTR(ptr)         (ptr)
#  define CVT_PTR_NOCHECK(ptr) (ptr)
#  ifndef PNG_NO_SNPRINTF
#    ifdef _MSC_VER
#      define png_snprintf _snprintf
#      define png_snprintf2 _snprintf
#      define png_snprintf6 _snprintf
#    else
#      define png_snprintf snprintf
#      define png_snprintf2 snprintf
#      define png_snprintf6 snprintf
#    endif
#  else
#    define png_snprintf(s1,n,fmt,x1) sprintf(s1,fmt,x1)
#    define png_snprintf2(s1,n,fmt,x1,x2) sprintf(s1,fmt,x1,x2)
#    define png_snprintf6(s1,n,fmt,x1,x2,x3,x4,x5,x6) \
 sprintf(s1,fmt,x1,x2,x3,x4,x5,x6)
#  endif
#  define png_strlen  strlen
#  define png_memcmp  memcmp
#  define png_memcpy  memcpy
#  define png_memset  memset
#endif
#if (PNG_ZBUF_SIZE > 65536L) && defined(PNG_MAX_MALLOC_64K)
#  undef PNG_ZBUF_SIZE
#  define PNG_ZBUF_SIZE 65536L
#endif
#endif
#endif
#ifndef PNG_H
#define PNG_H
#define PNG_LIBPNG_VER_STRING "1.2.32"
#define PNG_HEADER_VERSION_STRING \
 " libpng version 1.2.32 - September 18, 2008\n"
#define PNG_LIBPNG_VER_SONUM   0
#define PNG_LIBPNG_VER_DLLNUM  13
#define PNG_LIBPNG_VER_MAJOR   1
#define PNG_LIBPNG_VER_MINOR   2
#define PNG_LIBPNG_VER_RELEASE 32
#define PNG_LIBPNG_VER_BUILD  0
#define PNG_LIBPNG_BUILD_ALPHA    1
#define PNG_LIBPNG_BUILD_BETA     2
#define PNG_LIBPNG_BUILD_RC       3
#define PNG_LIBPNG_BUILD_STABLE   4
#define PNG_LIBPNG_BUILD_RELEASE_STATUS_MASK 7
#define PNG_LIBPNG_BUILD_PATCH    8
#define PNG_LIBPNG_BUILD_PRIVATE 16
#define PNG_LIBPNG_BUILD_SPECIAL 32
#define PNG_LIBPNG_BUILD_BASE_TYPE PNG_LIBPNG_BUILD_STABLE
#define PNG_LIBPNG_VER 10232
#ifndef PNG_VERSION_INFO_ONLY
#endif
#if defined(PNG_USER_PRIVATEBUILD)
#  define PNG_LIBPNG_BUILD_TYPE \
 (PNG_LIBPNG_BUILD_BASE_TYPE | PNG_LIBPNG_BUILD_PRIVATE)
#else
#  if defined(PNG_LIBPNG_SPECIALBUILD)
#    define PNG_LIBPNG_BUILD_TYPE \
 (PNG_LIBPNG_BUILD_BASE_TYPE | PNG_LIBPNG_BUILD_SPECIAL)
#  else
#    define PNG_LIBPNG_BUILD_TYPE (PNG_LIBPNG_BUILD_BASE_TYPE)
#  endif
#endif
#ifndef PNG_VERSION_INFO_ONLY
#ifdef __cplusplus
extern "C" {
#endif
#ifndef PNG_NO_TYPECAST_NULL
#define int_p_NULL                (int *)NULL
#define png_bytep_NULL            (png_bytep)NULL
#define png_bytepp_NULL           (png_bytepp)NULL
#define png_doublep_NULL          (png_doublep)NULL
#define png_error_ptr_NULL        (png_error_ptr)NULL
#define png_flush_ptr_NULL        (png_flush_ptr)NULL
#define png_free_ptr_NULL         (png_free_ptr)NULL
#define png_infopp_NULL           (png_infopp)NULL
#define png_malloc_ptr_NULL       (png_malloc_ptr)NULL
#define png_read_status_ptr_NULL  (png_read_status_ptr)NULL
#define png_rw_ptr_NULL           (png_rw_ptr)NULL
#define png_structp_NULL          (png_structp)NULL
#define png_uint_16p_NULL         (png_uint_16p)NULL
#define png_voidp_NULL            (png_voidp)NULL
#define png_write_status_ptr_NULL (png_write_status_ptr)NULL
#else
#define int_p_NULL                NULL
#define png_bytep_NULL            NULL
#define png_bytepp_NULL           NULL
#define png_doublep_NULL          NULL
#define png_error_ptr_NULL        NULL
#define png_flush_ptr_NULL        NULL
#define png_free_ptr_NULL         NULL
#define png_infopp_NULL           NULL
#define png_malloc_ptr_NULL       NULL
#define png_read_status_ptr_NULL  NULL
#define png_rw_ptr_NULL           NULL
#define png_structp_NULL          NULL
#define png_uint_16p_NULL         NULL
#define png_voidp_NULL            NULL
#define png_write_status_ptr_NULL NULL
#endif
#if !defined(PNG_NO_EXTERN) || defined(PNG_ALWAYS_EXTERN)
#ifdef PNG_USE_GLOBAL_ARRAYS
PNG_EXPORT_VAR (PNG_CONST char) png_libpng_ver[18];
#else
#define png_libpng_ver png_get_header_ver(NULL)
#endif
#ifdef PNG_USE_GLOBAL_ARRAYS
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_start[7];
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_inc[7];
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_ystart[7];
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_yinc[7];
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_mask[7];
PNG_EXPORT_VAR (PNG_CONST int FARDATA) png_pass_dsp_mask[7];
#endif
#endif
typedef struct png_color_struct
{
 png_byte red;
 png_byte green;
 png_byte blue;
} png_color;
typedef png_color FAR * png_colorp;
typedef png_color FAR * FAR * png_colorpp;
typedef struct png_color_16_struct
{
 png_byte index;
 png_uint_16 red;
 png_uint_16 green;
 png_uint_16 blue;
 png_uint_16 gray;
} png_color_16;
typedef png_color_16 FAR * png_color_16p;
typedef png_color_16 FAR * FAR * png_color_16pp;
typedef struct png_color_8_struct
{
 png_byte red;
 png_byte green;
 png_byte blue;
 png_byte gray;
 png_byte alpha;
} png_color_8;
typedef png_color_8 FAR * png_color_8p;
typedef png_color_8 FAR * FAR * png_color_8pp;
typedef struct png_sPLT_entry_struct
{
 png_uint_16 red;
 png_uint_16 green;
 png_uint_16 blue;
 png_uint_16 alpha;
 png_uint_16 frequency;
} png_sPLT_entry;
typedef png_sPLT_entry FAR * png_sPLT_entryp;
typedef png_sPLT_entry FAR * FAR * png_sPLT_entrypp;
typedef struct png_sPLT_struct
{
 png_charp name;
 png_byte depth;
 png_sPLT_entryp entries;
 png_int_32 nentries;
} png_sPLT_t;
typedef png_sPLT_t FAR * png_sPLT_tp;
typedef png_sPLT_t FAR * FAR * png_sPLT_tpp;
#ifdef PNG_TEXT_SUPPORTED
typedef struct png_text_struct
{
 int  compression;
 png_charp key;
 png_charp text;
 png_size_t text_length;
#ifdef PNG_iTXt_SUPPORTED
 png_size_t itxt_length;
 png_charp lang;
 png_charp lang_key;
#endif
} png_text;
typedef png_text FAR * png_textp;
typedef png_text FAR * FAR * png_textpp;
#endif
#define PNG_TEXT_COMPRESSION_NONE_WR -3
#define PNG_TEXT_COMPRESSION_zTXt_WR -2
#define PNG_TEXT_COMPRESSION_NONE    -1
#define PNG_TEXT_COMPRESSION_zTXt     0
#define PNG_ITXT_COMPRESSION_NONE     1
#define PNG_ITXT_COMPRESSION_zTXt     2
#define PNG_TEXT_COMPRESSION_LAST     3
typedef struct png_time_struct
{
 png_uint_16 year;
 png_byte month;
 png_byte day;
 png_byte hour;
 png_byte minute;
 png_byte second;
} png_time;
typedef png_time FAR * png_timep;
typedef png_time FAR * FAR * png_timepp;
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
#define PNG_CHUNK_NAME_LENGTH 5
typedef struct png_unknown_chunk_t
{
 png_byte name[PNG_CHUNK_NAME_LENGTH];
 png_byte *data;
 png_size_t size;
 png_byte location;
}
png_unknown_chunk;
typedef png_unknown_chunk FAR * png_unknown_chunkp;
typedef png_unknown_chunk FAR * FAR * png_unknown_chunkpp;
#endif
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
#if defined(PNG_gAMA_SUPPORTED) && defined(PNG_FLOATING_POINT_SUPPORTED)
 float gamma;
#endif
#if defined(PNG_sRGB_SUPPORTED)
 png_byte srgb_intent;
#endif
#if defined(PNG_TEXT_SUPPORTED)
 int num_text;
 int max_text;
 png_textp text;
#endif
#if defined(PNG_tIME_SUPPORTED)
 png_time mod_time;
#endif
#if defined(PNG_sBIT_SUPPORTED)
 png_color_8 sig_bit;
#endif
#if defined(PNG_tRNS_SUPPORTED) || defined(PNG_READ_EXPAND_SUPPORTED) || \
defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_bytep trans;
 png_color_16 trans_values;
#endif
#if defined(PNG_bKGD_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_color_16 background;
#endif
#if defined(PNG_oFFs_SUPPORTED)
 png_int_32 x_offset;
 png_int_32 y_offset;
 png_byte offset_unit_type;
#endif
#if defined(PNG_pHYs_SUPPORTED)
 png_uint_32 x_pixels_per_unit;
 png_uint_32 y_pixels_per_unit;
 png_byte phys_unit_type;
#endif
#if defined(PNG_hIST_SUPPORTED)
 png_uint_16p hist;
#endif
#ifdef PNG_cHRM_SUPPORTED
#ifdef PNG_FLOATING_POINT_SUPPORTED
 float x_white;
 float y_white;
 float x_red;
 float y_red;
 float x_green;
 float y_green;
 float x_blue;
 float y_blue;
#endif
#endif
#if defined(PNG_pCAL_SUPPORTED)
 png_charp pcal_purpose;
 png_int_32 pcal_X0;
 png_int_32 pcal_X1;
 png_charp pcal_units;
 png_charpp pcal_params;
 png_byte pcal_type;
 png_byte pcal_nparams;
#endif
#ifdef PNG_FREE_ME_SUPPORTED
 png_uint_32 free_me;
#endif
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
 png_unknown_chunkp unknown_chunks;
 png_size_t unknown_chunks_num;
#endif
#if defined(PNG_iCCP_SUPPORTED)
 png_charp iccp_name;
 png_charp iccp_profile;
 png_uint_32 iccp_proflen;
 png_byte iccp_compression;
#endif
#if defined(PNG_sPLT_SUPPORTED)
 png_sPLT_tp splt_palettes;
 png_uint_32 splt_palettes_num;
#endif
#if defined(PNG_sCAL_SUPPORTED)
 png_byte scal_unit;
#ifdef PNG_FLOATING_POINT_SUPPORTED
 double scal_pixel_width;
 double scal_pixel_height;
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
 png_charp scal_s_width;
 png_charp scal_s_height;
#endif
#endif
#if defined(PNG_INFO_IMAGE_SUPPORTED)
 png_bytepp row_pointers;
#endif
#if defined(PNG_FIXED_POINT_SUPPORTED) && defined(PNG_gAMA_SUPPORTED)
 png_fixed_point int_gamma;
#endif
#if defined(PNG_cHRM_SUPPORTED) && defined(PNG_FIXED_POINT_SUPPORTED)
 png_fixed_point int_x_white;
 png_fixed_point int_y_white;
 png_fixed_point int_x_red;
 png_fixed_point int_y_red;
 png_fixed_point int_x_green;
 png_fixed_point int_y_green;
 png_fixed_point int_x_blue;
 png_fixed_point int_y_blue;
#endif
} png_info;
typedef png_info FAR * png_infop;
typedef png_info FAR * FAR * png_infopp;
#define PNG_UINT_31_MAX ((png_uint_32)0x7fffffffL)
#define PNG_UINT_32_MAX ((png_uint_32)(-1))
#define PNG_SIZE_MAX ((png_size_t)(-1))
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
#define PNG_MAX_UINT PNG_UINT_31_MAX
#endif
#define PNG_COLOR_MASK_PALETTE    1
#define PNG_COLOR_MASK_COLOR      2
#define PNG_COLOR_MASK_ALPHA      4
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_PALETTE  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)
#define PNG_COLOR_TYPE_RGB        (PNG_COLOR_MASK_COLOR)
#define PNG_COLOR_TYPE_RGB_ALPHA  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_GRAY_ALPHA (PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_RGBA  PNG_COLOR_TYPE_RGB_ALPHA
#define PNG_COLOR_TYPE_GA  PNG_COLOR_TYPE_GRAY_ALPHA
#define PNG_COMPRESSION_TYPE_BASE 0
#define PNG_COMPRESSION_TYPE_DEFAULT PNG_COMPRESSION_TYPE_BASE
#define PNG_FILTER_TYPE_BASE      0
#define PNG_INTRAPIXEL_DIFFERENCING 64
#define PNG_FILTER_TYPE_DEFAULT   PNG_FILTER_TYPE_BASE
#define PNG_INTERLACE_NONE        0
#define PNG_INTERLACE_ADAM7       1
#define PNG_INTERLACE_LAST        2
#define PNG_OFFSET_PIXEL          0
#define PNG_OFFSET_MICROMETER     1
#define PNG_OFFSET_LAST           2
#define PNG_EQUATION_LINEAR       0
#define PNG_EQUATION_BASE_E       1
#define PNG_EQUATION_ARBITRARY    2
#define PNG_EQUATION_HYPERBOLIC   3
#define PNG_EQUATION_LAST         4
#define PNG_SCALE_UNKNOWN         0
#define PNG_SCALE_METER           1
#define PNG_SCALE_RADIAN          2
#define PNG_SCALE_LAST            3
#define PNG_RESOLUTION_UNKNOWN    0
#define PNG_RESOLUTION_METER      1
#define PNG_RESOLUTION_LAST       2
#define PNG_sRGB_INTENT_PERCEPTUAL 0
#define PNG_sRGB_INTENT_RELATIVE   1
#define PNG_sRGB_INTENT_SATURATION 2
#define PNG_sRGB_INTENT_ABSOLUTE   3
#define PNG_sRGB_INTENT_LAST       4
#define PNG_KEYWORD_MAX_LENGTH     79
#define PNG_MAX_PALETTE_LENGTH    256
#define PNG_INFO_gAMA 0x0001
#define PNG_INFO_sBIT 0x0002
#define PNG_INFO_cHRM 0x0004
#define PNG_INFO_PLTE 0x0008
#define PNG_INFO_tRNS 0x0010
#define PNG_INFO_bKGD 0x0020
#define PNG_INFO_hIST 0x0040
#define PNG_INFO_pHYs 0x0080
#define PNG_INFO_oFFs 0x0100
#define PNG_INFO_tIME 0x0200
#define PNG_INFO_pCAL 0x0400
#define PNG_INFO_sRGB 0x0800
#define PNG_INFO_iCCP 0x1000
#define PNG_INFO_sPLT 0x2000
#define PNG_INFO_sCAL 0x4000
#define PNG_INFO_IDAT 0x8000L
typedef struct png_row_info_struct
{
 png_uint_32 width;
 png_uint_32 rowbytes;
 png_byte color_type;
 png_byte bit_depth;
 png_byte channels;
 png_byte pixel_depth;
} png_row_info;
typedef png_row_info FAR * png_row_infop;
typedef png_row_info FAR * FAR * png_row_infopp;
typedef struct png_struct_def png_struct;
typedef png_struct FAR * png_structp;
typedef void (PNGAPI *png_error_ptr) PNGARG((png_structp, png_const_charp));
typedef void (PNGAPI *png_rw_ptr) PNGARG((png_structp, png_bytep, png_size_t));
typedef void (PNGAPI *png_flush_ptr) PNGARG((png_structp));
typedef void (PNGAPI *png_read_status_ptr) PNGARG((png_structp, png_uint_32,
 int));
typedef void (PNGAPI *png_write_status_ptr) PNGARG((png_structp, png_uint_32,
 int));
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
typedef void (PNGAPI *png_progressive_info_ptr) PNGARG((png_structp, png_infop));
typedef void (PNGAPI *png_progressive_end_ptr) PNGARG((png_structp, png_infop));
typedef void (PNGAPI *png_progressive_row_ptr) PNGARG((png_structp, png_bytep,
 png_uint_32, int));
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_LEGACY_SUPPORTED)
typedef void (PNGAPI *png_user_transform_ptr) PNGARG((png_structp,
 png_row_infop, png_bytep));
#endif
#if defined(PNG_USER_CHUNKS_SUPPORTED)
typedef int (PNGAPI *png_user_chunk_ptr) PNGARG((png_structp, png_unknown_chunkp));
#endif
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
typedef void (PNGAPI *png_unknown_chunk_ptr) PNGARG((png_structp));
#endif
#define PNG_TRANSFORM_IDENTITY       0x0000
#define PNG_TRANSFORM_STRIP_16       0x0001
#define PNG_TRANSFORM_STRIP_ALPHA    0x0002
#define PNG_TRANSFORM_PACKING        0x0004
#define PNG_TRANSFORM_PACKSWAP       0x0008
#define PNG_TRANSFORM_EXPAND         0x0010
#define PNG_TRANSFORM_INVERT_MONO    0x0020
#define PNG_TRANSFORM_SHIFT          0x0040
#define PNG_TRANSFORM_BGR            0x0080
#define PNG_TRANSFORM_SWAP_ALPHA     0x0100
#define PNG_TRANSFORM_SWAP_ENDIAN    0x0200
#define PNG_TRANSFORM_INVERT_ALPHA   0x0400
#define PNG_TRANSFORM_STRIP_FILLER   0x0800
#define PNG_FLAG_MNG_EMPTY_PLTE     0x01
#define PNG_FLAG_MNG_FILTER_64      0x04
#define PNG_ALL_MNG_FEATURES        0x05
typedef png_voidp (*png_malloc_ptr) PNGARG((png_structp, png_size_t));
typedef void (*png_free_ptr) PNGARG((png_structp, png_voidp));
struct png_struct_def
{
#ifdef PNG_SETJMP_SUPPORTED
 jmp_buf jmpbuf;
#endif
 png_error_ptr error_fn;
 png_error_ptr warning_fn;
 png_voidp error_ptr;
 png_rw_ptr write_data_fn;
 png_rw_ptr read_data_fn;
 png_voidp io_ptr;
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED)
 png_user_transform_ptr read_user_transform_fn;
#endif
#if defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED)
 png_user_transform_ptr write_user_transform_fn;
#endif
#if defined(PNG_USER_TRANSFORM_PTR_SUPPORTED)
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED)
 png_voidp user_transform_ptr;
 png_byte user_transform_depth;
 png_byte user_transform_channels;
#endif
#endif
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
#ifndef PNG_NO_WRITE_FILTER
 png_bytep sub_row;
 png_bytep up_row;
 png_bytep avg_row;
 png_bytep paeth_row;
#endif
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
#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
#ifdef PNG_LEGACY_SUPPORTED
 png_byte filler;
#else
 png_uint_16 filler;
#endif
#endif
#if defined(PNG_bKGD_SUPPORTED)
 png_byte background_gamma_type;
#  ifdef PNG_FLOATING_POINT_SUPPORTED
 float background_gamma;
#  endif
 png_color_16 background;
#if defined(PNG_READ_GAMMA_SUPPORTED)
 png_color_16 background_1;
#endif
#endif
#if defined(PNG_WRITE_FLUSH_SUPPORTED)
 png_flush_ptr output_flush_fn;
 png_uint_32 flush_dist;
 png_uint_32 flush_rows;
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
 int gamma_shift;
#ifdef PNG_FLOATING_POINT_SUPPORTED
 float gamma;
 float screen_gamma;
#endif
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_bytep gamma_table;
 png_bytep gamma_from_1;
 png_bytep gamma_to_1;
 png_uint_16pp gamma_16_table;
 png_uint_16pp gamma_16_from_1;
 png_uint_16pp gamma_16_to_1;
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_sBIT_SUPPORTED)
 png_color_8 sig_bit;
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
 png_color_8 shift;
#endif
#if defined(PNG_tRNS_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED) \
 || defined(PNG_READ_EXPAND_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_bytep trans;
 png_color_16 trans_values;
#endif
 png_read_status_ptr read_row_fn;
 png_write_status_ptr write_row_fn;
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
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
#  if defined(PNG_TEXT_SUPPORTED)
 png_size_t current_text_size;
 png_size_t current_text_left;
 png_charp current_text;
 png_charp current_text_ptr;
#  endif
#endif
#if defined(__TURBOC__) && !defined(_Windows) && !defined(__FLAT__)
 png_bytepp offset_table_ptr;
 png_bytep offset_table;
 png_uint_16 offset_table_number;
 png_uint_16 offset_table_count;
 png_uint_16 offset_table_count_free;
#endif
#if defined(PNG_READ_DITHER_SUPPORTED)
 png_bytep palette_lookup;
 png_bytep dither_index;
#endif
#if defined(PNG_READ_DITHER_SUPPORTED) || defined(PNG_hIST_SUPPORTED)
 png_uint_16p hist;
#endif
#if defined(PNG_WRITE_WEIGHTED_FILTER_SUPPORTED)
 png_byte heuristic_method;
 png_byte num_prev_filters;
 png_bytep prev_filters;
 png_uint_16p filter_weights;
 png_uint_16p inv_filter_weights;
 png_uint_16p filter_costs;
 png_uint_16p inv_filter_costs;
#endif
#if defined(PNG_TIME_RFC1123_SUPPORTED)
 png_charp time_buffer;
#endif
#ifdef PNG_FREE_ME_SUPPORTED
 png_uint_32 free_me;
#endif
#if defined(PNG_USER_CHUNKS_SUPPORTED)
 png_voidp user_chunk_ptr;
 png_user_chunk_ptr read_user_chunk_fn;
#endif
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
 int num_chunk_list;
 png_bytep chunk_list;
#endif
#if defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
 png_byte rgb_to_gray_status;
 png_uint_16 rgb_to_gray_red_coeff;
 png_uint_16 rgb_to_gray_green_coeff;
 png_uint_16 rgb_to_gray_blue_coeff;
#endif
#if defined(PNG_MNG_FEATURES_SUPPORTED) || \
 defined(PNG_READ_EMPTY_PLTE_SUPPORTED) || \
 defined(PNG_WRITE_EMPTY_PLTE_SUPPORTED)
#ifdef PNG_1_0_X
 png_byte mng_features_permitted;
#else
 png_uint_32 mng_features_permitted;
#endif
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_fixed_point int_gamma;
#endif
#if defined(PNG_MNG_FEATURES_SUPPORTED)
 png_byte filter_type;
#endif
#if defined(PNG_1_0_X)
 png_uint_32 row_buf_size;
#endif
#if defined(PNG_ASSEMBLER_CODE_SUPPORTED)
#  if !defined(PNG_1_0_X)
#    if defined(PNG_MMX_CODE_SUPPORTED)
 png_byte     mmx_bitdepth_threshold;
 png_uint_32  mmx_rowbytes_threshold;
#    endif
 png_uint_32  asm_flags;
#  endif
#endif
#ifdef PNG_USER_MEM_SUPPORTED
 png_voidp mem_ptr;
 png_malloc_ptr malloc_fn;
 png_free_ptr free_fn;
#endif
 png_bytep big_row_buf;
#if defined(PNG_READ_DITHER_SUPPORTED)
 png_bytep dither_sort;
 png_bytep index_to_palette;
 png_bytep palette_to_index;
#endif
 png_byte compression_type;
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
 png_uint_32 user_width_max;
 png_uint_32 user_height_max;
#endif
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
 png_unknown_chunk unknown_chunk;
#endif
 png_uint_32 old_big_row_buf_size, old_prev_row_size;
 png_charp chunkdata;
};
typedef png_structp version_1_2_32;
typedef png_struct FAR * FAR * png_structpp;
extern PNG_EXPORT(png_uint_32,png_access_version_number) PNGARG((void));
extern PNG_EXPORT(void,png_set_sig_bytes) PNGARG((png_structp png_ptr,
 int num_bytes));
extern PNG_EXPORT(int,png_sig_cmp) PNGARG((png_bytep sig, png_size_t start,
 png_size_t num_to_check));
extern PNG_EXPORT(int,png_check_sig) PNGARG((png_bytep sig, int num));
extern PNG_EXPORT(png_structp,png_create_read_struct)
 PNGARG((png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn));
extern PNG_EXPORT(png_structp,png_create_write_struct)
 PNGARG((png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn));
#ifdef PNG_WRITE_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_compression_buffer_size)
 PNGARG((png_structp png_ptr));
#endif
#ifdef PNG_WRITE_SUPPORTED
extern PNG_EXPORT(void,png_set_compression_buffer_size)
 PNGARG((png_structp png_ptr, png_uint_32 size));
#endif
extern PNG_EXPORT(int,png_reset_zstream) PNGARG((png_structp png_ptr));
#ifdef PNG_USER_MEM_SUPPORTED
extern PNG_EXPORT(png_structp,png_create_read_struct_2)
 PNGARG((png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
 png_malloc_ptr malloc_fn, png_free_ptr free_fn));
extern PNG_EXPORT(png_structp,png_create_write_struct_2)
 PNGARG((png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
 png_malloc_ptr malloc_fn, png_free_ptr free_fn));
#endif
extern PNG_EXPORT(void,png_write_chunk) PNGARG((png_structp png_ptr,
 png_bytep chunk_name, png_bytep data, png_size_t length));
extern PNG_EXPORT(void,png_write_chunk_start) PNGARG((png_structp png_ptr,
 png_bytep chunk_name, png_uint_32 length));
extern PNG_EXPORT(void,png_write_chunk_data) PNGARG((png_structp png_ptr,
 png_bytep data, png_size_t length));
extern PNG_EXPORT(void,png_write_chunk_end) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_infop,png_create_info_struct)
 PNGARG((png_structp png_ptr));
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
extern PNG_EXPORT(void,png_info_init) PNGARG((png_infop info_ptr));
#undef png_info_init
#define png_info_init(info_ptr) png_info_init_3(&info_ptr,\
 png_sizeof(png_info));
#endif
extern PNG_EXPORT(void,png_info_init_3) PNGARG((png_infopp info_ptr,
 png_size_t png_info_struct_size));
extern PNG_EXPORT(void,png_write_info_before_PLTE) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
extern PNG_EXPORT(void,png_write_info) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
extern PNG_EXPORT(void,png_read_info) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#endif
#if defined(PNG_TIME_RFC1123_SUPPORTED)
extern PNG_EXPORT(png_charp,png_convert_to_rfc1123)
 PNGARG((png_structp png_ptr, png_timep ptime));
#endif
#if !defined(_WIN32_WCE)
#if defined(PNG_WRITE_tIME_SUPPORTED)
extern PNG_EXPORT(void,png_convert_from_struct_tm) PNGARG((png_timep ptime,
 struct tm FAR * ttime));
extern PNG_EXPORT(void,png_convert_from_time_t) PNGARG((png_timep ptime,
 time_t ttime));
#endif
#endif
#if defined(PNG_READ_EXPAND_SUPPORTED)
extern PNG_EXPORT(void,png_set_expand) PNGARG((png_structp png_ptr));
#if !defined(PNG_1_0_X)
extern PNG_EXPORT(void,png_set_expand_gray_1_2_4_to_8) PNGARG((png_structp
 png_ptr));
#endif
extern PNG_EXPORT(void,png_set_palette_to_rgb) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_set_tRNS_to_alpha) PNGARG((png_structp png_ptr));
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
extern PNG_EXPORT(void,png_set_gray_1_2_4_to_8) PNGARG((png_structp png_ptr));
#endif
#endif
#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
extern PNG_EXPORT(void,png_set_bgr) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_GRAY_TO_RGB_SUPPORTED)
extern PNG_EXPORT(void,png_set_gray_to_rgb) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_rgb_to_gray) PNGARG((png_structp png_ptr,
 int error_action, double red, double green ));
#endif
extern PNG_EXPORT(void,png_set_rgb_to_gray_fixed) PNGARG((png_structp png_ptr,
 int error_action, png_fixed_point red, png_fixed_point green ));
extern PNG_EXPORT(png_byte,png_get_rgb_to_gray_status) PNGARG((png_structp
 png_ptr));
#endif
extern PNG_EXPORT(void,png_build_grayscale_palette) PNGARG((int bit_depth,
 png_colorp palette));
#if defined(PNG_READ_STRIP_ALPHA_SUPPORTED)
extern PNG_EXPORT(void,png_set_strip_alpha) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED) || \
 defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
extern PNG_EXPORT(void,png_set_swap_alpha) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED) || \
 defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
extern PNG_EXPORT(void,png_set_invert_alpha) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
extern PNG_EXPORT(void,png_set_filler) PNGARG((png_structp png_ptr,
 png_uint_32 filler, int flags));
#define PNG_FILLER_BEFORE 0
#define PNG_FILLER_AFTER 1
#if !defined(PNG_1_0_X)
extern PNG_EXPORT(void,png_set_add_alpha) PNGARG((png_structp png_ptr,
 png_uint_32 filler, int flags));
#endif
#endif
#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
extern PNG_EXPORT(void,png_set_swap) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_PACK_SUPPORTED) || defined(PNG_WRITE_PACK_SUPPORTED)
extern PNG_EXPORT(void,png_set_packing) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_PACKSWAP_SUPPORTED) || defined(PNG_WRITE_PACKSWAP_SUPPORTED)
extern PNG_EXPORT(void,png_set_packswap) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
extern PNG_EXPORT(void,png_set_shift) PNGARG((png_structp png_ptr,
 png_color_8p true_bits));
#endif
#if defined(PNG_READ_INTERLACING_SUPPORTED) || \
 defined(PNG_WRITE_INTERLACING_SUPPORTED)
extern PNG_EXPORT(int,png_set_interlace_handling) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
extern PNG_EXPORT(void,png_set_invert_mono) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_background) PNGARG((png_structp png_ptr,
 png_color_16p background_color, int background_gamma_code,
 int need_expand, double background_gamma));
#endif
#define PNG_BACKGROUND_GAMMA_UNKNOWN 0
#define PNG_BACKGROUND_GAMMA_SCREEN  1
#define PNG_BACKGROUND_GAMMA_FILE    2
#define PNG_BACKGROUND_GAMMA_UNIQUE  3
#endif
#if defined(PNG_READ_16_TO_8_SUPPORTED)
extern PNG_EXPORT(void,png_set_strip_16) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_DITHER_SUPPORTED)
extern PNG_EXPORT(void,png_set_dither) PNGARG((png_structp png_ptr,
 png_colorp palette, int num_palette, int maximum_colors,
 png_uint_16p histogram, int full_dither));
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_gamma) PNGARG((png_structp png_ptr,
 double screen_gamma, double default_file_gamma));
#endif
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
#if defined(PNG_READ_EMPTY_PLTE_SUPPORTED) || \
 defined(PNG_WRITE_EMPTY_PLTE_SUPPORTED)
extern PNG_EXPORT(void,png_permit_empty_plte) PNGARG((png_structp png_ptr,
 int empty_plte_permitted));
#endif
#endif
#if defined(PNG_WRITE_FLUSH_SUPPORTED)
extern PNG_EXPORT(void,png_set_flush) PNGARG((png_structp png_ptr, int nrows));
extern PNG_EXPORT(void,png_write_flush) PNGARG((png_structp png_ptr));
#endif
extern PNG_EXPORT(void,png_start_read_image) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_read_update_info) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
extern PNG_EXPORT(void,png_read_rows) PNGARG((png_structp png_ptr,
 png_bytepp row, png_bytepp display_row, png_uint_32 num_rows));
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
extern PNG_EXPORT(void,png_read_row) PNGARG((png_structp png_ptr,
 png_bytep row,
 png_bytep display_row));
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
extern PNG_EXPORT(void,png_read_image) PNGARG((png_structp png_ptr,
 png_bytepp image));
#endif
extern PNG_EXPORT(void,png_write_row) PNGARG((png_structp png_ptr,
 png_bytep row));
extern PNG_EXPORT(void,png_write_rows) PNGARG((png_structp png_ptr,
 png_bytepp row, png_uint_32 num_rows));
extern PNG_EXPORT(void,png_write_image) PNGARG((png_structp png_ptr,
 png_bytepp image));
extern PNG_EXPORT(void,png_write_end) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
extern PNG_EXPORT(void,png_read_end) PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#endif
extern PNG_EXPORT(void,png_destroy_info_struct) PNGARG((png_structp png_ptr,
 png_infopp info_ptr_ptr));
extern PNG_EXPORT(void,png_destroy_read_struct) PNGARG((png_structpp
 png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr));
extern void png_read_destroy PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_infop end_info_ptr));
extern PNG_EXPORT(void,png_destroy_write_struct)
 PNGARG((png_structpp png_ptr_ptr, png_infopp info_ptr_ptr));
extern void png_write_destroy PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_set_crc_action) PNGARG((png_structp png_ptr,
 int crit_action, int ancil_action));
#define PNG_CRC_DEFAULT       0
#define PNG_CRC_ERROR_QUIT    1
#define PNG_CRC_WARN_DISCARD  2
#define PNG_CRC_WARN_USE      3
#define PNG_CRC_QUIET_USE     4
#define PNG_CRC_NO_CHANGE     5
extern PNG_EXPORT(void,png_set_filter) PNGARG((png_structp png_ptr, int method,
 int filters));
#define PNG_NO_FILTERS     0x00
#define PNG_FILTER_NONE    0x08
#define PNG_FILTER_SUB     0x10
#define PNG_FILTER_UP      0x20
#define PNG_FILTER_AVG     0x40
#define PNG_FILTER_PAETH   0x80
#define PNG_ALL_FILTERS (PNG_FILTER_NONE | PNG_FILTER_SUB | PNG_FILTER_UP | \
 PNG_FILTER_AVG | PNG_FILTER_PAETH)
#define PNG_FILTER_VALUE_NONE  0
#define PNG_FILTER_VALUE_SUB   1
#define PNG_FILTER_VALUE_UP    2
#define PNG_FILTER_VALUE_AVG   3
#define PNG_FILTER_VALUE_PAETH 4
#define PNG_FILTER_VALUE_LAST  5
#if defined(PNG_WRITE_WEIGHTED_FILTER_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_filter_heuristics) PNGARG((png_structp png_ptr,
 int heuristic_method, int num_weights, png_doublep filter_weights,
 png_doublep filter_costs));
#endif
#endif
#define PNG_FILTER_HEURISTIC_DEFAULT    0
#define PNG_FILTER_HEURISTIC_UNWEIGHTED 1
#define PNG_FILTER_HEURISTIC_WEIGHTED   2
#define PNG_FILTER_HEURISTIC_LAST       3
extern PNG_EXPORT(void,png_set_compression_level) PNGARG((png_structp png_ptr,
 int level));
extern PNG_EXPORT(void,png_set_compression_mem_level)
 PNGARG((png_structp png_ptr, int mem_level));
extern PNG_EXPORT(void,png_set_compression_strategy)
 PNGARG((png_structp png_ptr, int strategy));
extern PNG_EXPORT(void,png_set_compression_window_bits)
 PNGARG((png_structp png_ptr, int window_bits));
extern PNG_EXPORT(void,png_set_compression_method) PNGARG((png_structp png_ptr,
 int method));
#if !defined(PNG_NO_STDIO)
extern PNG_EXPORT(void,png_init_io) PNGARG((png_structp png_ptr, png_FILE_p fp));
#endif
extern PNG_EXPORT(void,png_set_error_fn) PNGARG((png_structp png_ptr,
 png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn));
extern PNG_EXPORT(png_voidp,png_get_error_ptr) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_set_write_fn) PNGARG((png_structp png_ptr,
 png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn));
extern PNG_EXPORT(void,png_set_read_fn) PNGARG((png_structp png_ptr,
 png_voidp io_ptr, png_rw_ptr read_data_fn));
extern PNG_EXPORT(png_voidp,png_get_io_ptr) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_set_read_status_fn) PNGARG((png_structp png_ptr,
 png_read_status_ptr read_row_fn));
extern PNG_EXPORT(void,png_set_write_status_fn) PNGARG((png_structp png_ptr,
 png_write_status_ptr write_row_fn));
#ifdef PNG_USER_MEM_SUPPORTED
extern PNG_EXPORT(void,png_set_mem_fn) PNGARG((png_structp png_ptr,
 png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn));
extern PNG_EXPORT(png_voidp,png_get_mem_ptr) PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_LEGACY_SUPPORTED)
extern PNG_EXPORT(void,png_set_read_user_transform_fn) PNGARG((png_structp
 png_ptr, png_user_transform_ptr read_user_transform_fn));
#endif
#if defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_LEGACY_SUPPORTED)
extern PNG_EXPORT(void,png_set_write_user_transform_fn) PNGARG((png_structp
 png_ptr, png_user_transform_ptr write_user_transform_fn));
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED) || \
 defined(PNG_LEGACY_SUPPORTED)
extern PNG_EXPORT(void,png_set_user_transform_info) PNGARG((png_structp
 png_ptr, png_voidp user_transform_ptr, int user_transform_depth,
 int user_transform_channels));
extern PNG_EXPORT(png_voidp,png_get_user_transform_ptr)
 PNGARG((png_structp png_ptr));
#endif
#ifdef PNG_USER_CHUNKS_SUPPORTED
extern PNG_EXPORT(void,png_set_read_user_chunk_fn) PNGARG((png_structp png_ptr,
 png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn));
extern PNG_EXPORT(png_voidp,png_get_user_chunk_ptr) PNGARG((png_structp
 png_ptr));
#endif
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
extern PNG_EXPORT(void,png_set_progressive_read_fn) PNGARG((png_structp png_ptr,
 png_voidp progressive_ptr,
 png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn,
 png_progressive_end_ptr end_fn));
extern PNG_EXPORT(png_voidp,png_get_progressive_ptr)
 PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_process_data) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_bytep buffer, png_size_t buffer_size));
extern PNG_EXPORT(void,png_progressive_combine_row) PNGARG((png_structp png_ptr,
 png_bytep old_row, png_bytep new_row));
#endif
extern PNG_EXPORT(png_voidp,png_malloc) PNGARG((png_structp png_ptr,
 png_uint_32 size));
#if defined(PNG_1_0_X)
#  define png_malloc_warn png_malloc
#else
extern PNG_EXPORT(png_voidp,png_malloc_warn) PNGARG((png_structp png_ptr,
 png_uint_32 size));
#endif
extern PNG_EXPORT(void,png_free) PNGARG((png_structp png_ptr, png_voidp ptr));
#if defined(PNG_1_0_X)
extern PNG_EXPORT(voidpf,png_zalloc) PNGARG((voidpf png_ptr, uInt items,
 uInt size));
extern PNG_EXPORT(void,png_zfree) PNGARG((voidpf png_ptr, voidpf ptr));
#endif
extern PNG_EXPORT(void,png_free_data) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 free_me, int num));
#ifdef PNG_FREE_ME_SUPPORTED
extern PNG_EXPORT(void,png_data_freer) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int freer, png_uint_32 mask));
#endif
#define PNG_DESTROY_WILL_FREE_DATA 1
#define PNG_SET_WILL_FREE_DATA 1
#define PNG_USER_WILL_FREE_DATA 2
#define PNG_FREE_HIST 0x0008
#define PNG_FREE_ICCP 0x0010
#define PNG_FREE_SPLT 0x0020
#define PNG_FREE_ROWS 0x0040
#define PNG_FREE_PCAL 0x0080
#define PNG_FREE_SCAL 0x0100
#define PNG_FREE_UNKN 0x0200
#define PNG_FREE_LIST 0x0400
#define PNG_FREE_PLTE 0x1000
#define PNG_FREE_TRNS 0x2000
#define PNG_FREE_TEXT 0x4000
#define PNG_FREE_ALL  0x7fff
#define PNG_FREE_MUL  0x4220
#ifdef PNG_USER_MEM_SUPPORTED
extern PNG_EXPORT(png_voidp,png_malloc_default) PNGARG((png_structp png_ptr,
 png_uint_32 size));
extern PNG_EXPORT(void,png_free_default) PNGARG((png_structp png_ptr,
 png_voidp ptr));
#endif
extern PNG_EXPORT(png_voidp,png_memcpy_check) PNGARG((png_structp png_ptr,
 png_voidp s1, png_voidp s2, png_uint_32 size));
extern PNG_EXPORT(png_voidp,png_memset_check) PNGARG((png_structp png_ptr,
 png_voidp s1, int value, png_uint_32 size));
#if defined(USE_FAR_KEYWORD)
extern void *png_far_to_near PNGARG((png_structp png_ptr,png_voidp ptr,
 int check));
#endif
#ifndef PNG_NO_ERROR_TEXT
extern PNG_EXPORT(void,png_error) PNGARG((png_structp png_ptr,
 png_const_charp error_message));
extern PNG_EXPORT(void,png_chunk_error) PNGARG((png_structp png_ptr,
 png_const_charp error_message));
#else
extern PNG_EXPORT(void,png_err) PNGARG((png_structp png_ptr));
#endif
#ifndef PNG_NO_WARNINGS
extern PNG_EXPORT(void,png_warning) PNGARG((png_structp png_ptr,
 png_const_charp warning_message));
#ifdef PNG_READ_SUPPORTED
extern PNG_EXPORT(void,png_chunk_warning) PNGARG((png_structp png_ptr,
 png_const_charp warning_message));
#endif
#endif
extern PNG_EXPORT(png_uint_32,png_get_valid) PNGARG((png_structp png_ptr,
png_infop info_ptr, png_uint_32 flag));
extern PNG_EXPORT(png_uint_32,png_get_rowbytes) PNGARG((png_structp png_ptr,
png_infop info_ptr));
#if defined(PNG_INFO_IMAGE_SUPPORTED)
extern PNG_EXPORT(png_bytepp,png_get_rows) PNGARG((png_structp png_ptr,
png_infop info_ptr));
extern PNG_EXPORT(void,png_set_rows) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_bytepp row_pointers));
#endif
extern PNG_EXPORT(png_byte,png_get_channels) PNGARG((png_structp png_ptr,
png_infop info_ptr));
#ifdef PNG_EASY_ACCESS_SUPPORTED
extern PNG_EXPORT(png_uint_32, png_get_image_width) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_uint_32, png_get_image_height) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_byte, png_get_bit_depth) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_byte, png_get_color_type) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_byte, png_get_filter_type) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_byte, png_get_interlace_type) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_byte, png_get_compression_type) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_uint_32, png_get_pixels_per_meter) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_uint_32, png_get_x_pixels_per_meter) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_uint_32, png_get_y_pixels_per_meter) PNGARG((png_structp
png_ptr, png_infop info_ptr));
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(float, png_get_pixel_aspect_ratio) PNGARG((png_structp
png_ptr, png_infop info_ptr));
#endif
extern PNG_EXPORT(png_int_32, png_get_x_offset_pixels) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_int_32, png_get_y_offset_pixels) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_int_32, png_get_x_offset_microns) PNGARG((png_structp
png_ptr, png_infop info_ptr));
extern PNG_EXPORT(png_int_32, png_get_y_offset_microns) PNGARG((png_structp
png_ptr, png_infop info_ptr));
#endif
extern PNG_EXPORT(png_bytep,png_get_signature) PNGARG((png_structp png_ptr,
png_infop info_ptr));
#if defined(PNG_bKGD_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_bKGD) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_color_16p *background));
#endif
#if defined(PNG_bKGD_SUPPORTED)
extern PNG_EXPORT(void,png_set_bKGD) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_color_16p background));
#endif
#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_cHRM) PNGARG((png_structp png_ptr,
 png_infop info_ptr, double *white_x, double *white_y, double *red_x,
 double *red_y, double *green_x, double *green_y, double *blue_x,
 double *blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_cHRM_fixed) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point
 *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y,
 png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point
 *int_blue_x, png_fixed_point *int_blue_y));
#endif
#endif
#if defined(PNG_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_cHRM) PNGARG((png_structp png_ptr,
 png_infop info_ptr, double white_x, double white_y, double red_x,
 double red_y, double green_x, double green_y, double blue_x, double blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_cHRM_fixed) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y,
 png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point
 int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x,
 png_fixed_point int_blue_y));
#endif
#endif
#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_gAMA) PNGARG((png_structp png_ptr,
 png_infop info_ptr, double *file_gamma));
#endif
extern PNG_EXPORT(png_uint_32,png_get_gAMA_fixed) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_fixed_point *int_file_gamma));
#endif
#if defined(PNG_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_gAMA) PNGARG((png_structp png_ptr,
 png_infop info_ptr, double file_gamma));
#endif
extern PNG_EXPORT(void,png_set_gAMA_fixed) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_fixed_point int_file_gamma));
#endif
#if defined(PNG_hIST_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_hIST) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_16p *hist));
#endif
#if defined(PNG_hIST_SUPPORTED)
extern PNG_EXPORT(void,png_set_hIST) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_16p hist));
#endif
extern PNG_EXPORT(png_uint_32,png_get_IHDR) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 *width, png_uint_32 *height,
 int *bit_depth, int *color_type, int *interlace_method,
 int *compression_method, int *filter_method));
extern PNG_EXPORT(void,png_set_IHDR) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth,
 int color_type, int interlace_method, int compression_method,
 int filter_method));
#if defined(PNG_oFFs_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_oFFs) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y,
 int *unit_type));
#endif
#if defined(PNG_oFFs_SUPPORTED)
extern PNG_EXPORT(void,png_set_oFFs) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_int_32 offset_x, png_int_32 offset_y,
 int unit_type));
#endif
#if defined(PNG_pCAL_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_pCAL) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1,
 int *type, int *nparams, png_charp *units, png_charpp *params));
#endif
#if defined(PNG_pCAL_SUPPORTED)
extern PNG_EXPORT(void,png_set_pCAL) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1,
 int type, int nparams, png_charp units, png_charpp params));
#endif
#if defined(PNG_pHYs_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_pHYs) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type));
#endif
#if defined(PNG_pHYs_SUPPORTED)
extern PNG_EXPORT(void,png_set_pHYs) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type));
#endif
extern PNG_EXPORT(png_uint_32,png_get_PLTE) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_colorp *palette, int *num_palette));
extern PNG_EXPORT(void,png_set_PLTE) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_colorp palette, int num_palette));
#if defined(PNG_sBIT_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_sBIT) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_color_8p *sig_bit));
#endif
#if defined(PNG_sBIT_SUPPORTED)
extern PNG_EXPORT(void,png_set_sBIT) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_color_8p sig_bit));
#endif
#if defined(PNG_sRGB_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_sRGB) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int *intent));
#endif
#if defined(PNG_sRGB_SUPPORTED)
extern PNG_EXPORT(void,png_set_sRGB) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int intent));
extern PNG_EXPORT(void,png_set_sRGB_gAMA_and_cHRM) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int intent));
#endif
#if defined(PNG_iCCP_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_iCCP) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_charpp name, int *compression_type,
 png_charpp profile, png_uint_32 *proflen));
#endif
#if defined(PNG_iCCP_SUPPORTED)
extern PNG_EXPORT(void,png_set_iCCP) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_charp name, int compression_type,
 png_charp profile, png_uint_32 proflen));
#endif
#if defined(PNG_sPLT_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_sPLT) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_sPLT_tpp entries));
#endif
#if defined(PNG_sPLT_SUPPORTED)
extern PNG_EXPORT(void,png_set_sPLT) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_sPLT_tp entries, int nentries));
#endif
#if defined(PNG_TEXT_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_text) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_textp *text_ptr, int *num_text));
#endif
#if defined(PNG_TEXT_SUPPORTED)
extern PNG_EXPORT(void,png_set_text) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_textp text_ptr, int num_text));
#endif
#if defined(PNG_tIME_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_tIME) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_timep *mod_time));
#endif
#if defined(PNG_tIME_SUPPORTED)
extern PNG_EXPORT(void,png_set_tIME) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_timep mod_time));
#endif
#if defined(PNG_tRNS_SUPPORTED)
extern PNG_EXPORT(png_uint_32,png_get_tRNS) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_bytep *trans, int *num_trans,
 png_color_16p *trans_values));
#endif
#if defined(PNG_tRNS_SUPPORTED)
extern PNG_EXPORT(void,png_set_tRNS) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_bytep trans, int num_trans,
 png_color_16p trans_values));
#endif
#if defined(PNG_tRNS_SUPPORTED)
#endif
#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_sCAL) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int *unit, double *width, double *height));
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_get_sCAL_s) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int *unit, png_charpp swidth, png_charpp sheight));
#endif
#endif
#endif
#if defined(PNG_sCAL_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_sCAL) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int unit, double width, double height));
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
extern PNG_EXPORT(void,png_set_sCAL_s) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int unit, png_charp swidth, png_charp sheight));
#endif
#endif
#endif
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED)
extern PNG_EXPORT(void, png_set_keep_unknown_chunks) PNGARG((png_structp
 png_ptr, int keep, png_bytep chunk_list, int num_chunks));
extern PNG_EXPORT(void, png_set_unknown_chunks) PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_unknown_chunkp unknowns, int num_unknowns));
extern PNG_EXPORT(void, png_set_unknown_chunk_location)
 PNGARG((png_structp png_ptr, png_infop info_ptr, int chunk, int location));
extern PNG_EXPORT(png_uint_32,png_get_unknown_chunks) PNGARG((png_structp
 png_ptr, png_infop info_ptr, png_unknown_chunkpp entries));
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
PNG_EXPORT(int,png_handle_as_unknown) PNGARG((png_structp png_ptr, png_bytep
 chunk_name));
#endif
extern PNG_EXPORT(void, png_set_invalid) PNGARG((png_structp png_ptr,
 png_infop info_ptr, int mask));
#if defined(PNG_INFO_IMAGE_SUPPORTED)
extern PNG_EXPORT(void, png_read_png) PNGARG((png_structp png_ptr,
 png_infop info_ptr,
 int transforms,
 png_voidp params));
extern PNG_EXPORT(void, png_write_png) PNGARG((png_structp png_ptr,
 png_infop info_ptr,
 int transforms,
 png_voidp params));
#endif
#ifdef PNG_DEBUG
#if (PNG_DEBUG > 0)
#if !defined(PNG_DEBUG_FILE) && defined(_MSC_VER)
#include <crtdbg.h>
#if (PNG_DEBUG > 1)
#define png_debug(l,m)  _RPT0(_CRT_WARN,m)
#define png_debug1(l,m,p1)  _RPT1(_CRT_WARN,m,p1)
#define png_debug2(l,m,p1,p2) _RPT2(_CRT_WARN,m,p1,p2)
#endif
#else
#ifndef PNG_DEBUG_FILE
#define PNG_DEBUG_FILE stderr
#endif
#if (PNG_DEBUG > 1)
#define png_debug(l,m) \
{ \
 int num_tabs=l; \
 fprintf(PNG_DEBUG_FILE,"%s"m,(num_tabs==1 ? "\t" : \
 (num_tabs==2 ? "\t\t":(num_tabs>2 ? "\t\t\t":"")))); \
}
#define png_debug1(l,m,p1) \
{ \
 int num_tabs=l; \
 fprintf(PNG_DEBUG_FILE,"%s"m,(num_tabs==1 ? "\t" : \
 (num_tabs==2 ? "\t\t":(num_tabs>2 ? "\t\t\t":""))),p1); \
}
#define png_debug2(l,m,p1,p2) \
{ \
 int num_tabs=l; \
 fprintf(PNG_DEBUG_FILE,"%s"m,(num_tabs==1 ? "\t" : \
 (num_tabs==2 ? "\t\t":(num_tabs>2 ? "\t\t\t":""))),p1,p2); \
}
#endif
#endif
#endif
#endif
#ifndef png_debug
#define png_debug(l, m)
#endif
#ifndef png_debug1
#define png_debug1(l, m, p1)
#endif
#ifndef png_debug2
#define png_debug2(l, m, p1, p2)
#endif
extern PNG_EXPORT(png_charp,png_get_copyright) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_charp,png_get_header_ver) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_charp,png_get_header_version) PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_charp,png_get_libpng_ver) PNGARG((png_structp png_ptr));
#ifdef PNG_MNG_FEATURES_SUPPORTED
extern PNG_EXPORT(png_uint_32,png_permit_mng_features) PNGARG((png_structp
 png_ptr, png_uint_32 mng_features_permitted));
#endif
#define PNG_HANDLE_CHUNK_AS_DEFAULT   0
#define PNG_HANDLE_CHUNK_NEVER        1
#define PNG_HANDLE_CHUNK_IF_SAFE      2
#define PNG_HANDLE_CHUNK_ALWAYS       3
#if defined(PNG_ASSEMBLER_CODE_SUPPORTED)
#if defined(PNG_MMX_CODE_SUPPORTED)
#define PNG_ASM_FLAG_MMX_SUPPORT_COMPILED  0x01
#define PNG_ASM_FLAG_MMX_SUPPORT_IN_CPU    0x02
#define PNG_ASM_FLAG_MMX_READ_COMBINE_ROW  0x04
#define PNG_ASM_FLAG_MMX_READ_INTERLACE    0x08
#define PNG_ASM_FLAG_MMX_READ_FILTER_SUB   0x10
#define PNG_ASM_FLAG_MMX_READ_FILTER_UP    0x20
#define PNG_ASM_FLAG_MMX_READ_FILTER_AVG   0x40
#define PNG_ASM_FLAG_MMX_READ_FILTER_PAETH 0x80
#define PNG_ASM_FLAGS_INITIALIZED          0x80000000
#define PNG_MMX_READ_FLAGS ( PNG_ASM_FLAG_MMX_READ_COMBINE_ROW  \
 | PNG_ASM_FLAG_MMX_READ_INTERLACE    \
 | PNG_ASM_FLAG_MMX_READ_FILTER_SUB   \
 | PNG_ASM_FLAG_MMX_READ_FILTER_UP    \
 | PNG_ASM_FLAG_MMX_READ_FILTER_AVG   \
 | PNG_ASM_FLAG_MMX_READ_FILTER_PAETH )
#define PNG_MMX_WRITE_FLAGS ( 0 )
#define PNG_MMX_FLAGS ( PNG_ASM_FLAG_MMX_SUPPORT_COMPILED \
 | PNG_ASM_FLAG_MMX_SUPPORT_IN_CPU   \
 | PNG_MMX_READ_FLAGS                \
 | PNG_MMX_WRITE_FLAGS )
#define PNG_SELECT_READ   1
#define PNG_SELECT_WRITE  2
#endif
#if !defined(PNG_1_0_X)
extern PNG_EXPORT(png_uint_32,png_get_mmx_flagmask)
 PNGARG((int flag_select, int *compilerID));
extern PNG_EXPORT(png_uint_32,png_get_asm_flagmask)
 PNGARG((int flag_select));
extern PNG_EXPORT(png_uint_32,png_get_asm_flags)
 PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_byte,png_get_mmx_bitdepth_threshold)
 PNGARG((png_structp png_ptr));
extern PNG_EXPORT(png_uint_32,png_get_mmx_rowbytes_threshold)
 PNGARG((png_structp png_ptr));
extern PNG_EXPORT(void,png_set_asm_flags)
 PNGARG((png_structp png_ptr, png_uint_32 asm_flags));
extern PNG_EXPORT(void,png_set_mmx_thresholds)
 PNGARG((png_structp png_ptr, png_byte mmx_bitdepth_threshold,
 png_uint_32 mmx_rowbytes_threshold));
#endif
#if !defined(PNG_1_0_X)
extern PNG_EXPORT(int,png_mmx_support) PNGARG((void));
#endif
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
extern PNG_EXPORT(void,png_set_strip_error_numbers) PNGARG((png_structp
 png_ptr, png_uint_32 strip_mode));
#endif
#endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
extern PNG_EXPORT(void,png_set_user_limits) PNGARG((png_structp
 png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max));
extern PNG_EXPORT(png_uint_32,png_get_user_width_max) PNGARG((png_structp
 png_ptr));
extern PNG_EXPORT(png_uint_32,png_get_user_height_max) PNGARG((png_structp
 png_ptr));
#endif
#ifdef PNG_READ_COMPOSITE_NODIV_SUPPORTED
#  define png_composite(composite, fg, alpha, bg)                            \
 { png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) * (png_uint_16)(alpha) \
 +        (png_uint_16)(bg)*(png_uint_16)(255 -       \
 (png_uint_16)(alpha)) + (png_uint_16)128);           \
 (composite) = (png_byte)((temp + (temp >> 8)) >> 8); }
#  define png_composite_16(composite, fg, alpha, bg)                         \
 { png_uint_32 temp = (png_uint_32)((png_uint_32)(fg) * (png_uint_32)(alpha) \
 + (png_uint_32)(bg)*(png_uint_32)(65535L -           \
 (png_uint_32)(alpha)) + (png_uint_32)32768L);        \
 (composite) = (png_uint_16)((temp + (temp >> 16)) >> 16); }
#else
#  define png_composite(composite, fg, alpha, bg)                            \
 (composite) = (png_byte)(((png_uint_16)(fg) * (png_uint_16)(alpha) +    \
 (png_uint_16)(bg) * (png_uint_16)(255 - (png_uint_16)(alpha)) +       \
 (png_uint_16)127) / 255)
#  define png_composite_16(composite, fg, alpha, bg)                         \
 (composite) = (png_uint_16)(((png_uint_32)(fg) * (png_uint_32)(alpha) + \
 (png_uint_32)(bg)*(png_uint_32)(65535L - (png_uint_32)(alpha)) +      \
 (png_uint_32)32767) / (png_uint_32)65535L)
#endif
#if defined(PNG_READ_BIG_ENDIAN_SUPPORTED)
#  define png_get_uint_32(buf) ( *((png_uint_32p) (buf)))
#  define png_get_uint_16(buf) ( *((png_uint_16p) (buf)))
#  define png_get_int_32(buf)  ( *((png_int_32p)  (buf)))
#else
extern PNG_EXPORT(png_uint_32,png_get_uint_32) PNGARG((png_bytep buf));
extern PNG_EXPORT(png_uint_16,png_get_uint_16) PNGARG((png_bytep buf));
extern PNG_EXPORT(png_int_32,png_get_int_32) PNGARG((png_bytep buf));
#endif
extern PNG_EXPORT(png_uint_32,png_get_uint_31)
 PNGARG((png_structp png_ptr, png_bytep buf));
extern PNG_EXPORT(void,png_save_uint_32)
 PNGARG((png_bytep buf, png_uint_32 i));
extern PNG_EXPORT(void,png_save_int_32)
 PNGARG((png_bytep buf, png_int_32 i));
extern PNG_EXPORT(void,png_save_uint_16)
 PNGARG((png_bytep buf, unsigned int i));
#define PNG_HAVE_IHDR               0x01
#define PNG_HAVE_PLTE               0x02
#define PNG_HAVE_IDAT               0x04
#define PNG_AFTER_IDAT              0x08
#define PNG_HAVE_IEND               0x10
#if defined(PNG_INTERNAL)
#define PNG_HAVE_gAMA               0x20
#define PNG_HAVE_cHRM               0x40
#define PNG_HAVE_sRGB               0x80
#define PNG_HAVE_CHUNK_HEADER      0x100
#define PNG_WROTE_tIME             0x200
#define PNG_WROTE_INFO_BEFORE_PLTE 0x400
#define PNG_BACKGROUND_IS_GRAY     0x800
#define PNG_HAVE_PNG_SIGNATURE    0x1000
#define PNG_HAVE_CHUNK_AFTER_IDAT 0x2000
#define PNG_BGR                0x0001
#define PNG_INTERLACE          0x0002
#define PNG_PACK               0x0004
#define PNG_SHIFT              0x0008
#define PNG_SWAP_BYTES         0x0010
#define PNG_INVERT_MONO        0x0020
#define PNG_DITHER             0x0040
#define PNG_BACKGROUND         0x0080
#define PNG_BACKGROUND_EXPAND  0x0100
#define PNG_16_TO_8            0x0400
#define PNG_RGBA               0x0800
#define PNG_EXPAND             0x1000
#define PNG_GAMMA              0x2000
#define PNG_GRAY_TO_RGB        0x4000
#define PNG_FILLER             0x8000L
#define PNG_PACKSWAP          0x10000L
#define PNG_SWAP_ALPHA        0x20000L
#define PNG_STRIP_ALPHA       0x40000L
#define PNG_INVERT_ALPHA      0x80000L
#define PNG_USER_TRANSFORM   0x100000L
#define PNG_RGB_TO_GRAY_ERR  0x200000L
#define PNG_RGB_TO_GRAY_WARN 0x400000L
#define PNG_RGB_TO_GRAY      0x600000L
#define PNG_ADD_ALPHA       0x1000000L
#define PNG_EXPAND_tRNS     0x2000000L
#define PNG_STRUCT_PNG   0x0001
#define PNG_STRUCT_INFO  0x0002
#define PNG_WEIGHT_SHIFT 8
#define PNG_WEIGHT_FACTOR (1<<(PNG_WEIGHT_SHIFT))
#define PNG_COST_SHIFT 3
#define PNG_COST_FACTOR (1<<(PNG_COST_SHIFT))
#define PNG_FLAG_ZLIB_CUSTOM_STRATEGY     0x0001
#define PNG_FLAG_ZLIB_CUSTOM_LEVEL        0x0002
#define PNG_FLAG_ZLIB_CUSTOM_MEM_LEVEL    0x0004
#define PNG_FLAG_ZLIB_CUSTOM_WINDOW_BITS  0x0008
#define PNG_FLAG_ZLIB_CUSTOM_METHOD       0x0010
#define PNG_FLAG_ZLIB_FINISHED            0x0020
#define PNG_FLAG_ROW_INIT                 0x0040
#define PNG_FLAG_FILLER_AFTER             0x0080
#define PNG_FLAG_CRC_ANCILLARY_USE        0x0100
#define PNG_FLAG_CRC_ANCILLARY_NOWARN     0x0200
#define PNG_FLAG_CRC_CRITICAL_USE         0x0400
#define PNG_FLAG_CRC_CRITICAL_IGNORE      0x0800
#define PNG_FLAG_FREE_PLTE                0x1000
#define PNG_FLAG_FREE_TRNS                0x2000
#define PNG_FLAG_FREE_HIST                0x4000
#define PNG_FLAG_KEEP_UNKNOWN_CHUNKS      0x8000L
#define PNG_FLAG_KEEP_UNSAFE_CHUNKS       0x10000L
#define PNG_FLAG_LIBRARY_MISMATCH         0x20000L
#define PNG_FLAG_STRIP_ERROR_NUMBERS      0x40000L
#define PNG_FLAG_STRIP_ERROR_TEXT         0x80000L
#define PNG_FLAG_MALLOC_NULL_MEM_OK       0x100000L
#define PNG_FLAG_ADD_ALPHA                0x200000L
#define PNG_FLAG_STRIP_ALPHA              0x400000L
#define PNG_FLAG_CRC_ANCILLARY_MASK (PNG_FLAG_CRC_ANCILLARY_USE | \
 PNG_FLAG_CRC_ANCILLARY_NOWARN)
#define PNG_FLAG_CRC_CRITICAL_MASK  (PNG_FLAG_CRC_CRITICAL_USE | \
 PNG_FLAG_CRC_CRITICAL_IGNORE)
#define PNG_FLAG_CRC_MASK           (PNG_FLAG_CRC_ANCILLARY_MASK | \
 PNG_FLAG_CRC_CRITICAL_MASK)
#define PNG_COLOR_DIST(c1, c2) (abs((int)((c1).red) - (int)((c2).red)) + \
 abs((int)((c1).green) - (int)((c2).green)) + \
 abs((int)((c1).blue) - (int)((c2).blue)))
#define PNG_ROWBYTES(pixel_bits, width) \
 ((pixel_bits) >= 8 ? \
 ((width) * (((png_uint_32)(pixel_bits)) >> 3)) : \
 (( ((width) * ((png_uint_32)(pixel_bits))) + 7) >> 3) )
#define PNG_OUT_OF_RANGE(value, ideal, delta) \
 ( (value) < (ideal)-(delta) || (value) > (ideal)+(delta) )
#if !defined(PNG_NO_EXTERN) || defined(PNG_ALWAYS_EXTERN)
#ifdef PNG_USE_GLOBAL_ARRAYS
 PNG_EXPORT_VAR (PNG_CONST png_byte FARDATA) png_sig[8];
#else
#endif
#endif
#define PNG_IHDR png_byte png_IHDR[5] = { 73,  72,  68,  82, '\0'}
#define PNG_IDAT png_byte png_IDAT[5] = { 73,  68,  65,  84, '\0'}
#define PNG_IEND png_byte png_IEND[5] = { 73,  69,  78,  68, '\0'}
#define PNG_PLTE png_byte png_PLTE[5] = { 80,  76,  84,  69, '\0'}
#define PNG_bKGD png_byte png_bKGD[5] = { 98,  75,  71,  68, '\0'}
#define PNG_cHRM png_byte png_cHRM[5] = { 99,  72,  82,  77, '\0'}
#define PNG_gAMA png_byte png_gAMA[5] = {103,  65,  77,  65, '\0'}
#define PNG_hIST png_byte png_hIST[5] = {104,  73,  83,  84, '\0'}
#define PNG_iCCP png_byte png_iCCP[5] = {105,  67,  67,  80, '\0'}
#define PNG_iTXt png_byte png_iTXt[5] = {105,  84,  88, 116, '\0'}
#define PNG_oFFs png_byte png_oFFs[5] = {111,  70,  70, 115, '\0'}
#define PNG_pCAL png_byte png_pCAL[5] = {112,  67,  65,  76, '\0'}
#define PNG_sCAL png_byte png_sCAL[5] = {115,  67,  65,  76, '\0'}
#define PNG_pHYs png_byte png_pHYs[5] = {112,  72,  89, 115, '\0'}
#define PNG_sBIT png_byte png_sBIT[5] = {115,  66,  73,  84, '\0'}
#define PNG_sPLT png_byte png_sPLT[5] = {115,  80,  76,  84, '\0'}
#define PNG_sRGB png_byte png_sRGB[5] = {115,  82,  71,  66, '\0'}
#define PNG_tEXt png_byte png_tEXt[5] = {116,  69,  88, 116, '\0'}
#define PNG_tIME png_byte png_tIME[5] = {116,  73,  77,  69, '\0'}
#define PNG_tRNS png_byte png_tRNS[5] = {116,  82,  78,  83, '\0'}
#define PNG_zTXt png_byte png_zTXt[5] = {122,  84,  88, 116, '\0'}
#ifdef PNG_USE_GLOBAL_ARRAYS
PNG_EXPORT_VAR (png_byte FARDATA) png_IHDR[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_IDAT[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_IEND[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_PLTE[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_bKGD[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_cHRM[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_gAMA[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_hIST[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_iCCP[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_iTXt[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_oFFs[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_pCAL[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_sCAL[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_pHYs[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_sBIT[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_sPLT[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_sRGB[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_tEXt[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_tIME[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_tRNS[5];
PNG_EXPORT_VAR (png_byte FARDATA) png_zTXt[5];
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
extern PNG_EXPORT(void,png_read_init) PNGARG((png_structp png_ptr));
#undef png_read_init
#define png_read_init(png_ptr) png_read_init_3(&png_ptr, \
 PNG_LIBPNG_VER_STRING,  png_sizeof(png_struct));
#endif
extern PNG_EXPORT(void,png_read_init_3) PNGARG((png_structpp ptr_ptr,
 png_const_charp user_png_ver, png_size_t png_struct_size));
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
extern PNG_EXPORT(void,png_read_init_2) PNGARG((png_structp png_ptr,
 png_const_charp user_png_ver, png_size_t png_struct_size, png_size_t
 png_info_size));
#endif
#if defined(PNG_1_0_X) || defined (PNG_1_2_X)
extern PNG_EXPORT(void,png_write_init) PNGARG((png_structp png_ptr));
#undef png_write_init
#define png_write_init(png_ptr) png_write_init_3(&png_ptr, \
 PNG_LIBPNG_VER_STRING, png_sizeof(png_struct));
#endif
extern PNG_EXPORT(void,png_write_init_3) PNGARG((png_structpp ptr_ptr,
 png_const_charp user_png_ver, png_size_t png_struct_size));
extern PNG_EXPORT(void,png_write_init_2) PNGARG((png_structp png_ptr,
 png_const_charp user_png_ver, png_size_t png_struct_size, png_size_t
 png_info_size));
PNG_EXTERN png_voidp png_create_struct PNGARG((int type));
PNG_EXTERN void png_destroy_struct PNGARG((png_voidp struct_ptr));
PNG_EXTERN png_voidp png_create_struct_2 PNGARG((int type, png_malloc_ptr
 malloc_fn, png_voidp mem_ptr));
PNG_EXTERN void png_destroy_struct_2 PNGARG((png_voidp struct_ptr,
 png_free_ptr free_fn, png_voidp mem_ptr));
PNG_EXTERN void png_info_destroy PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#ifndef PNG_1_0_X
PNG_EXTERN voidpf png_zalloc PNGARG((voidpf png_ptr, uInt items, uInt size));
PNG_EXTERN void png_zfree PNGARG((voidpf png_ptr, voidpf ptr));
#ifdef PNG_SIZE_T
 PNG_EXTERN png_size_t PNGAPI png_convert_size PNGARG((size_t size));
#endif
PNG_EXTERN void PNGAPI png_default_read_data PNGARG((png_structp png_ptr,
 png_bytep data, png_size_t length));
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
PNG_EXTERN void PNGAPI png_push_fill_buffer PNGARG((png_structp png_ptr,
 png_bytep buffer, png_size_t length));
#endif
PNG_EXTERN void PNGAPI png_default_write_data PNGARG((png_structp png_ptr,
 png_bytep data, png_size_t length));
#if defined(PNG_WRITE_FLUSH_SUPPORTED)
#if !defined(PNG_NO_STDIO)
PNG_EXTERN void PNGAPI png_default_flush PNGARG((png_structp png_ptr));
#endif
#endif
#else
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
PNG_EXTERN void png_push_fill_buffer PNGARG((png_structp png_ptr,
 png_bytep buffer, png_size_t length));
#endif
#endif
PNG_EXTERN void png_reset_crc PNGARG((png_structp png_ptr));
PNG_EXTERN void png_write_data PNGARG((png_structp png_ptr, png_bytep data,
 png_size_t length));
PNG_EXTERN void png_read_data PNGARG((png_structp png_ptr, png_bytep data,
 png_size_t length));
PNG_EXTERN void png_crc_read PNGARG((png_structp png_ptr, png_bytep buf,
 png_size_t length));
#if defined(PNG_zTXt_SUPPORTED) || defined(PNG_iTXt_SUPPORTED) || \
 defined(PNG_iCCP_SUPPORTED) || defined(PNG_sPLT_SUPPORTED)
PNG_EXTERN void png_decompress_chunk PNGARG((png_structp png_ptr,
 int comp_type, png_size_t chunklength,
 png_size_t prefix_length, png_size_t *data_length));
#endif
PNG_EXTERN int png_crc_finish PNGARG((png_structp png_ptr, png_uint_32 skip));
PNG_EXTERN int png_crc_error PNGARG((png_structp png_ptr));
PNG_EXTERN void png_calculate_crc PNGARG((png_structp png_ptr, png_bytep ptr,
 png_size_t length));
#if defined(PNG_WRITE_FLUSH_SUPPORTED)
PNG_EXTERN void png_flush PNGARG((png_structp png_ptr));
#endif
PNG_EXTERN void png_write_sig PNGARG((png_structp png_ptr));
PNG_EXTERN void png_write_IHDR PNGARG((png_structp png_ptr, png_uint_32 width,
 png_uint_32 height,
 int bit_depth, int color_type, int compression_method, int filter_method,
 int interlace_method));
PNG_EXTERN void png_write_PLTE PNGARG((png_structp png_ptr, png_colorp palette,
 png_uint_32 num_pal));
PNG_EXTERN void png_write_IDAT PNGARG((png_structp png_ptr, png_bytep data,
 png_size_t length));
PNG_EXTERN void png_write_IEND PNGARG((png_structp png_ptr));
#if defined(PNG_WRITE_gAMA_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
PNG_EXTERN void png_write_gAMA PNGARG((png_structp png_ptr, double file_gamma));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
PNG_EXTERN void png_write_gAMA_fixed PNGARG((png_structp png_ptr, png_fixed_point
 file_gamma));
#endif
#endif
#if defined(PNG_WRITE_sBIT_SUPPORTED)
PNG_EXTERN void png_write_sBIT PNGARG((png_structp png_ptr, png_color_8p sbit,
 int color_type));
#endif
#if defined(PNG_WRITE_cHRM_SUPPORTED)
#ifdef PNG_FLOATING_POINT_SUPPORTED
PNG_EXTERN void png_write_cHRM PNGARG((png_structp png_ptr,
 double white_x, double white_y,
 double red_x, double red_y, double green_x, double green_y,
 double blue_x, double blue_y));
#endif
#ifdef PNG_FIXED_POINT_SUPPORTED
PNG_EXTERN void png_write_cHRM_fixed PNGARG((png_structp png_ptr,
 png_fixed_point int_white_x, png_fixed_point int_white_y,
 png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point
 int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x,
 png_fixed_point int_blue_y));
#endif
#endif
#if defined(PNG_WRITE_sRGB_SUPPORTED)
PNG_EXTERN void png_write_sRGB PNGARG((png_structp png_ptr,
 int intent));
#endif
#if defined(PNG_WRITE_iCCP_SUPPORTED)
PNG_EXTERN void png_write_iCCP PNGARG((png_structp png_ptr,
 png_charp name, int compression_type,
 png_charp profile, int proflen));
#endif
#if defined(PNG_WRITE_sPLT_SUPPORTED)
PNG_EXTERN void png_write_sPLT PNGARG((png_structp png_ptr,
 png_sPLT_tp palette));
#endif
#if defined(PNG_WRITE_tRNS_SUPPORTED)
PNG_EXTERN void png_write_tRNS PNGARG((png_structp png_ptr, png_bytep trans,
 png_color_16p values, int number, int color_type));
#endif
#if defined(PNG_WRITE_bKGD_SUPPORTED)
PNG_EXTERN void png_write_bKGD PNGARG((png_structp png_ptr,
 png_color_16p values, int color_type));
#endif
#if defined(PNG_WRITE_hIST_SUPPORTED)
PNG_EXTERN void png_write_hIST PNGARG((png_structp png_ptr, png_uint_16p hist,
 int num_hist));
#endif
#if defined(PNG_WRITE_TEXT_SUPPORTED) || defined(PNG_WRITE_pCAL_SUPPORTED) || \
 defined(PNG_WRITE_iCCP_SUPPORTED) || defined(PNG_WRITE_sPLT_SUPPORTED)
PNG_EXTERN png_size_t png_check_keyword PNGARG((png_structp png_ptr,
 png_charp key, png_charpp new_key));
#endif
#if defined(PNG_WRITE_tEXt_SUPPORTED)
PNG_EXTERN void png_write_tEXt PNGARG((png_structp png_ptr, png_charp key,
 png_charp text, png_size_t text_len));
#endif
#if defined(PNG_WRITE_zTXt_SUPPORTED)
PNG_EXTERN void png_write_zTXt PNGARG((png_structp png_ptr, png_charp key,
 png_charp text, png_size_t text_len, int compression));
#endif
#if defined(PNG_WRITE_iTXt_SUPPORTED)
PNG_EXTERN void png_write_iTXt PNGARG((png_structp png_ptr,
 int compression, png_charp key, png_charp lang, png_charp lang_key,
 png_charp text));
#endif
#if defined(PNG_TEXT_SUPPORTED)
PNG_EXTERN int png_set_text_2 PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_textp text_ptr, int num_text));
#endif
#if defined(PNG_WRITE_oFFs_SUPPORTED)
PNG_EXTERN void png_write_oFFs PNGARG((png_structp png_ptr,
 png_int_32 x_offset, png_int_32 y_offset, int unit_type));
#endif
#if defined(PNG_WRITE_pCAL_SUPPORTED)
PNG_EXTERN void png_write_pCAL PNGARG((png_structp png_ptr, png_charp purpose,
 png_int_32 X0, png_int_32 X1, int type, int nparams,
 png_charp units, png_charpp params));
#endif
#if defined(PNG_WRITE_pHYs_SUPPORTED)
PNG_EXTERN void png_write_pHYs PNGARG((png_structp png_ptr,
 png_uint_32 x_pixels_per_unit, png_uint_32 y_pixels_per_unit,
 int unit_type));
#endif
#if defined(PNG_WRITE_tIME_SUPPORTED)
PNG_EXTERN void png_write_tIME PNGARG((png_structp png_ptr,
 png_timep mod_time));
#endif
#if defined(PNG_WRITE_sCAL_SUPPORTED)
#if defined(PNG_FLOATING_POINT_SUPPORTED) && !defined(PNG_NO_STDIO)
PNG_EXTERN void png_write_sCAL PNGARG((png_structp png_ptr,
 int unit, double width, double height));
#else
#ifdef PNG_FIXED_POINT_SUPPORTED
PNG_EXTERN void png_write_sCAL_s PNGARG((png_structp png_ptr,
 int unit, png_charp width, png_charp height));
#endif
#endif
#endif
PNG_EXTERN void png_write_finish_row PNGARG((png_structp png_ptr));
PNG_EXTERN void png_write_start_row PNGARG((png_structp png_ptr));
#if defined(PNG_READ_GAMMA_SUPPORTED)
PNG_EXTERN void png_build_gamma_table PNGARG((png_structp png_ptr));
#endif
PNG_EXTERN void png_combine_row PNGARG((png_structp png_ptr, png_bytep row,
 int mask));
#if defined(PNG_READ_INTERLACING_SUPPORTED)
PNG_EXTERN void png_do_read_interlace PNGARG((png_structp png_ptr));
#endif
#if defined(PNG_WRITE_INTERLACING_SUPPORTED)
PNG_EXTERN void png_do_write_interlace PNGARG((png_row_infop row_info,
 png_bytep row, int pass));
#endif
PNG_EXTERN void png_read_filter_row PNGARG((png_structp png_ptr,
 png_row_infop row_info, png_bytep row, png_bytep prev_row, int filter));
PNG_EXTERN void png_write_find_filter PNGARG((png_structp png_ptr,
 png_row_infop row_info));
PNG_EXTERN void png_write_filtered_row PNGARG((png_structp png_ptr,
 png_bytep filtered_row));
PNG_EXTERN void png_read_finish_row PNGARG((png_structp png_ptr));
PNG_EXTERN void png_read_start_row PNGARG((png_structp png_ptr));
PNG_EXTERN void png_read_transform_info PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#if defined(PNG_READ_FILLER_SUPPORTED)
PNG_EXTERN void png_do_read_filler PNGARG((png_row_infop row_info,
 png_bytep row, png_uint_32 filler, png_uint_32 flags));
#endif
#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED)
PNG_EXTERN void png_do_read_swap_alpha PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
PNG_EXTERN void png_do_write_swap_alpha PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED)
PNG_EXTERN void png_do_read_invert_alpha PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
PNG_EXTERN void png_do_write_invert_alpha PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_WRITE_FILLER_SUPPORTED) || \
 defined(PNG_READ_STRIP_ALPHA_SUPPORTED)
PNG_EXTERN void png_do_strip_filler PNGARG((png_row_infop row_info,
 png_bytep row, png_uint_32 flags));
#endif
#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
PNG_EXTERN void png_do_swap PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_READ_PACKSWAP_SUPPORTED) || defined(PNG_WRITE_PACKSWAP_SUPPORTED)
PNG_EXTERN void png_do_packswap PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_READ_RGB_TO_GRAY_SUPPORTED)
PNG_EXTERN int png_do_rgb_to_gray PNGARG((png_structp png_ptr, png_row_infop
 row_info, png_bytep row));
#endif
#if defined(PNG_READ_GRAY_TO_RGB_SUPPORTED)
PNG_EXTERN void png_do_gray_to_rgb PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_READ_PACK_SUPPORTED)
PNG_EXTERN void png_do_unpack PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED)
PNG_EXTERN void png_do_unshift PNGARG((png_row_infop row_info, png_bytep row,
 png_color_8p sig_bits));
#endif
#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
PNG_EXTERN void png_do_invert PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_READ_16_TO_8_SUPPORTED)
PNG_EXTERN void png_do_chop PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_READ_DITHER_SUPPORTED)
PNG_EXTERN void png_do_dither PNGARG((png_row_infop row_info,
 png_bytep row, png_bytep palette_lookup, png_bytep dither_lookup));
#  if defined(PNG_CORRECT_PALETTE_SUPPORTED)
PNG_EXTERN void png_correct_palette PNGARG((png_structp png_ptr,
 png_colorp palette, int num_palette));
#  endif
#endif
#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
PNG_EXTERN void png_do_bgr PNGARG((png_row_infop row_info, png_bytep row));
#endif
#if defined(PNG_WRITE_PACK_SUPPORTED)
PNG_EXTERN void png_do_pack PNGARG((png_row_infop row_info,
 png_bytep row, png_uint_32 bit_depth));
#endif
#if defined(PNG_WRITE_SHIFT_SUPPORTED)
PNG_EXTERN void png_do_shift PNGARG((png_row_infop row_info, png_bytep row,
 png_color_8p bit_depth));
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED)
#if defined(PNG_READ_GAMMA_SUPPORTED)
PNG_EXTERN void png_do_background PNGARG((png_row_infop row_info, png_bytep row,
 png_color_16p trans_values, png_color_16p background,
 png_color_16p background_1,
 png_bytep gamma_table, png_bytep gamma_from_1, png_bytep gamma_to_1,
 png_uint_16pp gamma_16, png_uint_16pp gamma_16_from_1,
 png_uint_16pp gamma_16_to_1, int gamma_shift));
#else
PNG_EXTERN void png_do_background PNGARG((png_row_infop row_info, png_bytep row,
 png_color_16p trans_values, png_color_16p background));
#endif
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED)
PNG_EXTERN void png_do_gamma PNGARG((png_row_infop row_info, png_bytep row,
 png_bytep gamma_table, png_uint_16pp gamma_16_table,
 int gamma_shift));
#endif
#if defined(PNG_READ_EXPAND_SUPPORTED)
PNG_EXTERN void png_do_expand_palette PNGARG((png_row_infop row_info,
 png_bytep row, png_colorp palette, png_bytep trans, int num_trans));
PNG_EXTERN void png_do_expand PNGARG((png_row_infop row_info,
 png_bytep row, png_color_16p trans_value));
#endif
PNG_EXTERN void png_handle_IHDR PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
PNG_EXTERN void png_handle_PLTE PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
PNG_EXTERN void png_handle_IEND PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#if defined(PNG_READ_bKGD_SUPPORTED)
PNG_EXTERN void png_handle_bKGD PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_cHRM_SUPPORTED)
PNG_EXTERN void png_handle_cHRM PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_gAMA_SUPPORTED)
PNG_EXTERN void png_handle_gAMA PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
PNG_EXTERN void png_handle_hIST PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_iCCP_SUPPORTED)
extern void png_handle_iCCP PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
PNG_EXTERN void png_handle_iTXt PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_oFFs_SUPPORTED)
PNG_EXTERN void png_handle_oFFs PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_pCAL_SUPPORTED)
PNG_EXTERN void png_handle_pCAL PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_pHYs_SUPPORTED)
PNG_EXTERN void png_handle_pHYs PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_sBIT_SUPPORTED)
PNG_EXTERN void png_handle_sBIT PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_sCAL_SUPPORTED)
PNG_EXTERN void png_handle_sCAL PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_sPLT_SUPPORTED)
extern void png_handle_sPLT PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_sRGB_SUPPORTED)
PNG_EXTERN void png_handle_sRGB PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_tEXt_SUPPORTED)
PNG_EXTERN void png_handle_tEXt PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_tIME_SUPPORTED)
PNG_EXTERN void png_handle_tIME PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_tRNS_SUPPORTED)
PNG_EXTERN void png_handle_tRNS PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
PNG_EXTERN void png_handle_zTXt PNGARG((png_structp png_ptr, png_infop info_ptr,
 png_uint_32 length));
#endif
PNG_EXTERN void png_handle_unknown PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 length));
PNG_EXTERN void png_check_chunk_name PNGARG((png_structp png_ptr,
 png_bytep chunk_name));
PNG_EXTERN void png_do_read_transformations PNGARG((png_structp png_ptr));
PNG_EXTERN void png_do_write_transformations PNGARG((png_structp png_ptr));
PNG_EXTERN void png_init_read_transformations PNGARG((png_structp png_ptr));
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
PNG_EXTERN void png_push_read_chunk PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_push_read_sig PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_push_check_crc PNGARG((png_structp png_ptr));
PNG_EXTERN void png_push_crc_skip PNGARG((png_structp png_ptr,
 png_uint_32 length));
PNG_EXTERN void png_push_crc_finish PNGARG((png_structp png_ptr));
PNG_EXTERN void png_push_save_buffer PNGARG((png_structp png_ptr));
PNG_EXTERN void png_push_restore_buffer PNGARG((png_structp png_ptr,
 png_bytep buffer, png_size_t buffer_length));
PNG_EXTERN void png_push_read_IDAT PNGARG((png_structp png_ptr));
PNG_EXTERN void png_process_IDAT_data PNGARG((png_structp png_ptr,
 png_bytep buffer, png_size_t buffer_length));
PNG_EXTERN void png_push_process_row PNGARG((png_structp png_ptr));
PNG_EXTERN void png_push_handle_unknown PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 length));
PNG_EXTERN void png_push_have_info PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_push_have_end PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_push_have_row PNGARG((png_structp png_ptr, png_bytep row));
PNG_EXTERN void png_push_read_end PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_process_some_data PNGARG((png_structp png_ptr,
 png_infop info_ptr));
PNG_EXTERN void png_read_push_finish_row PNGARG((png_structp png_ptr));
#if defined(PNG_READ_tEXt_SUPPORTED)
PNG_EXTERN void png_push_handle_tEXt PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 length));
PNG_EXTERN void png_push_read_tEXt PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
PNG_EXTERN void png_push_handle_zTXt PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 length));
PNG_EXTERN void png_push_read_zTXt PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
PNG_EXTERN void png_push_handle_iTXt PNGARG((png_structp png_ptr,
 png_infop info_ptr, png_uint_32 length));
PNG_EXTERN void png_push_read_iTXt PNGARG((png_structp png_ptr,
 png_infop info_ptr));
#endif
#endif
#ifdef PNG_MNG_FEATURES_SUPPORTED
PNG_EXTERN void png_do_read_intrapixel PNGARG((png_row_infop row_info,
 png_bytep row));
PNG_EXTERN void png_do_write_intrapixel PNGARG((png_row_infop row_info,
 png_bytep row));
#endif
#if defined(PNG_ASSEMBLER_CODE_SUPPORTED)
#if defined(PNG_MMX_CODE_SUPPORTED)
PNG_EXTERN void png_init_mmx_flags PNGARG((png_structp png_ptr));
#endif
#endif
#if defined(PNG_INCH_CONVERSIONS) && defined(PNG_FLOATING_POINT_SUPPORTED)
PNG_EXTERN png_uint_32 png_get_pixels_per_inch PNGARG((png_structp png_ptr,
png_infop info_ptr));
PNG_EXTERN png_uint_32 png_get_x_pixels_per_inch PNGARG((png_structp png_ptr,
png_infop info_ptr));
PNG_EXTERN png_uint_32 png_get_y_pixels_per_inch PNGARG((png_structp png_ptr,
png_infop info_ptr));
PNG_EXTERN float png_get_x_offset_inches PNGARG((png_structp png_ptr,
png_infop info_ptr));
PNG_EXTERN float png_get_y_offset_inches PNGARG((png_structp png_ptr,
png_infop info_ptr));
#if defined(PNG_pHYs_SUPPORTED)
PNG_EXTERN png_uint_32 png_get_pHYs_dpi PNGARG((png_structp png_ptr,
png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type));
#endif
#endif
PNG_EXTERN png_uint_32 png_read_chunk_header PNGARG((png_structp png_ptr));
#endif
#ifdef __cplusplus
}
#endif
#endif
#endif
#define PNG_INTERNAL
#if defined(PNG_READ_SUPPORTED)
png_structp PNGAPI
png_create_read_struct(png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn)
{
#ifdef PNG_USER_MEM_SUPPORTED
 return (png_create_read_struct_2(user_png_ver, error_ptr, error_fn,
 warn_fn, png_voidp_NULL, png_malloc_ptr_NULL, png_free_ptr_NULL));
}
png_structp PNGAPI
png_create_read_struct_2(png_const_charp user_png_ver, png_voidp error_ptr,
 png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr,
 png_malloc_ptr malloc_fn, png_free_ptr free_fn)
{
#endif
#ifdef PNG_SETJMP_SUPPORTED
 volatile
#endif
 png_structp png_ptr;
#ifdef PNG_SETJMP_SUPPORTED
#ifdef USE_FAR_KEYWORD
 jmp_buf jmpbuf;
#endif
#endif
 int i;
 png_debug(1, "in png_create_read_struct\n");
#ifdef PNG_USER_MEM_SUPPORTED
 png_ptr = (png_structp)png_create_struct_2(PNG_STRUCT_PNG,
 (png_malloc_ptr)malloc_fn, (png_voidp)mem_ptr);
#else
 png_ptr = (png_structp)png_create_struct(PNG_STRUCT_PNG);
#endif
 if (png_ptr == NULL)
 return (NULL);
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
 png_ptr->user_width_max=PNG_USER_WIDTH_MAX;
 png_ptr->user_height_max=PNG_USER_HEIGHT_MAX;
#endif
#ifdef PNG_SETJMP_SUPPORTED
#ifdef USE_FAR_KEYWORD
 if (setjmp(jmpbuf))
#else
 if (setjmp(png_ptr->jmpbuf))
#endif
 {
 png_free(png_ptr, png_ptr->zbuf);
 png_ptr->zbuf = NULL;
#ifdef PNG_USER_MEM_SUPPORTED
 png_destroy_struct_2((png_voidp)png_ptr,
 (png_free_ptr)free_fn, (png_voidp)mem_ptr);
#else
 png_destroy_struct((png_voidp)png_ptr);
#endif
 return (NULL);
 }
#ifdef USE_FAR_KEYWORD
 png_memcpy(png_ptr->jmpbuf, jmpbuf, png_sizeof(jmp_buf));
#endif
#endif
#ifdef PNG_USER_MEM_SUPPORTED
 png_set_mem_fn(png_ptr, mem_ptr, malloc_fn, free_fn);
#endif
 png_set_error_fn(png_ptr, error_ptr, error_fn, warn_fn);
 if (user_png_ver)
 {
 i = 0;
 do
 {
 if (user_png_ver[i] != png_libpng_ver[i])
 png_ptr->flags |= PNG_FLAG_LIBRARY_MISMATCH;
 } while (png_libpng_ver[i++]);
 }
 else
 png_ptr->flags |= PNG_FLAG_LIBRARY_MISMATCH;
 if (png_ptr->flags & PNG_FLAG_LIBRARY_MISMATCH)
 {
 if (user_png_ver == NULL || user_png_ver[0] != png_libpng_ver[0] ||
 (user_png_ver[0] == '1' && user_png_ver[2] != png_libpng_ver[2]) ||
 (user_png_ver[0] == '0' && user_png_ver[2] < '9'))
 {
#if !defined(PNG_NO_STDIO) && !defined(_WIN32_WCE)
 char msg[80];
 if (user_png_ver)
 {
 png_snprintf(msg, 80,
 "Application was compiled with png.h from libpng-%.20s",
 user_png_ver);
 png_warning(png_ptr, msg);
 }
 png_snprintf(msg, 80,
 "Application  is  running with png.c from libpng-%.20s",
 png_libpng_ver);
 png_warning(png_ptr, msg);
#endif
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
 png_ptr->flags = 0;
#endif
 png_error(png_ptr,
 "Incompatible libpng version in application and library");
 }
 }
 png_ptr->zbuf_size = PNG_ZBUF_SIZE;
 png_ptr->zbuf = (png_bytep)png_malloc(png_ptr,
 (png_uint_32)png_ptr->zbuf_size);
 png_ptr->zstream.zalloc = png_zalloc;
 png_ptr->zstream.zfree = png_zfree;
 png_ptr->zstream.opaque = (voidpf)png_ptr;
 switch (inflateInit(&png_ptr->zstream))
 {
 case Z_OK:   break;
 case Z_MEM_ERROR:
 case Z_STREAM_ERROR: png_error(png_ptr, "zlib memory error"); break;
 case Z_VERSION_ERROR: png_error(png_ptr, "zlib version error"); break;
 default: png_error(png_ptr, "Unknown zlib error");
 }
 png_ptr->zstream.next_out = png_ptr->zbuf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_set_read_fn(png_ptr, png_voidp_NULL, png_rw_ptr_NULL);
#ifdef PNG_SETJMP_SUPPORTED
#ifdef USE_FAR_KEYWORD
 if (setjmp(jmpbuf))
 PNG_ABORT();
 png_memcpy(png_ptr->jmpbuf, jmpbuf, png_sizeof(jmp_buf));
#else
 if (setjmp(png_ptr->jmpbuf))
 PNG_ABORT();
#endif
#endif
 return (png_ptr);
}
#if defined(PNG_1_0_X) || defined(PNG_1_2_X)
#undef png_read_init
void PNGAPI
png_read_init(png_structp png_ptr)
{
 png_read_init_2(png_ptr, "1.0.6 or earlier", 0, 0);
}
void PNGAPI
png_read_init_2(png_structp png_ptr, png_const_charp user_png_ver,
 png_size_t png_struct_size, png_size_t png_info_size)
{
 if (png_ptr == NULL) return;
#if !defined(PNG_NO_STDIO) && !defined(_WIN32_WCE)
 if (png_sizeof(png_struct) > png_struct_size ||
 png_sizeof(png_info) > png_info_size)
 {
 char msg[80];
 png_ptr->warning_fn = NULL;
 if (user_png_ver)
 {
 png_snprintf(msg, 80,
 "Application was compiled with png.h from libpng-%.20s",
 user_png_ver);
 png_warning(png_ptr, msg);
 }
 png_snprintf(msg, 80,
 "Application  is  running with png.c from libpng-%.20s",
 png_libpng_ver);
 png_warning(png_ptr, msg);
 }
#endif
 if (png_sizeof(png_struct) > png_struct_size)
 {
 png_ptr->error_fn = NULL;
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
 png_ptr->flags = 0;
#endif
 png_error(png_ptr,
 "The png struct allocated by the application for reading is too small.");
 }
 if (png_sizeof(png_info) > png_info_size)
 {
 png_ptr->error_fn = NULL;
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
 png_ptr->flags = 0;
#endif
 png_error(png_ptr,
 "The info struct allocated by application for reading is too small.");
 }
 png_read_init_3(&png_ptr, user_png_ver, png_struct_size);
}
#endif
void PNGAPI
png_read_init_3(png_structpp ptr_ptr, png_const_charp user_png_ver,
 png_size_t png_struct_size)
{
#ifdef PNG_SETJMP_SUPPORTED
 jmp_buf tmp_jmp;
#endif
 int i = 0;
 png_structp png_ptr=*ptr_ptr;
 if (png_ptr == NULL) return;
 do
 {
 if (user_png_ver[i] != png_libpng_ver[i])
 {
#ifdef PNG_LEGACY_SUPPORTED
 png_ptr->flags |= PNG_FLAG_LIBRARY_MISMATCH;
#else
 png_ptr->warning_fn = NULL;
 png_warning(png_ptr,
 "Application uses deprecated png_read_init() and should be recompiled.");
 break;
#endif
 }
 } while (png_libpng_ver[i++]);
 png_debug(1, "in png_read_init_3\n");
#ifdef PNG_SETJMP_SUPPORTED
 png_memcpy(tmp_jmp, png_ptr->jmpbuf, png_sizeof(jmp_buf));
#endif
 if (png_sizeof(png_struct) > png_struct_size)
 {
 png_destroy_struct(png_ptr);
 *ptr_ptr = (png_structp)png_create_struct(PNG_STRUCT_PNG);
 png_ptr = *ptr_ptr;
 }
 png_memset(png_ptr, 0, png_sizeof(png_struct));
#ifdef PNG_SETJMP_SUPPORTED
 png_memcpy(png_ptr->jmpbuf, tmp_jmp, png_sizeof(jmp_buf));
#endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
 png_ptr->user_width_max=PNG_USER_WIDTH_MAX;
 png_ptr->user_height_max=PNG_USER_HEIGHT_MAX;
#endif
 png_ptr->zbuf_size = PNG_ZBUF_SIZE;
 png_ptr->zbuf = (png_bytep)png_malloc(png_ptr,
 (png_uint_32)png_ptr->zbuf_size);
 png_ptr->zstream.zalloc = png_zalloc;
 png_ptr->zstream.zfree = png_zfree;
 png_ptr->zstream.opaque = (voidpf)png_ptr;
 switch (inflateInit(&png_ptr->zstream))
 {
 case Z_OK:   break;
 case Z_MEM_ERROR:
 case Z_STREAM_ERROR: png_error(png_ptr, "zlib memory"); break;
 case Z_VERSION_ERROR: png_error(png_ptr, "zlib version"); break;
 default: png_error(png_ptr, "Unknown zlib error");
 }
 png_ptr->zstream.next_out = png_ptr->zbuf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->zbuf_size;
 png_set_read_fn(png_ptr, png_voidp_NULL, png_rw_ptr_NULL);
}
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_read_info(png_structp png_ptr, png_infop info_ptr)
{
 if (png_ptr == NULL || info_ptr == NULL) return;
 png_debug(1, "in png_read_info\n");
 if (png_ptr->sig_bytes < 8)
 {
 png_size_t num_checked = png_ptr->sig_bytes,
 num_to_check = 8 - num_checked;
 png_read_data(png_ptr, &(info_ptr->signature[num_checked]), num_to_check);
 png_ptr->sig_bytes = 8;
 if (png_sig_cmp(info_ptr->signature, num_checked, num_to_check))
 {
 if (num_checked < 4 &&
 png_sig_cmp(info_ptr->signature, num_checked, num_to_check - 4))
 png_error(png_ptr, "Not a PNG file");
 else
 png_error(png_ptr, "PNG file corrupted by ASCII conversion");
 }
 if (num_checked < 3)
 png_ptr->mode |= PNG_HAVE_PNG_SIGNATURE;
 }
 for (;;)
 {
#ifdef PNG_USE_LOCAL_ARRAYS
 PNG_CONST PNG_IHDR;
 PNG_CONST PNG_IDAT;
 PNG_CONST PNG_IEND;
 PNG_CONST PNG_PLTE;
#if defined(PNG_READ_bKGD_SUPPORTED)
 PNG_CONST PNG_bKGD;
#endif
#if defined(PNG_READ_cHRM_SUPPORTED)
 PNG_CONST PNG_cHRM;
#endif
#if defined(PNG_READ_gAMA_SUPPORTED)
 PNG_CONST PNG_gAMA;
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
 PNG_CONST PNG_hIST;
#endif
#if defined(PNG_READ_iCCP_SUPPORTED)
 PNG_CONST PNG_iCCP;
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
 PNG_CONST PNG_iTXt;
#endif
#if defined(PNG_READ_oFFs_SUPPORTED)
 PNG_CONST PNG_oFFs;
#endif
#if defined(PNG_READ_pCAL_SUPPORTED)
 PNG_CONST PNG_pCAL;
#endif
#if defined(PNG_READ_pHYs_SUPPORTED)
 PNG_CONST PNG_pHYs;
#endif
#if defined(PNG_READ_sBIT_SUPPORTED)
 PNG_CONST PNG_sBIT;
#endif
#if defined(PNG_READ_sCAL_SUPPORTED)
 PNG_CONST PNG_sCAL;
#endif
#if defined(PNG_READ_sPLT_SUPPORTED)
 PNG_CONST PNG_sPLT;
#endif
#if defined(PNG_READ_sRGB_SUPPORTED)
 PNG_CONST PNG_sRGB;
#endif
#if defined(PNG_READ_tEXt_SUPPORTED)
 PNG_CONST PNG_tEXt;
#endif
#if defined(PNG_READ_tIME_SUPPORTED)
 PNG_CONST PNG_tIME;
#endif
#if defined(PNG_READ_tRNS_SUPPORTED)
 PNG_CONST PNG_tRNS;
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
 PNG_CONST PNG_zTXt;
#endif
#endif
 png_uint_32 length = png_read_chunk_header(png_ptr);
 PNG_CONST png_bytep chunk_name = png_ptr->chunk_name;
 if (!png_memcmp(chunk_name, png_IDAT, 4))
 if (png_ptr->mode & PNG_AFTER_IDAT)
 png_ptr->mode |= PNG_HAVE_CHUNK_AFTER_IDAT;
 if (!png_memcmp(chunk_name, png_IHDR, 4))
 png_handle_IHDR(png_ptr, info_ptr, length);
 else if (!png_memcmp(chunk_name, png_IEND, 4))
 png_handle_IEND(png_ptr, info_ptr, length);
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
 else if (png_handle_as_unknown(png_ptr, chunk_name))
 {
 if (!png_memcmp(chunk_name, png_IDAT, 4))
 png_ptr->mode |= PNG_HAVE_IDAT;
 png_handle_unknown(png_ptr, info_ptr, length);
 if (!png_memcmp(chunk_name, png_PLTE, 4))
 png_ptr->mode |= PNG_HAVE_PLTE;
 else if (!png_memcmp(chunk_name, png_IDAT, 4))
 {
 if (!(png_ptr->mode & PNG_HAVE_IHDR))
 png_error(png_ptr, "Missing IHDR before IDAT");
 else if (png_ptr->color_type == PNG_COLOR_TYPE_PALETTE &&
 !(png_ptr->mode & PNG_HAVE_PLTE))
 png_error(png_ptr, "Missing PLTE before IDAT");
 break;
 }
 }
#endif
 else if (!png_memcmp(chunk_name, png_PLTE, 4))
 png_handle_PLTE(png_ptr, info_ptr, length);
 else if (!png_memcmp(chunk_name, png_IDAT, 4))
 {
 if (!(png_ptr->mode & PNG_HAVE_IHDR))
 png_error(png_ptr, "Missing IHDR before IDAT");
 else if (png_ptr->color_type == PNG_COLOR_TYPE_PALETTE &&
 !(png_ptr->mode & PNG_HAVE_PLTE))
 png_error(png_ptr, "Missing PLTE before IDAT");
 png_ptr->idat_size = length;
 png_ptr->mode |= PNG_HAVE_IDAT;
 break;
 }
#if defined(PNG_READ_bKGD_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_bKGD, 4))
 png_handle_bKGD(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_cHRM_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_cHRM, 4))
 png_handle_cHRM(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_gAMA_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_gAMA, 4))
 png_handle_gAMA(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_hIST, 4))
 png_handle_hIST(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_oFFs_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_oFFs, 4))
 png_handle_oFFs(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_pCAL_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_pCAL, 4))
 png_handle_pCAL(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sCAL_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sCAL, 4))
 png_handle_sCAL(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_pHYs_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_pHYs, 4))
 png_handle_pHYs(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sBIT_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sBIT, 4))
 png_handle_sBIT(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sRGB_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sRGB, 4))
 png_handle_sRGB(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_iCCP_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_iCCP, 4))
 png_handle_iCCP(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sPLT_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sPLT, 4))
 png_handle_sPLT(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tEXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tEXt, 4))
 png_handle_tEXt(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tIME_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tIME, 4))
 png_handle_tIME(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tRNS_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tRNS, 4))
 png_handle_tRNS(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_zTXt, 4))
 png_handle_zTXt(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_iTXt, 4))
 png_handle_iTXt(png_ptr, info_ptr, length);
#endif
 else
 png_handle_unknown(png_ptr, info_ptr, length);
 }
}
#endif
void PNGAPI
png_read_update_info(png_structp png_ptr, png_infop info_ptr)
{
 png_debug(1, "in png_read_update_info\n");
 if (png_ptr == NULL) return;
 if (!(png_ptr->flags & PNG_FLAG_ROW_INIT))
 png_read_start_row(png_ptr);
 else
 png_warning(png_ptr,
 "Ignoring extra png_read_update_info() call; row buffer not reallocated");
 png_read_transform_info(png_ptr, info_ptr);
}
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_start_read_image(png_structp png_ptr)
{
 png_debug(1, "in png_start_read_image\n");
 if (png_ptr == NULL) return;
 if (!(png_ptr->flags & PNG_FLAG_ROW_INIT))
 png_read_start_row(png_ptr);
}
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_read_row(png_structp png_ptr, png_bytep row, png_bytep dsp_row)
{
#ifdef PNG_USE_LOCAL_ARRAYS
 PNG_CONST PNG_IDAT;
 PNG_CONST int png_pass_dsp_mask[7] = {0xff, 0x0f, 0xff, 0x33, 0xff, 0x55,
 0xff};
 PNG_CONST int png_pass_mask[7] = {0x80, 0x08, 0x88, 0x22, 0xaa, 0x55, 0xff};
#endif
 int ret;
 if (png_ptr == NULL) return;
 png_debug2(1, "in png_read_row (row %lu, pass %d)\n",
 png_ptr->row_number, png_ptr->pass);
 if (!(png_ptr->flags & PNG_FLAG_ROW_INIT))
 png_read_start_row(png_ptr);
 if (png_ptr->row_number == 0 && png_ptr->pass == 0)
 {
#if defined(PNG_WRITE_INVERT_SUPPORTED) && !defined(PNG_READ_INVERT_SUPPORTED)
 if (png_ptr->transformations & PNG_INVERT_MONO)
 png_warning(png_ptr, "PNG_READ_INVERT_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_FILLER_SUPPORTED) && !defined(PNG_READ_FILLER_SUPPORTED)
 if (png_ptr->transformations & PNG_FILLER)
 png_warning(png_ptr, "PNG_READ_FILLER_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_PACKSWAP_SUPPORTED) && !defined(PNG_READ_PACKSWAP_SUPPORTED)
 if (png_ptr->transformations & PNG_PACKSWAP)
 png_warning(png_ptr, "PNG_READ_PACKSWAP_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_PACK_SUPPORTED) && !defined(PNG_READ_PACK_SUPPORTED)
 if (png_ptr->transformations & PNG_PACK)
 png_warning(png_ptr, "PNG_READ_PACK_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_SHIFT_SUPPORTED) && !defined(PNG_READ_SHIFT_SUPPORTED)
 if (png_ptr->transformations & PNG_SHIFT)
 png_warning(png_ptr, "PNG_READ_SHIFT_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_BGR_SUPPORTED) && !defined(PNG_READ_BGR_SUPPORTED)
 if (png_ptr->transformations & PNG_BGR)
 png_warning(png_ptr, "PNG_READ_BGR_SUPPORTED is not defined.");
#endif
#if defined(PNG_WRITE_SWAP_SUPPORTED) && !defined(PNG_READ_SWAP_SUPPORTED)
 if (png_ptr->transformations & PNG_SWAP_BYTES)
 png_warning(png_ptr, "PNG_READ_SWAP_SUPPORTED is not defined.");
#endif
 }
#if defined(PNG_READ_INTERLACING_SUPPORTED)
 if (png_ptr->interlaced && (png_ptr->transformations & PNG_INTERLACE))
 {
 switch (png_ptr->pass)
 {
 case 0:
 if (png_ptr->row_number & 0x07)
 {
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 1:
 if ((png_ptr->row_number & 0x07) || png_ptr->width < 5)
 {
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 2:
 if ((png_ptr->row_number & 0x07) != 4)
 {
 if (dsp_row != NULL && (png_ptr->row_number & 4))
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 3:
 if ((png_ptr->row_number & 3) || png_ptr->width < 3)
 {
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 4:
 if ((png_ptr->row_number & 3) != 2)
 {
 if (dsp_row != NULL && (png_ptr->row_number & 2))
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 5:
 if ((png_ptr->row_number & 1) || png_ptr->width < 2)
 {
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 case 6:
 if (!(png_ptr->row_number & 1))
 {
 png_read_finish_row(png_ptr);
 return;
 }
 break;
 }
 }
#endif
 if (!(png_ptr->mode & PNG_HAVE_IDAT))
 png_error(png_ptr, "Invalid attempt to read row data");
 png_ptr->zstream.next_out = png_ptr->row_buf;
 png_ptr->zstream.avail_out = (uInt)png_ptr->irowbytes;
 do
 {
 if (!(png_ptr->zstream.avail_in))
 {
 while (!png_ptr->idat_size)
 {
 png_crc_finish(png_ptr, 0);
 png_ptr->idat_size = png_read_chunk_header(png_ptr);
 if (png_memcmp(png_ptr->chunk_name, png_IDAT, 4))
 png_error(png_ptr, "Not enough image data");
 }
 png_ptr->zstream.avail_in = (uInt)png_ptr->zbuf_size;
 png_ptr->zstream.next_in = png_ptr->zbuf;
 if (png_ptr->zbuf_size > png_ptr->idat_size)
 png_ptr->zstream.avail_in = (uInt)png_ptr->idat_size;
 png_crc_read(png_ptr, png_ptr->zbuf,
 (png_size_t)png_ptr->zstream.avail_in);
 png_ptr->idat_size -= png_ptr->zstream.avail_in;
 }
 ret = inflate(&png_ptr->zstream, Z_PARTIAL_FLUSH);
 if (ret == Z_STREAM_END)
 {
 if (png_ptr->zstream.avail_out || png_ptr->zstream.avail_in ||
 png_ptr->idat_size)
 png_error(png_ptr, "Extra compressed data");
 png_ptr->mode |= PNG_AFTER_IDAT;
 png_ptr->flags |= PNG_FLAG_ZLIB_FINISHED;
 break;
 }
 if (ret != Z_OK)
 png_error(png_ptr, png_ptr->zstream.msg ? png_ptr->zstream.msg :
 "Decompression error");
 } while (png_ptr->zstream.avail_out);
 png_ptr->row_info.color_type = png_ptr->color_type;
 png_ptr->row_info.width = png_ptr->iwidth;
 png_ptr->row_info.channels = png_ptr->channels;
 png_ptr->row_info.bit_depth = png_ptr->bit_depth;
 png_ptr->row_info.pixel_depth = png_ptr->pixel_depth;
 png_ptr->row_info.rowbytes = PNG_ROWBYTES(png_ptr->row_info.pixel_depth,
 png_ptr->row_info.width);
 if (png_ptr->row_buf[0])
 png_read_filter_row(png_ptr, &(png_ptr->row_info),
 png_ptr->row_buf + 1, png_ptr->prev_row + 1,
 (int)(png_ptr->row_buf[0]));
 png_memcpy_check(png_ptr, png_ptr->prev_row, png_ptr->row_buf,
 png_ptr->rowbytes + 1);
#if defined(PNG_MNG_FEATURES_SUPPORTED)
 if ((png_ptr->mng_features_permitted & PNG_FLAG_MNG_FILTER_64) &&
 (png_ptr->filter_type == PNG_INTRAPIXEL_DIFFERENCING))
 {
 png_do_read_intrapixel(&(png_ptr->row_info), png_ptr->row_buf + 1);
 }
#endif
 if (png_ptr->transformations || (png_ptr->flags&PNG_FLAG_STRIP_ALPHA))
 png_do_read_transformations(png_ptr);
#if defined(PNG_READ_INTERLACING_SUPPORTED)
 if (png_ptr->interlaced &&
 (png_ptr->transformations & PNG_INTERLACE))
 {
 if (png_ptr->pass < 6)
 png_do_read_interlace(png_ptr);
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row,
 png_pass_dsp_mask[png_ptr->pass]);
 if (row != NULL)
 png_combine_row(png_ptr, row,
 png_pass_mask[png_ptr->pass]);
 }
 else
#endif
 {
 if (row != NULL)
 png_combine_row(png_ptr, row, 0xff);
 if (dsp_row != NULL)
 png_combine_row(png_ptr, dsp_row, 0xff);
 }
 png_read_finish_row(png_ptr);
 if (png_ptr->read_row_fn != NULL)
 (*(png_ptr->read_row_fn))(png_ptr, png_ptr->row_number, png_ptr->pass);
}
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_read_rows(png_structp png_ptr, png_bytepp row,
 png_bytepp display_row, png_uint_32 num_rows)
{
 png_uint_32 i;
 png_bytepp rp;
 png_bytepp dp;
 png_debug(1, "in png_read_rows\n");
 if (png_ptr == NULL) return;
 rp = row;
 dp = display_row;
 if (rp != NULL && dp != NULL)
 for (i = 0; i < num_rows; i++)
 {
 png_bytep rptr = *rp++;
 png_bytep dptr = *dp++;
 png_read_row(png_ptr, rptr, dptr);
 }
 else if (rp != NULL)
 for (i = 0; i < num_rows; i++)
 {
 png_bytep rptr = *rp;
 png_read_row(png_ptr, rptr, png_bytep_NULL);
 rp++;
 }
 else if (dp != NULL)
 for (i = 0; i < num_rows; i++)
 {
 png_bytep dptr = *dp;
 png_read_row(png_ptr, png_bytep_NULL, dptr);
 dp++;
 }
}
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_read_image(png_structp png_ptr, png_bytepp image)
{
 png_uint_32 i, image_height;
 int pass, j;
 png_bytepp rp;
 png_debug(1, "in png_read_image\n");
 if (png_ptr == NULL) return;
#ifdef PNG_READ_INTERLACING_SUPPORTED
 pass = png_set_interlace_handling(png_ptr);
#else
 if (png_ptr->interlaced)
 png_error(png_ptr,
 "Cannot read interlaced image -- interlace handler disabled.");
 pass = 1;
#endif
 image_height=png_ptr->height;
 png_ptr->num_rows = image_height;
 for (j = 0; j < pass; j++)
 {
 rp = image;
 for (i = 0; i < image_height; i++)
 {
 png_read_row(png_ptr, *rp, png_bytep_NULL);
 rp++;
 }
 }
}
#endif
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
void PNGAPI
png_read_end(png_structp png_ptr, png_infop info_ptr)
{
 png_debug(1, "in png_read_end\n");
 if (png_ptr == NULL) return;
 png_crc_finish(png_ptr, 0);
 do
 {
#ifdef PNG_USE_LOCAL_ARRAYS
 PNG_CONST PNG_IHDR;
 PNG_CONST PNG_IDAT;
 PNG_CONST PNG_IEND;
 PNG_CONST PNG_PLTE;
#if defined(PNG_READ_bKGD_SUPPORTED)
 PNG_CONST PNG_bKGD;
#endif
#if defined(PNG_READ_cHRM_SUPPORTED)
 PNG_CONST PNG_cHRM;
#endif
#if defined(PNG_READ_gAMA_SUPPORTED)
 PNG_CONST PNG_gAMA;
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
 PNG_CONST PNG_hIST;
#endif
#if defined(PNG_READ_iCCP_SUPPORTED)
 PNG_CONST PNG_iCCP;
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
 PNG_CONST PNG_iTXt;
#endif
#if defined(PNG_READ_oFFs_SUPPORTED)
 PNG_CONST PNG_oFFs;
#endif
#if defined(PNG_READ_pCAL_SUPPORTED)
 PNG_CONST PNG_pCAL;
#endif
#if defined(PNG_READ_pHYs_SUPPORTED)
 PNG_CONST PNG_pHYs;
#endif
#if defined(PNG_READ_sBIT_SUPPORTED)
 PNG_CONST PNG_sBIT;
#endif
#if defined(PNG_READ_sCAL_SUPPORTED)
 PNG_CONST PNG_sCAL;
#endif
#if defined(PNG_READ_sPLT_SUPPORTED)
 PNG_CONST PNG_sPLT;
#endif
#if defined(PNG_READ_sRGB_SUPPORTED)
 PNG_CONST PNG_sRGB;
#endif
#if defined(PNG_READ_tEXt_SUPPORTED)
 PNG_CONST PNG_tEXt;
#endif
#if defined(PNG_READ_tIME_SUPPORTED)
 PNG_CONST PNG_tIME;
#endif
#if defined(PNG_READ_tRNS_SUPPORTED)
 PNG_CONST PNG_tRNS;
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
 PNG_CONST PNG_zTXt;
#endif
#endif
 png_uint_32 length = png_read_chunk_header(png_ptr);
 PNG_CONST png_bytep chunk_name = png_ptr->chunk_name;
 if (!png_memcmp(chunk_name, png_IHDR, 4))
 png_handle_IHDR(png_ptr, info_ptr, length);
 else if (!png_memcmp(chunk_name, png_IEND, 4))
 png_handle_IEND(png_ptr, info_ptr, length);
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
 else if (png_handle_as_unknown(png_ptr, chunk_name))
 {
 if (!png_memcmp(chunk_name, png_IDAT, 4))
 {
 if ((length > 0) || (png_ptr->mode & PNG_HAVE_CHUNK_AFTER_IDAT))
 png_error(png_ptr, "Too many IDAT's found");
 }
 png_handle_unknown(png_ptr, info_ptr, length);
 if (!png_memcmp(chunk_name, png_PLTE, 4))
 png_ptr->mode |= PNG_HAVE_PLTE;
 }
#endif
 else if (!png_memcmp(chunk_name, png_IDAT, 4))
 {
 if ((length > 0) || (png_ptr->mode & PNG_HAVE_CHUNK_AFTER_IDAT))
 png_error(png_ptr, "Too many IDAT's found");
 png_crc_finish(png_ptr, length);
 }
 else if (!png_memcmp(chunk_name, png_PLTE, 4))
 png_handle_PLTE(png_ptr, info_ptr, length);
#if defined(PNG_READ_bKGD_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_bKGD, 4))
 png_handle_bKGD(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_cHRM_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_cHRM, 4))
 png_handle_cHRM(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_gAMA_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_gAMA, 4))
 png_handle_gAMA(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_hIST, 4))
 png_handle_hIST(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_oFFs_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_oFFs, 4))
 png_handle_oFFs(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_pCAL_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_pCAL, 4))
 png_handle_pCAL(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sCAL_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sCAL, 4))
 png_handle_sCAL(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_pHYs_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_pHYs, 4))
 png_handle_pHYs(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sBIT_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sBIT, 4))
 png_handle_sBIT(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sRGB_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sRGB, 4))
 png_handle_sRGB(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_iCCP_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_iCCP, 4))
 png_handle_iCCP(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_sPLT_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_sPLT, 4))
 png_handle_sPLT(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tEXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tEXt, 4))
 png_handle_tEXt(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tIME_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tIME, 4))
 png_handle_tIME(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_tRNS_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_tRNS, 4))
 png_handle_tRNS(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_zTXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_zTXt, 4))
 png_handle_zTXt(png_ptr, info_ptr, length);
#endif
#if defined(PNG_READ_iTXt_SUPPORTED)
 else if (!png_memcmp(chunk_name, png_iTXt, 4))
 png_handle_iTXt(png_ptr, info_ptr, length);
#endif
 else
 png_handle_unknown(png_ptr, info_ptr, length);
 } while (!(png_ptr->mode & PNG_HAVE_IEND));
}
#endif
void PNGAPI
png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr,
 png_infopp end_info_ptr_ptr)
{
 png_structp png_ptr = NULL;
 png_infop info_ptr = NULL, end_info_ptr = NULL;
#ifdef PNG_USER_MEM_SUPPORTED
 png_free_ptr free_fn = NULL;
 png_voidp mem_ptr = NULL;
#endif
 png_debug(1, "in png_destroy_read_struct\n");
 if (png_ptr_ptr != NULL)
 png_ptr = *png_ptr_ptr;
 if (png_ptr == NULL)
 return;
#ifdef PNG_USER_MEM_SUPPORTED
 free_fn = png_ptr->free_fn;
 mem_ptr = png_ptr->mem_ptr;
#endif
 if (info_ptr_ptr != NULL)
 info_ptr = *info_ptr_ptr;
 if (end_info_ptr_ptr != NULL)
 end_info_ptr = *end_info_ptr_ptr;
 png_read_destroy(png_ptr, info_ptr, end_info_ptr);
 if (info_ptr != NULL)
 {
#if defined(PNG_TEXT_SUPPORTED)
 png_free_data(png_ptr, info_ptr, PNG_FREE_TEXT, -1);
#endif
#ifdef PNG_USER_MEM_SUPPORTED
 png_destroy_struct_2((png_voidp)info_ptr, (png_free_ptr)free_fn,
 (png_voidp)mem_ptr);
#else
 png_destroy_struct((png_voidp)info_ptr);
#endif
 *info_ptr_ptr = NULL;
 }
 if (end_info_ptr != NULL)
 {
#if defined(PNG_READ_TEXT_SUPPORTED)
 png_free_data(png_ptr, end_info_ptr, PNG_FREE_TEXT, -1);
#endif
#ifdef PNG_USER_MEM_SUPPORTED
 png_destroy_struct_2((png_voidp)end_info_ptr, (png_free_ptr)free_fn,
 (png_voidp)mem_ptr);
#else
 png_destroy_struct((png_voidp)end_info_ptr);
#endif
 *end_info_ptr_ptr = NULL;
 }
 if (png_ptr != NULL)
 {
#ifdef PNG_USER_MEM_SUPPORTED
 png_destroy_struct_2((png_voidp)png_ptr, (png_free_ptr)free_fn,
 (png_voidp)mem_ptr);
#else
 png_destroy_struct((png_voidp)png_ptr);
#endif
 *png_ptr_ptr = NULL;
 }
}
void
png_read_destroy(png_structp png_ptr, png_infop info_ptr, png_infop end_info_ptr)
{
#ifdef PNG_SETJMP_SUPPORTED
 jmp_buf tmp_jmp;
#endif
 png_error_ptr error_fn;
 png_error_ptr warning_fn;
 png_voidp error_ptr;
#ifdef PNG_USER_MEM_SUPPORTED
 png_free_ptr free_fn;
#endif
 png_debug(1, "in png_read_destroy\n");
 if (info_ptr != NULL)
 png_info_destroy(png_ptr, info_ptr);
 if (end_info_ptr != NULL)
 png_info_destroy(png_ptr, end_info_ptr);
 png_free(png_ptr, png_ptr->zbuf);
 png_free(png_ptr, png_ptr->big_row_buf);
 png_free(png_ptr, png_ptr->prev_row);
 png_free(png_ptr, png_ptr->chunkdata);
#if defined(PNG_READ_DITHER_SUPPORTED)
 png_free(png_ptr, png_ptr->palette_lookup);
 png_free(png_ptr, png_ptr->dither_index);
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED)
 png_free(png_ptr, png_ptr->gamma_table);
#endif
#if defined(PNG_READ_BACKGROUND_SUPPORTED)
 png_free(png_ptr, png_ptr->gamma_from_1);
 png_free(png_ptr, png_ptr->gamma_to_1);
#endif
#ifdef PNG_FREE_ME_SUPPORTED
 if (png_ptr->free_me & PNG_FREE_PLTE)
 png_zfree(png_ptr, png_ptr->palette);
 png_ptr->free_me &= ~PNG_FREE_PLTE;
#else
 if (png_ptr->flags & PNG_FLAG_FREE_PLTE)
 png_zfree(png_ptr, png_ptr->palette);
 png_ptr->flags &= ~PNG_FLAG_FREE_PLTE;
#endif
#if defined(PNG_tRNS_SUPPORTED) || \
 defined(PNG_READ_EXPAND_SUPPORTED) || defined(PNG_READ_BACKGROUND_SUPPORTED)
#ifdef PNG_FREE_ME_SUPPORTED
 if (png_ptr->free_me & PNG_FREE_TRNS)
 png_free(png_ptr, png_ptr->trans);
 png_ptr->free_me &= ~PNG_FREE_TRNS;
#else
 if (png_ptr->flags & PNG_FLAG_FREE_TRNS)
 png_free(png_ptr, png_ptr->trans);
 png_ptr->flags &= ~PNG_FLAG_FREE_TRNS;
#endif
#endif
#if defined(PNG_READ_hIST_SUPPORTED)
#ifdef PNG_FREE_ME_SUPPORTED
 if (png_ptr->free_me & PNG_FREE_HIST)
 png_free(png_ptr, png_ptr->hist);
 png_ptr->free_me &= ~PNG_FREE_HIST;
#else
 if (png_ptr->flags & PNG_FLAG_FREE_HIST)
 png_free(png_ptr, png_ptr->hist);
 png_ptr->flags &= ~PNG_FLAG_FREE_HIST;
#endif
#endif
#if defined(PNG_READ_GAMMA_SUPPORTED)
 if (png_ptr->gamma_16_table != NULL)
 {
 int i;
 int istop = (1 << (8 - png_ptr->gamma_shift));
 for (i = 0; i < istop; i++)
 {
 png_free(png_ptr, png_ptr->gamma_16_table[i]);
 }
 png_free(png_ptr, png_ptr->gamma_16_table);
 }
#if defined(PNG_READ_BACKGROUND_SUPPORTED)
 if (png_ptr->gamma_16_from_1 != NULL)
 {
 int i;
 int istop = (1 << (8 - png_ptr->gamma_shift));
 for (i = 0; i < istop; i++)
 {
 png_free(png_ptr, png_ptr->gamma_16_from_1[i]);
 }
 png_free(png_ptr, png_ptr->gamma_16_from_1);
 }
 if (png_ptr->gamma_16_to_1 != NULL)
 {
 int i;
 int istop = (1 << (8 - png_ptr->gamma_shift));
 for (i = 0; i < istop; i++)
 {
 png_free(png_ptr, png_ptr->gamma_16_to_1[i]);
 }
 png_free(png_ptr, png_ptr->gamma_16_to_1);
 }
#endif
#endif
#if defined(PNG_TIME_RFC1123_SUPPORTED)
 png_free(png_ptr, png_ptr->time_buffer);
#endif
 inflateEnd(&png_ptr->zstream);
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
 png_free(png_ptr, png_ptr->save_buffer);
#endif
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
#ifdef PNG_TEXT_SUPPORTED
 png_free(png_ptr, png_ptr->current_text);
#endif
#endif
#ifdef PNG_SETJMP_SUPPORTED
 png_memcpy(tmp_jmp, png_ptr->jmpbuf, png_sizeof(jmp_buf));
#endif
 error_fn = png_ptr->error_fn;
 warning_fn = png_ptr->warning_fn;
 error_ptr = png_ptr->error_ptr;
#ifdef PNG_USER_MEM_SUPPORTED
 free_fn = png_ptr->free_fn;
#endif
 png_memset(png_ptr, 0, png_sizeof(png_struct));
 png_ptr->error_fn = error_fn;
 png_ptr->warning_fn = warning_fn;
 png_ptr->error_ptr = error_ptr;
#ifdef PNG_USER_MEM_SUPPORTED
 png_ptr->free_fn = free_fn;
#endif
#ifdef PNG_SETJMP_SUPPORTED
 png_memcpy(png_ptr->jmpbuf, tmp_jmp, png_sizeof(jmp_buf));
#endif
}
void PNGAPI
png_set_read_status_fn(png_structp png_ptr, png_read_status_ptr read_row_fn)
{
 if (png_ptr == NULL) return;
 png_ptr->read_row_fn = read_row_fn;
}
#ifndef PNG_NO_SEQUENTIAL_READ_SUPPORTED
#if defined(PNG_INFO_IMAGE_SUPPORTED)
void PNGAPI
png_read_png(png_structp png_ptr, png_infop info_ptr,
 int transforms,
 voidp params)
{
 int row;
 if (png_ptr == NULL) return;
#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED)
 if (transforms & PNG_TRANSFORM_INVERT_ALPHA)
 png_set_invert_alpha(png_ptr);
#endif
 png_read_info(png_ptr, info_ptr);
 if (info_ptr->height > PNG_UINT_32_MAX/png_sizeof(png_bytep))
 png_error(png_ptr, "Image is too high to process with png_read_png()");
#if defined(PNG_READ_16_TO_8_SUPPORTED)
 if (transforms & PNG_TRANSFORM_STRIP_16)
 png_set_strip_16(png_ptr);
#endif
#if defined(PNG_READ_STRIP_ALPHA_SUPPORTED)
 if (transforms & PNG_TRANSFORM_STRIP_ALPHA)
 png_set_strip_alpha(png_ptr);
#endif
#if defined(PNG_READ_PACK_SUPPORTED) && !defined(PNG_READ_EXPAND_SUPPORTED)
 if (transforms & PNG_TRANSFORM_PACKING)
 png_set_packing(png_ptr);
#endif
#if defined(PNG_READ_PACKSWAP_SUPPORTED)
 if (transforms & PNG_TRANSFORM_PACKSWAP)
 png_set_packswap(png_ptr);
#endif
#if defined(PNG_READ_EXPAND_SUPPORTED)
 if (transforms & PNG_TRANSFORM_EXPAND)
 if ((png_ptr->bit_depth < 8) ||
 (png_ptr->color_type == PNG_COLOR_TYPE_PALETTE) ||
 (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)))
 png_set_expand(png_ptr);
#endif
#if defined(PNG_READ_INVERT_SUPPORTED)
 if (transforms & PNG_TRANSFORM_INVERT_MONO)
 png_set_invert_mono(png_ptr);
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED)
 if ((transforms & PNG_TRANSFORM_SHIFT)
 && png_get_valid(png_ptr, info_ptr, PNG_INFO_sBIT))
 {
 png_color_8p sig_bit;
 png_get_sBIT(png_ptr, info_ptr, &sig_bit);
 png_set_shift(png_ptr, sig_bit);
 }
#endif
#if defined(PNG_READ_BGR_SUPPORTED)
 if (transforms & PNG_TRANSFORM_BGR)
 png_set_bgr(png_ptr);
#endif
#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED)
 if (transforms & PNG_TRANSFORM_SWAP_ALPHA)
 png_set_swap_alpha(png_ptr);
#endif
#if defined(PNG_READ_SWAP_SUPPORTED)
 if (transforms & PNG_TRANSFORM_SWAP_ENDIAN)
 png_set_swap(png_ptr);
#endif
 png_read_update_info(png_ptr, info_ptr);
#ifdef PNG_FREE_ME_SUPPORTED
 png_free_data(png_ptr, info_ptr, PNG_FREE_ROWS, 0);
#endif
 if (info_ptr->row_pointers == NULL)
 {
 info_ptr->row_pointers = (png_bytepp)png_malloc(png_ptr,
 info_ptr->height * png_sizeof(png_bytep));
#ifdef PNG_FREE_ME_SUPPORTED
 info_ptr->free_me |= PNG_FREE_ROWS;
#endif
 for (row = 0; row < (int)info_ptr->height; row++)
 {
 info_ptr->row_pointers[row] = (png_bytep)png_malloc(png_ptr,
 png_get_rowbytes(png_ptr, info_ptr));
 }
 }
 png_read_image(png_ptr, info_ptr->row_pointers);
 info_ptr->valid |= PNG_INFO_IDAT;
 png_read_end(png_ptr, info_ptr);
 transforms = transforms;
 params = params;
}
#endif
#endif
#endif
