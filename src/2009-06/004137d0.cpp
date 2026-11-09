// from server: 100% by EspClaude
// roc 2009-06 004137d0  unit: CRbxChildFrame  size: 455 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004137d0
//
// 004137d0  6aff                 push -1
// 004137d2  6874d88400           push 0x84d874
// 004137d7  64a100000000         mov eax, dword ptr fs:[0]
// 004137dd  50                   push eax
// 004137de  64892500000000       mov dword ptr fs:[0], esp
// 004137e5  83ec54               sub esp, 0x54
// 004137e8  53                   push ebx
// 004137e9  56                   push esi
// 004137ea  8bf1                 mov esi, ecx
// 004137ec  8974240c             mov dword ptr [esp + 0xc], esi
// 004137f0  e8f3593000           call 0x7191e8
// 004137f5  8d442408             lea eax, [esp + 8]
// 004137f9  50                   push eax
// 004137fa  33db                 xor ebx, ebx
// 004137fc  6885000000           push 0x85
// 00413801  895c246c             mov dword ptr [esp + 0x6c], ebx
// 00413805  c70628f68a00         mov dword ptr [esi], 0x8af628
// 0041380b  895c2410             mov dword ptr [esp + 0x10], ebx
// 0041380f  e8dc113200           call 0x7349f0
// 00413814  83c408               add esp, 8
// 00413817  895c2414             mov dword ptr [esp + 0x14], ebx
// 0041381b  c744241064f68a00     mov dword ptr [esp + 0x10], 0x8af664
// 00413823  50                   push eax
// 00413824  8d4c2414             lea ecx, [esp + 0x14]
// 00413828  c644246801           mov byte ptr [esp + 0x68], 1
// 0041382d  e8d0573000           call 0x719002
// 00413832  53                   push ebx
// 00413833  8bce                 mov ecx, esi
// 00413835  53                   push ebx
// 00413836  395c2410             cmp dword ptr [esp + 0x10], ebx
// 0041383a  0f8496000000         je 0x4138d6
// 00413840  6a20                 push 0x20
// 00413842  6a10                 push 0x10
// 00413844  6a10                 push 0x10
// 00413846  e897593000           call 0x7191e2
// 0041384b  85c0                 test eax, eax
// 0041384d  7531                 jne 0x413880
// 0041384f  6898f68a00           push 0x8af698
// 00413854  8d4c241c             lea ecx, [esp + 0x1c]
// 00413858  ff15b4e48900         call dword ptr [0x89e4b4]
// 0041385e  8d4c2418             lea ecx, [esp + 0x18]
// 00413862  51                   push ecx
// 00413863  8d4c2438             lea ecx, [esp + 0x38]
// 00413867  c644246802           mov byte ptr [esp + 0x68], 2
// 0041386c  e89f5bffff           call 0x409410
// 00413871  6850a79700           push 0x97a750
// 00413876  8d542438             lea edx, [esp + 0x38]
// 0041387a  52                   push edx
// 0041387b  e8ca613000           call 0x719a4a
// 00413880  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00413884  8b4604               mov eax, dword ptr [esi + 4]
// 00413887  51                   push ecx
// 00413888  51                   push ecx
// 00413889  50                   push eax
// 0041388a  e867543000           call 0x718cf6
// 0041388f  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00413895  8b08                 mov ecx, dword ptr [eax]
// 00413897  e8c4fcffff           call 0x413560
// 0041389c  83f8ff               cmp eax, -1
// 0041389f  0f85ca000000         jne 0x41396f
// 004138a5  6878f68a00           push 0x8af678
// 004138aa  8d4c241c             lea ecx, [esp + 0x1c]
// 004138ae  ff15b4e48900         call dword ptr [0x89e4b4]
// 004138b4  8d4c2418             lea ecx, [esp + 0x18]
// 004138b8  51                   push ecx
// 004138b9  8d4c2438             lea ecx, [esp + 0x38]
// 004138bd  c644246803           mov byte ptr [esp + 0x68], 3
// 004138c2  e8495bffff           call 0x409410
// 004138c7  6850a79700           push 0x97a750
// 004138cc  8d542438             lea edx, [esp + 0x38]
// 004138d0  52                   push edx
// 004138d1  e874613000           call 0x719a4a
// 004138d6  68ff000000           push 0xff
// 004138db  6a10                 push 0x10
// 004138dd  6a10                 push 0x10
// 004138df  e8fe583000           call 0x7191e2
// 004138e4  85c0                 test eax, eax
// 004138e6  7531                 jne 0x413919
// 004138e8  6898f68a00           push 0x8af698
// 004138ed  8d4c241c             lea ecx, [esp + 0x1c]
// 004138f1  ff15b4e48900         call dword ptr [0x89e4b4]
// 004138f7  8d442418             lea eax, [esp + 0x18]
// 004138fb  50                   push eax
// 004138fc  8d4c2438             lea ecx, [esp + 0x38]
// 00413900  c644246804           mov byte ptr [esp + 0x68], 4
// 00413905  e8065bffff           call 0x409410
// 0041390a  6850a79700           push 0x97a750
// 0041390f  8d4c2438             lea ecx, [esp + 0x38]
// 00413913  51                   push ecx
// 00413914  e831613000           call 0x719a4a
// 00413919  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041391d  8b4604               mov eax, dword ptr [esi + 4]
// 00413920  68ff00ff00           push 0xff00ff
// 00413925  52                   push edx
// 00413926  50                   push eax
// 00413927  e8ca533000           call 0x718cf6
// 0041392c  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00413932  8b08                 mov ecx, dword ptr [eax]
// 00413934  e837fdffff           call 0x413670
// 00413939  83f8ff               cmp eax, -1
// 0041393c  7531                 jne 0x41396f
// 0041393e  6878f68a00           push 0x8af678
// 00413943  8d4c241c             lea ecx, [esp + 0x1c]
// 00413947  ff15b4e48900         call dword ptr [0x89e4b4]
// 0041394d  8d4c2418             lea ecx, [esp + 0x18]
// 00413951  51                   push ecx
// 00413952  8d4c2438             lea ecx, [esp + 0x38]
// 00413956  c644246805           mov byte ptr [esp + 0x68], 5
// 0041395b  e8b05affff           call 0x409410
// 00413960  6850a79700           push 0x97a750
// 00413965  8d542438             lea edx, [esp + 0x38]
// 00413969  52                   push edx
// 0041396a  e8db603000           call 0x719a4a
// 0041396f  8d4c2410             lea ecx, [esp + 0x10]
// 00413973  885c2464             mov byte ptr [esp + 0x64], bl
// 00413977  c744241064f68a00     mov dword ptr [esp + 0x10], 0x8af664
// 0041397f  e84cbbffff           call 0x40f4d0
// 00413984  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00413988  8bc6                 mov eax, esi
// 0041398a  5e                   pop esi
// 0041398b  5b                   pop ebx
// 0041398c  64890d00000000       mov dword ptr fs:[0], ecx
// 00413993  83c460               add esp, 0x60
// 00413996  c3                   ret 
// copied from an identical function in another client (function ??0CClassImages@@QAE@XZ)

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