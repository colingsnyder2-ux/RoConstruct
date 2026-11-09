// from server: 100% by colin
struct CXTPControlGallery
{
    CXTPControlGallery* Construct();
};

extern "C" void __fastcall sub_63d8c0(CXTPControlGallery* self);

CXTPControlGallery* CXTPControlGallery::Construct()
{
    sub_63d8c0(this);
    *(int*)((char*)this + 0x128) = 0;
    *(int*)((char*)this + 0x130) = 0;
    *(int*)((char*)this) = 0x7d652c;
    *(int*)((char*)this + 0x43c) = 0x12;
    return this;
}
