// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>

namespace RBX {
namespace RenderNew {

// INFERRED: the layout comes from the disassembly. std::exception occupies
// offsets 0..0xb and a std::string sits at +0xc. The vector deleting
// destructor is compiler-generated from this class's virtual destructor.
class BadConversion : public std::exception
{
public:
    std::string message;

    explicit BadConversion(const std::string& m) : std::exception(), message(m) {}
    virtual ~BadConversion() {}
};

// INFERRED: a helper that instantiates the class so the vtable and the
// vector deleting destructor are emitted in this translation unit.
BadConversion* makeBadConversion(const std::string& m)
{
    return new BadConversion(m);
}

} // namespace RenderNew
} // namespace RBX
