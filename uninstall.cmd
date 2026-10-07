@echo off
setlocal
cd /d "%~dp0"
title RoConstruct uninstall

rem This removes what install.cmd put on this machine: downloaded compilers, cloudflared,
rem analysis state, the roconstruct:// links, and optionally the AI models, Ollama,
rem Docker and Tailscale. It asks before every step. Nothing shared is removed by
rem default, and your other Ollama models are never touched.

py -3.12 -c "import sys" >nul 2>nul
if errorlevel 1 (
  echo Python 3.12 not found, so the uninstaller cannot run.
  echo It was installed by install.cmd; uninstalling it is the last step below.
  echo.
  pause
  exit /b 0
)

py -3.12 -m roc.uninstall %*
set code=%errorlevel%

echo.
if errorlevel 1 (
  echo Uninstaller stopped early. Nothing was removed after that point.
) else (
  echo Done.
)
pause
exit /b %code%
