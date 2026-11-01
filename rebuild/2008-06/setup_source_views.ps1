$ErrorActionPreference = 'Stop'
$clientSource = (Resolve-Path (Join-Path $PSScriptRoot '../../tools/rbxgs/Client')).Path
$sourceViews = Join-Path $PSScriptRoot 'Source'
New-Item -ItemType Directory -Force -Path $sourceViews | Out-Null
foreach ($division in @('App', 'Network', 'RbxView', 'Rendering')) {
    $view = Join-Path $sourceViews $division
    $target = Join-Path $clientSource $division
    if (Test-Path -LiteralPath $view) {
        if ((Get-Item -LiteralPath $view).Target -ne $target) { throw "Preserving existing source path: $view" }
    } else {
        New-Item -ItemType Junction -Path $view -Target $target | Out-Null
    }
}

foreach ($recovery in @('Recovered', 'Include')) {
    $view = Join-Path $sourceViews $recovery
    $target = if ($recovery -eq 'Recovered') { Join-Path $PSScriptRoot 'native-classes' } else { Join-Path $PSScriptRoot 'native-headers' }
    if (Test-Path -LiteralPath $view) {
        if ((Get-Item -LiteralPath $view).Target -ne $target) { throw "Preserving existing source path: $view" }
    } else {
        New-Item -ItemType Junction -Path $view -Target $target | Out-Null
    }
}
