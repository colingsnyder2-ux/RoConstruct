// from server: 100% by tester
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /MD
struct TextureProxyBase
{
    void SetValue(float value);
};

void TextureProxyBase::SetValue(float value)
{
    *(float*)((char*)this + 0x2c) = value;
}
