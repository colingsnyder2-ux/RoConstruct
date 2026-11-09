// from server: 55% by atomic.potato
struct RBX_ViewRbxGfx {
    char pad[0x3c];
    struct Value {
        void* field[8];
    };
    Value* m_value;
    void* getValue();
};

void* RBX_ViewRbxGfx::getValue()
{
    return m_value->field[7];
}
