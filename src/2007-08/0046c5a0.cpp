// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0046c5a0  unit: RBX::LDraw2Lua::LuaWriter  size: 545 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046c5a0
//
// 0046c5a0  83ec24               sub esp, 0x24
// 0046c5a3  53                   push ebx
// 0046c5a4  55                   push ebp
// 0046c5a5  56                   push esi
// 0046c5a6  57                   push edi
// 0046c5a7  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0046c5ab  8d44241c             lea eax, [esp + 0x1c]
// 0046c5af  50                   push eax
// 0046c5b0  8bcf                 mov ecx, edi
// 0046c5b2  ff1580e57700         call dword ptr [0x77e580]
// 0046c5b8  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0046c5bc  8d4c2414             lea ecx, [esp + 0x14]
// 0046c5c0  51                   push ecx
// 0046c5c1  8bcd                 mov ecx, ebp
// 0046c5c3  ff1580e57700         call dword ptr [0x77e580]
// 0046c5c9  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 0046c5cf  90                   nop 
// 0046c5d0  8d542424             lea edx, [esp + 0x24]
// 0046c5d4  52                   push edx
// 0046c5d5  8bcf                 mov ecx, edi
// 0046c5d7  ff1584e57700         call dword ptr [0x77e584]
// 0046c5dd  8bf0                 mov esi, eax
// 0046c5df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046c5e3  83f8fe               cmp eax, -2
// 0046c5e6  740a                 je 0x46c5f2
// 0046c5e8  85c0                 test eax, eax
// 0046c5ea  7404                 je 0x46c5f0
// 0046c5ec  3b06                 cmp eax, dword ptr [esi]
// 0046c5ee  7402                 je 0x46c5f2
// 0046c5f0  ffd3                 call ebx
// 0046c5f2  8b442420             mov eax, dword ptr [esp + 0x20]
// 0046c5f6  3b4604               cmp eax, dword ptr [esi + 4]
// 0046c5f9  0f8492010000         je 0x46c791
// 0046c5ff  8d4c242c             lea ecx, [esp + 0x2c]
// 0046c603  51                   push ecx
// 0046c604  8bcd                 mov ecx, ebp
// 0046c606  ff1584e57700         call dword ptr [0x77e584]
// 0046c60c  8bf0                 mov esi, eax
// 0046c60e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046c612  83f8fe               cmp eax, -2
// 0046c615  740e                 je 0x46c625
// 0046c617  85c0                 test eax, eax
// 0046c619  7404                 je 0x46c61f
// 0046c61b  3b06                 cmp eax, dword ptr [esi]
// 0046c61d  7406                 je 0x46c625
// 0046c61f  ffd3                 call ebx
// 0046c621  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046c625  8b542418             mov edx, dword ptr [esp + 0x18]
// 0046c629  3b5604               cmp edx, dword ptr [esi + 4]
// 0046c62c  0f845f010000         je 0x46c791
// 0046c632  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c636  83f9fe               cmp ecx, -2
// 0046c639  7423                 je 0x46c65e
// 0046c63b  85c9                 test ecx, ecx
// 0046c63d  7506                 jne 0x46c645
// 0046c63f  ffd3                 call ebx
// 0046c641  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c645  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c64b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c64f  034114               add eax, dword ptr [ecx + 0x14]
// 0046c652  39442420             cmp dword ptr [esp + 0x20], eax
// 0046c656  7202                 jb 0x46c65a
// 0046c658  ffd3                 call ebx
// 0046c65a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046c65e  83f8fe               cmp eax, -2
// 0046c661  8b742420             mov esi, dword ptr [esp + 0x20]
// 0046c665  7421                 je 0x46c688
// 0046c667  85c0                 test eax, eax
// 0046c669  7506                 jne 0x46c671
// 0046c66b  ffd3                 call ebx
// 0046c66d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046c671  8bc8                 mov ecx, eax
// 0046c673  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c679  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046c67d  034214               add eax, dword ptr [edx + 0x14]
// 0046c680  39442418             cmp dword ptr [esp + 0x18], eax
// 0046c684  7202                 jb 0x46c688
// 0046c686  ffd3                 call ebx
// 0046c688  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046c68c  0fbe08               movsx ecx, byte ptr [eax]
// 0046c68f  51                   push ecx
// 0046c690  ff1590e97700         call dword ptr [0x77e990]
// 0046c696  0fbe16               movsx edx, byte ptr [esi]
// 0046c699  52                   push edx
// 0046c69a  89442418             mov dword ptr [esp + 0x18], eax
// 0046c69e  ff1590e97700         call dword ptr [0x77e990]
// 0046c6a4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046c6a8  83c408               add esp, 8
// 0046c6ab  3bc1                 cmp eax, ecx
// 0046c6ad  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c6b1  755e                 jne 0x46c711
// 0046c6b3  83f9fe               cmp ecx, -2
// 0046c6b6  741f                 je 0x46c6d7
// 0046c6b8  85c9                 test ecx, ecx
// 0046c6ba  7506                 jne 0x46c6c2
// 0046c6bc  ffd3                 call ebx
// 0046c6be  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c6c2  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c6c8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c6cc  034114               add eax, dword ptr [ecx + 0x14]
// 0046c6cf  39442420             cmp dword ptr [esp + 0x20], eax
// 0046c6d3  7202                 jb 0x46c6d7
// 0046c6d5  ffd3                 call ebx
// 0046c6d7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046c6db  be01000000           mov esi, 1
// 0046c6e0  01742420             add dword ptr [esp + 0x20], esi
// 0046c6e4  83f9fe               cmp ecx, -2
// 0046c6e7  741f                 je 0x46c708
// 0046c6e9  85c9                 test ecx, ecx
// 0046c6eb  7506                 jne 0x46c6f3
// 0046c6ed  ffd3                 call ebx
// 0046c6ef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046c6f3  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c6f9  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046c6fd  034214               add eax, dword ptr [edx + 0x14]
// 0046c700  39442418             cmp dword ptr [esp + 0x18], eax
// 0046c704  7202                 jb 0x46c708
// 0046c706  ffd3                 call ebx
// 0046c708  01742418             add dword ptr [esp + 0x18], esi
// 0046c70c  e9bffeffff           jmp 0x46c5d0
// 0046c711  83f9fe               cmp ecx, -2
// 0046c714  741f                 je 0x46c735
// 0046c716  85c9                 test ecx, ecx
// 0046c718  7506                 jne 0x46c720
// 0046c71a  ffd3                 call ebx
// 0046c71c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c720  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c726  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046c72a  034114               add eax, dword ptr [ecx + 0x14]
// 0046c72d  39442420             cmp dword ptr [esp + 0x20], eax
// 0046c731  7202                 jb 0x46c735
// 0046c733  ffd3                 call ebx
// 0046c735  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046c739  83f9fe               cmp ecx, -2
// 0046c73c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046c740  741f                 je 0x46c761
// 0046c742  85c9                 test ecx, ecx
// 0046c744  7506                 jne 0x46c74c
// 0046c746  ffd3                 call ebx
// 0046c748  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046c74c  ff15e8e57700         call dword ptr [0x77e5e8]
// 0046c752  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046c756  034214               add eax, dword ptr [edx + 0x14]
// 0046c759  39442418             cmp dword ptr [esp + 0x18], eax
// 0046c75d  7202                 jb 0x46c761
// 0046c75f  ffd3                 call ebx
// 0046c761  0fbe07               movsx eax, byte ptr [edi]
// 0046c764  8b3d90e97700         mov edi, dword ptr [0x77e990]
// 0046c76a  8b742418             mov esi, dword ptr [esp + 0x18]
// 0046c76e  50                   push eax
// 0046c76f  ffd7                 call edi
// 0046c771  0fbe0e               movsx ecx, byte ptr [esi]
// 0046c774  51                   push ecx
// 0046c775  8bd8                 mov ebx, eax
// 0046c777  ffd7                 call edi
// 0046c779  83c408               add esp, 8
// 0046c77c  33d2                 xor edx, edx
// 0046c77e  3bd8                 cmp ebx, eax
// 0046c780  0f9dc2               setge dl
// 0046c783  5f                   pop edi
// 0046c784  5e                   pop esi
// 0046c785  5d                   pop ebp
// 0046c786  5b                   pop ebx
// 0046c787  8d5412ff             lea edx, [edx + edx - 1]
// 0046c78b  8bc2                 mov eax, edx
// 0046c78d  83c424               add esp, 0x24
// 0046c790  c3                   ret 
// 0046c791  8bcf                 mov ecx, edi
// 0046c793  ff154ce67700         call dword ptr [0x77e64c]
// 0046c799  8bcd                 mov ecx, ebp
// 0046c79b  8bf0                 mov esi, eax
// 0046c79d  ff154ce67700         call dword ptr [0x77e64c]
// 0046c7a3  3bf0                 cmp esi, eax
// 0046c7a5  750a                 jne 0x46c7b1
// 0046c7a7  5f                   pop edi
// 0046c7a8  5e                   pop esi
// 0046c7a9  5d                   pop ebp
// 0046c7aa  33c0                 xor eax, eax
// 0046c7ac  5b                   pop ebx
// 0046c7ad  83c424               add esp, 0x24
// 0046c7b0  c3                   ret 
// 0046c7b1  5f                   pop edi
// 0046c7b2  1bc0                 sbb eax, eax
// 0046c7b4  5e                   pop esi
// 0046c7b5  83e0fe               and eax, 0xfffffffe
// 0046c7b8  5d                   pop ebp
// 0046c7b9  83c001               add eax, 1
// 0046c7bc  5b                   pop ebx
// 0046c7bd  83c424               add esp, 0x24
// 0046c7c0  c3                   ret 

// from server: 100% by EspClaude
// roc 2008-06 0046f9f0  size: 543 bytes
// roc-cl: 50727
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
extern "C" __declspec(dllimport) int __cdecl toupper(int c);

namespace rs {
template <class T> class basic_str;

template <class T> class citer {
public:
    typedef basic_str<T> S;
    const S* _Mycont;
    const T* _Myptr;
    citer() { _Myptr = 0; }
    const T& operator*() const
    {
        if (_Mycont != (const S*)-2) {
            if (!(_Mycont != 0)) _invalid_parameter_noinfo();
            if (!(_Myptr < (((S*)_Mycont)->_Myptr() + _Mycont->_Mysize))) _invalid_parameter_noinfo();
        }
        return *_Myptr;
    }
    citer& operator++()
    {
        if (_Mycont != (const S*)-2) {
            if (!(_Mycont != 0)) _invalid_parameter_noinfo();
            if (!(_Myptr < (((S*)_Mycont)->_Myptr() + _Mycont->_Mysize))) _invalid_parameter_noinfo();
        }
        ++_Myptr;
        return *this;
    }
    bool operator==(const citer& r) const
    {
        if (_Mycont != (const S*)-2) {
            if (!(_Mycont != 0 && _Mycont == r._Mycont)) _invalid_parameter_noinfo();
        }
        return _Myptr == r._Myptr;
    }
    bool operator!=(const citer& r) const { return !(*this == r); }
};

template <class T> class basic_str {
public:
    typedef citer<T> const_iterator;
    void* _Myaux;
    union { T _Buf[16]; T* _Ptr; } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    __declspec(noinline) const_iterator begin() const { const_iterator i; i._Mycont = this; i._Myptr = _Bx._Ptr; return i; }
    __declspec(noinline) const_iterator end() const { const_iterator i; i._Mycont = this; i._Myptr = _Bx._Ptr + _Mysize; return i; }
    __declspec(noinline) unsigned int size() const { return _Mysize; }
    __declspec(noinline) T* _Myptr() { return _Bx._Ptr; }
};
extern template class __declspec(dllimport) basic_str<char>;
typedef basic_str<char> string;
}

int stringCompareNoCase(const rs::string& s1, const rs::string& s2)
{
    rs::string::const_iterator it1 = s1.begin();
    rs::string::const_iterator it2 = s2.begin();
    while ((it1 != s1.end()) && (it2 != s2.end())) {
        if (::toupper(*it1) != ::toupper(*it2))
            return (::toupper(*it1) < ::toupper(*it2)) ? -1 : 1;
        ++it1;
        ++it2;
    }
    unsigned int size1 = s1.size(), size2 = s2.size();
    if (size1 == size2)
        return 0;
    return (size1 < size2) ? -1 : 1;
}
