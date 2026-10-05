param(
    [switch]$Clean
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$entry = Join-Path $PSScriptRoot 'roconstruct.py'

if ($Clean) {
    Remove-Item -Recurse -Force (Join-Path $root 'build\RoConstruct') -ErrorAction SilentlyContinue
    Remove-Item -Recurse -Force (Join-Path $root 'dist\RoConstruct') -ErrorAction SilentlyContinue
}

py -m pip install --upgrade pyinstaller
py -m PyInstaller --noconfirm --clean --console --onefile `
    --name RoConstruct `
    --distpath (Join-Path $root 'dist') `
    --workpath (Join-Path $root 'build') `
    $entry

Write-Host "Built: $(Join-Path $root 'dist\RoConstruct.exe')"
