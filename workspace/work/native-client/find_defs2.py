import os, re

# More unresolved engine symbols
targets = {
    'saveState': r'GlobalSettings::saveState\s*\(',
    'eraseSettingsStore': r'GlobalSettings::eraseSettingsStore\s*\(',
    'commit': r'ChangeHistoryService::commit\s*\(',
    'mergeFirst': r'ChangeHistoryService::mergeFirst\s*\(',
    'reset': r'ChangeHistoryService::reset\s*\(',
    'initializeBase': r'ChangeHistoryService::initializeBase\s*\(',
    'canAcceptChildren': r'Instance::canAcceptChildren\s*\(',
    'getWorkspace': r'CWorkspace::getWorkspace\s*\(',
    'insert': r'CWorkspace::insert\s*\(',
    'load': r'CWorkspace::load\s*\(',
    'recordCameraHistory': r'recordCameraHistory\s*\(',
    'getActiveDataModel': r'getActiveDataModel\s*\(',
    'play': r'ChangeHistoryService::play\s*\(',
    'unplay': r'ChangeHistoryService::unplay\s*\(',
    'queryPlay': r'ChangeHistoryService::queryPlay\s*\(',
    'queryUnplay': r'ChangeHistoryService::queryUnplay\s*\(',
    'setEnabled': r'ChangeHistoryService::setEnabled\s*\(',
}

for root, dirs, files in os.walk('tools/rbxgs/Client'):
    for f in files:
        if f.endswith('.cpp') and 'roc_' in f:
            path = os.path.join(root, f)
            try:
                with open(path, 'r', errors='replace') as fh:
                    content = fh.read()
            except:
                continue
            found = []
            for name, pat in targets.items():
                if re.search(pat, content):
                    found.append(name)
            if found:
                print(f'{path} -> {found}')
