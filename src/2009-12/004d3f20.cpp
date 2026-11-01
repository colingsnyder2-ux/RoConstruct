// from server: 85% by atomic.potato
extern "C" void __cdecl TextureArgsCall(void*, void*);

struct TextureArgs
{
};

void __cdecl f(void* value)
{
    TextureArgsCall((void*)0x00b11034, value);
}
