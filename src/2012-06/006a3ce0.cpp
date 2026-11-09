// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp

extern "C" void* helper1(void*, int, int);
extern "C" void* helper2(void*, int, void*);
extern "C" void helper3(void*, void*, void*);

extern void* global_ptr;

int func(void* esi)
{
    void* edi = helper1(esi, 2, 0);
    void* tmp = helper2(esi, 1, global_ptr);
    helper3(tmp, edi, esi);
    return 0;
}