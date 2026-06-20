# Quest to make smallest, simplest correct iOS app

## install app on Simulator
```shell
xcrun simctl install booted MinimalIos.app
```

## run app on Simulator
```shell
xcrun simctl launch booted pl.n4u.minimalios
```

## view logs
```shell
xcrun simctl spawn booted log stream --predicate 'process == "MinimalIos"'
xcrun simctl spawn booted log stream --predicate 'eventMessage CONTAINS "pl.n4u.minimalios"' --style compact
```