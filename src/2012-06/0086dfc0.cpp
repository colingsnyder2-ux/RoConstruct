// from server: 76% by atomic.potato
extern "C" int __stdcall sub_004be3e0(void*);

struct GeometryService {
    int padding[33];
    void* field_84;
    void set(void* value);
};

void GeometryService::set(void* value)
{
    field_84 = 0;
    if (value != 0)
        field_84 = (void*)sub_004be3e0(value);
}
