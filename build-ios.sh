#!/usr/bin/env sh
clang \
	src/main.c \
	src/print.c \
	src/NSString.c \
	src/props.c \
	src/AppDelegate.c \
	-target arm64-apple-ios26.5-simulator \
	-isysroot "$(xcrun --sdk iphonesimulator --show-sdk-path)" \
	-framework Foundation \
	-framework UIKit \
	-lobjc \
	-o MinimalIos.app/MinimalIos