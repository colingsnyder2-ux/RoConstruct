// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdexcept>
typedef void* HANDLE;
struct GdiObject {
 HANDLE handle;
 GdiObject():handle(0){}
 virtual ~GdiObject(){DeleteObject();}
 int Attach(HANDLE);
 int DeleteObject();
};
struct Bitmap:GdiObject {};
struct ImageList {
 virtual ~ImageList();
 HANDLE handle;
 ImageList();
 int Create(int,int,unsigned,int,int);
};
struct ImageManager {
 int add(HANDLE,HANDLE,HANDLE);
 int addMasked(HANDLE,HANDLE,unsigned);
};
struct ModuleState {char prefix[0x94];ImageManager** manager;};
extern "C" ModuleState* __stdcall GetModuleState();
struct CXTPImageManagerIcon {static HANDLE __cdecl LoadBitmapFromResource(const char*,int*);};
struct CClassImages:ImageList {
 CClassImages();
 virtual ~CClassImages();
};
CClassImages::CClassImages(){
 int alpha=0;
 HANDLE loaded=CXTPImageManagerIcon::LoadBitmapFromResource((const char*)133,&alpha);
 Bitmap bitmap;
 bitmap.Attach(loaded);
 if(alpha){
  if(!Create(16,16,32,0,0))throw std::runtime_error("Unable to create CClassImages");
  HANDLE bitmapHandle=bitmap.handle;
  HANDLE listHandle=handle;
  if((*GetModuleState()->manager)->add(listHandle,bitmapHandle,bitmapHandle)==-1)
   throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
 }else{
  if(!Create(16,16,0xff,0,0))throw std::runtime_error("Unable to create CClassImages");
  HANDLE bitmapHandle=bitmap.handle;
  HANDLE listHandle=handle;
  if((*GetModuleState()->manager)->addMasked(listHandle,bitmapHandle,0xff00ff)==-1)
   throw std::runtime_error("Unable to add IDB_CLASSIMAGES");
 }
}
