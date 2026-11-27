// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

#include <streambuf>
class Buf : public std::streambuf
{
public:
    virtual ~Buf();
    void close();
};
Buf::~Buf()
{
    close();
}
