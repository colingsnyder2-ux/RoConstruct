// from server: 31% by atomic.potato
struct ModelSetFrontTool
{
    void f(void*, void*, void*, void*);
};

void ModelSetFrontTool::f(void* a, void* b, void* c, void* d)
{
    *(unsigned long*)((char*)this + 4) = (unsigned long)a;
    *(unsigned long*)this = 0x00be0658;
    *(unsigned long*)((char*)this + 8) = (unsigned long)c;
    *(unsigned long*)((char*)this + 12) = *(unsigned long*)b;
    *(unsigned long*)((char*)this + 16) = *(unsigned long*)d;
    *(unsigned long*)this = 0x00be0678;
}
