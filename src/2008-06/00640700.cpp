// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Tool {
    char storage[0x74];
    Tool(void*);
};

struct AxisMoveTool {
    char padding[0x18];
    void* context;
    Tool* clone();
};

Tool* AxisMoveTool::clone() {
    return new Tool(context);
}
