// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local layouts of the libjpeg structs (j_common_struct, jpeg_memory_mgr),
// only the members this function reads: cinfo->mem at +4, mem->max_memory_to_use at +0x2c.
struct jpeg_memory_mgr_local {
    char pad[0x2c];
    long max_memory_to_use;
};

struct jpeg_common_local {
    void* err;
    jpeg_memory_mgr_local* mem;
};

// INFERRED: real name is jpeg_mem_available (jmemansi.c); using the fn_<addr> convention for the unnamed target.
extern "C" long fn_00530780(jpeg_common_local* cinfo, long min_bytes_needed,
                            long max_bytes_needed, long already_allocated)
{
    return cinfo->mem->max_memory_to_use - already_allocated;
}
