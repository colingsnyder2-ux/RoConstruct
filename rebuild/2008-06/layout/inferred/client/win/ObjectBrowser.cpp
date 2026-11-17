#include "CObjectBrowser.h"
#include <algorithm>

IMPLEMENT_DYNCREATE(CObjectBrowser, CView)

BEGIN_MESSAGE_MAP(CObjectBrowser, CView)
    ON_WM_SIZE()
    ON_WM_CREATE()
END_MESSAGE_MAP()

CObjectBrowser::CObjectBrowser()
{
}

CObjectBrowser::~CObjectBrowser()
{
}

BOOL CObjectBrowser::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs) != FALSE;
}

void CObjectBrowser::OnInitialUpdate()
{
    CView::OnInitialUpdate();
}

void CObjectBrowser::OnDraw(CDC* pDC)
{
}

void CObjectBrowser::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);
    if (nType != SIZE_MINIMIZED && classSplitter.m_hWnd) {
        CRect rect;
        classSplitter.GetClientRect(&rect);
        int delta = cy - rect.Height();
        classSplitter.MoveWindow(0, 0, cx, cy, TRUE);
        if (memberSplitter.m_hWnd) {
            int current, minimum;
            memberSplitter.GetRowInfo(0, current, minimum);
            int height = current + delta;
            height = (std::min)(cy - 150, height);
            height = (std::max)(50, height);
            memberSplitter.SetRowInfo(0, height, 0);
            memberSplitter.RecalcLayout();
        }
    }
}

int CObjectBrowser::OnCreate(LPCREATESTRUCT cs)
{
    if (CView::OnCreate(cs) == -1)
        return -1;
    if (!classSplitter.CreateStatic(this, 1, 2))
        return -1;
    classSplitter.SetSplitterStyle(XT_SPLIT_NOBORDER);
    CCreateContext context;
    context.m_pCurrentDoc = GetDocument();
    if (!classSplitter.CreateView(0, 0, _RUNTIME_CLASS(CClassTreeView), CSize(200, 600), &context))
        return -1;
    if (!memberSplitter.CreateStatic(&classSplitter, 2, 1, WS_CHILD | WS_VISIBLE | WS_BORDER, classSplitter.IdFromRowCol(0, 1)))
        return -1;
    if (!memberSplitter.CreateView(0, 0, _RUNTIME_CLASS(CMemberTreeView), CSize(300, 200), &context))
        return -1;
    if (!memberSplitter.CreateView(1, 0, _RUNTIME_CLASS(CDeclarationView), CSize(100, 190), &context))
        return -1;
    CClassTreeView* classView = static_cast<CClassTreeView*>(classSplitter.GetPane(0, 0));
    CMemberTreeView* memberView = static_cast<CMemberTreeView*>(memberSplitter.GetPane(0, 0));
    CDeclarationView* declarationView = static_cast<CDeclarationView*>(memberSplitter.GetPane(1, 0));
    classView->memberView = memberView;
    classView->declarationView = declarationView;
    memberView->declarationView = declarationView;
    return 0;
}

#include "COutputView.h"
#include <atlenc.h>
#include <time.h>

#define WM_STANDARD_OUT_MESSAGE (WM_USER + 0x65)

IMPLEMENT_DYNAMIC(COutputView, CSecureHtmlView)

COutputView::COutputView()
{
}

void COutputView::OnInitialUpdate()
{
    CSecureHtmlView::OnInitialUpdate();
    LoadFromResource(134);
}

void COutputView::OnDocumentComplete(LPCTSTR)
{
    document = GetHtmlDocument();
    if (document) {
        CComPtr<IHTMLElementCollection> all;
        document->get_all(&all);
        CComPtr<IDispatch> item;
        all->item(CComVariant("output"), CComVariant(), &item);
        output = item;
    } else {
        output.Release();
    }
}

void COutputView::appendElement(IHTMLElement* element)
{
    CComQIPtr<IHTMLDOMNode> node(element);
    CComPtr<IHTMLDOMNode> appended;
    if (output->appendChild(node, &appended) == S_OK) {
        element->scrollIntoView(CComVariant((short)0));
        nodes.push_back(node);
        if (nodes.size() > 250) {
            CComPtr<IHTMLDOMNode> removed;
            output->removeChild(nodes.front(), &removed);
            nodes.pop_front();
        }
    }
}

IMPLEMENT_DYNCREATE(CStandardOutputView, COutputView)

BEGIN_MESSAGE_MAP(CStandardOutputView, COutputView)
    ON_MESSAGE(WM_STANDARD_OUT_MESSAGE, OnStandardOutMessage)
END_MESSAGE_MAP()

CStandardOutputView::CStandardOutputView()
{
    flag_f4 = true;
    boost::mutex::scoped_lock lock(RBX::StandardOut::singleton()->sync);
    RBX::Notifier<RBX::StandardOut, RBX::StandardOutMessage>::connect(RBX::StandardOut::singleton(), this);
}

CStandardOutputView::~CStandardOutputView()
{
    boost::mutex::scoped_lock lock(RBX::StandardOut::singleton()->sync);
    RBX::Notifier<RBX::StandardOut, RBX::StandardOutMessage>::disconnect(RBX::StandardOut::singleton(), this);
}

void CStandardOutputView::onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message)
{
    boost::mutex::scoped_lock lock(messagesLock);
    if (messages.empty())
        ::PostMessage(m_hWnd, WM_STANDARD_OUT_MESSAGE, 0, 0);
    messages.push_back(message);
    if (messages.size() > 250)
        messages.pop_front();
}

void CStandardOutputView::appendMessage(RBX::MessageType type, const char* message, __time64_t time)
{
    CStringW text(message);
    CStringW escaped;
    int length = ATL::EscapeXML(text, text.GetLength(), NULL, 0);
    ATL::EscapeXML(text, text.GetLength(), escaped.GetBufferSetLength(length), length);
    escaped.ReleaseBuffer();

    CStringW html;
    if (type != RBX::MESSAGE_OUTPUT && time != 0) {
        char buffer[32];
        _ctime64_s(buffer, 32, &time);
        html = buffer;
        html += " - ";
    }
    switch (type) {
    case RBX::MESSAGE_INFO:
        html += "<FONT color=\"blue\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_WARNING:
        html += "<STRONG><FONT color=\"orange\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_ERROR:
        html += "<STRONG><FONT color=\"red\">";
        html += escaped;
        html += "</FONT>";
        break;
    case RBX::MESSAGE_OUTPUT:
        html += escaped;
        break;
    }

    CComPtr<IHTMLElement> element;
    if (document) {
        document->createElement(CComBSTR("DIV"), &element);
        element->put_innerHTML(CComBSTR(html));
        appendElement(element);
    }
}

LRESULT CStandardOutputView::OnStandardOutMessage(WPARAM, LPARAM)
{
    for (;;) {
        std::string text;
        RBX::MessageType type;
        __time64_t time;
        {
            boost::mutex::scoped_lock lock(messagesLock);
            if (messages.empty())
                break;
            if (messages.size() > 250) {
                messages.pop_front();
                continue;
            }
            type = messages.front().type;
            text = messages.front().message;
            time = messages.front().time;
            messages.pop_front();
        }
        appendMessage(type, text.c_str(), time);
    }
    return 0;
}

template class ATL::CComPtrBase<IDispatch>;
template class ATL::CComPtrBase<IHTMLDOMNode>;
template class ATL::CComPtrBase<IHTMLDocument2>;
template class ATL::CComPtrBase<IHTMLElement>;
template class ATL::CComPtrBase<IHTMLElementCollection>;
template class RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage>;
template class std::_Deque_const_iterator<ATL::CComPtr<IHTMLDOMNode>,std::allocator<ATL::CComPtr<IHTMLDOMNode> >,1>;
template class std::_Deque_const_iterator<RBX::StandardOutMessage,std::allocator<RBX::StandardOutMessage>,1>;
template class std::_Deque_iterator<RBX::StandardOutMessage,std::allocator<RBX::StandardOutMessage>,1>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
template class std::vector<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *,std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
