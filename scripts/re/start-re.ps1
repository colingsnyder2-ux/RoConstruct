# RE pipeline bootstrap: ensure Ollama is up, then launch Ghidra GUI with the 2008M project.
# Usage:  powershell -File scripts\re\start-re.ps1
#   -SkipGhidra   only start Ollama
#   -Headless     run export instead of GUI (needs Ghidra project lock free: GUI closed)

param(
    [switch]$SkipGhidra,
    [switch]$Headless
)

$ErrorActionPreference = "Stop"
$root    = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$re      = Join-Path $root 'work\re'
$ghidra  = "$re\ghidra"
$projDir = "$re\projects"
$proj    = "Rbx2008M"
$export  = "$re\export"
$bin     = "$re\bin"
$ollama  = "$env:LOCALAPPDATA\Programs\Ollama\ollama.exe"

# --- Ollama -------------------------------------------------------------
$listening = Get-NetTCPConnection -LocalPort 11434 -State Listen -ErrorAction SilentlyContinue
if (-not $listening) {
    Write-Host "[start-re] starting ollama serve"
    Start-Process -FilePath $ollama -ArgumentList "serve" -WindowStyle Hidden
    Start-Sleep -Seconds 3
} else {
    Write-Host "[start-re] ollama already listening on 11434"
}

# --- Ghidra MCP port check (8080 must be free for GhidraMCP) ------------
$p8080 = Get-NetTCPConnection -LocalPort 8080 -State Listen -ErrorAction SilentlyContinue
if ($p8080) {
    $owner = Get-Process -Id $p8080.OwningProcess -ErrorAction SilentlyContinue
    Write-Warning "[start-re] port 8080 held by: $($owner.Name) (pid $($p8080.OwningProcess)) -- GhidraMCP needs it"
}

if ($SkipGhidra) { exit 0 }

if ($Headless) {
    # decompile loop over ~10k functions needs headroom (default is 2G)
    $env:MAXMEM = "4G"
    # Full pipeline: export JSONL via pyghidra (project must not be open in GUI), ingest, summarize
    python "$PSScriptRoot\export_pyghidra.py"
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
    python "$PSScriptRoot\summarize.py" ingest
    python "$PSScriptRoot\summarize.py" run
    exit $LASTEXITCODE
}

# --- GUI ----------------------------------------------------------------
Write-Host "[start-re] launching Ghidra GUI (project: $projDir\$proj)"
Start-Process -FilePath "$ghidra\ghidraRun.bat" -ArgumentList "$projDir\$proj" -WorkingDirectory $ghidra
Write-Host "[start-re] done. In Ghidra: open RobloxApp_client.exe, GhidraMCP serves on 8080."
