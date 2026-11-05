// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// roc-lang: cpp
#include <stdexcept>
#include <string>
struct VecX {
    static void _Xlen();
};
void VecX::_Xlen()
{
    throw std::length_error("vector<T> too long");
}
