#include "CSelectionCaption.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/SelectionChanged.h"

IMPLEMENT_DYNAMIC(CSelectionCaption, CXTCaption)

BEGIN_MESSAGE_MAP(CSelectionCaption, CWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CSelectionCaption::CSelectionCaption()
{
}

bool CSelectionCaption::filter(const RBX::Selection*, const RBX::SelectionChanged&,
                               const RBX::Selection*, const RBX::SelectionChanged&)
{
    return true;
}

BOOL CSelectionCaption::PreCreateWindow(CREATESTRUCT& create)
{
    return CWnd::PreCreateWindow(create);
}

BOOL CSelectionCaption::Create(LPCTSTR text, DWORD style, const RECT& bounds, CWnd* parent, UINT id)
{
    return CStatic::Create(text, style, bounds, parent, id);
}

int CSelectionCaption::OnCreate(LPCREATESTRUCT)
{
    if (Default() == -1) return -1;
    refresh();
    return 0;
}

void CSelectionCaption::onMarshaledEvent(const RBX::Selection*, RBX::SelectionChanged)
{
    updateCaption();
}

#include "v8datamodel/DataModel.h"

typedef RBX::Notifier<RBX::Selection, RBX::SelectionChanged> SelectionNotifier;

CSelectionCaption::~CSelectionCaption()
{
    RBX::DataModel::Lock lock(dataModel);
    SelectionNotifier::disconnect(selection, this);
}

void CSelectionCaption::update(boost::shared_ptr<RBX::DataModel> model,
                               boost::shared_ptr<RBX::DataModel>)
{
    {
        RBX::DataModel::Lock lock(dataModel);
        SelectionNotifier::disconnect(selection, this);
        selection.reset();
    }
    dataModel.reset();
    if (model) {
        dataModel = model;
        RBX::DataModel::Lock lock(dataModel);
        selection = RBX::shared_from(RBX::ServiceProvider::create<RBX::Selection>(dataModel.get()));
        SelectionNotifier::connect(selection, this);
    }
    if (!selection) updateCaption();
}

template class boost::shared_ptr<RBX::Selection const >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_val<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
