// from server: 100% by colin
struct LuaWriter {
    void writeString(int arg);
};

extern LuaWriter g_luaWriter;

void func_0046dce0(int arg)
{
    g_luaWriter.writeString(arg);
}
