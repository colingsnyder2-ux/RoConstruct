# 2026-11-08 findings-work integration batch (steps 1-4 of the run protocol).
# Run from C:\Users\colin\RoConstruct after the old guard has self-expired.
param(
    [string]$Message = "Integrate reviewed status/site site-link repair and P6 provider-ownership candidate fixes"
)
$ErrorActionPreference = 'Stop'
$root = 'C:\Users\colin\RoConstruct'
Set-Location $root
$manifest = 'work\native-candidates\integration-manifest-20261108.json'
$tokenFile = 'work\native-candidates\integration-token-20261108.txt'

# --- step 1: acquire the integration lock -----------------------------------
Write-Output "=== STEP 1: integration-lock start ==="
$start = cmd /c "python -m roc.native_drafts integration-lock start 2>&1" | Out-String
Write-Output "LOCK START: $start"
$tok = ($start | ConvertFrom-Json).token
if (-not $tok) { throw 'integration-lock start returned no token' }
Set-Content -Path $tokenFile -Value $tok -Encoding ascii -NoNewline
Write-Output "TOKEN retained in $tokenFile"

# --- step 2: confirm the findings work tip ----------------------------------
Write-Output "=== STEP 2: fetch findings/work ==="
cmd /c "git fetch --no-write-fetch-head findings refs/heads/work:refs/remotes/findings/work 2>&1"
$tip = git rev-parse refs/remotes/findings/work
Write-Output "WORK TIP: $tip"
if ($tip -ne '2da654506111296a9f85e38b18500710df5dd5c3') {
    Write-Warning "findings/work advanced past the manifest base; per-file guard inside integrate() will still reject stale file replacements"
}

# --- step 3: isolated-index integrate using the work-branch tooling ----------
Write-Output "=== STEP 3: findings_workspace integrate ==="
Set-Location C:\Users\colin\AppData\Local\Temp\roc-work-tool-20261108\workspace
python -m roc.findings_workspace --root $root integrate --manifest "C:\Users\colin\RoConstruct\$manifest" --message $Message
if ($LASTEXITCODE -ne 0) { throw "integrate failed rc=$LASTEXITCODE" }

# --- step 4: verify ---------------------------------------------------------
Set-Location $root
Write-Output "=== STEP 4: verify-integration ==="
python work\native-candidates\verify-integration-20261108.py
if ($LASTEXITCODE -ne 0) { throw 'post-integration verification failed' }
Write-Output "=== BATCH COMPLETE ==="