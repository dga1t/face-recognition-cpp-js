{
  "targets": [
    {
      "target_name": "faces",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/index.cpp",
        "./src/detector.cpp",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "/usr/local/include/opencv4",
        "/usr/local/lib",
      ],
      "library_dirs": [
       "-lopencv_objdetect",
       "-lopencv_highgui",
       "-lopencv_imgproc",
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}