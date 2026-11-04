#pragma once
namespace RBX { class ContentProvider; }

// Render entry points assign this service before GUI/texture work, then clear it.
// Name follows existing recovered texture source; original debug spelling unknown.
extern RBX::ContentProvider* provider;
