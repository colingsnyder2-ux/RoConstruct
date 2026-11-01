// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Item {
    std::string name;
    int value;
};
class ExeObj {
    char pad[0xdc];
    Item item;
public:
    Item getItem() const;
};
Item ExeObj::getItem() const { return item; }
}
