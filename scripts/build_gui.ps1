param([switch]$Clean)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
if ($Clean) {
    Remove-Item -Recurse -Force (Join-Path $root 'build\RoConstruct-GUI') -ErrorAction SilentlyContinue
    Remove-Item -Recurse -Force (Join-Path $root 'dist\RoConstruct-GUI') -ErrorAction SilentlyContinue
}
py -m pip install --upgrade pyinstaller
py -m PyInstaller --noconfirm --clean --windowed --onefile `
    --name RoConstruct-GUI `
    --distpath (Join-Path $root 'dist') `
    --workpath (Join-Path $root 'build\RoConstruct-GUI') `
    (Join-Path $root 'scripts\roconstruct_gui.py')
Write-Host "Built: $(Join-Path $root 'dist\RoConstruct-GUI.exe')"
