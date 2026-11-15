"""Compile original toolbar method bodies with the browser platform subset."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SOURCE = ROOT / 'tools/libs/xtp-11.2.2/Source/CommandBars'
OUT = ROOT / 'work/codejock-wasm'
SDK = ROOT / 'tools/emsdk'
OUT.mkdir(parents=True, exist_ok=True)
(OUT / 'site').mkdir(exist_ok=True)


def block(text, signature):
    start = text.index(signature)
    # Count C++ braces only, ignoring comments and quoted literals.
    masked = re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                    lambda m: ' ' * len(m.group()), text, flags=re.S)
    brace = masked.index('{', start)
    depth = 1
    end = brace + 1
    while depth:
        depth += (masked[end] == '{') - (masked[end] == '}')
        end += 1
    return text[start:end]


selection = {
    'XTPControls.cpp': [
        'CXTPControl* CXTPControls::HitTest(',
        'struct CXTPControls::XTPBUTTONINFO ',
        'CSize CXTPControls::_CalcSize(',
        'int CXTPControls::_WrapToolBar(',
        'void CXTPControls::_CenterControlsInRow(',
        'void CXTPControls::_AdjustBorders(',
        'void CXTPControls::_MoveRightAlligned(',
        'void  CXTPControls::_SizePopupToolBar(',
        'void  CXTPControls::_SizeFloatableBar(',
        'int CXTPControls::GetVisibleCount(',
        'CSize CXTPControls::CalcDynamicSize(',
        'void CXTPControls::_MakeSameWidth(',
        'CSize CXTPControls::CalcPopupSize(',
    ],
    'XTPControl.cpp': [
        'BOOL CXTPControl::OnSetSelected(',
        'void CXTPControl::ClickToolBarButton(',
        'BOOL CXTPControl::NeedPressOnExecute(',
        'CSize CXTPControl::GetSize(',
        'void CXTPControl::Draw(',
        'BOOL CXTPControl::IsCaptionVisible() const',
    ],
    'XTPControlButton.cpp': [
        'CXTPControlButton::CXTPControlButton()',
        'CXTPControlButton::~CXTPControlButton()',
        'void CXTPControlButton::OnLButtonUp(',
        'void CXTPControlButton::OnClick(',
    ],
    'XTPControlPopup.cpp': [
        'CXTPControlPopup::CXTPControlPopup()',
        'CXTPControlPopup::~CXTPControlPopup()',
        'void CXTPControlPopup::OnClick(',
        'void CXTPControlPopup::OnLButtonUp(',
        'BOOL CXTPControlPopup::OnSetPopup(',
    ],
    'XTPToolBar.cpp': ['CRect CXTPToolBar::GetBorders()', 'CSize CXTPToolBar::CalcDockingLayout('],
    'XTPCommandBar.cpp': [
        'void CXTPCommandBar::FillCommandBarEntry(',
        'void CXTPCommandBar::DrawCommandBar(',
        'BOOL CXTPCommandBar::SetPopuped(',
    ],
    'XTPPaintManager.cpp': [
        'void CXTPPaintManager::DrawControlEntry(',
        'CRect CXTPPaintManager::GetCommandBarBorders(',
        'CSize CXTPPaintManager::DrawControlText(CDC* pDC, CXTPControl* pButton, CRect rcText, BOOL bDraw, BOOL bVert, BOOL bCentered, BOOL bTriangled)',
        'void CXTPPaintManager::DrawControlText3(',
        'CSize CXTPPaintManager::DrawControl(',
        'CSize CXTPPaintManager::DrawControlToolBarParent(',
        'CSize CXTPPaintManager::DrawControlText(CDC* pDC, CXTPControl* pButton, CRect rcText, BOOL bDraw, BOOL bTriangled, CSize szButton, BOOL bDrawImage)',
        'CSize CXTPPaintManager::GetControlSize(',
        'CSize CXTPPaintManager::GetIconSize(',
        'int CXTPPaintManager::GetSplitDropDownHeight() const',
        'COLORREF CXTPPaintManager::GetControlTextColor(',
        'CSize CXTPPaintManager::DrawControlPopupParent(',
        'CSize CXTPPaintManager::GetPopupBarImageSize(',
        'void CXTPPaintManager::DrawPopupBarText(',
        'void CXTPPaintManager::DrawDropDownGlyph(',
    ],
    'XTPDefaultTheme.cpp': [
        'void CXTPDefaultTheme::DrawRectangle(',
        'void CXTPDefaultTheme::FillCommandBarEntry(',
        'CSize CXTPDefaultTheme::DrawCommandBarSeparator(',
        'COLORREF CXTPDefaultTheme::GetRectangleTextColor(',
        'CSize CXTPDefaultTheme::DrawControlPopupParent(',
        'CSize CXTPDefaultTheme::GetPopupBarImageSize(',
        'CRect CXTPDefaultTheme::GetCommandBarBorders(',
    ],
}
chunks = ['#include "ToolbarSubset.h"\n']
receipt = []
for filename, signatures in selection.items():
    original = (SOURCE / filename).read_text(encoding='cp1252')
    chunks.append(original[:original.index('#include')])
    for signature in signatures:
        method = block(original, signature)
        if signature.startswith('struct '):
            method += ';'
        chunks.append(f'\n#line {original[:original.index(signature)].count(chr(10)) + 1} "{filename}"\n' + method)
        receipt.append({'source': filename, 'signature': signature,
                        'sourceSha256': hashlib.sha256(original.encode()).hexdigest(),
                        'line': original[:original.index(signature)].count('\n') + 1,
                        'sha256': hashlib.sha256(method.encode()).hexdigest()})
generated = OUT / 'CodejockToolbar.cpp'
generated.write_text('\n'.join(chunks), encoding='utf-8')
(OUT / 'provenance.json').write_text(json.dumps(receipt, indent=2))
command = [sys.executable, str(SDK / 'upstream/emscripten/em++.py'),
           '-std=c++17', '-O1', '-g2', '-fexceptions', '-sASYNCIFY=1',
           '--emit-symbol-map',
           '-sASSERTIONS=1', '-sALLOW_MEMORY_GROWTH=1',
           '-I' + str(HERE), str(generated), str(HERE / 'BrowserPlatform.cpp'),
           str(HERE / 'toolbar_main.cpp'), '--shell-file', str(HERE / 'shell.html'),
           '-o', str(OUT / 'site/index.html')]
env = dict(os.environ, EMSDK=str(SDK), EM_CONFIG=str(SDK / '.emscripten'))
result = subprocess.run(command, env=env, capture_output=True, text=True)
(OUT / 'build.log').write_text(result.stdout + result.stderr)
(OUT / 'build.json').write_text(json.dumps({'exit': result.returncode, 'command': command}, indent=2))
print((result.stdout + result.stderr)[-12000:])
print('Build exit:', result.returncode)
raise SystemExit(result.returncode)
