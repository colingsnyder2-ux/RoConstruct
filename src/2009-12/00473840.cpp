// from server: 100% by atomic.potato
extern "C" float* __cdecl getShaderVector();

struct DxUserInput
{
    float padding[26];

    void update();
};

void DxUserInput::update()
{
    float* value = getShaderVector();
    padding[26] = value[0];
    padding[27] = value[1];
}
