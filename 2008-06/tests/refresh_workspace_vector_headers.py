"""Refresh diagnostic Workspace/Model headers from the current native declarations."""
from pathlib import Path

root = Path(__file__).resolve().parents[3]
native = root / 'rebuild/2008-06/native-headers/v8datamodel'
overlay = root / 'rebuild/2008-06/out/native-layouts/workspace-model-vector-include/v8datamodel'
overlay.mkdir(parents=True, exist_ok=True)
model = (native / 'ModelInstance.h').read_text()
assert model.count('std::vector<IModelModifier*> modifiers;') == 1
overlay.joinpath('ModelInstance.h').write_text(model)
workspace = (native / 'Workspace.h').read_text()
marker = 'RBXASSERT(currentCommand.get());'
assert workspace.count(marker) == 1
overlay.joinpath('Workspace.h').write_text(workspace.replace(marker, '', 1))
print('PASS refreshed diagnostic ModelInstance and Workspace headers')
