{
  "targets": [
    {
      "target_name": "faces",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/index.cpp",
        "./src/detector.cpp",
        "/home/tripleog/prgrmng/safeguard/face-recognition-cpp-js/src"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "<!(node -e \"require('nan')\")",
        "/usr/local/include/opencv4",
        "/usr/local/lib",
        "/home/tripleog/prgrmng/safeguard/face-recognition-cpp-js/src"
      ],
      "library_dirs": [
       "-lopencv_objdetect",
       "-lopencv_highgui",
       "-lopencv_imgproc",
       "/home/tripleog/prgrmng/safeguard/face-recognition-cpp-js/src"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}