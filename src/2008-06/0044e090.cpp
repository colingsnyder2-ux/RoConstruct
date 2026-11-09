// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-imports roc_espeon_colorselectornative98f882a955130b44.cpp

// Candidate translation unit (score above; library headers required).
#include <XTToolkitPro.h>
#include <vector>
// Native XTP CColorInfo fields; vector stride12 is proven by the target.
struct ColorEntry {COLORREF clrButton;UINT toolTipID;CString strTip;};
extern std::vector<ColorEntry> colorEntries;
class ColorSelectorRecovery: public CXTPControl {
public:
 template<class T>T& field(unsigned offset){return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);}
 void Draw(CDC* pDC);
 __forceinline CRect colorRect(int index){int x=index%8,y=index/8;return CRect(CPoint(2+m_rcControl.left+x*32,2+m_rcControl.top+y*32),CSize(32,32));}
};
void ColorSelectorRecovery::Draw(CDC* pDC){
 int nCount=colorEntries.size();
 for(int i=0;i<nCount;i++){
  CRect rcButton=colorRect(i);
  if(i==field<int>(0x174)||colorEntries[i].clrButton==field<COLORREF>(0x180)){
   BOOL bPressed=GetPressed()&&i==field<int>(0x174);
   GetPaintManager()->DrawRectangle(pDC,rcButton,i==field<int>(0x174),bPressed,GetEnabled(),colorEntries[i].clrButton==field<COLORREF>(0x180),FALSE,xtpBarTypeNormal,xtpBarPopup);
  }
  rcButton.DeflateRect(3,3);
  if(GetEnabled())pDC->FillSolidRect(rcButton,colorEntries[i].clrButton);
  pDC->Draw3dRect(rcButton,GetXtremeColor(COLOR_3DSHADOW),GetXtremeColor(COLOR_3DSHADOW));
 }
}
