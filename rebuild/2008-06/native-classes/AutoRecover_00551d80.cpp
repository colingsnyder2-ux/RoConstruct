// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: No header for TextureProxy was provided, so this minimal class is declared locally.
// The `vector deleting destructor' (??_E) cannot be written directly in C++. The compiler
// generates it when the vtable is emitted. Defining the constructor here forces that emission.
// The destructor body (0x00551db0) is only declared, so the generated deleting destructor
// calls it out of line, as in the original.

namespace RBX {
namespace Render {

class TextureProxy {
public:
    TextureProxy();
    virtual ~TextureProxy();   // defined elsewhere (0x00551db0)
private:
    int pad_;
};

// INFERRED: the constructor exists only to emit the vtable and its deleting destructor in this file.
TextureProxy::TextureProxy()
    : pad_(0)
{
}

} // namespace Render
} // namespace RBX
