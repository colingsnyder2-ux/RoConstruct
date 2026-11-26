// from server: 100% by Xemicl
// roc 2012-06 0085da80  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085da80
//
// 0085da80  83ec18               sub esp, 0x18
// 0085da83  53                   push ebx
// 0085da84  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0085da88  55                   push ebp
// 0085da89  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0085da8d  56                   push esi
// 0085da8e  8bf1                 mov esi, ecx
// 0085da90  8b4620               mov eax, dword ptr [esi + 0x20]
// 0085da93  8b08                 mov ecx, dword ptr [eax]
// 0085da95  57                   push edi
// 0085da96  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0085da9a  85c9                 test ecx, ecx
// 0085da9c  7454                 je 0x85daf2
// 0085da9e  83fd01               cmp ebp, 1
// 0085daa1  754f                 jne 0x85daf2
// 0085daa3  396c243c             cmp dword ptr [esp + 0x3c], ebp
// 0085daa7  7549                 jne 0x85daf2
// 0085daa9  8b5610               mov edx, dword ptr [esi + 0x10]
// 0085daac  8b02                 mov eax, dword ptr [edx]
// 0085daae  2bc1                 sub eax, ecx
// 0085dab0  99                   cdq 
// 0085dab1  3bd3                 cmp edx, ebx
// 0085dab3  7f3d                 jg 0x85daf2
// 0085dab5  7c04                 jl 0x85dabb
// 0085dab7  3bc7                 cmp eax, edi
// 0085dab9  7737                 ja 0x85daf2
// 0085dabb  8b4630               mov eax, dword ptr [esi + 0x30]
// 0085dabe  8b00                 mov eax, dword ptr [eax]
// 0085dac0  99                   cdq 
// 0085dac1  3bda                 cmp ebx, edx
// 0085dac3  7f2d                 jg 0x85daf2
// 0085dac5  7c04                 jl 0x85dacb
// 0085dac7  3bf8                 cmp edi, eax
// 0085dac9  7727                 ja 0x85daf2
// 0085dacb  8b4630               mov eax, dword ptr [esi + 0x30]
// 0085dace  2938                 sub dword ptr [eax], edi
// 0085dad0  8b4620               mov eax, dword ptr [esi + 0x20]
// 0085dad3  0138                 add dword ptr [eax], edi
// 0085dad5  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0085dadb  6a01                 push 1
// 0085dadd  6a01                 push 1
// 0085dadf  6a00                 push 0
// 0085dae1  6a00                 push 0
// 0085dae3  51                   push ecx
// 0085dae4  83c640               add esi, 0x40
// 0085dae7  56                   push esi
// 0085dae8  8d542428             lea edx, [esp + 0x28]
// 0085daec  52                   push edx
// 0085daed  e8def1ffff           call 0x85ccd0
// 0085daf2  8b4624               mov eax, dword ptr [esi + 0x24]
// 0085daf5  833800               cmp dword ptr [eax], 0
// 0085daf8  7408                 je 0x85db02
// 0085dafa  8bce                 mov ecx, esi
// 0085dafc  ff158425b200         call dword ptr [0xb22584]
// 0085db02  83fd01               cmp ebp, 1
// 0085db05  7512                 jne 0x85db19
// 0085db07  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0085db0a  833900               cmp dword ptr [ecx], 0
// 0085db0d  740a                 je 0x85db19
// 0085db0f  8b5630               mov edx, dword ptr [esi + 0x30]
// 0085db12  8b02                 mov eax, dword ptr [edx]
// 0085db14  99                   cdq 
// 0085db15  2bf8                 sub edi, eax
// 0085db17  1bda                 sbb ebx, edx
// 0085db19  8b4610               mov eax, dword ptr [esi + 0x10]
// 0085db1c  c70000000000         mov dword ptr [eax], 0
// 0085db22  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0085db25  c70100000000         mov dword ptr [ecx], 0
// 0085db2b  8b5630               mov edx, dword ptr [esi + 0x30]
// 0085db2e  c70200000000         mov dword ptr [edx], 0
// 0085db34  8b4614               mov eax, dword ptr [esi + 0x14]
// 0085db37  c70000000000         mov dword ptr [eax], 0
// 0085db3d  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0085db40  c70100000000         mov dword ptr [ecx], 0
// 0085db46  8b5634               mov edx, dword ptr [esi + 0x34]
// 0085db49  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0085db4d  c70200000000         mov dword ptr [edx], 0
// 0085db53  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 0085db59  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0085db5d  50                   push eax
// 0085db5e  51                   push ecx
// 0085db5f  55                   push ebp
// 0085db60  53                   push ebx
// 0085db61  57                   push edi
// 0085db62  52                   push edx
// 0085db63  8d4e40               lea ecx, [esi + 0x40]
// 0085db66  e885f2ffff           call 0x85cdf0
// copied from an identical function in another client (function ?seek_impl@indirect_streambuf@@QAE?AV?$fpos@H@std@@_JHH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <streambuf>
#include <ios>
typedef __int64 stream_offset;
struct Next;
struct Adapter {
    __int64 align_;
    char pad[0x58];
    __declspec(noreturn) std::streampos seek(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which, Next* next);
};
__declspec(noreturn) std::streampos seek_filter(Adapter& t, Next& dev, stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which);
class indirect_streambuf : public std::basic_streambuf<char> {
public:
    Adapter obj_;
    Next* next_;
    std::streampos seek_impl(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which);
};
std::streampos indirect_streambuf::seek_impl(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which)
{
    if (gptr() != 0 && way == std::ios_base::cur && which == std::ios_base::in &&
        eback() - gptr() <= off && off <= egptr() - gptr())
    {
        gbump(static_cast<int>(off));
        return seek_filter(obj_, *next_, 0, std::ios_base::cur, std::ios_base::in) - static_cast<std::streamoff>(egptr() - gptr());
    }
    if (pptr() != 0)
        this->pubsync();
    if (way == std::ios_base::cur && gptr())
        off -= static_cast<std::streamoff>(egptr() - gptr());
    setg(0, 0, 0);
    setp(0, 0);
    return obj_.seek(off, way, which, next_);
}