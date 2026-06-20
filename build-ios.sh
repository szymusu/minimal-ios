clang main.c \
	-target arm64-apple-ios26.5-simulator \
	-isysroot "$(xcrun --sdk iphonesimulator --show-sdk-path)" \
	-framework Foundation \
	-framework UIkit \
	-lobjc \
	-o MinimalIos.app/MinimalIos