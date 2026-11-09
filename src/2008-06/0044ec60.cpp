// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>

namespace RBX {
class BrickColor {
public:
    int number;
    static const std::vector<BrickColor>& colorPalette();
};
}

class PartA {
public:
    virtual ~PartA();
    char pad[0x1c];
};
class PartB {
public:
    virtual void onB();
};

class ControlBase : public PartA, public PartB {
public:
    ControlBase();
    virtual ~ControlBase();
    void SetFlags(unsigned flags);
    char pad[0x174 - 0x24];
};

struct ColorEntry {
    int a, b, c;
};

class CRobloxControlColorSelector : public ControlBase {
public:
    int m_174;
    int m_178;
    bool m_17c;
    int m_180;
    CRobloxControlColorSelector();
    virtual ~CRobloxControlColorSelector();
    virtual void onB();
    static std::vector<ColorEntry> colors;
    static void addColor(RBX::BrickColor color);
};

CRobloxControlColorSelector::CRobloxControlColorSelector()
    : m_17c(false)
{
    if (colors.empty())
        std::for_each(RBX::BrickColor::colorPalette().begin(), RBX::BrickColor::colorPalette().end(), &addColor);
    m_174 = -1;
    m_180 = -1;
    SetFlags(0x10);
    m_178 = -1;
}
