// from server: 94% by atomic.potato
extern "C" void __stdcall FactoryProductCreator(int, int);

void FactoryProductCreatorThunk()
{
    FactoryProductCreator(0, 0);
}
