// from server: 100% by EspClaude
// roc 2007-08 005524f0  unit: std::D::V?$allocator::U?$basic_zlib_decompressor::?$stream_buffer  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005524f0
//
// 005524f0  51                   push ecx
// 005524f1  56                   push esi
// 005524f2  8bf1                 mov esi, ecx
// 005524f4  8b4620               mov eax, dword ptr [esi + 0x20]
// 005524f7  833800               cmp dword ptr [eax], 0
// 005524fa  7507                 jne 0x552503
// 005524fc  8b16                 mov edx, dword ptr [esi]
// 005524fe  8b4254               mov eax, dword ptr [edx + 0x54]
// 00552501  ffd0                 call eax
// 00552503  8b4620               mov eax, dword ptr [esi + 0x20]
// 00552506  8b08                 mov ecx, dword ptr [eax]
// 00552508  8b5630               mov edx, dword ptr [esi + 0x30]
// 0055250b  8b12                 mov edx, dword ptr [edx]
// 0055250d  03d1                 add edx, ecx
// 0055250f  3bca                 cmp ecx, edx
// 00552511  8bc1                 mov eax, ecx
// 00552513  7306                 jae 0x55251b
// 00552515  0fb600               movzx eax, byte ptr [eax]
// 00552518  5e                   pop esi
// 00552519  59                   pop ecx
// 0055251a  c3                   ret 
// 0055251b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0055251e  2b02                 sub eax, dword ptr [edx]
// 00552520  57                   push edi
// 00552521  394658               cmp dword ptr [esi + 0x58], eax
// 00552524  8d7e58               lea edi, [esi + 0x58]
// 00552527  89442408             mov dword ptr [esp + 8], eax
// 0055252b  8bc7                 mov eax, edi
// 0055252d  7c04                 jl 0x552533
// 0055252f  8d442408             lea eax, [esp + 8]
// 00552533  53                   push ebx
// 00552534  8b18                 mov ebx, dword ptr [eax]
// 00552536  85db                 test ebx, ebx
// 00552538  7416                 je 0x552550
// 0055253a  8b07                 mov eax, dword ptr [edi]
// 0055253c  53                   push ebx
// 0055253d  2bcb                 sub ecx, ebx
// 0055253f  51                   push ecx
// 00552540  2bc3                 sub eax, ebx
// 00552542  034650               add eax, dword ptr [esi + 0x50]
// 00552545  53                   push ebx
// 00552546  50                   push eax
// 00552547  ff1548e77700         call dword ptr [0x77e748]
// 0055254d  83c410               add esp, 0x10
// 00552550  8b0f                 mov ecx, dword ptr [edi]
// 00552552  8b5650               mov edx, dword ptr [esi + 0x50]
// 00552555  8d0411               lea eax, [ecx + edx]
// 00552558  8b5610               mov edx, dword ptr [esi + 0x10]
// 0055255b  8bc8                 mov ecx, eax
// 0055255d  2bcb                 sub ecx, ebx
// 0055255f  890a                 mov dword ptr [edx], ecx
// 00552561  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00552564  8901                 mov dword ptr [ecx], eax
// 00552566  8bd0                 mov edx, eax
// 00552568  2bd0                 sub edx, eax
// 0055256a  8b4630               mov eax, dword ptr [esi + 0x30]
// 0055256d  8910                 mov dword ptr [eax], edx
// 0055256f  8b17                 mov edx, dword ptr [edi]
// 00552571  8b4654               mov eax, dword ptr [esi + 0x54]
// 00552574  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 00552577  8b5e4c               mov ebx, dword ptr [esi + 0x4c]
// 0055257a  2bc2                 sub eax, edx
// 0055257c  03ca                 add ecx, edx
// 0055257e  50                   push eax
// 0055257f  51                   push ecx
// 00552580  53                   push ebx
// 00552581  8d4e40               lea ecx, [esi + 0x40]
// 00552584  e827d7ffff           call 0x54fcb0
// 00552589  83f8ff               cmp eax, -1
// 0055258c  5b                   pop ebx
// 0055258d  7506                 jne 0x552595
// 0055258f  c6463c01             mov byte ptr [esi + 0x3c], 1
// 00552593  33c0                 xor eax, eax
// 00552595  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00552598  8b11                 mov edx, dword ptr [ecx]
// 0055259a  8b0f                 mov ecx, dword ptr [edi]
// 0055259c  034e50               add ecx, dword ptr [esi + 0x50]
// 0055259f  5f                   pop edi
// 005525a0  03c8                 add ecx, eax
// 005525a2  2bca                 sub ecx, edx
// 005525a4  85c0                 test eax, eax
// 005525a6  8b5630               mov edx, dword ptr [esi + 0x30]
// 005525a9  890a                 mov dword ptr [edx], ecx
// 005525ab  740b                 je 0x5525b8
// 005525ad  8b4620               mov eax, dword ptr [esi + 0x20]
// 005525b0  8b08                 mov ecx, dword ptr [eax]
// 005525b2  0fb601               movzx eax, byte ptr [ecx]
// 005525b5  5e                   pop esi
// 005525b6  59                   pop ecx
// 005525b7  c3                   ret 
// 005525b8  83c8ff               or eax, 0xffffffff
// 005525bb  5e                   pop esi
// 005525bc  59                   pop ecx
// 005525bd  c3                   ret 

#include <streambuf>
#include <algorithm>

typedef std::char_traits<char> traits_type;

// object at +0x40 (12 bytes up to next_ at +0x4c); read is the direct call target
struct Adapter {
    int storage_[3];
    std::streamsize read(std::streambuf* next, char* s, std::streamsize n);
};

struct Buffer {
    char* buf_;
    std::streamsize size_;
    char* data() const { return buf_; }
    std::streamsize size() const { return size_; }
};

class linked_streambuf : public std::basic_streambuf<char> {
protected:
    virtual void set_next(std::streambuf* next);   // +0x38
    virtual void close_impl(int which);            // +0x3c
    virtual void v40();                            // +0x40
    virtual void v44();                            // +0x44
    virtual void v48();                            // +0x48
    virtual void v4c();                            // +0x4c
    virtual void v50();                            // +0x50
    virtual void init_get_area();                  // +0x54 (slot read from call [edx+0x54])
    void set_true_eof(bool eof) { flags_ = eof; }
    bool flags_;                                   // +0x3c
};

class indirect_streambuf : public linked_streambuf {
public:
    int_type underflow();
private:
    Adapter& obj() { return storage_; }
    Buffer& in() { return buffer_; }
    Adapter storage_;                              // +0x40
    std::streambuf* next_;                         // +0x4c
    Buffer buffer_;                                // +0x50
    int pback_size_;                               // +0x58
};

indirect_streambuf::int_type indirect_streambuf::underflow()
{
    using namespace std;
    if (!gptr()) init_get_area();
    Buffer& buf = in();
    if (gptr() < egptr()) return traits_type::to_int_type(*gptr());

    streamsize keep = (std::min)( static_cast<streamsize>(gptr() - eback()), pback_size_ );
    if (keep)
        traits_type::move( buf.data() + (pback_size_ - keep), gptr() - keep, keep );

    setg( buf.data() + pback_size_ - keep, buf.data() + pback_size_, buf.data() + pback_size_ );

    std::streambuf* next = next_;
    streamsize n = buf.size() - pback_size_;
    char* p = buf.data() + pback_size_;
    streamsize chars = obj().read(next, p, n);
    if (chars == -1) {
        this->set_true_eof(true);
        chars = 0;
    }
    setg(eback(), gptr(), buf.data() + pback_size_ + chars);
    return chars != 0 ?
        traits_type::to_int_type(*gptr()) :
        traits_type::eof();
}
