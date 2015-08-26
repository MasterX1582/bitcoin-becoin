
Debian
====================
This directory contains files used to package becoind/becoin-qt
for Debian-based Linux systems. If you compile becoind/becoin-qt yourself, there are some useful files here.

## becoin: URI support ##


becoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install becoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your becoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/becoin128.png` to `/usr/share/pixmaps`

becoin-qt.protocol (KDE)

