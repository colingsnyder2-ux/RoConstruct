// from server: 100% by colin
struct DescribedBase;

void* getPropValue(const DescribedBase* object);

void* RefPropDescriptor_getValue(const DescribedBase* object)
{
    void* result = getPropValue(object);
    if (result != 0) {
        void* p = *(void**)((char*)result + 0x138);
        if (p != 0) {
            return *(void**)((char*)p + 0x118);
        }
    }
    return 0;
}
