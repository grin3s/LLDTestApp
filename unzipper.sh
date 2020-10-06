rm -rf ./app/build/outputs/apk/debug/unzipped-armv7
rm -rf ./app/build/outputs/apk/debug/unzipped-x86_64
rm -rf ./app/build/outputs/apk/debug/unzipped-armv8
rm -rf ./app/build/outputs/apk/debug/unzipped-x86

unzip ./app/build/outputs/apk/debug/app-armeabi-v7a-debug.apk -d ./app/build/outputs/apk/debug/unzipped-armv7
unzip ./app/build/outputs/apk/debug/app-x86_64-debug.apk -d ./app/build/outputs/apk/debug/unzipped-x86_64
unzip ./app/build/outputs/apk/debug/app-arm64-v8a-debug.apk -d ./app/build/outputs/apk/debug/unzipped-armv8
unzip ./app/build/outputs/apk/debug/app-x86-debug.apk -d ./app/build/outputs/apk/debug/unzipped-x86

sha1sum ./app/build/outputs/apk/debug/unzipped-armv7/lib/armeabi-v7a/libnative-lib.so
sha1sum ./app/build/outputs/apk/debug/unzipped-x86_64/lib/x86_64/libnative-lib.so
sha1sum ./app/build/outputs/apk/debug/unzipped-armv8/lib/arm64-v8a/libnative-lib.so
sha1sum ./app/build/outputs/apk/debug/unzipped-x86/lib/x86/libnative-lib.so