// from server: 88% by king_originala
int __stdcall function(void* value, void*)
{
    try {
        throw value;
    }
    catch (...) {
        return 1;
    }
}
