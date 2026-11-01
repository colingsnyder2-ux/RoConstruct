// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// roc-lang: cpp
#include <stdexcept>
#include <string>
struct DeqX {
    static void _Xlen();
};
void DeqX::_Xlen()
{
    throw std::length_error("deque<T> too long");
}
