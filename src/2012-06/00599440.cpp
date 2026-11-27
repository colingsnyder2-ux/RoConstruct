// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

namespace RakNet {
template <class Type> Type* OP_NEW(const char *file, unsigned int line);
class StringCompressor {
public:
    static void AddReference(void);
    static StringCompressor *instance;
    static int referenceCount;
};
StringCompressor* StringCompressor::instance=0;
int StringCompressor::referenceCount=0;
void StringCompressor::AddReference(void)
{
    if (++referenceCount==1)
    {
        instance = RakNet::OP_NEW<StringCompressor>( "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\StringCompressor.cpp", 30 );
    }
}
}
