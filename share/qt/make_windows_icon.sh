#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/becoin.png
ICON_DST=../../src/qt/res/icons/becoin.ico
convert ${ICON_SRC} -resize 16x16 becoin-16.png
convert ${ICON_SRC} -resize 32x32 becoin-32.png
convert ${ICON_SRC} -resize 48x48 becoin-48.png
convert becoin-16.png becoin-32.png becoin-48.png ${ICON_DST}

