import os, re

targets = {
    'saveState': r'GlobalSettings::saveState\s*\(',
    'eraseSettingsStore': r'GlobalSettings::eraseSettingsStore\s*\(',
    'commit': r'ChangeHistoryService::commit\s*\(',
    'mergeFirst': r'ChangeHistoryService::mergeFirst\s*\(',
    'reset': r'ChangeHistoryService::reset\s*\(',
    'initializeBase': r'ChangeHistoryService::initializeBase\s*\(',
    'createDataModel': r'DataModel::createDataModel\s*\(',
    'initializeContents': r'DataModel::initializeContents\s*\(',
    'canAcceptChildren': r'Instance::canAcceptChildren\s*\(',
    'askAddChild': r'Instance::askAddChild\s*\(',
    'askSetParent': r'Instance::askSetParent\s*\(',
    'getWorkspace': r'CWorkspace::getWorkspace\s*\(',
    'insert': r'CWorkspace::insert\s*\(',
    'load': r'CWorkspace::load\s*\(',
    'recordCameraHistory': r'recordCameraHistory\s*\(',
    'getMimeType': r'getMimeType\s*\(',
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
