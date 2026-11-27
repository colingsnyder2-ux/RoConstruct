// from server: 99% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <streambuf>
struct Opt { bool flag; char pad2[7]; char* buf; unsigned size; ~Opt() { if (buf) std::allocator<char>().deallocate(buf, size); if (flag) flag = false; } };
struct S {
    std::streambuf sb;
    char pad[0x48 - sizeof(std::streambuf)];
    Opt o;
    ~S();
};
S::~S() {}
