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
  echo This copy was downloaded as a ZIP. Linking it to the repository so it can update...
  git init -q
  git remote remove origin >nul 2>nul
  git remote add origin https://github.com/colingsnyder2-ux/RoConstruct.git
  git fetch --depth 1 origin main || (
    echo Could not reach the repository. Check your internet connection and run update.cmd again.
    pause
    exit /b 1
  )
  rem reset --hard only touches tracked files; your clients, mined work, models and settings are untracked and stay.
  git reset --hard origin/main || (
    echo Linking failed. No files were removed.
    pause
    exit /b 1
  )
  git branch -M main >nul 2>nul
  echo.
  echo Done. This copy is now a Git checkout and will update with update.cmd from now on.
  echo Preserved clients, work, downloaded models, and settings.
  pause
  exit /b 0
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
