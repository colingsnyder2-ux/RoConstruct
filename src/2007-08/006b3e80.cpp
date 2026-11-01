// from server: 100% by colin
struct CXTPControlGallery {
    void sub_6B3D90(int, int);
    void OnGalleryChanged(int, int);
    char pad[0x1ec];
    int m_nGallery;
};

void CXTPControlGallery::OnGalleryChanged(int, int)
{
    if (m_nGallery != 0)
    {
        m_nGallery = 0;
        sub_6B3D90(0, 1);
        (*(void (__thiscall **)(CXTPControlGallery *))(*(int *)this + 0x98))(this);
    }
}
