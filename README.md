# yolov8pose_rknn_Cplusplus

yolov8pose  瑞芯微 rknn 板端 C++部署，使用平台 rk3588。模型转换和仿真测试参考 [onnx转rknn](https://blog.csdn.net/zhangqian_1/article/details/131857506)。

## 编译和运行

1）编译

```
cd examples/rknn_yolov8pose_demo_open

bash build-linux_RK3588.sh

```

2）运行

```
cd install/rknn_yolov8pose_demo_Linux

./rknn_yolov8pose_demo

```

注意：修改模型、测试图像、保存图像的路径，修改文件为src下的main.cc

```

int main(int argc, char **argv)
{
    char model_path[256] = "/home/zhangqian/rknn/examples/rknn_yolov8pose_demo_open/model/RK3588/yolov8pos_relu_zq.rknn";
    char image_path[256] = "/home/zhangqian/rknn/examples/rknn_yolov8pose_demo_open/test.jpg";
    char save_image_path[256] = "/home/zhangqian/rknn/examples/rknn_yolov8pose_demo_open/test_result.jpg";

    detect(model_path, image_path, save_image_path);
    return 0;
}
```


# 板端测试效果

冒号“:”前的数子是coco的80类对应的类别，后面的浮点数是目标得分。（类别:得分）

![images](https://github.com/cqu20160901/yolov8pose_rknn_Cplusplus/blob/main/examples/rknn_yolov8pose_demo_open/test_result.jpg)


说明：推理测试预处理没有考虑等比率缩放，激活函数 SiLU 用 Relu 进行了替换。由于使用的数据不多，效果并不是很好，仅供测试流程用。

把板端模型推理和后处理时耗也附上，供参考，使用的芯片rk3588，输入分辨率640x640。
![image](https://github.com/cqu20160901/yolov8pose_rknn_Cplusplus/blob/main/examples/rknn_yolov8pose_demo_open/yolov8pose_rknn%E6%8E%A8%E7%90%86%E5%92%8C%E5%90%8E%E5%A4%84%E7%90%86%E6%97%B6%E8%80%97.png)


# 相关参考链接
[【yolov8pose 瑞芯微RKNN芯片、地平线Horizon芯片、TensorRT部署】](https://blog.csdn.net/zhangqian_1/article/details/131857506)

[【yolov8pose 瑞芯微 RKNN 的 C++部署】](https://blog.csdn.net/zhangqian_1/article/details/133267470)

[【yolov8 瑞芯微RKNN和地平线Horizon芯片仿真测试部署】](https://blog.csdn.net/zhangqian_1/article/details/128918268)

[【yolov8 瑞芯微 RKNN 的 C++部署】](https://blog.csdn.net/zhangqian_1/article/details/131130085)

