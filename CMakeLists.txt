cmake_minimum_required(VERSION 3.25)
project(test_onnx_runtime)

set(CMAKE_CXX_STANDARD 17)

include_directories(./onnxruntime_coreml/include)  # ヘッダファイルへのパス
link_directories(./onnxruntime_coreml/lib)  # ライブラリへのパス

add_executable(onnxruntime_test main.cpp)

target_link_libraries(onnxruntime_test onnxruntime)


