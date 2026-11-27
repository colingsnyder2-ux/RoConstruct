// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
namespace RBX { namespace Profiling {
class Profiler {
    char pad[0x8c];
    std::vector<int>* buckets;
public:
    int getBucket(unsigned int index);
};
int Profiler::getBucket(unsigned int index)
{
    if (index >= buckets->size())
        return -1;
    return (*buckets)[index];
}
} }