// from server: 100% by EspClaude
// roc 2007-08 0046a9d0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 34 bytes
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
struct E { int v[16]; };
extern template class std::vector<E>;
class LDraw2RobloxMapRoot {
public:
    char pad[0x5c];
    std::vector<E> items;
    const E* first() const;
};

const E* LDraw2RobloxMapRoot::first() const
{
    if (items.size() != 0)
        return &items.at(0);
    return 0;
}
