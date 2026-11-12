// from server: 100% by EspClaude
// roc 2007-08 0046b1a0  unit: RBX::LDraw2Lua::LuaObjectWriter  size: 86 bytes
// Destructor: derived vtable store, std::string member at +0x70 destroyed via
// msvcp80 import, then base vtable store.
#include <string>

namespace RBX { namespace LDraw2Lua {

class ObjectWriter
{
public:
    virtual ~ObjectWriter() {}
};

class LuaObjectWriter : public ObjectWriter
{
    char pad04[0x6c];
    std::string text;   // +0x70
public:
    virtual ~LuaObjectWriter();
};

LuaObjectWriter::~LuaObjectWriter()
{
}

}}
