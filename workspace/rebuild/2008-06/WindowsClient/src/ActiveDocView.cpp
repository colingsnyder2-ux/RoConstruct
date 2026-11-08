#include "ActiveDocView.h"
ActiveDocView::ActiveDocView() { activeDocViews.insert(this); }
ActiveDocView::~ActiveDocView() { activeDocViews.erase(this); }
