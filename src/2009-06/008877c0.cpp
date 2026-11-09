// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 007f1980  unit: seg_007f0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f1980
//
// 007f1980  6a04                 push 4
// 007f1982  688cf08000           push 0x80f08c
// 007f1987  33c9                 xor ecx, ecx
// 007f1989  68dc2b8200           push 0x822bdc
// 007f198e  51                   push ecx
// 007f198f  b8d0e14900           mov eax, 0x49e1d0
// 007f1994  50                   push eax
// 007f1995  b958059700           mov ecx, 0x970558
// 007f199a  e89198caff           call 0x49b230
// 007f199f  6870b87f00           push 0x7fb870
// 007f19a4  e806feeaff           call 0x6a17af
// 007f19a9  59                   pop ecx
// 007f19aa  c3                   ret 

#include <string>

namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { AnyCaller, NeedTrustedCaller = 4 };
};

template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

namespace Network {
class Players : public Instance, public Service
{
public:
    void setAbuseReportUrl(std::string url);
};
}
}

using namespace RBX;

static Reflection::BoundFuncDesc<Network::Players, void(std::string), 1> func_setAbuseReportUrl(&Network::Players::setAbuseReportUrl, "SetAbuseReportUrl", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
