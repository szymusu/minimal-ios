#!/usr/bin/env sh
sh ./build-ios.sh
xcrun simctl install booted MinimalIos.app
xcrun simctl launch --console booted pl.n4u.minimalios