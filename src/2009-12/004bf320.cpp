// from server: 50% by atomic.potato
extern "C" void* __stdcall Ogre_Node_removeChild(void* node, unsigned int);

struct S_func_004bf320
{
    void* m_node;
    void f(void*);
};

void S_func_004bf320::f(void* child)
{
    void* result = Ogre_Node_removeChild(m_node, 4);
    m_node = result;
}
