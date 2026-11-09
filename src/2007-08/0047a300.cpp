// from server: 84% by colin
// roc 2007-08 0047a300  unit: G3D::TextureManager::TextureArgs  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0047a300
//
// 0047a300  e819671b00           call 0x630a1e
// 0047a305  83c450               add esp, 0x50
// 0047a308  c22000               ret 0x20

extern "C" void __cdecl helper_630a1e();

struct TextureArgs
{
    void run(int a, int b, int c, int d, int e, int f, int g, int h);
};

void TextureArgs::run(int a, int b, int c, int d, int e, int f, int g, int h)
{
    helper_630a1e();
}
