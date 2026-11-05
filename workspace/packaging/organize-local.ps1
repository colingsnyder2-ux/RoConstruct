param([switch]$Apply)
$ErrorActionPreference = 'Stop'
$workspaceRoot = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$localRoot = Join-Path $workspaceRoot 'local'
$manifest = [Collections.Generic.List[object]]::new()

function Check-Path([string]$path) {
    $full = [IO.Path]::GetFullPath($path)
    if (-not $full.StartsWith($workspaceRoot + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Outside workspace: $full"
    }
    return $full
}

function Relocate([string]$relative, [string]$destination, [bool]$alias = $false, [bool]$busy = $false) {
    $source = Check-Path (Join-Path $workspaceRoot $relative)
    $target = Check-Path (Join-Path $localRoot $destination)
    if (-not (Test-Path -LiteralPath $source)) { return }
    $item = Get-Item -LiteralPath $source -Force
    if ($item.Attributes -band [IO.FileAttributes]::ReparsePoint) { return }
    $state = 'planned'
    if ($Apply) {
        New-Item -ItemType Directory -Path (Split-Path $target) -Force | Out-Null
        if ($busy) {
            if (-not (Test-Path -LiteralPath $target)) {
                New-Item -ItemType Junction -Path $target -Target $source | Out-Null
            }
            $state = 'live directory retained; local junction added'
        } elseif (Test-Path -LiteralPath $target) {
            $state = 'destination exists; retained both'
        } else {
            try {
                Move-Item -LiteralPath $source -Destination $target
                if ($alias) {
                    try { New-Item -ItemType Junction -Path $source -Target $target | Out-Null }
                    catch { Move-Item -LiteralPath $target -Destination $source; throw }
                }
                $state = if ($alias) { 'moved; legacy junction preserved' } else { 'archived' }
            } catch { $state = 'retained: ' + $_.Exception.Message }
        }
    }
    $manifest.Add([pscustomobject]@{source=$relative;destination=$target;state=$state})
}

$active = @(Get-CimInstance Win32_Process | Where-Object {
    $_.Name -match '^python|^cl\.exe|^link\.exe' -and
    $_.CommandLine -match 'roc\.py (server|worker|agent)|benchmarks|scratchpad|ui_preview'
})
$publishLock = $null
if ($Apply) {
    New-Item -ItemType Directory -Path $localRoot -Force | Out-Null
    # Same byte-range lock the server's publish_once holds; the lock file itself is
    # persistent publisher state and is never deleted here.
    $lockPath = Join-Path $workspaceRoot 'work/publish.lock'
    try {
        $publishLock = [IO.File]::Open($lockPath, 'OpenOrCreate', 'ReadWrite', 'ReadWrite')
        $publishLock.Lock(0, 1)
    } catch {
        if ($publishLock) { $publishLock.Dispose(); $publishLock = $null }
        Write-Host 'Publisher active; recovered sources stay in place.'
    }
}
try {
    Relocate 'src' 'findings/src' $true ($Apply -and (-not $publishLock -or $active.Count -gt 0))
    # dist/ and scripts/ were retired 2026-10-12: packages build into local/packages directly.
    Relocate 'scripts' 'archive/legacy-scripts'
    Relocate 'dist' 'packages'
    Relocate 'work' 'work' $true ($active.Count -gt 0)
    Relocate 'tools' 'tools' $true ($active.Count -gt 0)
    foreach ($name in @('clients.zip','r2009.zip')) { Relocate $name ('archive/downloads/' + $name) }
    Relocate 'test_out.txt' 'archive/test-output/test_out.txt'
    Relocate 'colin.lnk' 'shortcuts/colin.lnk'
    foreach ($item in @(Get-ChildItem -LiteralPath (Join-Path $workspaceRoot 'work') -Directory | Where-Object {
        $_.Name -match '^cluster-(solo-test|test)-'
    })) { Relocate ('work/' + $item.Name) ('archive/test-runs/' + $item.Name) }
} finally {
    if ($publishLock) {
        $publishLock.Unlock(0, 1)
        $publishLock.Dispose()
    }
}
if ($Apply) { $manifest | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath (Join-Path $localRoot 'organization.json') }
$manifest | Format-Table source,state,destination -AutoSize
