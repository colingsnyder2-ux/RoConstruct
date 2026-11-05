// roc 2012-06 00744310  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744310
//
// 00744310  56                   push esi
// 00744311  57                   push edi
// 00744312  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00744316  57                   push edi
// 00744317  8bf1                 mov esi, ecx
// 00744319  ff15282ab200         call dword ptr [0xb22a28]
// 0074431f  c7067ca8ba00         mov dword ptr [esi], 0xbaa87c
// 00744325  8b470c               mov eax, dword ptr [edi + 0xc]
// 00744328  89460c               mov dword ptr [esi + 0xc], eax
// 0074432b  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0074432e  5f                   pop edi
// 0074432f  894e10               mov dword ptr [esi + 0x10], ecx
// 00744332  8bc6                 mov eax, esi
// 00744334  5e                   pop esi
// 00744335  c20400               ret 4
// copied from an identical function in another client (function ??0format_error@@QAE@ABU0@@Z)

// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 100% by tajop
namespace std
{
class exception
{
public:
    __declspec(dllimport) exception(const exception &);
    __declspec(dllimport) virtual ~exception();
private:
    const char *_m_what;
    int _m_doFree;
};
}

struct format_error : public std::exception
{
    format_error(const format_error &o);
    unsigned int cur_;
    unsigned int expected_;
};

format_error::format_error(const format_error &o)
    : std::exception(o), cur_(o.cur_), expected_(o.expected_)
{
}