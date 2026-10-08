@echo off
setlocal
cd /d "%~dp0"
title RoConstruct update

where git >nul 2>nul || (
  echo Git not found. Install Git, then run update.cmd again.
  pause
  exit /b 1
)
if not exist ".git\HEAD" (
  echo This copy is not a Git checkout.
  echo Download a fresh release ZIP, or clone the repository first.
  pause
  exit /b 1
)

rem Never overwrite local tracked edits. Untracked clients, work, and settings stay untouched.
git diff --quiet HEAD
if errorlevel 1 (
  echo Local source edits detected. Update skipped to protect your changes.
  echo Commit or save those edits, then run update.cmd again.
  pause
  exit /b 1
)

echo Updating RoConstruct source...
git pull --ff-only origin main
if errorlevel 1 (
  echo Update failed. No files were removed.
  pause
  exit /b 1
)
echo.
echo Updated. Preserved clients, work, downloaded models, and settings.
pause
