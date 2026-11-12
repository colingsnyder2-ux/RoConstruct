// from server: 100% by EspClaude
// from server: 54% by tester
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_c4172315f52c5d6b.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 0x456970: a constructor that runs an out-of-line base
// constructor (base occupies 0x58 bytes: member tree at this+0x58), stores its own
// vtable, then default-constructs a std::map member (VS2005 _Tree::_Init, node _Isnil at +0x15).
#include <map>

class RocBase0456970
{
public:
    RocBase0456970();
    virtual ~RocBase0456970();
private:
    char pad[0x58 - 4];
};

class RocView0456970 : public RocBase0456970
{
public:
    RocView0456970();
    virtual ~RocView0456970();
    std::map<int, int> items;
};

RocView0456970::RocView0456970()
{
}
