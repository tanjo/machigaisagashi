# 間違い探し

## はじめに

```bash
git submodule update --init --recursive
pushd opencv
mkdir release
pushd release
cmake ..
make -j8
make install
popd
popd
cmake .
make
./machigaisagashi /Users/hoge/thisisimagepath/fuga.jpg
```

## おまけ

```bash
cmake -GXcode .
```

で Xcode のプロジェクトが作成される
便利
