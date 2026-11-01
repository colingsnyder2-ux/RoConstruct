// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct ResizeTool {
    char pad[0x18];
    void* context;
    char tail[0x2c];

    ResizeTool(void*);
    ResizeTool* clone();
};

ResizeTool* ResizeTool::clone()
{
    return new ResizeTool(context);
}
