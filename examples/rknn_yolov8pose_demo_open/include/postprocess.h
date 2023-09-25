#ifndef _POSTPROCESS_H_
#define _POSTPROCESS_H_

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>

typedef signed char int8_t;
typedef unsigned int uint32_t;

typedef struct
{
    float x;
    float y;
    float score;
} KeyPoint;

typedef struct
{
    float xmin;
    float ymin;
    float xmax;
    float ymax;
    float score;
    int classId;
    std::vector<KeyPoint> keyPoints;
} DetectRect;

// yolov8
class GetResultRectYolov8
{
public:
    GetResultRectYolov8();

    ~GetResultRectYolov8();

    int GenerateMeshgrid();

    int GetConvDetectionResult(int8_t **pBlob, std::vector<int> &qnt_zp, std::vector<float> &qnt_scale, std::vector<float> &DetectiontRects, std::vector<float> &DetectKeyPoints);

    float sigmoid(float x);

private:
    std::vector<float> meshgrid;

    const int class_num = 1;
    int headNum = 3;

    int input_w = 640;
    int input_h = 640;
    int strides[3] = {8, 16, 32};
    int mapSize[3][2] = {{80, 80}, {40, 40}, {20, 20}};
    int keypoint_num = 17;

    float nmsThresh = 0.45;
    float objectThresh = 0.5;
};

#endif
