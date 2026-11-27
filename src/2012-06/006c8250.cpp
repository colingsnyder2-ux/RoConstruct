// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <exception>
class depth_exceed : public std::exception
{
public:
    depth_exceed(const depth_exceed& other);
    virtual ~depth_exceed() throw();
    bool flag;
};
depth_exceed::depth_exceed(const depth_exceed& other)
    : std::exception(other), flag(other.flag)
{
}
