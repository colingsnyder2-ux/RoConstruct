// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2007-08 00551a20  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00551a20
//
// 00551a20  56                   push esi
// 00551a21  8bf1                 mov esi, ecx
// 00551a23  8b4614               mov eax, dword ptr [esi + 0x14]
// 00551a26  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00551a29  8b00                 mov eax, dword ptr [eax]
// 00551a2b  57                   push edi
// 00551a2c  8b39                 mov edi, dword ptr [ecx]
// 00551a2e  2bf8                 sub edi, eax
// 00551a30  85ff                 test edi, edi
// 00551a32  7e5e                 jle 0x551a92
// 00551a34  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00551a37  57                   push edi
// 00551a38  50                   push eax
// 00551a39  51                   push ecx
// 00551a3a  8d4e40               lea ecx, [esi + 0x40]
// 00551a3d  e80ec3ffff           call 0x54dd50
// 00551a42  3bc7                 cmp eax, edi
// 00551a44  751c                 jne 0x551a62
// 00551a46  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 00551a49  8b5614               mov edx, dword ptr [esi + 0x14]
// 00551a4c  8b4654               mov eax, dword ptr [esi + 0x54]
// 00551a4f  890a                 mov dword ptr [edx], ecx
// 00551a51  8b5624               mov edx, dword ptr [esi + 0x24]
// 00551a54  03c1                 add eax, ecx
// 00551a56  890a                 mov dword ptr [edx], ecx
// 00551a58  2bc1                 sub eax, ecx
// 00551a5a  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00551a5d  5f                   pop edi
// 00551a5e  8901                 mov dword ptr [ecx], eax
// 00551a60  5e                   pop esi
// 00551a61  c3                   ret 
// 00551a62  8b5624               mov edx, dword ptr [esi + 0x24]
// 00551a65  8b3a                 mov edi, dword ptr [edx]
// 00551a67  8b5650               mov edx, dword ptr [esi + 0x50]
// 00551a6a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00551a6d  034e50               add ecx, dword ptr [esi + 0x50]
// 00551a70  03d0                 add edx, eax
// 00551a72  8b4614               mov eax, dword ptr [esi + 0x14]
// 00551a75  8910                 mov dword ptr [eax], edx
// 00551a77  8b4624               mov eax, dword ptr [esi + 0x24]
// 00551a7a  8910                 mov dword ptr [eax], edx
// 00551a7c  2bca                 sub ecx, edx
// 00551a7e  8b5634               mov edx, dword ptr [esi + 0x34]
// 00551a81  890a                 mov dword ptr [edx], ecx
// 00551a83  8b4624               mov eax, dword ptr [esi + 0x24]
// 00551a86  2b38                 sub edi, dword ptr [eax]
// 00551a88  8b4634               mov eax, dword ptr [esi + 0x34]
// 00551a8b  2938                 sub dword ptr [eax], edi
// 00551a8d  8b7624               mov esi, dword ptr [esi + 0x24]
// 00551a90  013e                 add dword ptr [esi], edi
// 00551a92  5f                   pop edi

// boost::iostreams indirect_streambuf::sync_impl shape on VS2005 std::streambuf
// (pbase/pptr/pcount indirections at +0x14/+0x24/+0x34 as the target reads them).
#include <streambuf>

struct Device
{
    int write(void* next, const char* s, int n);   // thiscall on this+0x40, 3 args
};

struct Buffer
{
    char* data;   // +0x50
    int size;     // +0x54
    char* begin() const { return data; }
    char* end() const { return data + size; }
};

struct IndirectStreambuf : std::streambuf
{
    char pad3c[0x40 - sizeof(std::streambuf)];
    Device obj;           // +0x40
    char pad41[0x4c - 0x41];
    void* next_;          // +0x4c
    Buffer out;           // +0x50
    void sync_impl();
    void* next() const { return next_; }
    Device& dev() { return obj; }
};

void IndirectStreambuf::sync_impl()
{
    int avail, amt;
    if ((avail = (int)(pptr() - pbase())) > 0) {
        if ((amt = dev().write(next(), pbase(), avail)) == avail)
            setp(out.begin(), out.end());
        else {
            char* ptr = pptr();
            setp(out.begin() + amt, out.end());
            pbump((int)(ptr - pptr()));
        }
    }
}
