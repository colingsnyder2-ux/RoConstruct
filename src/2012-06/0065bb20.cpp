// from server: 100% by Xemicl
// roc 2012-06 0065bb20  unit: seg_00650000  size: 514 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065bb20
//
// 0065bb20  57                   push edi
// 0065bb21  8b7c2408             mov edi, dword ptr [esp + 8]
// 0065bb25  8b4768               mov eax, dword ptr [edi + 0x68]
// 0065bb28  a801                 test al, 1
// 0065bb2a  750d                 jne 0x65bb39
// 0065bb2c  68a4a6b800           push 0xb8a6a4
// 0065bb31  57                   push edi
// 0065bb32  e87926ffff           call 0x64e1b0
// 0065bb37  eb2e                 jmp 0x65bb67
// 0065bb39  a804                 test al, 4
// 0065bb3b  741b                 je 0x65bb58
// 0065bb3d  688ca6b800           push 0xb8a68c
// 0065bb42  57                   push edi
// 0065bb43  e81827ffff           call 0x64e260
// 0065bb48  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065bb4c  50                   push eax
// 0065bb4d  57                   push edi
// 0065bb4e  e8fdf3ffff           call 0x65af50
// 0065bb53  83c410               add esp, 0x10
// 0065bb56  5f                   pop edi
// 0065bb57  c3                   ret 
// 0065bb58  a802                 test al, 2
// 0065bb5a  740e                 je 0x65bb6a
// 0065bb5c  6874a6b800           push 0xb8a674
// 0065bb61  57                   push edi
// 0065bb62  e8f926ffff           call 0x64e260
// 0065bb67  83c408               add esp, 8
// 0065bb6a  56                   push esi
// 0065bb6b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065bb6f  85f6                 test esi, esi
// 0065bb71  7425                 je 0x65bb98
// 0065bb73  f7460800080000       test dword ptr [esi + 8], 0x800
// 0065bb7a  741c                 je 0x65bb98
// 0065bb7c  685ca6b800           push 0xb8a65c
// 0065bb81  57                   push edi
// 0065bb82  e8d926ffff           call 0x64e260
// 0065bb87  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065bb8b  51                   push ecx
// 0065bb8c  57                   push edi
// 0065bb8d  e8bef3ffff           call 0x65af50
// 0065bb92  83c410               add esp, 0x10
// 0065bb95  5e                   pop esi
// 0065bb96  5f                   pop edi
// 0065bb97  c3                   ret 
// 0065bb98  53                   push ebx
// 0065bb99  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0065bb9d  83fb01               cmp ebx, 1
// 0065bba0  7419                 je 0x65bbbb
// 0065bba2  6840a6b800           push 0xb8a640
// 0065bba7  57                   push edi
// 0065bba8  e8b326ffff           call 0x64e260
// 0065bbad  53                   push ebx
// 0065bbae  57                   push edi
// 0065bbaf  e89cf3ffff           call 0x65af50
// 0065bbb4  83c410               add esp, 0x10
// 0065bbb7  5b                   pop ebx
// 0065bbb8  5e                   pop esi
// 0065bbb9  5f                   pop edi
// 0065bbba  c3                   ret 
// 0065bbbb  6a01                 push 1
// 0065bbbd  8d542414             lea edx, [esp + 0x14]
// 0065bbc1  52                   push edx
// 0065bbc2  57                   push edi
// 0065bbc3  e82822ffff           call 0x64ddf0
// 0065bbc8  6a01                 push 1
// 0065bbca  8d442420             lea eax, [esp + 0x20]
// 0065bbce  50                   push eax
// 0065bbcf  57                   push edi
// 0065bbd0  e8bb22feff           call 0x63de90
// 0065bbd5  6a00                 push 0
// 0065bbd7  57                   push edi
// 0065bbd8  e873f3ffff           call 0x65af50
// 0065bbdd  83c420               add esp, 0x20
// 0065bbe0  85c0                 test eax, eax
// 0065bbe2  0f8536010000         jne 0x65bd1e
// 0065bbe8  0fb65c2410           movzx ebx, byte ptr [esp + 0x10]
// 0065bbed  83fb04               cmp ebx, 4
// 0065bbf0  7c12                 jl 0x65bc04
// 0065bbf2  682ca6b800           push 0xb8a62c
// 0065bbf7  57                   push edi
// 0065bbf8  e86326ffff           call 0x64e260
// 0065bbfd  83c408               add esp, 8
// 0065bc00  5b                   pop ebx
// 0065bc01  5e                   pop esi
// 0065bc02  5f                   pop edi
// 0065bc03  c3                   ret 
// 0065bc04  85f6                 test esi, esi
// 0065bc06  0f8407010000         je 0x65bd13
// 0065bc0c  f6460801             test byte ptr [esi + 8], 1
// 0065bc10  7441                 je 0x65bc53
// 0065bc12  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0065bc18  3dc8af0000           cmp eax, 0xafc8
// 0065bc1d  7c07                 jl 0x65bc26
// 0065bc1f  3db0b30000           cmp eax, 0xb3b0
// 0065bc24  7e2d                 jle 0x65bc53
// 0065bc26  68bca3b800           push 0xb8a3bc
// 0065bc2b  57                   push edi
// 0065bc2c  e82f26ffff           call 0x64e260
// 0065bc31  8b8f34020000         mov ecx, dword ptr [edi + 0x234]
// 0065bc37  83c408               add esp, 8
// 0065bc3a  51                   push ecx
// 0065bc3b  680ca6b800           push 0xb8a60c
// 0065bc40  ff15c029b200         call dword ptr [0xb229c0]
// 0065bc46  83c040               add eax, 0x40
// 0065bc49  50                   push eax
// 0065bc4a  ff15a829b200         call dword ptr [0xb229a8]
// 0065bc50  83c40c               add esp, 0xc
// 0065bc53  f6460804             test byte ptr [esi + 8], 4
// 0065bc57  0f84b6000000         je 0x65bd13
// 0065bc5d  8b8600010000         mov eax, dword ptr [esi + 0x100]
// 0065bc63  3d3e760000           cmp eax, 0x763e
// 0065bc68  0f8c97000000         jl 0x65bd05
// 0065bc6e  3d0e7e0000           cmp eax, 0x7e0e
// 0065bc73  0f8f8c000000         jg 0x65bd05
// 0065bc79  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 0065bc7f  3d9c7c0000           cmp eax, 0x7c9c
// 0065bc84  7c7f                 jl 0x65bd05
// 0065bc86  3d6c840000           cmp eax, 0x846c
// 0065bc8b  7f78                 jg 0x65bd05
// 0065bc8d  8b8608010000         mov eax, dword ptr [esi + 0x108]
// 0065bc93  3d18f60000           cmp eax, 0xf618
// 0065bc98  7c6b                 jl 0x65bd05
// 0065bc9a  3de8fd0000           cmp eax, 0xfde8
// 0065bc9f  7f64                 jg 0x65bd05
// 0065bca1  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0065bca7  3d007d0000           cmp eax, 0x7d00
// 0065bcac  7c57                 jl 0x65bd05
// 0065bcae  3dd0840000           cmp eax, 0x84d0
// 0065bcb3  7f50                 jg 0x65bd05
// 0065bcb5  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0065bcbb  3d48710000           cmp eax, 0x7148
// 0065bcc0  7c43                 jl 0x65bd05
// 0065bcc2  3d18790000           cmp eax, 0x7918
// 0065bcc7  7f3c                 jg 0x65bd05
// 0065bcc9  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0065bccf  3d78e60000           cmp eax, 0xe678
// 0065bcd4  7c2f                 jl 0x65bd05
// 0065bcd6  3d48ee0000           cmp eax, 0xee48
// 0065bcdb  7f28                 jg 0x65bd05
// 0065bcdd  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0065bce3  3db0360000           cmp eax, 0x36b0
// 0065bce8  7c1b                 jl 0x65bd05
// 0065bcea  3d803e0000           cmp eax, 0x3e80
// 0065bcef  7f14                 jg 0x65bd05
// 0065bcf1  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0065bcf7  3d88130000           cmp eax, 0x1388
// 0065bcfc  7c07                 jl 0x65bd05
// 0065bcfe  3d581b0000           cmp eax, 0x1b58
// 0065bd03  7e0e                 jle 0x65bd13
// 0065bd05  6850a5b800           push 0xb8a550
// 0065bd0a  57                   push edi
// 0065bd0b  e85025ffff           call 0x64e260
// 0065bd10  83c408               add esp, 8
// 0065bd13  53                   push ebx
// 0065bd14  56                   push esi
// 0065bd15  57                   push edi
// 0065bd16  e8d5b1feff           call 0x646ef0
// 0065bd1b  83c40c               add esp, 0xc
// 0065bd1e  5b                   pop ebx
// 0065bd1f  5e                   pop esi
// 0065bd20  5f                   pop edi
// 0065bd21  c3                   ret 
// copied from an identical function in another client (function _png_handle_sRGB)

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