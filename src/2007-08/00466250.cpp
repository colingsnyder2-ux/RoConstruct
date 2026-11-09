// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_cursor_bounded_order_4f886855f339790d.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>

#include "util/Rect.h"
void updateCursor(const G3D::Vector2& delta, G3D::Vector2& movement, G3D::Vector2& position, const G3D::Vector2& viewport, int margin, float smoothing) {
 G3D::Vector2 half = viewport * 0.5f;
 RBX::Rect bounds(-half,half);
 bounds.low.x += margin; bounds.low.y += margin;
 bounds.high.x -= margin; bounds.high.y -= margin;
 G3D::Vector2 oldPosition = position;
 bounds.unionWith(RBX::Rect(oldPosition,oldPosition));
 G3D::Vector2 desired = delta + oldPosition;
 G3D::Vector2 clamped = desired.clamp(bounds.low,bounds.high);
 G3D::Vector2 excess = desired - clamped;
 position = clamped + excess * smoothing;
 movement += excess;
}
void updateCursorVertical(const G3D::Vector2& delta, G3D::Vector2& movement, G3D::Vector2& position, const G3D::Vector2& viewport) {
 float y = delta.y + position.y;
 updateCursor(delta,movement,position,viewport,20,0.05f);
 movement.y=0.0f;
 position.y=y;
}
void updateCursorNormal(const G3D::Vector2& delta, G3D::Vector2& movement, G3D::Vector2& position, const G3D::Vector2& viewport) {
 updateCursor(delta,movement,position,viewport,6,0.0f);
}

void updateCursorBoundedVertical(const G3D::Vector2& delta, G3D::Vector2& movement, G3D::Vector2& position, const G3D::Vector2& viewport) {
 float y = delta.y + position.y;
 updateCursor(delta,movement,position,viewport,6,0.0f);
 movement.y=0.0f;
 position.y=y;
 float maxY = viewport.y * 0.5f - 2.0f;
 position.y=std::max(-maxY,position.y);
}
