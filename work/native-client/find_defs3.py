import os, re
targets = {
    'saveState': r'GlobalSettings::saveState\s*\(',
    'eraseSettingsStore': r'GlobalSettings::eraseSettingsStore\s*\(',
    'getDutyCycle': r'DataModel::getDutyCycle\s*\(',
    'getFrameRate': r'DataModel::getFrameRate\s*\(',
    'getGameTime': r'DataModel::getGameTime\s*\(',
    'cameraRadiansToDegrees': r'cameraRadiansToDegrees',
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
            found = [name for name, pat in targets.items() if re.search(pat, content)]
            if found:
                print(f'{path} -> {found}')
