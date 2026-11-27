// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

#include <algorithm>
namespace Ogre {
enum SharedPtrFreeMethod { SPFM_DELETE, SPFM_DELETE_T, SPFM_FREE };
class AnimableValue;
template <class T> class SharedPtr {
protected:
    T* pRep;
    unsigned int* pUseCount;
    SharedPtrFreeMethod useFreeMethod;
public:
    mutable void* mutex;
    virtual ~SharedPtr();
protected:
    virtual void swap(SharedPtr<T>& other)
    {
        std::swap(pRep, other.pRep);
        std::swap(pUseCount, other.pUseCount);
        std::swap(useFreeMethod, other.useFreeMethod);
        std::swap(mutex, other.mutex);
    }
};
template class SharedPtr<AnimableValue>;
}
