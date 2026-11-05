// from server: 54% by atomic.potato
struct ModelSetFrontTool
{
    void f(int, int*, int*, int*);
};

void ModelSetFrontTool::f(int a, int* b, int* c, int* d)
{
    *(int*)((char*)this + 4) = a;
    *(int*)((char*)this + 8) = *c;
    *(int*)((char*)this + 12) = *b;
    *(int*)((char*)this + 16) = *d;
    *(int*)this = 0xBE0668;
}
