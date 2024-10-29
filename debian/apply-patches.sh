#!/bin/sh
while read -r line; do
    line=${line%%#*}
    file=debian/patches/${line%% *}
    case $file in
        *.patch)
            patch -p1 < $file
            git commit -m "Apply $file" -a
            ;;
    esac
done <debian/patches/series
