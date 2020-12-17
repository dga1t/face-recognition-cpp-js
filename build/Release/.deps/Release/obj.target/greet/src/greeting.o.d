cmd_Release/obj.target/greet/src/greeting.o := g++ -o Release/obj.target/greet/src/greeting.o ../src/greeting.cpp '-DNODE_GYP_MODULE_NAME=greet' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DBUILDING_NODE_EXTENSION' -I/usr/include/nodejs/include/node -I/usr/include/nodejs/src -I/usr/include/nodejs/deps/openssl/config -I/usr/include/nodejs/deps/openssl/openssl/include -I/usr/include/nodejs/deps/uv/include -I/usr/include/nodejs/deps/zlib -I/usr/include/nodejs/deps/v8/include -I/home/tripleog/prgrmng/safeguard/face-recognition-cpp-js/node_modules/node-addon-api  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -fPIC -O3 -fno-omit-frame-pointer -fno-rtti -std=gnu++1y -MMD -MF ./Release/.deps/Release/obj.target/greet/src/greeting.o.d.raw   -c
Release/obj.target/greet/src/greeting.o: ../src/greeting.cpp \
 ../src/greeting.h
../src/greeting.cpp:
../src/greeting.h:
