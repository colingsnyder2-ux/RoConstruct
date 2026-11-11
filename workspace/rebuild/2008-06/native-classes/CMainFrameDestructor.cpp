// >>> native-status (generated) -- do not edit >>>
// CMainFrameDestructor | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ec0cd03b | roc native-status --write
#include "CMainFrame.h"
#include "v8datamodel/ToolsPart.h"

CMainFrame::~CMainFrame()
{
    if (resource) {
        reinterpret_cast<CCmdTarget*>(resource)->InternalRelease();
        resource = NULL;
    }
    RBX::FillTool::color.removeListener(this);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class CXTPCommandBarsSiteBase<CMDIFrameWnd>;
template class CXTPFrameWndBase<CMDIFrameWnd>;
template class RBX::Listener<RBX::FillToolColor,RBX::BrickColor>;
template class RBX::Notifier<RBX::FillToolColor,RBX::BrickColor>;
template class boost::scoped_ptr<CDataModelPropGrid>;
template class boost::scoped_ptr<CSelectionCaption>;
template class boost::scoped_ptr<CXTSplitterWnd>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *,std::allocator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *,std::allocator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *> >;
template class std::vector<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *,std::allocator<RBX::Listener<RBX::FillToolColor,RBX::BrickColor> *> >;
