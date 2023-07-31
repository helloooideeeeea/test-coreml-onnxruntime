#include <iostream>
#include <vector>

#include "onnxruntime_cxx_api.h"

using namespace std;

int main() {

    Ort::SessionOptions session_options;

    // cpu
//    Ort::ThrowOnError(OrtSessionOptionsAppendExecutionProvider_CPU(session_options, 0));

    // coreml
    Ort::ThrowOnError(OrtSessionOptionsAppendExecutionProvider_CoreML(session_options, 1));

    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "TestONNXRuntime");
    Ort::Session onnx_session(env, "/Users/XXXX/dev/C++/test-onnx-runtime/large_model.onnx", session_options);

    // 入力と出力の情報を取得します。
    std::vector<int64_t> input_shape = {1, 16000};
    std::vector<float> input_tensor_values(1 * 16000);

    std::vector<const char*> input_node_names = {"input"};
    std::vector<const char*> output_node_names = {"output"};

    Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
    Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(), input_shape.data(), input_shape.size());

    // 現在の時刻を取得
    auto start = std::chrono::high_resolution_clock::now();

    auto output_tensors = onnx_session.Run(Ort::RunOptions{nullptr}, input_node_names.data(), &input_tensor, 1, output_node_names.data(), 1);

    // 推論後の時刻を取得
    auto end = std::chrono::high_resolution_clock::now();

//    for (auto& tensor : output_tensors) {
//        float* data = tensor.GetTensorMutableData<float>();
//        Ort::TensorTypeAndShapeInfo type_info = tensor.GetTensorTypeAndShapeInfo();
//        std::vector<int64_t> dimensions = type_info.GetShape();
//        int num_elements = std::accumulate(dimensions.begin(), dimensions.end(), 1, std::multiplies<int64_t>());
//        for (int i = 0; i < num_elements; i++) {
//            std::cout << "Result " << i << ": " << data[i] << std::endl;
//        }
//    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Inference time: " << duration << " ms" << std::endl;

    return 0;
}
