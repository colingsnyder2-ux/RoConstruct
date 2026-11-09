// from server: 70% by atomic.potato
struct Ray
{
    Ray* function_004e0750();
};

extern "C" void* __stdcall function_0061eb10(Ray*);
extern "C" void __stdcall function_004dd450(Ray*, void*, int, int);

Ray* Ray::function_004e0750()
{
    void* value = function_0061eb10(this);
    function_004dd450(this, &value, 6, 1);
    return this;
}
